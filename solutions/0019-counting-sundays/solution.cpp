#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

bool isLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void solve()
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 1 Jan 1900 was a Monday. With Monday = 0, Sunday = 6.
    int dow = 0;
    int count = 0;

    for (int year = 1900; year <= 2000; year++)
    {
        for (int month = 0; month < 12; month++)
        {
            // dow is the weekday of the first of this month.
            if (year >= 1901 && dow == 6)
            {
                count++;
            }

            int days = daysInMonth[month];
            if (month == 1 && isLeap(year))
            {
                days = 29;
            }

            dow = (dow + days) % 7;
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
