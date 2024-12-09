// IDEA: 
// if n >= k then according to the pigeon hole principle there would be two occurrance of same prefix modulo sum hence [l + 1, r] will have an modulo 0.

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    if(n >= k) {
        cout << "YES" << endl;
        return 0;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));

    auto f = [&](int i, int m, int flag, auto &&self) -> int {
        if(i == n) {
            return flag and m == 0;
        }

        if(dp[i][m][flag] != -1) return dp[i][m][flag];

        int cur = ((arr[i] % k) + m) % k;
        return dp[i][m][flag] = self(i + 1, cur, 1, self) | self(i + 1, m, flag, self);
    };

    if(f(0, 0, 0, f)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}   
