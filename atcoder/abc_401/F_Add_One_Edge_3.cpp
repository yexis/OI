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
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

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

vector<int> cal (vector<vector<int>>& g, int n) {
    // 第一步：dfs 计算以节点0为根节点时，每个节点到叶子的最大距离
    vector<int> val(n);
    auto dfs = [&](auto&& dfs, int u, int o) -> int {
        int vv = 0;
        for (auto& v : g[u]) {
            if (v == o) continue;
            int v1 = dfs(dfs, v, u);
            vv = max(vv, v1 + 1);
        }
        return val[u] = vv;
    };
    dfs(dfs, 0, -1);

    // 第二步：换根DP，统计以每个节点为根时到叶子的最大距离
    vector<int> farthest(n);
    auto dfs2 = [&](auto&& dfs2, int u, int o, int mx) -> int {
        farthest[u] = max(val[u], mx);
        multiset<int> ms;
        for (auto& v : g[u]) {
            if (v == o) continue;
            ms.insert(val[v] + 1);
        }
        for (auto &v : g[u]) {
            if (v == o) continue;
            ms.erase(ms.find(val[v] + 1));
            int mx2 = mx + 1;
            if (ms.size()) {
                mx2 = max(mx2, *ms.rbegin() + 1);
            }
            dfs2(dfs2, v, u, mx2);
            ms.insert(val[v] + 1);
        }
        return 0;
    };
    dfs2(dfs2, 0, -1, 0);
    return farthest;
}

void solve() {
    int n1;
    cin >> n1;
    vector<vector<int> > g1(n1);
    for (int i = 0; i < n1 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    int n2;
    cin >> n2;
    vector<vector<int> > g2(n2);
    for (int i = 0; i < n2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }


    auto lo1 = cal(g1, n1);
    sort(lo1.begin(), lo1.end());
    auto lo2 = cal(g2, n2);
    sort(lo2.begin(), lo2.end());
    if (lo1.back() < lo2.back()) {
        lo1.swap(lo2);
        swap(n1, n2);
    }
    int mx = lo1.back();
    // 较小者
    vector<ll> sum(n2 + 1);
    for (int i = 0; i < n2; i++) {
        lo2[i] += 1;
        sum[i + 1] = sum[i] + lo2[i];
    }
    

    ll ans = 0;
    for (int i = 0; i < n1; i++) {
        int k = lower_bound(lo2.begin(), lo2.end(), mx, [&](const auto& aa, const auto& bb) {
            return lo1[i] + aa < bb;
        }) - lo2.begin();
        ans += (ll)k * mx + ((ll)lo1[i] * (n2 - k) + sum[n2] - sum[k]);
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









