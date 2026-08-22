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
 * 
*/

ll n, m, K;
vector<ll> V;

// 求和 1^2 + 2^2 + 3^2 + ... + x^2
ll sum_sq(ll x) {
    return x * (x + 1) * (2 * x + 1) / 6;
}


// 求大于x的元素数量和元素和
// 返回 { count(>=x), sum(>=x) }
pll calc(ll x) {
    // 求 i * i - j * j >= x
    // -> j * j <= i * i - x, 求最大的j
    ll cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        ll val = i * i - x;     // j * j <= i * i - x
        if (val < 0) continue;

        // 用 二分 求最大的 j
        ll j = lower_bound(V.begin(), V.end(), val, [&](const ll& aa, const ll& bb) {
            return aa * aa <= bb;
        }) - V.begin();
        j = min(j, m);

        if (j <= 0) continue;

        cnt += j;
        sum += j * i * i - sum_sq(j);
    }
    return pll(cnt, sum);
}

void solve() {
    cin >> n >> m >> K;
    V.resize(m); iota(V.begin(), V.end(), 1);
    
    // 确定数据范围
    ll left = - m * m + 1, right = n * n - 1, pos = -1;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        auto [c, _] = calc(mid);
        if (c >= K) {
            left = mid + 1;
            pos = mid;
        } else {
            right = mid - 1;
        }
    }
    
    // x可能会存在多个，所以需要减
    ll x = pos;
    auto [c, s] = calc(x);
    ll ans = s - (c - K) * x;
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









