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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    set<int> se;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        se.insert(x);
    }

    vector<ll> cnt(n);
    auto dfs = [&](auto&& dfs, int u, int o) -> ll {
        ll c = se.count(u) ? 1 : 0;
        for (auto& v : g[u]) {
            if (v == o) continue;
            ll cc = dfs(dfs, v, u);
            cnt[u] += c * cc * 2;
            c += cc;
        }
        if (se.count(u)) {
            cnt[u]++;
        }
        return c;
    };
    dfs(dfs, 0, -1);
    for (auto& e : cnt) {
        cout << e << " ";
    }
    cout << "\n";

}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}