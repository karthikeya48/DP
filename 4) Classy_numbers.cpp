#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) {
        string s, t; cin >> s >> t;
        vector<vector<vector<vector<int>>>> dp(t.size(), vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(4, -1))));

        auto f = [&](int index, int bound, int leadz, int count, string &s, int n, auto&&self) -> int {
            if(index == n) return count <= 3;

            if(dp[index][bound][leadz][count] != -1) return dp[index][bound][leadz][count];

            int answer = 0;

            for(char digit = '0'; digit <= (bound ? s[index] : '9'); digit++) { 
                if(count + (digit != '0') <= 3) {
                    answer += self(index + 1, bound && (digit == s[index]), leadz && digit == '0', count + (digit != '0'), s, n, self);
                }
            }

            return dp[index][bound][leadz][count] = answer;

        };
        int isvalid = 1;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt += (s[i] != '0');
        }

        int ans =  f(0, 1, 1, 0, t, t.size(), f);
        dp.assign(s.size(), vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(4, -1))));
        cout << ans - f(0, 1, 1, 0, s, s.size(), f) + (cnt <= 3) << endl;
    }
    
    
}   
