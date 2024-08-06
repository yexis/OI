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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int xf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        vector<ll> e(n);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }
        ll odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            if (e[i] % 2 == 0) {
                odd++;
            } else {
                even++;
            }
        }
        if (a >= 0 && b >= 0) {
            ll ans = 0;
            if (a < b) {
                if (odd) ans += (odd - 1) * a;
                if (even) ans += (even - 1) * a;
                if (odd && even) ans += b;
            } else if (a > b) {
                if (odd == 0 || even == 0) ans = (n - 1) * a;
                else ans = (n - 1) * b;
            } else {
                // a == b
                ans = (n - 1) * a;
            }
            cout << ans << "\n";
        } else if (a >= 0) {
            // b < 0
            ll ans = 0;
            if (odd == 0 || even == 0) {
                ans = (n - 1) * a;
            } else {
                ans = odd * even * b;
            }
            cout << ans << "\n";
        } else if (b >= 0) {
            ll ans = 0;
            if (odd) ans += 1ll * odd * (odd - 1) / 2 * a;
            if (even) ans += 1ll * even * (even - 1) / 2 * a;
            if (odd && even) ans += b;
            cout << ans << "\n";
        } else {
            // a < 0 && b < 0
            ll ans = 0;
            ans += 1ll * odd * (odd - 1) / 2 * a;
            ans += 1ll * even * (even - 1) / 2 * a;
            ans += 1ll * odd * even * b;
            cout << ans << "\n";
        }
    }
    return 0;
}