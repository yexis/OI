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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
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
 * 
*/


struct DJSet {
    vector<int> fa;
    int n;
    DJSet(int _n) {
        n = _n;
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
    bool conn(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> X(m), Y(m), Z(m);
    for (int i = 0; i < m; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--, Y[i]--;
    }

    unordered_map<int, unordered_map<int, int> > mp;
    using ar = array<int, 3>;
    vector<ar> pr;
    vector<pii> g[n];
    for (int i = 0; i < m; i++) {
        if (mp.count(X[i]) && mp[X[i]].count(Y[i]) && mp[X[i]][Y[i]] !=  Z[i]) {
            cout << -1 << "\n";
            return;
        }
        if (X[i] == Y[i] && Z[i] != 0) {
            cout << -1 << "\n";
            return;
        } 
        if (X[i] == Y[i]) continue;
        g[X[i]].emplace_back(Y[i], Z[i]);
        g[Y[i]].emplace_back(X[i], Z[i]);
        mp[X[i]][Y[i]] = mp[Y[i]][X[i]] = Z[i];
        pr.push_back({Z[i], X[i], Y[i]});
    }

    vector<int> tmp(n);
    vector<bool> vis(n);
    auto dfs = [&](auto&& self, int u) -> bool {
        for (auto& [v, w] : g[u]) {
            if (vis[v]) {
                if (tmp[v] != (tmp[u] ^ w)) {
                    return false;
                }
                continue;
            } 
            vis[v] = true;
            tmp[v] = tmp[u] ^ w;
            if (!self(self, v)) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        tmp[i] = 0;
        if (!dfs(dfs, i)) {
            cout << -1 << "\n";
            return;
        }
    }


    vector<int> deg(n);
    vector<vector<pii>> g2(n);
    sort(pr.begin(), pr.end());
    DJSet dj(n);
    for (int i = 0; i < (int)pr.size(); i++) {
        auto [v, x, y] = pr[i];
        if (dj.conn(x, y)) continue;
        g2[x].emplace_back(y, v);
        g2[y].emplace_back(x, v);
        deg[x]++;
        deg[y]++;
        dj.merge(x, y);
    }

    vector<int> res(n, -1);
    auto go = [&](auto&& self, int u) -> void {
        for (auto& [v, w] : g2[u]) {
            if (res[v] != -1) continue;
            res[v] = res[u] ^ w;
            self(self, v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (res[i] != -1) continue;
        if (deg[i] > 1) continue;
        res[i] = 0;
        go(go, i);
    }
    for (auto& e : res) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









