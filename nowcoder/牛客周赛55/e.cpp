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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

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


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 10;
    }

    /*
     * 方法1: 动态规划（滚动数组） + 快速幂
     * dp[x]表示前i个元素时，以i结尾的个位数是x的数的个数
     */
    ll ans = 0;
    vector<ll> dp(10);
    for (int i = 0; i < n; i++) {
        vector<ll> cdp(10);
        ll x = a[i];

        for (int y = 0; y < 10; y++) {
            ll c = x * y % 10;
            cdp[c] += dp[y];
        }
        cdp[x]++;
        ans += cdp[6] * power(2, n - i - 1);
        ans %= mod;

        for (int y = 0; y < 10; y++) {
            dp[y] += cdp[y];
            dp[y] %= mod;
        }
    }
    cout << ans << "\n";

    return 0;
}