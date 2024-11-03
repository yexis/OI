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

int M = 50;
int _max(vector<int>& a, int x) {
    int n = a.size();
    int f[n][101], g[n][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 101; j++) {
            f[i][j] = -INF;
            g[i][j] = INF;
        }
    }
    if (a[0] == -999) {
        for (int i = -50; i <= 50; i++) {
            f[0][i + M] = 0;
            g[0][i + M] = 0;
        }
    } else {
        f[0][a[0] + M] = 0;
        g[0][a[0] + M] = 0;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == -999) {
            for (int now = -50; now <= 50; now++) {
                for (int pre = -50; pre <= 50; pre++) {
                    f[i][now + M] = max(f[i][now + M], f[i - 1][pre + M] + (pre - now >= x));
                    g[i][now + M] = min(g[i][now + M], g[i - 1][pre + M] + (pre - now >= x));
                }
            }
        } else {
            // a[i]
            int now = a[i];
            for (int pre = -50; pre <= 50; pre++) {
                f[i][now + M] = max(f[i][now + M], f[i - 1][pre + M] + (pre - now >= x));
                g[i][now + M] = min(g[i][now + M], g[i - 1][pre + M] + (pre - now >= x));
            }
        }
    }
    int ans = 0, ans2 = n;
    for (int i = -50; i <= 50; i++) {
        // cout << i << " " << f[n - 1][i + M] << "\n";
        ans = max(ans, f[n - 1][i + M]);
        ans2 = min(ans2, g[n - 1][i + M]);
    }
    cout << ans << " " << ans2 << "\n";
    return ans;
}

int _min(vector<int>& a) {
    int ans = 0;
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    _max(a, x);
}

int main() {
    solve();
    return 0;
}