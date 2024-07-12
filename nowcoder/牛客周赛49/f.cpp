
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

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll = long long;

constexpr static int maxn = 5e5;
const int base = 2e9 + 3;
const int mod = 2e9 + 9;
ll h[maxn + 10], f[maxn + 10];
void init(vector<ll>& a) {
    int n = a.size();
    h[0] = 0, f[0] = 1;
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * base + (a[i] + mod)) % mod;
        f[i + 1] = f[i] * base % mod;
    }
}
ll get(int l, int r) {
    return (h[r + 1] + mod - h[l] * f[r - l + 1] % mod) % mod;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a);

    // 三段
    // 1. [0, n - 1 - 2 * k]
    // 2. [k, n - 1 - k]
    // 3. [2 * k, n - 1]
    for (int k = 1; k; k++) {
        ll x = get(0, n - 1 - 2 * k) + get(2 * k, n - 1);
        x %= mod;
        ll y = 2 * get(k, n - 1 - k);
        y %= mod;
        if (x == y) {
            cout << k << '\n';
            break;
        }
    }
    return 0;
}