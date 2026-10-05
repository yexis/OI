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

// 由两点 (x1,y1)、(x2,y2) 求一般式 Ax + By + C = 0
array<ll, 3> cal(int x1, int y1, int x2, int y2) {
    ll A = y2 - y1;
    ll B = x1 - x2;
    ll C = 1ll * x2 * y1 - 1ll * x1 * y2;
    return array<ll, 3>{A, B, C};
    // Ax + By + C = 0
}

// 标准叉积公式
// 判断点(x,y)位于直线kb的哪个方向
// 返回 > 0: 位于左侧
// 返回 < 0: 位于右侧
// 返回 = 0： 位于直线上
ll side(array<ll, 3> kb, ll x, ll y) {
    auto [A, B, C] = kb;
    return -(1ll * A * x + 1ll * B * y + C);
}

// 求叉积：(x, y) 相对于向量 (x2 - x1, y2 - y1)的位置
// 注意 叉积是带方向的线段，计算两个向量的差积
// 叉积 > 0: 从向量a逆时针旋转到向量b，即向量b位于向量a的左侧
// 叉积 > 0: 从向量a顺时针旋转到向量b，即向量b位于向量a的右侧
// 叉积 = 0: 两个向量共线
ll cross(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    return 1ll * (x2 - x1) * (y - y1) - 1ll * (y2 - y1) * (x - x1);
}

// 求叉积 (向量a，向量b)
// 叉积 > 0: 从向量a逆时针旋转到向量b，即向量b位于向量a的左侧
// 叉积 > 0: 从向量a顺时针旋转到向量b，即向量b位于向量a的右侧
// 叉积 = 0: 两个向量共线
ll cross(ll delta_x1, ll delta_y1, ll delta_x2, ll delta_y2) {
    return 1ll * delta_x1 * delta_y2 - 1ll * delta_y1 * delta_x2;
}


void solve() {
    int n; cin >> n;
    int u1, v1, u2, v2; cin >> u1 >> v1 >> u2 >> v2;
    
    // 方法一
    auto line = cal(u1, v1, u2, v2);

    // auto line1 = cal(u2, v2, u1, v1);
    // cout << line[0] << " " << line[1] << " " << line[2] << "\n";
    // cout << line1[0] << " " << line1[1] << " " << line1[2] << "\n";

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        ll side1 = side(line, a, b);
        ll side2 = side(line, c, d);

        auto line2 = cal(a, b, c, d);
        ll side3 = side(line2, u1, v1);
        ll side4 = side(line2, u2, v2);
        
        if (side1 == 0 || side2 == 0 ||
            (side1 > 0) == (side2 > 0)) continue;

        if (side3 == 0 || side4 == 0 ||
            (side3 > 0) == (side4 > 0)) continue;
        
        if (side1 > 0) ans--;
        else ans++;
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









