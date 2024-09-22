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

/*
 * 
*/

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

bool fg = false;
const int maxn = 100010;
ll fac[maxn], inv[maxn];
ll get_inv(ll x) {
    ll ans = 1;
    int p = mod - 2;
    while (p) {
        if (p & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = get_inv(fac[i]);
    }
}

ll C(int n, int k) {
    if (n < 0 || k < 0 || k > n) {
        return 0;
    }
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') l++;
        else if (s[i] == 'R') r++;
        else if (s[i] == 'U') u++;
        else if (s[i] == 'D') d++;
    }

    int nl = 0, nr = 0, nu = 0, nd = 0;
    if (x < 0) {
        nd = -x;
    } else if (x > 0) {
        nu = x;
    }
    if (y < 0) {
        nl = -y;
    } else if (y > 0) {
        nr = y;
    }

    int rl = l - nl;
    int rr = r - nr;
    int ru = u - nu;
    int rd = d - nd;
    if (rl < 0 || rr < 0 || ru < 0 || rd < 0) {
        cout << NO << "\n";
        return;
    }

    cout << YES << " ";

    int nnl = nl, nnr = nr, nnd = nd, nnu = nu;
    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (nnl > 0) {
                ans += s[i];
                nnl--;
            }
        } else if (s[i] == 'R') {
            if (nnr > 0) {
                ans += s[i];
                nnr--;
            }
        } else if (s[i] == 'U') {
            if (nnu > 0) {
                ans += s[i];
                nnu--;
            }
        } else if (s[i] == 'D') {
            if (nnd > 0) {
                ans += s[i];
                nnd--;
            }
        }
    }
    cout << ans << " ";

    ll res = 0, res2 = 0;
    for (int k = 0; k <= min(rl, rr); k++) {
        cout << l << " " << nl + k << " " << C(l, nl + k) << "\n";
        cout << r << " " << nr + k << " " << C(r, nr + k) << "\n";
        res += C(l, nl + k) * C(r, nr + k);
        res %= mod;
    }
    cout << res << "\n";
    for (int k = 0; k <= min(rd, ru); k++) {
        res2 += C(u, nu + k) * C(d, nd + k);
        res2 %= mod;
    }
    cout << res2 << "\n";

    res *= res2;
    res %= mod;
    cout << res << "\n";
}

int main() {
    if (!fg) {
        init();
        fg = true;
    }


    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}