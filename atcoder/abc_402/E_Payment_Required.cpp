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


double dp[1 << 8][5005];
void solve() {
    int n, x;
    cin >> n >> x;
    vector<arr> pr;
    for (int i = 0; i < n; i++) {
        int s, c, p;
        cin >> s >> c >> p;
        pr.push_back({s, c, p});
    }

    // dp[s][x]表示通过集合为s且花费为x的最大期望
    double ans = 0;    
    for (int i = 1; i <= x; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int d = 0; d < n; d++) {
                auto& [s, c, p] = pr[d];
                if ((mask >> d & 1) && c <= i) {
                    dp[mask][i] = max(dp[mask][i], 
                        (dp[mask ^ (1 << d)][i - c] + s) * p / 100.0 + 
                        (dp[mask][i - c] + 0) * (100 - p) / 100.0);
                    ans = max(ans, dp[mask][i]);
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









