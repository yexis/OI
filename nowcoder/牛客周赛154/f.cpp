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
    int n, X, Y; cin >> n >> X >> Y;
    vector<int> a(n); for (int& e : a) cin >> e;

    // 前i个元素 最后一位剩余j，往右能消灭k个所需要的最小法力
    const int N = 50;
    ll dp[n + 1][51][51]; for (int i = 0; i <= n; i++) for (int j = 0; j <= 50; j++) for (int k = 0; k <= 50; k++) dp[i][j][k] = LLINF;

    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        ll x = a[i - 1];
        // 上一位剩余d
        int mx_d = (i - 2 >= 0 ? a[i - 2] : N); 
        for (int d = 0; d <= min(mx_d, N); d++) {
            // 上一位置额外给到本位置的法力
            for (int e = 0; e <= N; e++) {
                if (dp[i - 1][d][e] == LLINF) continue;
                // 使用几个y
                for (int f = 0; f <= 50; f++) {
                    ll cost = 1ll * f * Y;
                    int last = max(d - f, 0);
                    cost += max((ll)last * X, 0ll);

                    int cd = max(x - e - 2 * f, 0ll);
                    int ce = f;

                    dp[i][cd][ce] = min(dp[i][cd][ce], dp[i - 1][d][e] + cost);
                }
            }
        }
    }
    ll ans = LLINF;
    for (int d = 0; d <= min(a[n - 1], N); d++) {
        for (int k = 0; k <= N; k++) {
            ans = min(ans, dp[n][0][k]);
            ans = min(ans, dp[n][d][k] + (ll)d * X);
        }        
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









