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

# Create directory
New-Item -ItemType Directory -Force -Path $Folder | Out-Null

# Generate solution.cpp
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
"@ | Set-Content "$Folder\solution.cpp"

# Generate explanation.md
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
"@ | Set-Content "$Folder\explanation.md"

Write-Host ""
Write-Host "Created:"
Write-Host "$Folder"
Write-Host " ├── solution.cpp"
Write-Host " └── explanation.md"
Write-Host ""