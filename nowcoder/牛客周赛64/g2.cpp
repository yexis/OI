#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

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
 *
*/

struct Lca {
    // n : 节点数量
    // m : n的二进制长度
    int n, m;
    vector<int> dep;
    vector<vector<int>> g;
    vector<vector<int>> st;
    // 1. 初始化 + 计算倍增数组
    Lca(int nn, vector<vector<int>>& gg) {
        n = nn;
        m = 32 - __builtin_clz(n);
        g = gg;
        dep.resize(n);
        st.resize(n, vector<int>(m, -1));

        function<void(int, int)> dfs = [&](int u, int o) {
            st[u][0] = o;
            for (auto& v : g[u]) {
                if (v != o) {
                    dep[v] += dep[u] + 1;
                    dfs(v, u);
                }
            }
        };
        dfs(0, -1);

        for (int i = 1; i < m; i++) {
            for (int u = 0; u < n; u++) {
                if (st[u][i - 1] != -1) {
                    st[u][i] = st[st[u][i - 1]][i - 1];
                }
            }
        }
    }

    // 2. 根据倍增数组计算lca
    int lca(int x, int y) {
        // 将 y 置于 较深的位置
        if (dep[x] > dep[y]) {
            swap(x, y);
        }

        // 让 x 和 y 位于同一深度
        int d = dep[y] - dep[x];
        for (; d; d &= d - 1) {
            int i = __builtin_ctz(d);
            y = st[y][i];
        }
        if (y == x) {
            return x;
        }

        // 从大到小往上跳
        for (int i = m - 1; i >= 0; i--) {
            if (st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i];
            }
        }

        // 最后返回x的父节点
        return st[x][0];
    }
    // 点x到点y的距离
    int get(int x, int y) {
        int ca = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[ca];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    // 询问
    vector<pii> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].first >> qs[i].second;
        qs[i].first--, qs[i].second--;
    }

    // 构建lca， 用于计算节点(a,b)之间的距离
    Lca la(n, g);

    vector<ll> sz(n), sum(n);
    auto dfs = [&](auto&& dfs, int u, int o) -> pll {
        ll s = 0, c = 1;
        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }
            auto [ss, sc] = dfs(dfs, v, u);
            s += ss + sc;
            c += sc;
        }
        return {sum[u] = s, sz[u] = c};
    };
    dfs(dfs, 0, -1);

    vector<ll> f(n);
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        f[u] = sum[u];
        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }

            ll us = sum[u], uc = sz[u];
            ll vs = sum[v], vc = sz[v];

            // 换根
            sum[u] -= (sum[v] + sz[v]);
            sz[u] -= sz[v];
            sum[v] += sum[u] + sz[u];
            sz[v] += sz[u];

            dfs2(dfs2, v, u);
            // recover
            sum[u] = us, sz[u] = uc;
            sum[v] = vs, sz[v] = vc;
        }
    };
    dfs2(dfs2, 0, -1);

    for (auto& [x, y] : qs) {
        ll ans = (f[x] + f[y] - n * la.get(x, y) ) / 2;
        cout << ans << "\n";
    }
}

int main() {
    solve();
    return 0;
}