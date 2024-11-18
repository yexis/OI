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
 * bitset优化dp
 * 逆推dp
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bitset<100001> dp[n + 1][25];
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int ti = 0;
        for (int d = 0; d < 20; d++) {
            for (int ld = 0; ld < 20; ld++) {
                dp[i + 1][d] |= (dp[i][ld] << x);
            }
            x >>= 1;
        }
    }
    bool ok = false;
    for (int d = 0; d < 20; d++) {
        if (dp[n][d][100000]) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << -1 << "\n";
        return;
    }
    // 逆推
    vector<int> res;
    int tmp = 100000;
    for (int i = n - 1; i >= 0; i--) {
        int v = a[i];
        if (tmp == 0) {
            res.push_back(12345);
            continue;
        }

        for (int d = 0; d < 20; d++) {
            if (dp[i + 1][d][tmp]) {
                if (dp[i][d][tmp]) {
                    // 不选
                    res.push_back(12345);
                } else {
                    res.push_back(d);
                    tmp -= v;    
                }
                break;
            }
            v >>= 1;
        }
    }
    reverse(res.begin(), res.end());
    for (auto& e : res) cout << e << " "; cout << "\n";
}

int main() {
    solve();
    return 0;
}



/*
10
100000 100000 100000 100000 100000 100000 100000 100000 100000 1
*/

