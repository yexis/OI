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
 * 回文串 + DP
*/

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int d; cin >> d;
            g[i].push_back(d);
        }
    }

    /*
    1
    00
    111
    0000
    11111
    */

    ll dp[n + 1][n + 1][n + 1]; memset(dp, 0, sizeof(dp));
    auto add = [&](ll& x, ll y) {
        x += y;
        x %= mod;
    };
    ll ans = 0;
    if (n & 1) {
        int mid = n / 2, len = mid + 1; // mid + 1 个数
        for (int j = 0; j <= mid; j++) {
            dp[1][j][j] = 1;
            if (mid == 0) add(ans, dp[1][j][j]);
        }
        for (int d = 2; d <= len; d++) { 
            int lb = mid - (d - 1), rb = mid + (d - 1);
            for (int j1 = 0; j1 <= lb; j1++) {
                for (int j2 = 0; j2 <= rb; j2++) {
                    if (g[lb][j1] != g[rb][j2]) continue;

                    add(dp[d][j1][j2], dp[d - 1][j1][j2]);
                    if (j2 - 1 >= 0) add(dp[d][j1][j2], dp[d - 1][j1][j2 - 1]);
                    add(dp[d][j1][j2], dp[d - 1][j1 + 1][j2]);
                    if (j2 - 1 >= 0) add(dp[d][j1][j2], dp[d - 1][j1 + 1][j2 - 1]);
                    if (lb == 0 && rb == n - 1) add(ans, dp[d][j1][j2]);
                }
            }
        }
    } else {
        int mid = n / 2 - 1, len = mid + 1;
        for (int j1 = 0; j1 <= mid; j1++) {
            add(dp[1][j1][j1], g[mid][j1] == g[mid + 1][j1]);
            add(dp[1][j1][j1 + 1], g[mid][j1] == g[mid + 1][j1 + 1]);
            if (mid == 0) {
                add(ans, dp[1][j1][j1]);
                add(ans, dp[1][j1][j1 + 1]);
            }
        }

        for (int d = 2; d <= len; d++) {
            int lb = mid - (d - 1), rb = (mid + 1) + (d - 1);
            for (int j1 = 0; j1 <= lb; j1++) {
                for (int j2 = 0; j2 <= rb; j2++) {
                    if (g[lb][j1] != g[rb][j2]) continue;

                    add(dp[d][j1][j2], dp[d - 1][j1][j2]);
                    if (j2 - 1 >= 0) add(dp[d][j1][j2], dp[d - 1][j1][j2 - 1]);
                    add(dp[d][j1][j2], dp[d - 1][j1 + 1][j2]);
                    if (j2 - 1 >= 0) add(dp[d][j1][j2], dp[d - 1][j1 + 1][j2 - 1]);
                    if (lb == 0 && rb == n - 1) add(ans, dp[d][j1][j2]);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









