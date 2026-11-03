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
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

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
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> C(n); for (int i = 0; i < n; i++) cin >> C[i];

    int diameter = 0, root = -1;
    vector<int> dp(n, 0), dep(n, 0);
    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        int curr = 0;
        dp[u] = 1;
        
        for (auto& v : g[u]) if (v != o) {
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u);
            
            dp[u] = max(dp[u], 1 + dp[v]);

            if (curr + 1 + dp[v] > diameter) {
                diameter = curr + 1 + dp[v];
                root = u;
            }
            curr = max(curr, dp[v]);
        }
    };
    dfs(dfs, 0, -1);

    diameter = 0;

    int max_dep = -1, max_dep2 = -1;
    vector<int> dp2(n, 0), dep2(n, 0);
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        int curr = 0;
        dp2[u] = 1;
        for (auto& v : g[u]) if (v != o) {
            dep2[v] = dep2[u] + 1;
            dfs2(dfs2, v, u);
            dp2[u] = max(dp2[u], 1 + dp2[v]);
            
            if (curr + 1 + dp2[v] > diameter) {
                diameter = curr + 1 + dp2[v];
                root = u;
                curr == 0 ? (max_dep = dp2[v], max_dep2 = -1) : (max_dep2 = curr, max_dep = dp2[v]);
            }
            curr = max(curr, dp2[v]);
        }
    };
    dfs2(dfs2, root, -1);
    if (max_dep < max_dep2) swap(max_dep, max_dep2);

    ll ans = 0;
    vector<int> mp[n + 1];
    for (int i = 0; i < n; i++) {
        mp[C[i]].push_back(i);
    }

    // 直径的一端是root
    if (max_dep2 == -1) {
        for (int i = 0; i < n; i++) {
            if (dep2[i] == max_dep && C[i] == C[root]) ans++;
        }
        cout << ans << "\n";
        return;
    }

    if (max_dep == max_dep2) {
        unordered_map<int, int> tmp;
        auto work = [&](auto&& work, int u, int o) -> void {
            if (dep2[u] == max_dep) tmp[C[u]]++;
            for (auto v : g[u]) if (v != o) {
                work(work, v, u);
            }
        };
        vector<int> gColors(n + 1);
        for (auto& nxt : g[root]) {
            work(work, nxt, root);
            for (auto [k, v] : tmp) {
                ans += 1ll * gColors[k] * v;
                gColors[k] += v;
            }
            tmp.clear();
        }
        cout << ans << "\n";
    } else {
        int fg = 0;
        unordered_map<int, int> tmp1, tmp2;
        vector<int> gColors(n + 1), gColors2(n + 1);
        auto work = [&](auto&& work, int u, int o) -> void {
            if (dep2[u] == max_dep) {
                fg |= 1;
                tmp1[C[u]]++;
            }
            if (dep2[u] == max_dep2) {
                fg |= 1 << 1;
                tmp2[C[u]]++;
            }
            for (auto v : g[u]) if (v != o) {
                work(work, v, u);
            }
        };
        for (auto& nxt : g[root]) {
            work(work, nxt, root);
            // debugs(fg);
            if (fg & 1) {
                for (auto [k, v] : tmp1) {
                    ans += 1ll * v * gColors2[k];
                    gColors[k] += v;
                }
            } else {
                for (auto [k, v] : tmp2) {
                    ans += 1ll * v * gColors[k];
                    gColors2[k] += v;
                }
            }
            fg = 0;
            tmp1.clear();
            tmp2.clear();
        }
        cout << ans << "\n";
    }
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









