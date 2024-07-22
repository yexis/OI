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
constexpr static int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
ll fac[maxn], inv[maxn];
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

void init() {
    memset(fac, 0, sizeof(fac));
    memset(inv, 0, sizeof(inv));
    fac[0] = inv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = power(fac[i], mod - 2);
    }
}

ll C(int n, int m) {
    if (n < 0 || m < 0 || n < m) {
        return 0;
    }
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}


int main() {
    init();

    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c : s) {
        if (c == '(') {
            a++;
        } else if (c == ')') {
            b++;
        }
    }
    if (n & 1) {
        cout << 0 << "\n";
        return 0;
    }
    cout << C(n - a - b, n / 2 - b) << "\n";
    return 0;
}