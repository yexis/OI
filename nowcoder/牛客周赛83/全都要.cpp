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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
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
 * 动态规划
*/

void solve() {
    int n, K;
    cin >> n >> K;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n + 1][K + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -LLINF;
        }
    }
    dp[0][0] = 0;
    

    // dp[i][k]表示 恰好到达第i-1个元素时 恰好用了k步的最大余额
    // dp[i][k] = max(dp[i - 1][k - 1], dp[i - 2][k - 1], ... , dp[i - 6][k - 1]) + a[i - 1];
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= min(i, K); k++) {
            for (int i1 = i - 1; i1 >= max(0, i - 6); i1--) {
                dp[i][k] = max(dp[i][k], dp[i1][k - 1] + a[i - 1]);
            }
        }
    }

    ll ans = -LLINF;
    for (int i = K; i <= n; i++) {
        ans = max(ans, dp[i][K]);
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









