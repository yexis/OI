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
using ull = unsigned long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
struct Com {
    constexpr static int maxn = 4010;
    ll fac[maxn], inv[maxn];
    Com() {
        memset(fac, 0, sizeof(fac));
        memset(inv, 0, sizeof(inv));
        fac[0] = inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = power(fac[i], mod - 2);
        }
    }
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
    ll get(int n, int m) {
        if (n < 0 || m < 0 || n < m) {
            return 0;
        }
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 范德蒙德卷积
    Com c;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                ans += c.power(2, j - i - 1) * c.get(n + i - j - 1, i);
                ans %= mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}