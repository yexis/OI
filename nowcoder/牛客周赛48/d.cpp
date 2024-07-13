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

// 2 3 2
// 8 1 8 1 2 1 16 12
const ll inf = 1e15;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto get = [&](ll x, ll b) -> ll {
        if (b == 1) x *= 2;
        else if (b == 2) x /= 2;
        else if (b == 3) x = x / 2 * 2;
        return x;
    };

    vector<vector<ll>> dp(4, vector<ll>(4, inf));
    for (int d = 0; d < 4; d++) {
        dp[d][d] = 0;
    }

    for (int i = 1; i < n; i++) {
        auto cdp = dp;
        for (int d = 0; d < 4; d++) {
            for (int b = 0; b < 4; b++) {
                dp[d][b] = inf;
            }
        }

        for (int mask = 0; mask < 4; mask++) {
            for (int b = 0; b <= mask; b++) {
                if ((mask & b) != b) continue;
                for (int d = 0; d < 4; d++) {
                    if (d & mask) continue;
                    ll diff = abs(get(a[i], d) - get(a[i - 1], b));
                    dp[d | mask][d] = min(dp[d | mask][d], cdp[mask][b] + diff);
                }
            }
        }
    }

    ll ans = inf;
    for (int d = 0; d < 4; d++) {
        ans = min(ans, dp[3][d]);
    }
    cout << ans << "\n";
    return 0;
}