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

/*
 * 线段树
 * 乘法逆元
 * 等比数列求和
*/

// 快速幂
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

// 等比数列求和公式
ll cal(ll a1, ll q, ll n) {
    if (q == 1) {
        return a1 * n % mod;
    }
    return a1 * (power(q, n) - 1 + mod % mod) % mod * power((q - 1), mod - 2) % mod;
}

struct Node {
    ll f;
    ll g;
    ll z;
    Node() {
        f = 0;
        g = 1;
        z = 0;
    }
};
inline Node operator+(const Node& a, const Node& b) {
    Node res;
    res.f = (a.f + a.g * b.f % mod) % mod;
    res.g = a.g * b.g % mod;
    return res;
}
struct Seg {
    Node tr[400010];
    Seg() {}
    void add(int o, int l, int r, int L, int R, ll u) {
        if (L <= l && R >= r) {
            tr[o].f = cal(u, u, r - l + 1);
            tr[o].g = power(u, r - l + 1);
            tr[o].z = u;
            return;
        }
        int m = (l + r) >> 1;
        if (tr[o].z) {
            tr[o * 2].f = cal(tr[o].z, tr[o].z, m - l + 1);
            tr[o * 2].g = power(tr[o].z, m - l + 1);
            tr[o * 2].z = tr[o].z;
            tr[o * 2 + 1].f = cal(tr[o].z, tr[o].z, r - m);
            tr[o * 2 + 1].g = power(tr[o].z, r - m);
            tr[o * 2 + 1].z =  tr[o].z;
            tr[o].z = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        tr[o].f = (tr[o * 2].f + tr[o * 2].g * tr[o * 2 + 1].f % mod) % mod;
        tr[o].g = tr[o * 2].g * tr[o * 2 + 1].g % mod;
    }
    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        int m = (l + r) >> 1;
        if (tr[o].z) {
            tr[o * 2].f = cal(tr[o].z, tr[o].z, m - l + 1);
            tr[o * 2].g = power(tr[o].z, m - l + 1);
            tr[o * 2].z = tr[o].z;
            tr[o * 2 + 1].f = cal(tr[o].z, tr[o].z, r - m);
            tr[o * 2 + 1].g = power(tr[o].z, r - m);
            tr[o * 2 + 1].z =  tr[o].z;
            tr[o].z = 0;
        }
        Node ans;
        if (L <= m) {
            ans = ans + ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
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
            cout << seg.ask(1, 1, n, l, r).f << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}