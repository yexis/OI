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
 * 
*/

const int maxn = 200000001;
ll p[200000000];
void init() {
    p[0] = 1;
    for (int d = 1; d < maxn; d++) {
        p[i] = p[i - 1] * i;
        p[i] %= mod;
    }
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll c = (r - l + 1);
    ll d = (r - l + 2);

    // 区间起点和终点
    ll st = -1, en = -1;

    ll left = 1, right = 1e8;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        if (mid * mid >= l) {
            st = mid;
            right = mid - 1;
        } else {
            // l < mid * mid
            left = mid + 1;
        }
    }
    cout << "st:" << st << "\n";

    left = 1, right = 1e8;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        if (mid * mid <= r) {
            en = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "en:" << en << "\n";

    if (st > en) {
        cout << 0 << "\n";
        return;
    }
    
    ll len = r - l + 1;
    ll tot = len * (len - 1) / 2 % mod;

    ll num = en - st + 1;
    ll aa = 2 * st - 1, bb = 2 * en;
    ll ans = p[bb] * power(aa - 1, mod - 2);
    if (st * st > l) {
        ll x = st * st - l;
        ans += x * (x - 1) / 2;
        ans %= mod;
    }
    if (en * en < r) {
        ll x = r - en * en;
        ans += x * (x - 1) / 2;
        ans %= mod;
    }
    cout << (tot - ans + mod) % mod << "\n";
}

int main() {
    ios;
    init();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
(r - d0 + 1) + 
(d0 - l) * (r - d0 + 1) + 
(d1 - d0) * (r - d1 + 1) + 
(d2 - d1) * (r - d2 + 1) + 
... + 
(dn - dn-1) * (r - dn + 1)

(r - d0 + 1) + 
(d0 - l) * (r - d0 + 1) + 
(d1 - d0) * (r - d0 + 1) + (d1 - d0) * (d0 - d1)
(d2 - d1) * (r - d0 + 1) + (d2 - d0 - d1 + d0) * (d0 - d2)
... + 
(dn - dn-1) * (r - d0 + 1) + (dn - dn-1) * (d0 - dn)
 */



