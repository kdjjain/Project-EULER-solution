param(
    [int]$ProblemNumber,
    [string]$ProblemTitle
)

# Format problem number to 4 digits
$FormattedNumber = $ProblemNumber.ToString("0000")

# Convert title to kebab-case
$Slug = $ProblemTitle.ToLower()
$Slug = $Slug -replace '[^a-z0-9]+', '-'
$Slug = $Slug.Trim('-')

# Create folder path
$Folder = "solutions\$FormattedNumber-$Slug"
$SolutionPath = "$Folder\solution.cpp"
$ExplanationPath = "$Folder\explanation.md"

# Create directory only if it does not already exist
if (Test-Path $Folder)
{
    Write-Host "Folder already exists: $Folder. Existing content will be preserved."
}
else
{
    New-Item -ItemType Directory -Force -Path $Folder | Out-Null
}

# Generate solution.cpp only if it does not already exist
if (Test-Path $SolutionPath)
{
    Write-Host "solution.cpp already exists. Skipping to avoid overwriting existing work."
}
else
{
    @"
#include<bits/stdc++.h>
using namespace std;

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
"@ | Set-Content $SolutionPath
}

# Generate explanation.md only if it does not already exist
if (Test-Path $ExplanationPath)
{
    Write-Host "explanation.md already exists. Skipping to avoid overwriting existing work."
}
else
{
    @"
# Problem $FormattedNumber - $ProblemTitle

## Problem

Project Euler Problem #$ProblemNumber

Problem Link:
https://projecteuler.net/problem=$ProblemNumber

## Approach

TODO

## Complexity

Time Complexity: TODO

Space Complexity: TODO
"@ | Set-Content $ExplanationPath
}

# Update README progress table
$ReadmePath = "README.md"

if (Test-Path $ReadmePath)
{
    $Lines = Get-Content $ReadmePath
    $NewRow = "| $FormattedNumber | $ProblemTitle | [View Solution](solutions/$FormattedNumber-$Slug/) |"

    if ($Lines -match [regex]::Escape("solutions/$FormattedNumber-$Slug/"))
    {
        Write-Host "README already contains an entry for problem $FormattedNumber. Skipping table update."
    }
    else
    {
        # Find the index of the last existing table row
        $LastRowIndex = -1

        for ($i = 0; $i -lt $Lines.Count; $i++)
        {
            if ($Lines[$i] -match '^\|\s*\d{4}\s*\|')
            {
                $LastRowIndex = $i
            }
        }

        $Result = New-Object System.Collections.Generic.List[string]
        $Inserted = $false

        for ($i = 0; $i -lt $Lines.Count; $i++)
        {
            $Line = $Lines[$i]

            # Insert the new row in sorted order among existing rows
            if (-not $Inserted -and $Line -match '^\|\s*(\d{4})\s*\|' -and [int]$Matches[1] -gt $ProblemNumber)
            {
                $Result.Add($NewRow)
                $Inserted = $true
            }

            $Result.Add($Line)

            # If this is the last table row and no larger row was found, append after it
            if (-not $Inserted -and $i -eq $LastRowIndex)
            {
                $Result.Add($NewRow)
                $Inserted = $true
            }

            # Update the total counter
            if ($Line -match '^\*\*Total problems solved:\s*(\d+)\*\*')
            {
                $Result.RemoveAt($Result.Count - 1)
                $Total = [int]$Matches[1] + 1
                $Result.Add("**Total problems solved: $Total**")
            }
        }

        Set-Content -Path $ReadmePath -Value $Result
        Write-Host "Updated README progress table."
    }
}

Write-Host ""
Write-Host "Created:"
Write-Host "$Folder"
Write-Host "  - solution.cpp"
Write-Host "  - explanation.md"
Write-Host ""