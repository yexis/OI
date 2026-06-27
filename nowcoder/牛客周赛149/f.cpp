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
 * https://ac.nowcoder.com/acm/contest/136720/F
 * 很难的换根DP
 * 第一次见 在边上统计答案
*/

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v); g[v].push_back(u);
    }

    // -1 表示子节点中没有红色节点
    // dp 往上合并成一个红色联通块，需要的修改个数
    // dp2 子树内部自身形成一个红色连通，需要的修改个数
    // ms 记录所有子节点单独形成一个红色连通的修改个数
    int dp[n]; memset(dp, -1, sizeof(dp));
    int dp2[n]; memset(dp2, 0, sizeof(dp2));
    multiset<int> ms[n];
    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        int u_is_red = (s[u] == '1');
        for (auto& v : g[u]) if (v != o) {
            dfs(dfs, v, u);
        }
        int red_child = 0, red_child_idx = -1;
        for (auto& v : g[u]) if (v != o) {
            if (dp[v] == -1) continue;
            red_child++; red_child_idx = v;
            dp[u] = (dp[u] == -1 ? dp[v] : dp[u] + dp[v]);  
            ms[u].insert(dp2[v]); // v子树包含1
        }
        dp2[u] = red_child;
        // 没有包含红色的孩子，且u也不是红色
        if (red_child == 0) { 
            if (u_is_red) dp[u] = 0;
            else dp[u] = -1;  
        } else {
            // 有包含红色的孩子
            if (!u_is_red) { 
                dp[u] += 1; 
            }
        }
        
        if (u_is_red) dp2[u] = dp[u];
        else if (dp[u] == -1) dp2[u] = 1;
        else if (red_child == 1) dp2[u] = dp2[red_child_idx]; 
        else dp2[u] = dp[u];
        return;
    };
    dfs(dfs, 0, -1);

    unordered_map<ll, int> mp;
    auto get_key = [&](int u, int v) -> ll {
        return 1ll * u * (200010) + v;
    };

    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        bool u_is_red = (s[u] == '1');
        for (auto& v : g[u]) if (v != o) {
            bool v_is_red = (s[v] == '1');
            int uu = u, vv = v; if (uu > vv) swap(uu, vv);
            ll key = get_key(uu, vv);

            // save env
            int tmp_u = dp[u], tmp_v = dp[v];
            int tmp2_u = dp2[u], tmp2_v = dp2[v];

            if (tmp_v != -1) ms[u].erase(ms[u].find(tmp2_v)); 

            if (dp[v] != -1) dp[u] -= dp[v];
            if (ms[u].empty() && !u_is_red) dp[u] = -1;
            dp[v] = (dp[v] == -1 ? dp[u] : (dp[u] == -1 ? dp[v] : dp[v] + dp[u]));

            // upd dp2[u]
            if (u_is_red) dp2[u] = dp[u];
            else {
                if (ms[u].size() == 0) dp2[u] = 1;
                else if (ms[u].size() == 1) dp2[u] = *ms[u].begin();
                else dp2[u] = dp[u];
            }

            if (dp[u] != -1) ms[v].insert(dp2[u]);
            
            // 在已经更新了u，但是v还没更新时统计答案
            mp[key] = dp2[u] + dp2[v];

            // upd dp2[v]
            if (v_is_red) dp2[v] = dp[v];
            else {
                if (ms[v].size() == 0) dp2[v] = 1;
                else if (ms[v].size() == 1) dp2[v] = *ms[v].begin();
                else dp2[v] = dp[v];
            }
            
            dfs2(dfs2, v, u);

            // recover env
            if (dp[u] != -1) ms[v].erase(ms[v].find(dp2[u])); 
            if (tmp_v != -1) ms[u].insert(tmp2_v);
            dp2[u] = tmp2_u, dp2[v] = tmp2_v;
            dp[u] = tmp_u, dp[v] = tmp_v;
        }
    };
    dfs2(dfs2, 0, -1);

    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v) swap(u, v);
        ll key = get_key(u, v);
        cout << mp[key] << "\n";
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









