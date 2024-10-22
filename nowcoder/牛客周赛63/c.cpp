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
    int n, m;
    cin >> n >> m;
    int g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    auto check = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };
    int dr[2][2] = {{1, 0}, {0, 1}};

    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    auto bfs = [&]() {
        queue<pii> q;
        q.emplace(0, 0);
        vis[0][0] = true;
        while (q.size()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 2; d++) {
                int nr = r + dr[d][0], nc = c + dr[d][1];
                if (not check(nr, nc)) continue;
                if (vis[nr][nc]) continue;
                if (g[nr][nc] != g[r][c]) continue;
                q.emplace(nr, nc);
                vis[nr][nc] = true;
            }
        }

    };
    bfs();
    if (vis[n - 1][m - 1]) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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