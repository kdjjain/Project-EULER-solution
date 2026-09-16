#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

// Add two large numbers stored as vectors of digits (least significant digit first)
vector<int> add(vector<int> v1, vector<int> v2)
{
	vector<int> result;
	int carry = 0;
	int n = max(v1.size(), v2.size());

	for (int i = 0; i < n; i++)
	{
		int digit = carry;

		if (i < (int)v1.size())
		{
			digit += v1[i];
		}

		if (i < (int)v2.size())
		{
			digit += v2[i];
		}

		result.push_back(digit % 10);
		carry = digit / 10;
	}

	while (carry > 0)
	{
		result.push_back(carry % 10);
		carry /= 10;
	}

	return result;
}

void solve()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v2.push_back(1);

	for (int i = 3; ; i++)
	{
		vector<int> v3 = add(v1, v2);

		if (v3.size() >= 1000)
		{
			cout << i << endl;
			break;
		}

		v1 = v2;
		v2 = v3;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
