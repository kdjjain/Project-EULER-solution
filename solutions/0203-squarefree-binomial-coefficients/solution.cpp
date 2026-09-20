#include<bits/stdc++.h>
using namespace std;

// A number is squarefree if no prime square divides it.
bool isSquarefree(long long n)
{
    for (long long p = 2; p * p <= 51; p++)
    {
        if (n % (p * p) == 0)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    const int ROWS = 51; // rows 0 to 50

    // Build Pascal's triangle row by row.
    vector<vector<long long>> c(ROWS, vector<long long>(ROWS, 0));
    set<long long> distinct;

    for (int n = 0; n < ROWS; n++)
    {
        c[n][0] = c[n][n] = 1;

        for (int r = 1; r < n; r++)
        {
            c[n][r] = c[n - 1][r - 1] + c[n - 1][r];
        }

        for (int r = 0; r <= n; r++)
        {
            distinct.insert(c[n][r]);
        }
    }

    long long sum = 0;

    for (long long value : distinct)
    {
        if (isSquarefree(value))
        {
            sum += value;
        }
    }

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
