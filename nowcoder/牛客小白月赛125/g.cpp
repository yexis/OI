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
 * 等比数列公式 (1 + n) * n / 2;
 * 对于从0开始的数列也合适
 * 
 * 除法求余应该就0放在最前面，比如 %p [0,1,2,...,p-1]
*/

void solve() {
    // p - 1, q - p + 1, p - 1, q - p + 1

    // [0][1, p - 1] [p, q] [q + 1, q + p - 1] 
    // [q + p][q + p + 1, q + 2 * p][][]
    int l, r, p, q; cin >> l >> r >> p >> q;
    // (1, p - 1)
    ll base = 1ll * p * (p - 1) / 2;
    int c1 = l / q, c2 = r / q;
    int r1=  l % q, r2 = r % q;
    if (c1 == c2) {
        if (r1 >= p) {
            cout << 0 << "\n";
            return;
        }
        // r1 <= p
        r2 = min(r2, p - 1);
        cout << 1ll * (r1 + r2) * (r2 - r1 + 1) / 2 << "\n";
    } else {
        ll ans = 0;
        if (r1 < p) ans += 1ll * (r1 + p - 1) * (p - 1 - r1 + 1) / 2;
        int mid = max(0, c2 - c1 - 1); ans += 1ll * mid * (p - 1) * p / 2;
        r2 = min(r2, p - 1);
        ans += 1ll * (0 + r2) * (r2 + 1) / 2;
        cout << ans << "\n";
    }

}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









