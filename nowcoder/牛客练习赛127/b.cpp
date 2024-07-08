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

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using pii = pair<int, int>;

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

ll cal(ll a1, ll q, ll n) {
    if (q == 1) {
        return n * q % mod;
    }
    return a1 * (power(q, n) - 1) * power(q - 1, mod - 2) % mod;
}
int main() {
    int w, d;
    cin >> w >> d;
    vector<pair<ll, ll>> pr(w);
    for (int i = 0; i < w; i++) {
        cin >> pr[i].first >> pr[i].second;
    }

    ll ans = 1;
    for (int i = 0; i < w; i++) {
        auto [p, a] = pr[i];
        p = power(p, d);
        // 等比数列求和 a1 * (q^n - 1) / (q - 1)
        if (p == 1) {
            ans *= (a + 1) * p;
            ans %= mod;
        } else {
            ans *= (1 - power(p, a + 1) + mod) * power(1 - p + mod, mod - 2);
            ans %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}

