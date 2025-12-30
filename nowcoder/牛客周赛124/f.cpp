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
 * 
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n & 1) {
        cout << -1 << "\n";
        return;
    }

    int dp[n][n]; memset(dp, 0, sizeof(dp));
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    for (int l = 4; l <= n; l += 2) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
            }
        }
    }

    ll dp2[n][n]; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp2[i][j] = 1e18;
    for (int i = 0; i < n; i++) if (s[i] == s[i + 1]) dp2[i][i + 1] = 1ll * a[i] * a[i + 1];
    for (int l = 4; l <= n; l += 2) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            for (int k = i + 1; k + 1 < j; k += 2) {
                if (dp[i][k] && s[i] == s[k] && 
                    dp[k + 1][j] && s[k + 1] == s[j]) {
                    dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k + 1][j]);
                }
            }
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp2[i][j] = min(dp2[i][j], dp2[i + 1][j - 1] + 1ll * a[i] * a[j]);
            }
        }
    }
    if (dp2[0][n - 1] == 1e18) {
        cout << -1 << "\n";
        return;
    }
    cout << dp2[0][n - 1] << "\n";
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









