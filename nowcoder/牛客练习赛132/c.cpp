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
bool fg = false;
const int maxn = 10000007;
ll fac[maxn];
ll inv[maxn];
ll p[maxn];
void init() {
    p[0] = 1;
    fac[0] = inv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = power(fac[i], mod - 2);
        p[i] = p[i - 1] * 2 % mod;
    }
}
ll C(ll n, ll m) {
    if (n < 0 || m < 0 || n < m) {
        return 0;
    }
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    // n为奇数，一定不存在
    if (n & 1) {
        cout << 0 << "\n";
        return;
    }
    // k小于2，一定不存在
    if (k < 2) {
        cout << 0 << "\n";
        return;
    }
    // k大于n / 2，全部都是
    if (k > n / 2) {
        cout << C(n, k) << "\n";
        return;
    }
    
    cout << (C(n, k) - C(n / 2, k) * power(2, k) % mod + mod) % mod << "\n";
}

int main() {
    ios;

    init();       
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}