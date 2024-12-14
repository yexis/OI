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

void cal(ll& a, ll& b, ll& c) {
    ll g = gcd(a, b);
    g = gcd(g, c);
    a = a / g;
    b = b / g;
    c = c / g;
    return;
}

void solve() {
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            ll mh = 5;
            if ((x & 1) || (y & 1)) {
                x *= 2;
                y *= 2;
                mh *= 2;
            }
            ll mx = x / 2;
            ll my = y / 2;
            cal(mx, my, mh);
            cout << mx << " " << my << " " << mh << "\n";
            continue;
        }

        // z != 0
        if (z > 0) {
            ll fz = h - z;
            ll fm = h;
            ll fa = fz + fm;
            // fm / fa
            ll mx = x * fm;
            ll my = y * fm;
            ll mz = h * fa;
            cal(mx, my, mz);
            cout << mx << " " << my << " " << mz << "\n";
            continue;
        }
        // z < 0
        if (z < 0) {
            z = -z;
            ll fz = h;
            ll fm = h + z;
            ll fa = fz + fm;
            ll mx = x * fm;
            ll my = y * fm;
            ll mz = h * fa;
            cal(mx, my, mz);
            cout << mx << " " << my << " " << mz << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}