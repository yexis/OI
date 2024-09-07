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
using lll = __int128;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
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

/*
 * 关键字：高精度计算 | k的幂次数 | 溢出
 * 计算小于n的k的所以幂次数，且n=1e18;
 * 【错误做法】
 *  vector<ll> v;
 *  ll d = 1;
 *  while (d <= n) {
 *      v.push_back(d);
 *      d *= k
 *  }
 *  使用 while(d * k <= n)作为循环条件，此时d * k可能会很大，溢出long long
 *
 * 【正确做法】：将乘法转换成除法
 *  vector<ll> v;
 *  ll d = 1;
 *  while (d <= n) {
 *      v.push_back(d);
 *      if (p > n / k) break;
 *      d *= k
 *  }
 *  使用 while(d <= n / k)作为循环条件，这样能保证d永远是小于等于n的
*/

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k > n) {
        cout << n << "\n";
        return;
    }
    if (k == n) {
        cout << 1 << "\n";
        return;
    }
    // 这里被k=1的情况下卡了，导致最后没有ac
    // 【仔细审题】
    // 题目要求是k的幂次不同，并没有说k的不同幂次数k^x不能相等
    // 所以，虽然1^1 = 1^2 = 1^3 = ... = 1^n，但是幂次是不同的，所以可以同时存在
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }

    // k < n
    ll cn = n;
    vector<ll> v;
    ll p = 1;
    while (p <= n) {
        v.push_back(p);
        if (p > n / k) break;
        p *= k;
    }

    vector<ll> cnt(70);
    for (int i = v.size() - 1; i >= 0; --i) {
        if (n >= v[i]) {
            ll c = n / v[i];
            cnt[i] += c;
            n -= c * v[i];
        }
        if (n == 0) break;
    }

    ll ans = cn;
    ll mx = 0;
    for (int i = 0; i < 65; i++) {
        mx = max(mx, cnt[i]);
    }
    ans = min(ans, mx);
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}