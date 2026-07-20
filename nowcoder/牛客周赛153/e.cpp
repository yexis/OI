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
 * 
*/

multiset<ll> A;
multiset<ll> B;
multiset<array<ll, 4>> C;
void cal(int x1, int y1, int x2, int y2) {
    // dy / dx
    ll dx = x2 - x1;
    ll dy = y2 - y1;

    // 垂直，中线为水平线
    if (dx == 0) {
        B.insert(x1);
        return;
    }
    // 水平，中线为垂直线
    if (dy == 0) {
        A.insert(y1);
        return;
    }
    if (dy < 0) {
        dx = -dx, dy = -dy;
    }
    ll g = gcd(abs(dx), abs(dy));
    dx /= g, dy /= g;

    ll c = dx, d = y1 * dx - x1 * dy;
    g = gcd(abs(c), abs(d));
    c /= g, d /= g;
    if (d == 0) c = 0;
  	// k = dy / dx
  	// b = d / c
    C.insert({dy, dx, d, c});
}

// 判断点(x,y)位于直线kb的哪个位置
// 必须是斜线，不能是垂直或水平直线
// ans > 0: 位于直线上方
// ans = 0: 位于直线上
// ans < 0: 位于直线下方
__int128 judge(array<ll, 4> kb, __int128 x, __int128 y) {
    auto [dy, dx, d, c] = kb;
    if (c) return __int128(1) * y * dx * c  - __int128(1) * dy * x * c - __int128(1) * d * dx;
    else return __int128(1) * y * dx - __int128(1) * dy * x;
};


void solve() {
    int n; cin >> n;
    vector<pii> ps(n); for (int i = 0; i < n; i++) cin >> ps[i].first >> ps[i].second;

    for (int i = 0; i < n; i++) {
        auto [x1, y1] = ps[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = ps[j];
            if (x1 == x2 && y1 == y2) continue;
            cal(x1, y1, x2, y2);
        }
    }
    int ans = 0;
    // 水平 A
    for (int sp : A) {
        int up = 0, down = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y] = ps[i];
            if (y > sp) up++;
            if (y < sp) down++;
        }
        if (up == down) ans++;
    }

    // 垂直 B
    for (int sp : B) {
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y] = ps[i];
            if (x < sp) left++;
            if (x > sp) right++;
        }
        if (left == right) ans++;
    }
    
    // 斜率 k = dy / dx, b = d / c
    // y > kx + b
    // y - kx - b > 0 上，否则下
    // y - (dy / dx) * x - d / c
    // (y * dx * c) / (c * dx) - dy * x * c/ (dx * c) - (d * dx) / (c * dx)
    
    // y - (dy / dx) * x
    auto judge = [&](array<ll, 4> kb, __int128 x, __int128 y) -> __int128 {
        auto [dy, dx, d, c] = kb;
        if (c) return __int128(1) * y * dx * c  - __int128(1) * dy * x * c - __int128(1) * d * dx;
        else return __int128(1) * y * dx - __int128(1) * dy * x;
    };
    
    for (auto kb : C) {
        int up = 0, down = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y] = ps[i];
            __int128 tag = judge(kb, x, y);
            if (tag > 0) up++;
            if (tag < 0) down++;
        }
        if (up == down) ans++;
    }

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









