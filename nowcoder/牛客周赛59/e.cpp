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
 * 小红的X型矩阵
 * 循环右移和循环下移是什么意思？
 * 将矩阵g分表向右和向下复制一份，得到 g * 4
 *
 * 例如g =
 * 1 0 1
 * 0 1 0
 * 1 0 0
 * 变成g4 =
 * 1 0 1 1 0 1
 * 0 1 0 0 1 0
 * 1 0 0 1 0 0
 * 1 0 1 1 0 1
 * 0 1 0 0 1 0
 * 1 0 1 1 0 1
 *
 * 1. 循环右移和循环下移 可以转化成 矩阵的左上角(x0, y0)可以矩阵g4中任意移动
 * 2. 现在考虑当以任意一点(x,y)为左上角时，两条对角线上的点有什么规律吗？
 *   2.1 左上->右下 这条对角线上的点(x,y)满足 (x - y + n) % n = c，其中c为定值
 *   2.2 右上->左下 这条对角线上的点(x,y)满足 (x + y) % n = d，其中d为定值
 * 3. 当n为奇数时，两条对角线会产生一条交点，交点坐标为( (x + n / 2) % n, y + (n / 2) % n)
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    auto cal1 = [&](int i, int j) {
        return (i - j + n) % n;
    };
    auto cal2 = [&](int i, int j) {
        return (i + j) % n;
    };

    int sum = 0;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j]) {
                sum++;
                b[cal1(i, j)]++;
                c[cal2(i, j)]++;
            }
        }
    }

    int ans = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int bb = cal1(i, j);
            int cc = cal2(i, j + n - 1);
            // n为奇数的时候，两条对角线会存在交点
            // 当左上角为(i,j)时，交点坐标为(i + n / 2, j + n / 2)
            int cur = b[bb] + c[cc] - n % 2 * (g[(i + n / 2) % n][(j + n / 2) % n] == 1);
            ans = min(ans, sum - cur + 2 * n - n % 2 - cur);
        }
    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}