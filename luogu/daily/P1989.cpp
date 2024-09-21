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

/*
 * keywords: 无向图 | 三元环
 *
 * 无向图的三元环计数
 * https://www.luogu.com.cn/problem/P1989
 * 时间复杂度: O(m * sqrt(m))，其中m表示边的数量
 *
*/

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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        auto& [u, v] = edges[i];
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
    }

    // 无向图 定向（无向图转有向图）
    // 规定从度数小的点指向度数大的点，度数相同就从编号小的点指向编号大的点
    // 此时会形成一张有向无环图（DAG），且每个点的出度不超过 sqrt(m)
    vector<pii> g[n];
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        if (deg[u] > deg[v]) swap(u, v);
        if (deg[u] == deg[v] && u > v) swap(u, v);
        g[u].emplace_back(v, i);
    }

    int cnt = 0;
    vector<int> vis(n);
    for (int u = 0; u < n; u++) {
        for (auto& [v, id] : g[u]) {
            vis[v] = true;
        }
        for (auto& [v, id] : g[u]) {
            for (auto& [w, id2] : g[v]) {
                if (vis[w]) {
                    cnt++;
                }
            }
        }
        for (auto& [v, id] : g[u]) {
            vis[v] = false;
        }
    }
    cout << cnt << "\n";
}

int main() {
    solve();
    return 0;
}