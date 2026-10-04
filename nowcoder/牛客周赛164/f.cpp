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
const int mod = 998244353;
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

const int maxn = 200000;
ll fac[maxn + 10], inv[maxn + 10];
ll get_inv(ll x) {
    ll ans = 1;
    int p = mod - 2;
    while (p) {
        if (p & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = get_inv(fac[i]);
    }
}

ll C(int n, int k) {
    if (n < 0 || k < 0 || k > n) {
        return 0;
    }
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() {
    int n, q; cin >> n >> q;
    int rx, ry;
    vector<int> g[n + 1];
    vector<pii> edges(n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = pii(u, v);
    }

    ll dp1[n + 1]; for (int i = 1; i <= n; i++) dp1[i] = 0; // ans
    ll dp2[n + 1]; for (int i = 1; i <= n; i++) dp2[i] = 0; // cnt
    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        dp1[u] = 1;
        for (auto& v : g[u]) if (v != o) {
            dfs(dfs, v, u);
            if (dp2[u] == 0) {
                dp1[u] = dp1[v];
                dp2[v] += dp2[v];
            } else {
                dp1[u] *= C(dp2[u] + dp2[v], dp2[v]); dp1[u] %= mod;
                dp1[u] *= dp1[v]; dp1[u] %= mod;
                dp2[u] += dp2[v];
            }
            
        }
        dp2[u] += 1; 
    };

    while (q--) {
        int x; cin >> x;
        rx = edges[x].first;
        ry = edges[x].second;

        dfs(dfs, rx, ry); 
        dfs(dfs, ry, rx);
        
        ll ans = 1;
        ans *= C(dp2[rx] - 1 + dp2[ry] - 1, dp2[ry] - 1); ans %= mod;
        ans *= dp1[rx]; ans %= mod;
        ans *= dp1[ry]; ans %= mod;
        ans *= 2; ans %= mod;
        cout << ans << "\n";
    }
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    
    init();

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









