#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int target = 10001;
    const int limit = 200000;

    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; (long long)i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;

    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {
            count++;

            if (count == target)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
