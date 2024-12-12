#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<vector<int>> transitions(1 << n);

    // Build the transitions for the dp recursive function.
    // For all the possible ith mask find the i + 1 th mask. (Here mask represents wheather the cell is filled or not).

    auto generate = [&](int index, int mask1, int mask2, auto &&self) -> void {
        if(index > n) return;
        if(index == n) {
            transitions[mask1].push_back(mask2);
            return;
        }

        self(index + 1, mask1 | (1 << index), mask2, self);

        self(index + 1, mask1, mask2 | (1 << index), self);
        self(index + 2, mask1, mask2, self);
    };

    generate(0, 0, 0, generate);

    vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));


    // dp[i][j] -> states the number of ways the tills can be fitted were the ith column is completely filled and while it has jth bitmask fillings currently.

    auto  f = [&](int index, int mask, auto &&self) -> int {
        if(index == m) {
            return mask == 0;
        }
        if(dp[index][mask] != -1) return dp[index][mask];
        int ways = 0;
        for(auto it : transitions[mask]) {
            ways = (ways  + self(index + 1, it, self)) % mod;
        }
        return dp[index][mask] = ways;
    };

    cout << f(0, 0, f) << endl;
    
}   
