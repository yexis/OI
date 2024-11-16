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

void solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    // [l1 + l2, r1 + r2]
    ll x = l1 + l2, y = r1 + r2;
    string sx = to_string(x);
    string sy = to_string(y);

    int ans = 0;
    // 自己
    int t = 0;
    for (int i = 0; i < sy.size(); i++) {
        t += sy[i] - '0';
    }
    ans = max(ans, t);

    if (sx.size() == sy.size()) {
        bool fg = false;
        int idx = -1;
        for (int i = 0; i < sy.size(); i++) {
            if (i == 0) {
                if (sy[i] - '0' > 1 && sy[i] - 1 >= sx[i]) {
                    fg = true;
                    idx = i;
                    break;
                }
            } else {
                if (sy[i] - '0' > 0 && sy[i] - 1 >= sx[i]) {
                    fg = true;
                    idx = i;
                    break;
                }
            }
        }
        if (fg && idx < sy.size() - 1) {
            t = 0;
            for (int i = 0; i < idx; i++) {
                t += sy[i] - '0';
            }
            t += sy[idx] - '0' - 1;
            for (int i = idx + 1; i < sy.size(); i++) {
                t += 9;
            }
            ans = max(ans, t);
        }
        cout << ans << "\n";
        return;
    }


    for (int len = sy.size(); len >= 1; len--) {
        if (len < sx.size()) {
            break;
        }
        if (len < sy.size()) {
            ans = max(ans, len * 9);
            continue;
        }

        // len = sy.size()
        bool fg = false;
        int idx = -1;
        for (int i = 0; i < sy.size(); i++) {
            if (i == 0) {
                if (sy[i] - '0' > 1) {
                    fg = true;
                    idx = i;
                    break;
                }
            } else {
                if (sy[i] - '0' > 0) {
                    fg = true;
                    idx = i;
                    break;
                }
            }
        } 

        // 减一，后面全9
        if (fg && idx < sy.size() - 1) {
            t = 0;
            for (int i = 0; i < idx; i++) {
                t += sy[i] - '0';
            }
            t += sy[idx] - '0' - 1;
            for (int i = idx + 1; i < sy.size(); i++) {
                t += 9;
            }
            ans = max(ans, t);
        }

    }
    cout << ans << "\n";;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}