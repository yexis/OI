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
 * 0-1博弈
 * 情景一：如果 x = y，则后者必胜
 * 这题有一个结论：后者一定可以让棋子走到(x,x)【说明：前者向右，后者则向下；前者向下，后者则向右】
 * 所以 (x,x)一定是后者的必胜态
 *
 * 情景二：如果 abs(x - y) == 1;则前者必胜
 * 为什么？考虑：前者通过第一步改变起点，如果x = y + 1，则第一步将起点移动到(1,0);如果y = x + 1，则第一步移动到(0,1);
 * 以上两种方案都能将(x,y)变成(x,x)，即变成了"后者"的必胜态，而此时前者变成了"后者"
 *
 * 场景三：其他场景
 * 必是平局，即abs(x - y) >= 2
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

void solve() {
    int x, y;
    cin >> x >> y;
    if (x < 0 || y < 0) {
        cout << "PING" << "\n";
        return;
    }
    if (x == 0 && y == 0) {
        cout << "YES" << "\n";
        return;
    }

    int dp[x + 1][y + 1];
    dp[x][y] = 1;
    for (int i = y - 1; i >= 0; i--) {
        if (i == y - 1) dp[x][i] = -1;
        else dp[x][i] = 0;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (i == x - 1) dp[i][y] = -1;
        else dp[i][y] = 0;
    }
    for (int i = x - 1; i >= 0; i--) {
        for (int j = y - 1; j >= 0; j--) {
            if (dp[i][j + 1] == -1 || dp[i + 1][j] == -1) {
                dp[i][j] = 1;
                continue;
            }
            if (dp[i][j + 1] == 0 || dp[i + 1][j] == 0) {
                dp[i][j] = 0;
                break;
            }
            dp[i][j] = -1;
        }
    }
    if (dp[0][0] == 1) {
        cout << "NO" << "\n";
    } else if (dp[0][0] == -1) {
        cout << "YES" << "\n";
    } else {
        cout << "PING" << "\n";
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}