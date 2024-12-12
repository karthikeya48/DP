#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) {
      
        int n; cin >> n;
      
        vector<int> a(n);
        vector<int> b(n);
      
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }    

        // idea: At every index atmost 2 increment is more than enough.

        vector<vector<int>> dp(n + 1, vector<int>(3, -1));

        auto f = [&](int index, int times, auto &&self) -> int {
            if(index == n) {
                return 0;
            }
            if(dp[index][times] != -1) return dp[index][times];

            int cost = LLONG_MAX; 

            for(int i = 0; i <= 2; i++) {
                if(index != 0) {
                    if(a[index - 1] + times != a[index] + i) {
                        cost = min(cost, b[index] * i + self(index + 1, i, self));
                    }
                } else {
                    cost = min(cost, b[index] * i + self(index + 1, i, self));
                } 
            }

            return dp[index][times] = cost;
        };

        cout << f(0, 0, f) << endl;
    }
    
    
}   
