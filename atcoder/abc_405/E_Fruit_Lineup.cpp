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
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()
#define debug(x) cerr << (#x) << " = " << (x) << endl;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
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

const int maxn = 3000000;
ll fac[maxn + 10], inv[maxn + 10];
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

int C(int n, int k) {
    if (n < 0 || k < 0 || k > n) {
        return 0;
    }
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() {
    // a left c
    // a left d
    // b left d
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // think b after a c d 
    ll ans = 0;
    for (int e = 0; e <= c; e++) {
        ll x = C(c + d - e - 1, d - 1);
        ll y = C(a + e + b, b);
        ans += x * y;
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    init();
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









