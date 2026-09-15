#include <iostream>
using namespace std;

int main()
{
    long long sumOfSquares = 0;
    long long sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        sumOfSquares += (long long)i * i;
        sum += i;
    }

    long long squareOfSum = sum * sum;

    cout << squareOfSum - sumOfSquares << endl;

    return 0;
}
