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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    vector<ll> p(n);
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        p[u] = 1;
        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }
            dfs2(dfs2, v, u);
            p[u] += p[v];
        }
    };
    dfs2(dfs2, 0, -1);
//     for (auto& e : p) cout << e << " "; cout << "\n";

    ll ans = 0;
    auto dfs = [&](auto&& dfs, int u, int o) -> array<ll, 3> {
        ll small = 0, big = 0, all = 0, tot = 1;
        if (w[u] <= a) {
            small++;
        }
        if (w[u] >= b) {
            big++;
        }
        
        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }
            auto [ss, bb, aa] = dfs(dfs, v, u);
            ans += small * bb;
            ans += big * ss;
            
            ans += all * (p[v] - aa);
            ans += (tot - all) * aa;
            ans += all * aa;
            
            tot += p[v];
            if (w[u] <= a) {
                all += aa;
                all += bb;
                small += p[v] - bb - aa;
            } else if (w[u] >= b) {
                all += aa;
                all += ss;
                big += p[v] - ss - aa;
            } else {
                all += aa;
                big += bb;
                small += ss;
            }
        }
        
        return array<ll, 3>({small, big, all});
    };
    dfs(dfs, 0, -1);
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}