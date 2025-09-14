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
    // x is ok, x + 1 is ok ?
    vector<bool> subsequenceSumAfterCapping(vector<int>& a, int K) {
        int n = a.size();
        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0);
        sum = min(sum, 4000);

        // n * 4000
        vector<vector<bool>> dp(n, vector<bool>(sum + 1));
        for (int i = 0; i < n; i++) {
            if (i > 0) dp[i] = dp[i - 1];
            for (int x = 0; x <= sum; x++) {
                if (x - a[i] >= 0 && 
                    i - 1 >= 0 && dp[i - 1][x - a[i]]) {
                    dp[i][x] = true;
                }
            }
            dp[i][a[i]] = true;
        }

        vector<bool> res(n);
        for (int x = 1; x <= n; x++) {
            int k = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
            if (k < 0) {
                // no left
                int rst = n - k - 1;
                if (K % x == 0 && K / x <= rst) {
                    res[x - 1] = true;
                }
            } else {
                // dp[k]
                int rst = n - k - 1;
                if (K % x == 0 && K / x <= rst) {
                    res[x - 1] = true;
                    continue;
                }
                for (int d = 0; d <= sum; d++) {
                    if (!dp[k][d]) continue;
                    if (d > K) break;
                    if (d == K && dp[k][d]) {
                        res[x - 1] = true;
                        break;
                    }
                    int diff = K - d;
                    if (diff % x == 0 && diff / x <= rst) {
                        res[x - 1] = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};








