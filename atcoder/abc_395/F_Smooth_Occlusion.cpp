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
    int n, x;
    cin >> n >> x;
    vector<int> U(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> U[i] >> D[i];
    }

    ll sum = 0;
    ll mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        mi = min(mi, (ll)U[i] + D[i]);
        sum += U[i] + D[i];
    }

    auto check = [&](ll h) -> bool {
        // 设 u' + d' = h
        // u' = t, d' = h - t
        // t <= u && h - t <= d
        // h - d <= t <= u
        vector<pll> f(n);
        for (int i = 0; i < n; i++) {
            ll l = max(0ll, h - D[i]), r = U[i];
            if (i - 1 >= 0) {
                auto [l0, r0] = f[i - 1];
                l = max(l, l0 - x);
                r = min(r, r0 + x);
            }
            f[i] = pll(l, r);
            if (l > r) {
                return false;
            }
        }
        return true;
    };

    ll h = 0;
    ll l = 0, r = mi;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid) ) {
            h = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << sum - h * n << "\n";
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









