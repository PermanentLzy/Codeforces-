#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long a_max = a[n - 1];
        long long ans = 0;

        for (int k = 2; k < n; ++k) {
            long long current = a[k];
            long long threshold = max(current, a_max - current);

            int l = 0, r = k - 1;
            int cnt = 0;

            while (l < r) {
                long long sum = a[l] + a[r];
                if (sum > threshold) {
                    cnt += r - l;
                    r--;
                } else {
                    l++;
                }
            }

            ans += cnt;
        }

        cout << ans << endl;
    }

    return 0;
}
