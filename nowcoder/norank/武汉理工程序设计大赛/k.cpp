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

// pass 93%
int main() {
    ll n, m;
    cin >> n;
    vector<ll> g[n + 1];
    for (ll i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        if (k == 0) continue;
        for (ll j = 1; j <= k; j++) {
            ll fa;
            cin >> fa;
            g[i].push_back(fa);
        }
    }
    cin >> m;

    vector<ll> val(n + 1, -1);
    auto go = [&](auto&& go, ll u) -> ll {
        if (val[u] != -1) {
            return val[u];
        }
        ll ans = 1;
        for (auto& v : g[u]) {
            ans += go(go, v);
        }
        return val[u] = ans;
    };
    go(go, n);

    auto dfs = [&](auto&& dfs, ll u, ll d) -> ll {
        if (val[u] == d) {
            return u;
        }
        int cur = 0;
        for (auto& v : g[u]) {
            if (cur + val[v] >= d) {
                return dfs(dfs, v, d - cur);
            }
            cur += val[v];
        }
        return 0;
    };

    ll ans = dfs(dfs, n, m);
    cout << ans << '\n';
    return 0;
}