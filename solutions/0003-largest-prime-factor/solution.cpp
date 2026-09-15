#include <iostream>
using namespace std;

int main()
{
    long long n = 600851475143;
    long long largest = 1;

    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            largest = i;
            n /= i;
        }
    }

    if (n > 1)
    {
        largest = n;
    }

    cout << largest << endl;

    return 0;
}
