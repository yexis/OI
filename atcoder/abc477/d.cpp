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
 * liguoyang
 * atcode 477
 * D 很有意思的设计题 
*/

void solve() {
    int n, q;
    cin >> n >> q;

    // 位置i是否有tile
    vector<bool> hasTile(n + 1, false);
    // 位置i变成 有tile 状态时 的颜色
    vector<char> tileColor(n + 1, 'a');
    // 位置i进入 空格子状态时 的颜色
    vector<char> baseColor(n + 1, 'a');
    // 位置i进入 空格子状态时 的全局时间戳
    vector<int> lastUpdate(n + 1, 0);
    // 全局颜色更新次数
    int version = 0;
    // 最近一次操作设置的颜色
    char cur = 'a';

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;

            if (!hasTile[x]) {
                // 空格子当前的颜色
                char c = (lastUpdate[x] == version)
                         ? baseColor[x]
                         : cur;

                tileColor[x] = c;
                hasTile[x] = true;
            } else {
                // 移除瓷砖，保留原来的颜色
                hasTile[x] = false;
                baseColor[x] = tileColor[x];
                lastUpdate[x] = version;
            }
        } else {
            char c;
            cin >> c;

            cur = c;
            version++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (hasTile[i]) {
            cout << tileColor[i];
        } else {
            cout << (lastUpdate[i] == version
                     ? baseColor[i]
                     : cur);
        }
    }

    cout << '\n';
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









