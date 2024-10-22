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

void solve() {
    int n, qq;
    cin >> n >> qq;
    vector<int> g[n];

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    int s, t;
    cin >> s >> t;
    s--, t--;

    vector<int> po;
    vector<bool> vis(n);
    auto dfs = [&](auto&& dfs, int u) -> bool {
        if (u == t) {
            return true;
        }
        for (auto& v : g[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            po.emplace_back(v);
            if (dfs(dfs, v)) {
                return true;
            }
            po.pop_back();
        }
        return false;
    };
    vis[s] = true;
    po.emplace_back(s);
    dfs(dfs, s);

    vector<int> res(n, INF);
    auto bfs = [&]() {
        queue<int> q;
        for(int i = 0; i < po.size(); i++) {
            q.push(po[i]);
            res[po[i]] = 0;
        }

        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (auto& v : g[u]) {
                if (res[v] < INF) {
                    continue;
                }
                res[v] = res[u] + 1;
                q.push(v);
            }
        }
    };
    bfs();

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += res[i];
    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}