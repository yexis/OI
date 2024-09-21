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
const int maxn = 1000010;
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
    for (int i = 1; i <= maxn; ++i) {
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
    ll n, m;
    cin >> n >> m;
    ll left = (m - 1) / 2, right = m - 1 - left;
    if (right == 0) {
        cout << 1 << "\n";
        return;
    }
    if (left == 0 && right == 1) {
        cout << n - 2 << "\n";
        return;
    }

    ll ans = C(n - 1, left + right);
    cout << ans << "\n";
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