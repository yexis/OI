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
#define debug(x) cerr << (#x) << " = " << (x) << endl;
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
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        // 不包含返回
        double dp[1 << n][m];
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < m; i++) {
                dp[mask][i] = LLINF;
            }
        }  
        dp[0][0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            // int cnt = __builtin_popcount(mask);
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                int rst = mask ^ sub;

                int mx_time = 0, mn_time = INF;
                for (int d = 0; d < n; d++) {
                    if (sub >> d & 1) {
                        mx_time = max(mx_time, time[d]);
                        mn_time = min(mn_time, time[d]);
                    }
                }

                for (int sta = 0; sta < m; sta++) {
                    if (rst == 0) {
                        double t = 0;
                        int now_sta = sta;
                        t += (mx_time * mul[now_sta]);
                        now_sta += (int)(mx_time * mul[now_sta]) % m; 
                        dp[mask][now_sta] = min(dp[mask][now_sta], dp[rst][sta] + t);
                    } else {
                        double t = 0;
                        int now_sta = sta;

                        t += mn_time * mul[sta];
                        now_sta += (int)(mn_time * mul[sta]) % m;

                        t += (mx_time * mul[now_sta]);
                        now_sta += (int)(mx_time * mul[now_sta]) % m;
                        
                        dp[mask][now_sta] = min(dp[mask][now_sta], dp[rst][sta] + t);
                    }
                }
            }
        }

        double ans = LLINF;
        for (int sta = 0; sta < m; sta++) {
            ans = min(ans, dp[(1 << n) - 1][sta]);
        }

        double eps = 0.000000000001;
        if (abs(ans - LLINF) <= eps) {
            return -1;
        }
        return ans;
    }
};









