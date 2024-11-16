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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

/*
 * TLE 
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<pii>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<pii> os(n);
    vector<unordered_set<int>> qs(n);
    int q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        int u, d;
        cin >> u >> d;
        u--;
        qs[u].insert(d);
        os.emplace_back(u, d);
    }

    auto dfs = [&](auto&& dfs, int u, int o) -> ll {
        for (auto& [v, w] : g[u]) {
            if (v == o) {
                continue;
            }
            for (auto& e : qs[u]) {
                qs[v].insert(e - 1);
            }
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1);

    vector<unordered_map<int, int> > tt(n);
    auto dfs2 = [&](auto&& dfs2, int u, int v) -> void {
        for (auto& e : qs[u]) {
            tt[u][e] = -1;       
        }

        for (auto& [v, w] : g[u]) {
            if (v == o) {
                continue;
            }
            for (auto& e : qs[u]) {
                if (tt[v].count(e - 1) && tt[v][e - 1] != -1) {
                    tt[u][e] = max(tt[u][e], tt[v][e - 1] + w);
                }        
            }
        }
    };
    dfs2(dfs2, 0, -1);

    for (auto& [u, d] : os) {
        cout << tt[u][d] << "\n";
    }
}

int main() {
    solve();
    return 0;
}