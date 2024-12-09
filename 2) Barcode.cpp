#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        int n, m; cin >> n >> m;
        int x, y; cin >> x >> y;

        vector<vector<int>>mat(m, vector<int>(2, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch; cin >> ch;
                if(ch == '.') mat[j][0]++;
                else mat[j][1]++;     
            }           
        }

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(2, vector<int>(m + 1, -1)));

        auto f = [&](int i, int prev, int con, auto&&self) -> int {

            if(i == m) {
                if(con < x) {
                    return INT_MAX;
                }
                return 0;
            }
            if(dp[i][prev][con] != -1) return dp[i][prev][con];

            int count = INT_MAX;

            // 0 -> .
            // 1 -> #

            if(con < x || con + 1 <= y) {
                count = min(count, mat[i][prev ^ 1] + self(i + 1, prev, con + 1, self));
            } 
            if(con >= x) {
                count = min(count, mat[i][prev] + self(i + 1, prev ^ 1, 1, self));
            }

            return dp[i][prev][con] = count;

        };

        cout << min(mat[0][1] + f(1, 0, 1, f), mat[0][0] + f(1, 1, 1, f)) << endl;

}   
