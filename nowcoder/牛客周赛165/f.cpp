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
 * 二分 + 递推求范围
 * 
 * 从左到右：
 * x_0的范围 [L0, R0]
 * x_1的范围 [max(L0 + 1, l_1), min(R0 + D, r_1)] => [L1, R1]
 * x_2的范围 [max(L1 + 1, l_2), min(R1 + D, r_2)] => [L2, R2]
 * ...
 * x_m的范围 [max(L{m-1} + 1, l_m), min(R{m-1}  + D, r_m)] => [Lm, Rm]
 * 
 * 反方向，从右到左
 * ...
 * 如果对于某个位置i，从左到右计算的[L_i, R_i] 和 从右到左计算的 [L_i, R_i]存在交集的话
 * 说明有解，即步幅 mid 是合法的
*/

void solve() {
    int n; cin >> n;
    vector<pii> limits(n);
    for (int i = 0; i < n; i++)  cin >> limits[i].first >> limits[i].second;
    
    ll ans = LLINF;
    auto check = [&](ll mid) -> bool {
        vector<ll> preL(n, LLINF), preR(n, -LLINF);
        preL[0] = limits[0].first, preR[0] = limits[0].second;
        for (int i = 1; i < n; i++) {
            auto [l, r] = limits[i];
            preL[i] = max((ll)l, preL[i - 1] + 1);
            preR[i] = min((ll)r, preR[i - 1] + mid);
            if (preL[i] > preR[i]) break;
        }

        vector<ll> sufL(n, LLINF), sufR(n, -LLINF);
        sufL[n - 1] = limits[n - 1].first, sufR[n - 1] = limits[n - 1].second;
        for (int i = n - 2; i >= 0; i--) {
            auto [l, r] = limits[i];
            sufL[i] = max((ll)l, sufL[i + 1] + 1);
            sufR[i] = min((ll)r, sufR[i + 1] + mid);
            if (sufL[i] > sufR[i]) break;
        }
        for (int i = 1; i < n - 1; i++) {
            if (preL[i] > preR[i]) continue;
            if (sufL[i] > sufR[i]) continue;
            auto [l1, r1] = tie(preL[i], preR[i]);
            auto [l2, r2] = tie(sufL[i], sufR[i]);
            if (min(r1, r2) - max(l1, l2) + 1 > 0) return true;
        }
        return false;
    };

    ll l = 1, r = 2e9;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (ans == LLINF) ans = -1;
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









