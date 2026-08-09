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
    string color; cin >> color;
    vector<int> g[n]; for (int i = 0; i < n - 1; i++) { int u, v; cin >> u >> v; u--, v--; g[u].push_back(v); g[v].push_back(u); }

    int ans = 0;
    multiset<int> ms[n];
    vector<int> dp(n, -1); // u子树中离u最远的红点距离
    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        if (color[u] == '1') dp[u] = 0, ms[u].insert(0);
        for (auto& v : g[u]) if (v != o) {
            dfs(dfs, v, u);
            if (dp[v] != -1) {
                dp[u] = max(dp[u], dp[v] + 1);
                ms[u].insert(dp[v] + 1);
            }
            if (ms[u].size() >= 2) {
                int t = *ms[u].rbegin() + *next(ms[u].rbegin());
                ans = max(ans, t);
            }
            if (ms[u].size() >= 1 && color[u] == '1') {
                int t = *ms[u].begin();
                ans = max(ans, t);
            }
        }
    };
    dfs(dfs, 0, -1);

    vector<int> res(n);
    // re-root
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        // 增加点的话，这个点一定是白色，才有可能使得ans更大
        // 且节点u一定是线段的一端
        res[u] = max(ans, dp[u]);

        for (auto& v : g[u]) if (v != o) {
            int tmp_u = dp[u], tmp_v = dp[v];

            if (dp[v] != -1) ms[u].erase(ms[u].find(dp[v] + 1));
            if (ms[u].size()) dp[u] = *ms[u].rbegin();
            else dp[u] = -1;

            if (dp[u] != -1) ms[v].insert(dp[u] + 1);
            if (ms[v].size()) dp[v] = *ms[v].rbegin();
            else dp[v] = -1;
 
            dfs2(dfs2, v, u);

            if (dp[u] != -1) ms[v].erase(ms[v].find(dp[u] + 1));
            dp[v] = tmp_v, dp[u] = tmp_u;
            if (dp[v] != -1) ms[u].insert(dp[v] + 1);
        }
    };
    // dfs2(dfs2, 0, -1);

    auto dfs3 = [&](auto&& dfs2, int u, int o, int last) -> void {
        res[u] = max(ans, max(dp[u], last)); 
        for (auto& v : g[u]) if (v != o) {
            int last2 = -1;
            if (last != -1) last2 = last + 1;
            if (dp[v] != -1) ms[u].erase(ms[u].find(dp[v] + 1));
            if (ms[u].size()) last2 = max(last2, *ms[u].rbegin() + 1);
            dfs2(dfs2, v, u, last2);
            if (dp[v] != -1) ms[u].insert(dp[v] + 1);
        }
    };
    dfs3(dfs3, 0, -1, -1);
    
    for (auto& e : res) cout << e << "\n";
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









