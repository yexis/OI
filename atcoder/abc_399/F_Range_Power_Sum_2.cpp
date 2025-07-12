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

struct Comb {
    static constexpr int N = 20; 
    ll c[N + 1][N + 1];
    Comb() {
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= N; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
    int C(int n, int m) {
        if (n < 0 || m < 0 || m > n) {
            return 0;
        }
        return c[n][m];
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // f[i]表示以当前元素结尾的贡献
    // 即 a[i]^k, (a[i - 1] + a[i])^k, (a[0] + ... + a[i])^k
    // 状态转移：
    // 即将当前元素与f[i-1]合并
    // 二项式定理，(x + y)^k = C_k^0(x^0 * y^k) + C_k^1(x^1 * y^{k-1}) + ... + C_k^k(x^k * y^0)
    vector<ll> f(k + 1), f2(k + 1);
    for (int i = 0; i <= k; i++) {
        f[i] = power(a[0], i);
    }
    f2 = f;

    Comb th;

    ll ans = f[k];
    for (int i = 1; i < n; i++) {
        ll x = a[i];
        vector<ll> p(k + 1);
        for (int d = 0; d <= k; d++) {
            p[d] = power(x, d);
        }

        vector<ll> g(k + 1);
        for (int d = 0; d <= k; d++) {
            g[d] += p[d];
            g[d] %= mod;

            for (int d1 = 0; d1 <= d; d1++) {
                int d2 = d - d1;
                g[d] += th.C(d, d1) * f[d1] % mod * p[d2];
                g[d] %= mod;
            }
        }
        for (int d = 0; d <= k; d++) {
            f2[d] += g[d];
            f2[d] %= mod;
        }
        f.swap(g);
    }

    cout << f2[k] << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









