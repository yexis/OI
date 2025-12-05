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

void solve() {
    int n; cin >> n;
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> is_leaf(n);
    vector<bool> is_leaf_fa(n);
    vector<int> dep(n);
    auto dfs = [&](auto&& dfs, int u, int o)  -> void  {
        bool leaf  = true;
        for (auto& v : g[u]) if (v != o) {
            leaf = false;
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u);
        } 
        if (leaf) is_leaf[u] = true;
    };
    dfs(dfs, 0, -1);
    
    // 记录叶子节点的父节点的数量
    vector<int> res(n);
    int dp[n][4]; memset(dp, 0, sizeof(dp));
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        dp[u][2] = 1;
        dp[u][0] = 0, dp[u][1] = 0;
        
        bool all_leaf = true;
        for (auto& v : g[u]) if (v != o) {
            dfs2(dfs2, v, u);
            dp[u][2] += dp[v][2];
            if (!is_leaf[v]) all_leaf = false;

            if (dp[v][0] + 1 > dp[u][0]) {
                dp[u][0] = dp[v][0] + 1;
                dp[u][1] = dp[v][1];
            } else if (dp[v][0] + 1 == dp[u][0]) {
                dp[u][1] += dp[v][1];
            }
        }
        if (all_leaf) is_leaf_fa[u] = true;

        if (is_leaf[u]) {
            res[u] = 0;
        } else {
            if (is_leaf_fa[u]) {
                dp[u][1] = 1;
                res[u] = 1;
            } else {
                res[u] = dp[u][1];
            }
        }
    };
    dfs2(dfs2, 0, -1);
    
    for (auto & e : res) {
        cout << e << " ";
    }
    cout << "\n";
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









