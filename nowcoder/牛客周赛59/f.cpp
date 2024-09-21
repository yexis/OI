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

/*
 * 
*/

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

void solve(vector<int>& a) {
    int n = a.size();
    ll dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] == a[i]) {
                if (i - j + 1 == 2) {
                    dp[j][i] = 0;
                } else {
                    // > 2
                    dp[j][i] = 2 * dp[j + 1][i - 1] % mod;
                }
            } else if (a[i] != a[j]) {
                if (i - j + 1 == 2) {
                    dp[j][i] = 1;
                } else {
                    dp[j][i] += 2 * dp[j + 1][i - 1];
                    dp[j][i] %= mod;
                    dp[j][i] += power(2, i - j - 1);
                    dp[j][i] %= mod;
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin  >> a[i];
    }
    solve(a);
    return 0;
}