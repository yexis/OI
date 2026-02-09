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
 * 
*/

void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<int> a(n); for (int i = 0; i < n; i++) a[i] = int(s[i] - 'a');

    int dp[n][26]; 
    
    int ans = 1e9;
    for (int d = 0; d < 26; d++) {
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                for (int last = 0; last < 26; last++) {
                    if (a[i] == last) dp[i][last] = 0;
                    else dp[i][last] = 1;
                }
                continue;
            }
            // i > n
            for (int last = 0; last < 26; last++) {
                int x = a[i];
                if (x == last) {
                    dp[i][last] = min(dp[i][last], dp[i - 1][(last + d) % 26]);
                    dp[i][last] = min(dp[i][last], dp[i - 1][(last - d + 26) % 26]);
                } else {
                    dp[i][last] = min(dp[i][last], dp[i - 1][(last + d) % 26] + 1);
                    dp[i][last] = min(dp[i][last], dp[i - 1][(last - d + 26) % 26] + 1);
                }
            }
        }
        
        for (int last = 0; last < 26; last++) {
            ans = min(ans, dp[n - 1][last]);
        }
    }
    
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









