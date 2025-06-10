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
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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

struct BIT {
    int n;
    vector<int> tr;
    BIT(int nn) {
        n = nn;
        tr.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
        }
    }
    int ask(int x) {
        if (x == 0) return 0;
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }  
        return ans;
    }
    int ask(int x, int y) {
        if (x > y) return 0;
        return ask(y) - ask(x - 1);
    }
};

struct Seg {
    ll f[2000010];
    ll z[2000010];
    Seg() {
        memset(f, 0, sizeof(f));
        memset(z, 0, sizeof(z));
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            f[o] += (r - l + 1) * u;
            z[o] += u;
            return;
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] +=  z[o];
            z[o] = 0;
        }
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        f[o] = f[o * 2] + f[o * 2 + 1];
    }
    int ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return f[o];
        }
        int m = (l + r) >> 1;
        if (z[o]) {
            f[o * 2] += (m - l + 1) * z[o];
            f[o * 2 + 1] += (r - m) * z[o];
            z[o * 2] += z[o];
            z[o * 2 + 1] +=  z[o];
            z[o] = 0;
        }
        int ans = 0;
        if (L <= m) {
            ans += ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
};

const int N = 300000;
void solve() {
    Seg seg;

    int ans = 0;
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int rs = seg.ask(1, 1, N, l, r);
        if (rs > 0) {

        } else {
            seg.add(1, 1, N, l, r, 1);
            ans = max(ans, r - l + 1);
        }
        cout << ans + 1 << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









