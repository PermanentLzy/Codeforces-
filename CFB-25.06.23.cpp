#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		b[i] = a[n-1-i];
	}
	
	int ans1 = -1, initial1 = -1;
	for(int i = 0; i < n-1; i++)
	{
		int min_value1 = -1, max_value1 = -1;
		for(int j = i+1; j < n; j++)
		{
			if(j == i+1)
			{
				if(abs(a[j] - a[i]) < 2)
				{
					ans1 = 0;
					break;
				}
				else
				{
					initial1 = a[j];
				}				
			}
			else 
			{
				if(j == i+2)
				{
					min_value1 = min(initial1, a[j]);
					max_value1 = max(initial1, a[j]);
				}
				else
				{
					min_value1 = min(min_value1, a[j]);
					max_value1 = max(max_value1, a[j]);
				}
				
				if(min_value1 - 1 <= a[i] && max_value1 + 1 >= a[i])
				{
					if(ans1 == -1)
						ans1 = j - i - 1;
					else
						ans1 = min(ans1, j - i - 1);
						
					break;
				}
			}		
		}
	}
	
	int ans2 = -1, initial2 = -1;
	for(int i = 0; i < n-1; i++)
	{
		int min_value2 = -1, max_value2 = -1;
		for(int j = i+1; j < n; j++)
		{
			if(j == i+1)
			{
				if(abs(b[j] - b[i]) < 2)
				{
					ans2 = 0;
					break;
				}
				else
				{
					initial2 = b[j];
				}				
			}
			else 
			{
				if(j == i+2)
				{
					min_value2 = min(initial2, b[j]);
					max_value2 = max(initial2, b[j]);
				}
				else
				{
					min_value2 = min(min_value2, b[j]);
					max_value2 = max(max_value2, b[j]);
				}
				
				if(min_value2 - 1 <= b[i] && max_value2 + 1 >= b[i])
				{
					if(ans2 == -1)
						ans2 = j - i - 1;
					else
						ans2 = min(ans2, j - i - 1);
						
					break;
				}
			}		
		}
	}
	
	if(ans1 == -1 || ans2 == -1)
		cout << max(ans1, ans2) << endl;
	else
		cout << min(ans1, ans2) << endl;
	
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	
	return 0;
}
