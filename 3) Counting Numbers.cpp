#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    string s, t; cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<vector<vector<int>>>> dp(m + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(11, -1))));

    auto f =[&](string &s, int index, int bound, int leadz, int prev, int n, auto &&self) -> int {
        if(index == n) {
            return 1;
        }

        if(dp[index][bound][leadz][prev] != -1) return dp[index][bound][leadz][prev];

        int answer = 0; 

        for(char i = '0'; i <= (bound ? s[index] : '9'); i++) {
            if((i - '0') == prev and !leadz) continue;
            answer += self(s, index + 1, (bound && (i == s[index])), (leadz && (i == '0')), i - '0', n, self);
        }

        return dp[index][bound][leadz][prev] = answer;

    };

    int x = f(t, 0, 1, 1, 0, m, f);

    dp.assign(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(11, -1))));

    x -= f(s, 0, 1, 1, 0, n, f);

    int fx = 1;

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            fx = 0;  
            break;
        }
    }
    cout << x + fx << endl;
    
    
}   
