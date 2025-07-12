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
using arr = array<int, 4>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 2e5;
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

    auto dfs = [&](auto&& dfs, int u, int o) -> arr {
        if (g.size() == 1) {
            return arr{0, INF, INF, 0};
        }
        int ou0 = 0, ou1 = 0, on0 = 0, on1 = 0;
        vector<arr> pr;
        for (auto& v : g[u]) {
            auto p = dfs(dfs, v, u);
            pr.emplace_back(p);
        }
        int m = pr.size();
        // n1: 最终是1，且不依赖父节点，与子节点变偶数次
        // 选哪几个变？
        sort(pr.begin(), pr.end(), [&](const auto& aa, const auto& bb) {
            return aa[0] - aa[2] < bb[0] - bb[2];
        });

        for (int i = 0; i < m; i++) {
            auto [u0, u1, n0, n1] = pr[i];
            on1 += n0;
        }
        
        for (int i = 0; i + 1 < m; i += 2) {
            auto [u0, u1, n0, n1] = pr[i];
            auto [uu0, uu1, nn0, nn1] = pr[i + 1];
            on1 = min(on1, on1 + 1 + u0 - n0 + 1 + uu0 - nn0);
        }

        // n0: 最终是0，且不依赖父节点，与子节点变奇数次
        // (u0 u1) (n0 n1)
        sort(pr.begin(), pr.end(), [&](const auto& aa, const auto& bb) {
            return min(aa[0], aa[1]) - min(aa[2], aa[3]) < min(bb[0], bb[1]) - min(bb[2], bb[3]);
        });
        on0 = 1 + (pr[0][0], pr[0][1]);
        for (int i = 1; i + 1 < m; i++) {
            auto [u0, u1, n0, n1] = pr[i];
            auto [uu0, uu1, nn0, nn1] = pr[i + 1];
            on0 += min(1 + min(u0, u1) + 1 + min(uu0, uu1), min(n0, n1) + min(nn0, nn1) );
        }

        // o_u0
        ou0 = on1, ou1 = on0;
        return arr{ou0, ou1, on0, on1};
    };

    auto [u0, u1, n0, n1] = dfs(dfs, 0, -1);
    cout << min(n0, n1) << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









