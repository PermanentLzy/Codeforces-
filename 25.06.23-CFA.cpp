#include <iostream>
#include <vector>
using namespace std;

void solve(){
	long long int a, x, y;
	cin >> a >> x >> y;
	if((a < x && a < y) || (a > x && a > y))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	long long int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
