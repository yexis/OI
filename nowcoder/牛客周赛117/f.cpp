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
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> Dist(n, vector<int>(10));

    vector<int> dep(n);
    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        auto& dist = Dist[u];
        Dist[u][0] += 1;
        for (auto& v : g[u]) {
            if (v == o) continue;
            dep[v] = dep[u] + 1;

            dfs(dfs, v, u);
            auto& dist2 = Dist[v];
            for (int i = 1; i < 10; i++) {
                dist[i] += dist2[i - 1];
            }
        }
    };
    dfs(dfs, 0, -1);
    
    vector<int> res(n);
    
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        res[u] = Dist[u][9];

        for (auto& v : g[u]) {
            if (v == o) continue;
            auto mfa = Dist[u];
            // 除去v剩余部分
            for (int i = 1; i < 10; i++) {
                mfa[i] -= Dist[v][i - 1];
            }
            // 保存v
            vector<int> v_tmp = Dist[v];
            // 剩余部分加入到v中
            for (int i = 1; i < 10; i++) {
                Dist[v][i] += mfa[i - 1];
            }
            dfs2(dfs2, v, u);
            Dist[v] = v_tmp;
        }
    };
    vector<int> dist(10);
    dfs2(dfs2, 0, -1);
    for (auto& e : res) {
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









