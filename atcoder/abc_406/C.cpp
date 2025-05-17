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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x = INF, y = INF;
    vector<vector<int>> cnt(n, vector<int>(2, 0));
    vector<int> LX(n, -1), LY(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        LX[i] = x, LY[i] = y;
        if (i - 1 >= 0 && i + 1 < n && a[i] > a[i - 1] && a[i] > a[i + 1]) {
            x = i;
        }
        if (i - 1 >= 0 && i + 1 < n && a[i] < a[i - 1] && a[i] < a[i + 1]) {
            y = i;
        }
        if (i + 1 < n && a[i] <= a[i + 1]) {
            cnt[i][0] = cnt[i + 1][0] + 1;
        } else {
            cnt[i][0] = 1;
        }
        if (i + 1 < n && a[i] >= a[i + 1]) {
            cnt[i][1] = cnt[i + 1][1] + 1;
        } else {
            cnt[i][1] = 1;
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     cout << LX[i] << " ";
    // }
    // cout << "\n";

    // for (int i = 0; i < n; i++) {
    //     cout << LY[i] << " ";
    // }
    // cout << "\n";

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 >= n) continue;
        if (a[i] >= a[i + 1]) continue;
        int xx = LX[i], yy = LY[i];
        if (xx == INF || yy == INF) continue;
        if (xx < yy) {
            if (LX[xx] < yy) {

            } else {
                ans += cnt[yy + 1][0];
            }
        } else {
        if (LY[yy] < xx) {

            } else {
                ans += cnt[xx + 1][1];
            }
        }
        // cout << i << " " << ans << "\n";
    }
    cout << ans << "\n";
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









