#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <limits>
#include <climits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 
*/

class Solution {
public:
    int countStableSubsequences(vector<int>& a) {
        int n = a.size();

        ll dp[n + 1][2][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            // odd
            int odd = (a[i - 1] & 1);
            
            for (int i1 = 0; i1 < 2; i1++) {
                for (int i2 = 0; i2 < 2; i2++) {
                    dp[i][i1][i2] = dp[i - 1][i1][i2];
                }
            }
            
            dp[i][odd][0] += 1;
            dp[i][odd][0] %= mod;

            dp[i][odd][0] += (dp[i - 1][!odd][0] + dp[i - 1][!odd][1]);
            dp[i][odd][0] %= mod;

            dp[i][odd][1] += (dp[i - 1][odd][0]);
            dp[i][odd][1] %= mod;
        }

        ll ans = 0;
        for (int i1 = 0; i1 < 2; i1++) {
            for (int i2 = 0; i2 < 2; i2++) {
                ans += dp[n][i1][i2];
                ans %= mod;
            }
        }
        return ans;
    }
};





