#include <iostream>
using namespace std;

int main()
{
    long long a = 1, b = 2;
    long long ans = 0;

    while (b < 4000000)
    {
        if (b % 2 == 0)
        {
            ans += b;
        }

        long long next = a + b;
        a = b;
        b = next;
    }

    cout << ans << endl;

    return 0;
}
