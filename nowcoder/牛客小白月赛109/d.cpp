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
    int n, m; cin >> n >> m;
    vector<int> a(n); 
    for (auto& e : a) cin >> e;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> c[i];
    }
    vector<arr> pr; for (int i = 0; i < n; i++) pr.push_back({a[i], b[i], c[i]});
    sort(pr.begin(), pr.end());
    vector<ll> sum(n + 1); for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + pr[i][2];

    // for (auto& e : pr) cout << e[0] << " " << e[1] << " " << e[2] << "\n";

    ll dp[n + 1]; memset(dp, 0x3f, sizeof(dp)); dp[n] = 0;
    ll R = 0;
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
        auto [aa, bb, cc] = pr[i];
        int rr = aa + m - 1;
        while (pr[j][0] > rr) {
            R = dp[j];
            j--;
        }
        // do
        dp[i] = min(dp[i], R + bb + max(0ll, sum[j + 1] - sum[i + 1]));
        // do not
        dp[i] = min(dp[i], dp[i + 1] + cc);
        // cout << i << " " << dp[i] << "\n";
    }
    cout << dp[0] << "\n";
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









