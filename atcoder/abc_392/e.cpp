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

// 注意： 并查集在合并的过程中，联通分量的root是可能变化的
struct DJ {
    int n;
    int count;
    vector<int> fa;
    DJ(int nn) {
        n = nn;
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        count = n;
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        fa[ry] = rx;
        count--;
    }
    bool conn(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};

// 哪条路径是多余的
void solve() {
    // N servers
    // M cables
    int n, m;
    cin >> n >> m;

    vector<pii> pr;
    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        ai--, bi--;
        pr.emplace_back(ai, bi);
    }

    DJ dj(n);

    // 归类
    // 注意(踩坑)：在合并的过程中，root[i]是可能发生变化的
    // 所以将多余的电缆绑定到root[i]时，可能绑定到非root节点上
    vector<int> roots;
    unordered_map<int, vector<int> > rest;
    vector<int> rest_all;
    for (int i = 0; i < pr.size(); i++) {
        auto [ai, bi] = pr[i];
        if (dj.conn(ai, bi)) {
            rest_all.push_back(i);
        } else {
            dj.merge(ai, bi);
        }
    }
    if (dj.count == 1) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        int root = dj.find(i);
        if (root == i) {
            roots.push_back(i);
            continue;
        }
    }
    for (auto& e : rest_all) {
        auto& [ai, bi] = pr[e];
        rest[dj.find(ai)].push_back(e);
    }


    // 将多余边 比较多 的连通分量 排在前面
    int ans = dj.count - 1;
    vector<array<int, 3> > res;
    sort(roots.begin(), roots.end(), [&](const auto& aa, const auto& bb) {
        return rest[aa].size() > rest[bb].size();
    });
    
    vector<int> can;
    for (auto& e : rest[roots[0]]) can.push_back(e);
    for (int i = 1; i < roots.size(); i++) {
        auto root = roots[i];
        auto& can2 = rest[root];
        if (can.size()) {
            auto t = can.back();
            can.pop_back();
            auto [ai, bi] = pr[t];
            res.push_back({t, bi, root});
        } else if (can2.size()) {
            auto t = can2.back();
            can2.pop_back();
            auto [ai, bi] = pr[t];
            res.push_back({t, bi, roots[0]});
        }
        for (auto& e : can2) can.push_back(e);
    }

    cout << ans << "\n";
    for (auto [a, b, c] : res) {
        cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}