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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    // 1. 所有连续的9个数需要是9的倍数，那么9个数的和必须是9的倍数
    // 2. 考虑滑动窗口
    //     a0 a1 a2 a3 a4 a5 a6 a7 a8 
    //        a1 a2 a3 a4 a5 a6 a7 a8 a9
    // 由于 sum(a0+...+a8) % 9 == 0 且 sum(a1+...+a9) % 9 == 0
    // 所有 a0 % 9 == a9 % 9
    // 同理 a1 == 10, a2 == a11 , ..., 
    // 由裴蜀定理得，可以将字符串s分成g组，每个组内的元素mod(9)相等，其中 g = gcd(n, 9)
    // g的取值情况：1,3,9
    
    int g = gcd(n, 9);
    vector<int> sz(9);
    vector<vector<int>> cnt(9, vector<int>(9));
    for (int i = 0; i < n; ++i) {
        sz[i % g]++;
        cnt[i % g][(s[i] - '0') % 9]++;
    }
    
    int ans = INF;
    if (g == 1) {
        // 所有元素mod(9)都相等
        for (int d = 0; d < 9; d++) {
            ans = min(ans, n - cnt[0][d]);
        }
    } else if (g == 3) {
        // 将第i个组全部改成j mod(3) 需要的修改次数
        vector<vector<int>> cost(3, vector<int>(3, INF));
        for (int i = 0; i < 3; i++) {
            for (int d = 0; d < 9; d++) {
                cost[i][d % 3] = min(cost[i][d % 3], sz[i] - cnt[i][d]);
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if ((i + j + k) % 3 == 0) {
                        ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
                    }
                }
            }
        }
    } else { // g == 9
        // dp[i][j] 表示将前面i组求和得到j mod(9)的最小修改次数
        vector<int> dp(9, INF); dp[0] = 0;
        for (int i = 0; i < 9; i++) {
            vector<int> ndp(9, INF);
            for (int x = 0; x < 9; x++) if (dp[x] != INF) {
                for (int y = 0; y < 9; y++) {
                    ndp[(x + y) % 9] = min(ndp[(x + y) % 9], dp[x] + sz[i] - cnt[i][y]);
                }
            } 
            dp.swap(ndp);
        }
        ans = dp[0];
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









