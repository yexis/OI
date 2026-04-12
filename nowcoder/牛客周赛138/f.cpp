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
const int mod = 1e9 + 7;
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
 * 时间复杂度：O(n^3)
* ~500的三次方可以通过
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    
    int ans = 2;
    int dp[n][n]; memset(dp, 0, sizeof(dp));    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i + 1 < n) dp[i][i + 1] = 2;
    }
    
    for (int l = 3; l <= n; l++) {
        vector<vector<int>> q(2001);
        vector<int> I(2001, 0);
        for (int i = 0; i < l - 1; i++) q[a[i]].push_back(i);
        // 
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            I[a[i]]++;
            int x = a[i] + a[j];
            dp[i][j] = max(dp[i][j], 2);
            for (int k = i + 1; k <= j - 1; k++) {
                int y = x - a[k];
                if (y >= 0 && I[y] != -1 && q[y].size() && I[y] < q[y].size()) {
                    int k2 = q[y].back();
                    if (k <= k2) {
                        dp[i][j] = max(dp[i][j], dp[k][k2] + 2);
                        ans = max(ans, dp[i][j]);                        
                    }
                }
            }
            q[a[j]].push_back(j);
        }
    }
    
    cout << ans << "\n";
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









