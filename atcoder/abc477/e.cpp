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

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];

    vector<ll> sum(n + 2); for (int i = 1; i <= n; i++) sum[i + 1] = sum[i] + A[i - 1];
    ll loop = sum[n + 1] + A[n];

    multiset<pll> ms, msr;
    vector<ll> sh(n + 2, LLINF);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            sh[i] = B[i];
        } else {
            auto [d, j] = *ms.begin();
            sh[i] = min((ll)B[i], d + sum[i + 1]);

            auto [dr, jr] = *msr.begin();
            sh[i] = min((ll)sh[i], dr + sum[n + 1] - sum[i + 1]);
        }
        ms.insert(pll(B[i] - sum[i + 1], i));
        msr.insert(pll(B[i] + sum[i + 1] + A[n], i));
    }

    ms.clear(); msr.clear();
    for (int i = n; i >= 1; i--) {
        if (i == n) {
            sh[i] = min(sh[i], (ll)B[i]);
        } else {
            auto [d, j] = *ms.begin();
            sh[i] = min(sh[i], d - sum[i + 1]);

            auto [dr, jr] = *msr.begin();
            sh[i] = min(sh[i], dr + sum[i + 1]);
        }
        ms.insert(pll(B[i] + sum[i + 1], i));
        msr.insert(pll(B[i] + sum[n + 1] - sum[i + 1] + A[n], i));
    }

    while (q--) {
        int S, T; cin >> S >> T;
        if (T == n + 1) {
            cout << sh[S] << "\n";
        } else {
            ll ans = min(sum[T + 1] - sum[S + 1], loop - (sum[T + 1] - sum[S + 1]));
            ans = min(ans, sh[S] + sh[T]);
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









