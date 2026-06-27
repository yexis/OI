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
const int mod = 998244353;
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
    vector<string> s(2); for (auto& e : s) cin >> e;

    ll dp[n][4]; 
    for (int i = 0; i < n; i++) for (int j = 0; j < 4; j++) dp[i][j] = -LLINF;

    auto check = [&](int i, int mask) -> bool {
        int b0 = mask & 1;
        int b1 = mask >> 1 & 1;
        if (b0 && s[0][i] == '0') return false;
        if (!b0 && s[0][i] == '1') return false;

        if (b1 && s[1][i] == '0') return false;
        if (!b1 && s[1][i] == '1') return false;

        return true;
    };

    auto check2 = [&](int mask1, int mask2) -> bool {
        int b0 = mask1 & 1;
        int b1 = mask1 >> 1 & 1;

        int c0 = mask2 & 1;
        int c1 = mask2 >> 1 & 1;
        if (b0 == b1 && b0 == c0 && b0 == c1) return false;
        return true;
    };

    for (int mask = 0; mask < 4; mask++) {
        if (check(0, mask)) dp[0][mask] = 1;
    }
    // for (auto& e : dp[0]) cout << e << " "; cout << "\n";

    for (int i = 1; i < n; i++) {
        for (int mask = 0; mask < 4; mask++) {
            if (!check(i, mask)) continue;
            // can mask
            for (int mask2 = 0; mask2 < 4; mask2++) {
                if (!check2(mask, mask2)) continue;
                mod_add(dp[i][mask],dp[i - 1][mask2]);
            }
        }
    }

    for (auto& e : dp[n - 1]) cout << e << " "; cout << "\n";

    ll ans = 0;
    for (int mask = 0; mask < 4; mask++) {
        if (!check(n - 1, mask)) continue;
        mod_add(ans, dp[n - 1][mask]);
    }
    if (ans < 0) ans = 0;
    cout << ans << "\n";
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









