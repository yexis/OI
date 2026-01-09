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

constexpr static int maxn = 2e5;
vector<int> fac[maxn + 5];
int _ = []() -> int {
    for (int i = 1; i <= maxn; i++) {
        // 以i为步长
        // 3 6 9 12 15 18 ...
        // 4 8 12 16 20 24 ...
        for (int j = i; j <= maxn; j += i) {
            fac[j].push_back(i);
        }
    }
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1;
    
    int dp[n + 1]; memset(dp, 1, sizeof(dp));
    // f：从因子转移
    int f[n + 1]; memset(f, 0, sizeof(f));
    // g：从倍数转移
    int g[n + 1]; memset(g, 0, sizeof(g));
    for (int i = 0; i < n; i++) {
        int x = a[i];
        // 1. 从因子转移而来
        // 2. 从倍数转移而来
        for (int fa : fac[x]) {
            dp[i] = max(dp[i], f[fa] + 1);
            dp[i] = max(dp[i], g[x] + 1);
        }

        ans = max(ans, dp[i]);

        f[x] = max(f[x], dp[i]);
        for (int fa : fac[x]) {
            g[fa] = max(g[fa], dp[i]);
        }
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









