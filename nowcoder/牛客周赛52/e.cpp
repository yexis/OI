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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> v;
    int vis[n];
    memset(vis, 0, sizeof(vis));
    auto dfs = [&](auto&& dfs, int u, int& d) -> void {
        for (auto& v : g[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            d = max(d, a[v]);
            dfs(dfs, v, d);
        }
    };

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        int d = a[i];
        dfs(dfs, i, d);
        v.push_back(d);
    }

    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 1; i < v.size(); i++) {
        ans += v[i];
    }
    cout << ans << "\n";

    return 0;
}