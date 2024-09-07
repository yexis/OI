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

/*
 * 
*/

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

struct DJ {
    int n;
    vector<int> fa;
    DJ(int nn) {
        n = nn;
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        fa[ry] = rx;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n);
    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        auto& [u, v] = edges[i];
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
    }

    vector<pii> g[n];
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        if (deg[u] > deg[v]) swap(u, v);
        if (deg[u] == deg[v] && u > v) swap(u, v);
        g[u].emplace_back(v, i);
    }

    DJ dj(m);
    vector<int> e(n, -1);
    for (int u = 0; u < n; u++) {
        for (auto& [v, id] : g[u]) {
            e[v] = id;
        }
        for (auto& [v, id] : g[u]) {
            for (auto& [w, id2] : g[v]) {
                if (e[w] != -1) {
                    dj.merge(e[w], id);
                    dj.merge(id2, id);
                }
            }
        }
        for (auto& [v, id] : g[u]) {
            e[v] = -1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += (i == dj.find(i));
    }
    if (cnt != 1) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}