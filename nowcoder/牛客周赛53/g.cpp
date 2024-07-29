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

int main() {
    int n;
    cin >> n;
    vector<int> g[n];
    for (int i = 0; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // p[u]:当前节点的最大深度
    vector<int> p(n);
    // d[u]:当前节点的最大直径
    vector<int> d(n);
    // md[u]:记录所有子节点的最大直径
    vector<multiset<int>> md(n);
    // mp[u]:记录所有子节点的最大深度
    vector<multiset<int>> mp(n);
    auto dfs1 = [&](auto&& dfs1, int u, int o) -> int {
        int ans = 0, max_p = 0;
        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }
            auto pv = dfs1(dfs1, v, u);
            d[u] = max(d[u], d[v]);
            md[u].insert(d[v]);
            mp[u].insert(p[v]);

            ans = max(ans, max_p + pv + 1);
            max_p = max(max_p, pv + 1);
        }
        d[u] = max(d[u], ans);
        return p[u] = max_p;
    };
    dfs1(dfs1, 0, -1);

    vector<int> res(n);
    auto dfs2 = [&](auto&& dfs2, int u, int o) -> void {
        res[u] = *md[u].rbegin();

        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }
            // 保存现场
            int du = d[u], pu = p[u];
            int dv = d[v], pv = p[v];

            md[u].erase(md[u].find(dv));
            mp[u].erase(mp[u].find(pv));
            p[u] = (mp[u].size() ? 1 + *mp[u].rbegin() : 0);
            int y = (mp[u].size() >= 2 ? 1 + *next(mp[u].rbegin()) : 0) + p[u];
            d[u] = max({(md[u].size() ? *md[u].rbegin() : 0), y});

            mp[v].insert(p[u]);
            md[v].insert(d[u]);
            d[v] = max(d[v], p[v] + p[u] + 1);
            p[v] = max(p[v], p[u] + 1);

            dfs2(dfs2, v, u);

            d[v] = dv, p[v] = pv;
            md[v].erase(md[v].find(d[u]));
            mp[v].erase(mp[v].find(p[u]));
            d[u] = du, p[u] = pu;
            mp[u].insert(p[v]);
            md[u].insert(d[v]);
        }
    };
    dfs2(dfs2, 0, -1);

    for (int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}