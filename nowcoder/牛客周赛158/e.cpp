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
struct BIT {
    int n;
    vector<int> tr;
    BIT(int nn) {
        n =  nn;
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
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }
        return ans;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    
    BIT bit(n);
    for (int i = 1; i + 1 < n; i++) {
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) bit.add(i + 1, 1);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int p, x; cin >> p >> x; p--;
            // 自己
            vector<bool> fg1(3), fg2(3);
            for (int i = p - 1; i <= p + 1; i++) {
                if (i - 1 >= 0 && i + 1 < n) {
                    if (a[i] - a[i - 1] < a[i + 1] - a[i]) fg1[i - (p - 1)] = true;
                }
            }
            a[p] = x;
            for (int i = p - 1; i <= p + 1; i++) {
                if (i - 1 >= 0 && i + 1 < n) {
                    if (a[i] - a[i - 1] < a[i + 1] - a[i]) fg2[i - (p - 1)] = true;
                }
            }
            for (int i = p - 1; i <= p + 1; i++) {
                int j = i - (p - 1);
                if (!fg1[j] && fg2[j]) bit.add(i + 1, 1);
                if (fg1[j] && !fg2[j]) bit.add(i + 1, -1);
            }

        } else if (op == 2) {
            int l, r; cin >> l >> r;
            int ans = bit.ask(r - 1) - bit.ask(l);
            cout << ans << "\n";
        }
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









