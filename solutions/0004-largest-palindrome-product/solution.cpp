#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    int reversed = 0;
    int original = n;

    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return reversed == original;
}

int main()
{
    int largest = 0;

    for (int a = 100; a < 1000; a++)
    {
        for (int b = a; b < 1000; b++)
        {
            int product = a * b;

            if (product > largest && isPalindrome(product))
            {
                largest = product;
            }
        }
    }

    cout << largest << endl;

    return 0;
}
