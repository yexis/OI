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
 * 
*/

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto check = [&](ll mid) {
        ll mx = 0;
        ll kk = k;
        for (int i = 0; i < n; i++) {
            if (kk == 0) return false;
            ll one = 0, zero = 0;
            ll t = 0;
            int j = i;
            while (j < n && one * zero <= mid) {
                if (s[j] == '1') {
                    one++;
                } else {
                    zero++;
                }
                if (one * zero > mid) break;
                t = one * zero;
                j++;
            }
            kk--;
            mx = max(mx, t);
            i = j - 1;
        }
        return mx <= mid;
    };

    ll ans = -1;
    ll l = 0, r = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        bool fg = check(mid);
        if (fg) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}