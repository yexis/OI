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

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x, y;
    cin >> x >> y;
    x--, y--;


    vector<int> tmp, vis(n);
    tmp.push_back(x);
    vis[x] = true;
    auto dfs = [&](auto&& dfs, int u) -> bool {
        if (u == y) return true;
        for (auto& v : g[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            tmp.push_back(v);
            if (dfs(dfs, v)) {
                return true;
            }
            tmp.pop_back();
        }
        return false;
    };
    dfs(dfs, x);
    for (auto i : tmp) {
        s[i] = 'R';
    }

    auto dfs2 = [&](auto&& dfs2, int u, int o) -> array<int, 4> {
        int r0 = 0, b0 = 0;
        int r1 = INF, b1 = INF;
        vector<array<int, 4> > p;
        for (auto& v : g[u]) {
            if (v == o) continue;
            auto [rr0, bb0, rr1, bb1] = dfs2(dfs2, v, u);
            p.push_back({rr0, bb0, rr1, bb1});
        }
        // to red
        int vv = 0;
        if (s[u] == 'B') {
            vv++;
        }
        // to blue
        int vv2 = 0;
        if (s[u] == 'R') {
            vv2++;
        }
        r0 = vv, b0 = vv2;
        
        for (int i = 0; i < p.size(); i++) {
            auto [rr0, bb0, rr1, bb1] = p[i];
            r0 += bb1;
            b0 += rr1;
            vv += bb1;
            vv2 += rr1;
        }
        for (int i = 0; i < p.size(); i++) {
            auto [rr0, bb0, rr1, bb1] = p[i];
            r1 = min(r1, vv - bb1 + rr0);
            b1 = min(b1, vv2 - rr1 + bb0);
        }

        return {r0, b0, r1, b1};
    };

    auto [r0, b0, r1, b1] = dfs2(dfs2, 0, -1);
    int ans = min(r1, b1);
    if (ans == INF) {
        cout << -1 << "\n";
        return;
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}