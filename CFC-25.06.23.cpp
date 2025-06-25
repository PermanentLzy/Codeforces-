#include <iostream>
#include <vector>
using namespace std;

void ans_state_right(vector<long long int>& a, long long int left, long long int right, long long int num, long long int& result) {
	if (left == right)
	{
		if (a[left] < num)
			result = left;

		return;
	}

	long long int mid = (left + right) / 2;
	if (a[mid] < num)
	{
		result = mid;
		ans_state_right(a, mid + 1, right, num, result);
	}
	else
	{
		ans_state_right(a, left, mid, num, result);
	}

	return;
}

void ans_state_left(vector<long long int>& a, long long int left, long long int right, long long int max_value, long long int& result){
	if (left == right)
	{
		if (a[left] > max_value)
			result = left;

		return;
	}

	long long int mid = (left + right) / 2;
	if (a[mid] > max_value)
	{
		result = mid;
		ans_state_left(a, left, mid, max_value, result);
	}
	else
	{
		ans_state_left(a, mid+1, right, max_value, result);
	}

	return;
}

void solve() {
	long long int n;
	cin >> n;
	vector<long long int> a(n);

	for (long long int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	long long int ans = 0;
	for (long long int i = 0; i < n - 2; i++)
	{
		for (long long int j = i + 1; j < n - 1; j++)
		{
			long long int num = a[i] + a[j];
			long long int max_value = a[n-1] - a[i] - a[j];
			long long int part_left = -1;
			long long int part_right = -1;
			
			ans_state_left(a, j + 1, n - 1, max_value, part_left);
			ans_state_right(a, j + 1, n - 1, num, part_right);
			
		
			if (part_right >= 0 && part_left >= 0 && part_right >= part_left)
			{
				ans += part_right - part_left + 1;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	long long int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
