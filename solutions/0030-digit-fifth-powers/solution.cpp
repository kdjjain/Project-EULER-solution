#include<bits/stdc++.h>
using namespace std;

void solve()
{
    // Precomputed fifth powers of digits 0..9.
    int pow5[10];
    for (int d = 0; d < 10; d++)
    {
        pow5[d] = d * d * d * d * d;
    }

    // Upper bound: 6 * 9^5 = 354294 (7-digit numbers are impossible).
    const int LIMIT = 6 * pow5[9];
    int total = 0;

    for (int n = 10; n <= LIMIT; n++)
    {
        int sum = 0;
        for (int x = n; x > 0; x /= 10)
        {
            sum += pow5[x % 10];
        }

        if (sum == n)
        {
            total += n;
        }
    }

    cout << total << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
