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

const ll inf = 1e17;
void solve() {
    int n;
    cin >> n;
    vector<int> c(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> f(n);
    // multiset 一般记录子树的数据（不包括当前节点）
    vector<multiset<ll>> ms(n);
    vector<ll> res(n, -inf);
    auto dfs = [&](auto&& dfs, int u, int o) -> ll {
        ll x = w[u];
        for (auto& v : g[u]) {
            if (v == o) continue;
            ll xx = dfs(dfs, v, u);
            ms[u].insert(xx);
            x = max(x, xx + w[u]);
        }
        return f[u] = x;
    };
    dfs(dfs, 0, -1);

    auto check = [&](int u) -> ll {
        ll ans = 0;
        if (ms[u].size() >= 2) {
            ans = max(0ll, *ms[u].rbegin()) + w[u]  + max(0ll, *next(ms[u].rbegin()));
            return ans;
        }
        return w[u] + max(*ms[u].rbegin(), 0ll);
    };

    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        res[u] = check(u);
        for (auto& v : g[u]) {
            if (v == o) continue;
            ll fv = f[v];
            ms[u].erase(ms[u].find(fv));
            ll t = w[u];
            if (ms[u].size()) {
                t += max(0ll, *ms[u].rbegin());
            }
            ms[v].insert(t);

            dfs2(dfs2, v, u);

            ms[v].erase(ms[v].find(t));
            ms[u].insert(fv);
        }
    };
    dfs2(dfs2, 0, -1);

    // 类型
    vector<ll> tp(n + 1, -inf);
    for (int i = 0; i < n; i++) {
        int ci = c[i];
        tp[ci] = max(tp[ci], res[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (tp[i] == -inf) tp[i] = -1;
        cout << tp[i] << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}