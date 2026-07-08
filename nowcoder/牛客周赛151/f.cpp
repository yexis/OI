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
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 
*/

constexpr static int maxn = 2e5;
vector<int> fac[maxn + 10];
auto init = []() -> int {
    for (int i = 1; i <= maxn; i++) {
        // 以i为步长
        // 3 6 9 12 15 18 ...
        // 4 8 12 16 20 24 ...
        for (int j = i; j <= maxn; j += i) {
            fac[j].push_back(i);
        }
    }
    return 0;
}();

struct Seg {
    // 线段树
    int f[800010];

    Seg() {
        memset(f, 0, sizeof(f));
    }

    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            // 注意
            f[o] = max(f[o], u);
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = max(f[o * 2], f[o * 2 + 1]);
    }

    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }

        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans = max(ans, ask(o * 2, l, m, L, R));
        }
        if (R > m) {
            ans = max(ans, ask(o * 2 + 1, m + 1, r, L, R));
        }
        return ans;
    }
};

struct Comb {
    ll fac[maxn + 10], inv[maxn + 10];
    Comb() {
        fac[0] = inv[0] = 1;
        for (int i = 1; i <= maxn; ++i) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = get_inv(fac[i]);
        }
    }
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

    int C(int n, int k) {
        if (n < 0 || k < 0 || k > n) {
            return 0;
        }
        return fac[n] * inv[k] % mod * inv[n - k] % mod;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    // 因子： 个数
    unordered_map<int, int> cnt;
    for (auto& x : a) {
        for (auto& fa : fac[x]) {
            cnt[fa]++;
        }
    }
    
    Seg seg;
    for (auto& [k, v] : cnt) {
        seg.add(1, 1, n, v, k);
    }

    Comb comb;
    int q; cin >> q;
    while (q--) {
        int K; cin >> K;
        int e = seg.ask(1, 1, n, K, n);
        int t = cnt[e];
        cout << comb.C(t, K) << "\n";
    }

}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









