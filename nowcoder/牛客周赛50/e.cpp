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

const int mod = 998244353;
ll inv(ll x) {
    ll ans = 1;
    int p = mod - 2;
    while (p) {
        if(p & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int N = 0;
    vector<int> dep(n);
    vector<int> a(n), b(n);
    auto dfs = [&](auto&& dfs, int u, int o, int d) -> void {
        dep[u] = d;
        a[d]++;
        N = max(N, d);
        if (u != 0 && g[u].size() == 1) {
            b[d]++;
        }
        for (auto& v : g[u]) {
            if (v == o) continue;
            dfs(dfs, v, u, d + 1);
        }
    };
    dfs(dfs, 0, -1, 0);

    vector<ll> q(N + 1), qq(N + 1);
    q[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (a[i] == 0) break;
        q[i] = q[i - 1] * (a[i] - b[i]) % mod * inv(a[i]) % mod;
        qq[i] = q[i - 1] * b[i] % mod * inv(a[i]) % mod;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] == 0) break;
        ans += i * qq[i];
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}

// ans: 499122178