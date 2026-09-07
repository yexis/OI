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
 * 区间DP
 * 很有意思的区间DP题
 * 
*/

void solve() {
    int n; cin >> n;
    vector<int> L(n), R(n), W(n); for (int i = 0; i < n; i++) cin >> L[i] >> R[i] >> W[i];

    // 每个点只会是一个弦的端点
    vector<int> PL(2 * n + 1, -1); for (int i = 0; i < n; i++) PL[L[i]] = i;
    vector<int> PR(2 * n + 1, -1); for (int i = 0; i < n; i++) PR[R[i]] = i;

    ll dp[2 * n + 1][2 * n + 1]; 
    for (int i = 0; i <= 2 * n; i++) for (int j = 0; j <= 2 * n; j++) dp[i][j] = 0;

    for (int len = 2; len <= 2 * n; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            // 保证 [l, r] 内部的弦有被记录
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            
            // 保证弦 [l, r] 有被记录
            if (R[PL[i]] == j) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + W[PL[i]]);
            }
            // 保证弦 [l, x] 有被记录
            if (PL[i] != -1 && R[PL[i]] < j) {
                int r = R[PL[i]];
                dp[i][j] = max(dp[i][j], dp[i][r] + dp[r + 1][j]);
            }
            // 保证弦 [x, r] 有被记录
            if (PR[i] != -1 && L[PR[i]] > i) {
                int l = L[PR[i]];
                dp[i][j] = max(dp[i][j], dp[i][l - 1] + dp[l][j]);
            }
        }        
    }
    
    cout << dp[1][2 * n] << "\n";
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









