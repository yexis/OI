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
// 排列组合
// 设存在3个集合，3个集合内部存在各自的元素数量和排列方式
// cnt: 2 3 4
// per: 1 2 3
// 求三个集合融合后的排列方式有多少种？保持集合内部的排列方式
// 比如集合2内部3个元素，2种排列：分别是 1 2 3 和 2 1 3
// 融合后的排列依然需要保证原本的 1 2 3 或 2 1 3
// 最终答案是 1 * C(2,2) * 2 * C(5, 3) * 3 * C(9, 4) = 7560

// 如何计算移除一个集合后，剩余的排列数:
// 移除集合1：答案为 2 * C(3, 3) * 3 * C(7, 4) = 378
// 移除集合2：答案为 1 * C(2, 2) * 3 * C(6, 4) = 36
// 移除集合3：答案为 1 * C(2, 2) * 2 * C(5, 3) = 168

// 如何根据原排列数O(1)求得呢？
// 移除集合1：答案为 7560 / 1 * C(9, 2) = 378
// 移除集合2：答案为 7560 / 2 * C(9, 3) = 36
// 移除集合3：答案为 7560 / 3 * C(9, 4) = 168

// 证明：
// 原式为：1 * C(2,2) * 2 * C(5, 3) * 3 * C(9, 4)
// 将每个集合加入的顺序改一下，依然可以得到相同的结果，如：
// 2 * C(3, 3) * 1 * C(5, 2) * 3 * C(9, 4)
// 2 * C(3, 3) * 3 * C(7, 4) * 1 * C(9, 2) 
// 3 * C(4, 4) * 2 * C(7, 3) * 1 * C(9, 2) 
// 换句话说：
// C(2, 2) * C(5, 3) * C(9, 4)
// C(3, 3) * C(5, 2) * C(9, 4)
// C(3, 3) * C(7, 4) * C(9, 2)
// 即，对于相同的划分（可以是不是的顺序），最终得到的结果是一样的
// 也就是相同的划分，与划分顺序没有关系
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
    vector<pii> g[n + 1];
    vector<pii> edges(n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(pii(v, i));
        g[v].push_back(pii(u, i));
        edges[i] = pii(u, v);
    }

    ll dp1[n + 1]; for (int i = 1; i <= n; i++) dp1[i] = 0; // ans
    ll dp2[n + 1]; for (int i = 1; i <= n; i++) dp2[i] = 0; // cnt
    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        dp1[u] = 1;
        for (auto& [v, _] : g[u]) if (v != o) {
            dfs(dfs, v, u);
            dp1[u] *= C(dp2[u] + dp2[v], dp2[v]); dp1[u] %= mod;
            dp1[u] *= dp1[v]; dp1[u] %= mod; 
            
            dp2[u] += dp2[v]; 
        }
        dp2[u] += 1; 
    };

    // n - 1条边
    ll dp3[n]; for (int i = 0; i < n; i++) dp3[i] = 0;
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        bool debug = (o == 2 && u == 3);
        for (auto& [v, id] : g[u]) if (v != o) {
            // save 
            ll t1 = dp1[u], t2 = dp1[v];
            ll s1 = dp2[u], s2 = dp2[v];
            
            ll y = dp1[u] * power(dp2[v] * C(dp2[u] - 1, dp2[v]) % mod, mod - 2); y %= mod;
            dp2[u] -= dp2[v];
            // 这里为什么能这样计算？
            // 排列组合的公式：对于一个集合不同顺序的相同划分，划分方案数是不变的
            // 比如将 9 分成 (2, 3, 4)，则 C(2, 2) * C(5, 3) * C(9, 4)
            dp1[u] = y * dp1[o] % mod * C(dp2[u] - 1 + dp2[o], dp2[o]) % mod;
            dp2[u] += dp2[o];

            dp3[id] = dp1[v] * dp1[u] % mod *
                C(dp2[u] - 1 + dp2[v] - 1, dp2[v] - 1) % mod * 2 % mod;

            dfs2(dfs2, v, u);

            // recover 
            dp1[u] = t1, dp1[v] = t2;
            dp2[u] = s1, dp2[v] = s2;
        };
    };

    bool first = true;
    while (q--) {
        int x; cin >> x;
        rx = edges[x].first;
        ry = edges[x].second;
        if (first) {
            first = false;

            dfs(dfs, rx, ry); 
            dfs(dfs, ry, rx);
        
            dfs2(dfs2, rx, ry);
            dfs2(dfs2, ry, rx);

            ll ans = C(dp2[rx] - 1 + dp2[ry] - 1, dp2[ry] - 1);
            ans *= dp1[rx]; ans %= mod;
            ans *= dp1[ry]; ans %= mod;
            ans *= 2; ans %= mod;
            cout << ans << "\n";

            dp3[x] = ans;

            continue;
        }
        
        cout << dp3[x] << "\n";
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









