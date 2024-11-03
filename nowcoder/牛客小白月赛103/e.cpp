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
bool fg = false;
const int maxn = 1e5;
vector<int> fac[maxn + 10];
void init() {
    for (int d = 1; d <= maxn; d++) {
        for (int j = d; j <= maxn; j += d) {
            fac[j].push_back(d);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    // b gcd
    vector<int> last(n + 1, n + 1);
    vector<int> f(n + 1, -1);
    for (int i = n; i >= 1; i--) {
        int lst = n + 1;
        for (auto& fa : fac[b[i]]) {
            if (fa == 1) continue;
            if (last[fa] < lst) {
                f[i] = fa;
                lst = last[fa];
            }
            last[fa] = i;
        }
        if (f[i] == -1) {
            f[i] = b[i];
        }
    }

    vector<int> cc(n + 1);
    for (int i = 1; i <= n; i++) {
        cc[c[i]] = i;
    }

    // a 倍数
    vector<int> cnt(n + 1);
    vector<int> h(n + 1);
    for (int i = n; i >= 1; i--) {
        for (auto& fa : fac[a[i]]) {
            cnt[fa]++;
        }
        int ce = cc[i];
        h[i] = cnt[ce];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int y = f[x];
        int z = c[y];
        cout << h[z] << "\n";
    }
}

int main() {
    if (!fg) {
        init();
        fg = true;
    }
    for (int i = 1; i <= 100; i++) {
        for (auto& f : fac[i]) {
            cout << f << " ";
        }
        cout << "\n";
    }
    solve();
    return 0;
}