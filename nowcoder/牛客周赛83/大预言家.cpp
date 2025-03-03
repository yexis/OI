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
 * 找规律：
 从起点出发，
 先往右走1，再往下走1；
 先往左走2，再往上走2；
 先往右走3，再往下走3；
 先往左走4，再往上走4；
 先往右走5，再往下走5；
 先往左走6，再往上走6；
 ...
 整体的步伐为： 1 1 2 2 3 3 4 4 5 5 6 6 ... n n
 1. 所以对于时间t，判断其处于哪个阶段，二分
 2. 计算顶点位置
    - 找规律，不难发现，顶点位置也是有规律的
    - 顶点分别是 (1, -1) (-1, 1) (2, -2) (-2, 2) (3, -3) (-4, 4) ... (n, -n) (-n n)
 3. 判断此时应该往上下左右哪个方向走，以及沿着该方向走后是否需要转弯
 
*/

void solve() {
    ll t;
    cin >> t;
    t--;
    
    ll pos = 0;
    ll l = 1, r = 1e9 + 10;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll val = mid * (mid + 1); 
        if (val <= t) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    ll ver_x, ver_y;
    if (pos % 2 == 0) {
        // 偶数时，顶点在第二象限
        ver_x = -(pos + 1) / 2;
        ver_y = (pos + 1) / 2;
    } else {
        // 奇数时，顶点在第四象限
        ver_x = (pos + 1) / 2;
        ver_y = -(pos + 1) / 2;
    }
    
    
    ll diff = t - pos * (pos + 1);
    if (pos % 2 == 0) {
        // 偶数时，右 -> 下
        ll x, y;
        if (diff <= pos + 1) {
            x = ver_x + diff;
            y = ver_y;
        } else if (diff > pos + 1) {
          	// 需要转弯
            ver_x = ver_x + (pos + 1);
            diff -= (pos + 1);
            ver_y = ver_y;
            x = ver_x;
            y = ver_y - diff;
        }
        cout << x << " " << y << "\n";
    } else {
        // 奇数时，左 -> 上
        ll x, y;
        // left + up
        if (diff <= pos + 1) {
            x = ver_x - diff;
            y = ver_y;
        } else if (diff > pos + 1) {
          	// 需要转弯
            ver_x = ver_x - (pos + 1);
            diff -= (pos + 1);
            ver_y = ver_y;
            x = ver_x;
            y = ver_y + diff;
        }
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

