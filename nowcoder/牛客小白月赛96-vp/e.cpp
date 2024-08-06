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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int xf = 0x3f3f3f3f;
const int mod = 1e9 + 7;


// 树形DP+树状数组
// 在树上进行区间查询
struct BIT {
    int n;
    vector<int> tr;

    BIT(int nn) {
        n = nn;
        tr.resize(n + 1);
    }

    int lb(int x) {
        return x & -x;
    }

    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
        }
    }

    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }
        return ans;
    }
};

int ini = 0;
vector<ll> bs;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    vector<int> g[n];
    for (int i = 1; i < n; i++) {
        int x = i;
        int y = e[i] - 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> sum(n);
    vector<ll> cnt(n);
    ini = 0;
    bs = vector<ll>();
    auto dfs = [&](auto &&dfs, int u, int o, ll ups) -> pair<ll, int> {
        for (auto &v : g[u]) {
            if (v == o) continue;
            auto[sons, cv] = dfs(dfs, v, u, ups + a[u]);
            sum[u] += sons;
            cnt[u] += cv;
        }
        if (ups >= a[u] && a[u] >= sum[u]) {
            ini++;
            cnt[u]++;
        }
        // sum[u]：所有孩子的和
        bs.emplace_back(sum[u] - a[u]);
        return {sum[u] + a[u], cnt[u]};
    };
    dfs(dfs, 0, -1, 0);


    // 离散化
    sort(bs.begin(), bs.end());
    bs.erase(unique(bs.begin(), bs.end()), bs.end());
    int bn = bs.size();
    auto get = [&](ll x) -> int {
        int k = lower_bound(bs.begin(), bs.end(), x) - bs.begin();
        if (k < bn && bs[k] == x) {
            return k;
        } else {
            return k - 1;
        }
    };


    BIT bit(bn);
    ll ans = ini;
    auto go = [&](auto &&go, int u, int o, ll d) -> void {
        // 如果删除本节点
        int idx = get(sum[u] + a[u]);
        if (idx >= 0) {
            ans = max(ans, ini - cnt[u] + bit.ask(idx + 1));
        }

        if (d >= a[u] && a[u] < sum[u]) {
            bit.add(get(sum[u] - a[u]) + 1, 1);
        }

        for (auto &v : g[u]) {
            if (v == o) continue;
            go(go, v, u, d + a[u]);
        }

        if (d >= a[u] && a[u] < sum[u]) {
            bit.add(get(sum[u] - a[u]) + 1, -1);
        }
    };
    go(go, 0, -1, 0);

    cout << ans << "\n";
    return 0;
}