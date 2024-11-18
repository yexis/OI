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
 * 二维前缀和
*/

void solve() {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int ans = 0;
    for (int i0 = 0; i0 < n; i0++) {
        for (int j0 = 0; j0 < m; j0++) {

            for (int i1 = i0; i1 < n; i1++) {
                for (int j1 = j0; j1 < m; j1++) {

                    bool fg = true;
                    for (int i = i0; i <= i1; i++) {
                        for (int j = j0; j <= j1; j++) {
                            if (g[i][j] == '*') {
                                fg = false;
                                break;
                            }
                        }
                    }
                    if (fg) {
                        if ((i1 - i0 + 1) * (j1 - j0 + 1) > ans) {
                            ans = (i1 - i0 + 1) * (j1 - j0 + 1);
                            x1 = i0, y1= j0;
                            x2 = i1, y2 = j1;
                        }
                    }
                }
            }
        }
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

int main() {
    solve();
    return 0;
}