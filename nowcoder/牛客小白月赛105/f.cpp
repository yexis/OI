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
 *
*/
ll cal(ll a1, ll q, ll n) {
    if (q == 1) {
        return a1 * n % mod;
    }
    return a1 * (power(q, n) - 1 + mod % mod) % mod * power((q - 1), mod - 2) % mod;
}
struct Seg {
    ll f[400010];
    ll g[400010];
    ll z[400010];
    Seg() {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, ll u) {
        if (L <= l && R >= r) {
            // u + u * u + u * u * u
            f[o] = cal(u, u, r - l + 1);
            g[o] = power(u, r - l + 1);
            z[o] = u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] = cal(z[o], z[o], m - l + 1);
            g[o * 2] = power(z[o], m - l + 1);
            z[o * 2] = z[o];

            f[o * 2 + 1] = cal(z[o], z[o], r - m);
            g[o * 2 + 1] = power(z[o], r - m);
            z[o * 2 + 1] =  z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = (f[o * 2] + g[o * 2] * f[o * 2 + 1] % mod) % mod;
        g[o] = g[o * 2] * g[o * 2 + 1] % mod;
    }
    pll ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return pll(f[o], g[o]);
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] = cal(z[o], z[o], m - l + 1);
            g[o * 2] = power(z[o], m - l + 1);
            z[o * 2] = z[o];

            f[o * 2 + 1] = cal(z[o], z[o], r - m);
            g[o * 2 + 1] = power(z[o], r - m);
            z[o * 2 + 1] =  z[o];
            z[o] = 0;
        }
        pll lc(0, 1), rc(0, 1);
        if (L <= m) {
            lc = ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            rc = ask(o * 2 + 1, m + 1, r, L, R);
        }
        return pll( (lc.first + lc.second * rc.first % mod) % mod, lc.second * rc.second % mod);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    Seg seg;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seg.add(1, 1, n, i + 1, i + 1, a[i]);
    }

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.add(1, 1, n, l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.ask(1, 1, n, l, r).first << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}