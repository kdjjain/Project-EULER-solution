#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    // logic : C(n, r) increases up to the middle and then decreases, and it is
    // symmetric (C(n, r) == C(n, n - r)). So once it first exceeds one million at
    // some r = k, it stays above the limit until r = n - k. That gives
    // (n - k + 1) - k = n - 2k + 1 values for this n, and we never need to compute
    // the huge middle values (which would overflow).
    const long long LIMIT = 1000000;
    int count = 0;

    for (int n = 1; n <= 100; n++) {
        long long ncr = 1; // C(n, 0)
        for (int r = 1; r <= n / 2; r++) {
            ncr = ncr * (n - r + 1) / r;
            if (ncr > LIMIT) {
                count += n - 2 * r + 1;
                break;
            }
        }
    }

    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
