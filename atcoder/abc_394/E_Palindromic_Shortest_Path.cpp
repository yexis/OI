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
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<char>> g2(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g2[i][j] = g[j][i];
        }
    }
    
    vector<vector<int>> res(n, vector<int>(n, INF));
    int xx = -1, yy = -1;

    vector<vector<vector<int> > > v1(n, vector<vector<int>>(26));
    vector<vector<vector<int> > > v2(n, vector<vector<int>>(26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '-') continue;
            v1[i][g[i][j] - 'a'].push_back(j);
        }
        for (int j = 0; j < n; j++) {
            if (g2[i][j] == '-') continue;
            v2[i][g2[i][j] - 'a'].push_back(j);
        }
    }
    

    // 递归深度优先搜索函数
    int vis[101][101];
    auto dfs = [&](auto&& dfs, int x, int y, int len) {
        if (vis[x][y]) return;
        if (g[x][y] != '-') {
            res[xx][yy] = min(res[xx][yy], len + 1);
            return;
        }
        if (x == y) {
            res[xx][yy] = min(res[xx][yy], len);
            return;
        }
        if (len >= res[xx][yy]) {
            return;
        }
        vis[x][y] = true;

        auto& vv1 = v1[x];
        auto& vv2 = v2[y];
        for (int d = 0; d < 26; d++) {
            if (vv1[d].empty() || vv2[d].empty()) {
                continue;
            }
            for (int i = 0; i < vv1[d].size(); i++) {
                for (int j = 0; j < vv2[d].size(); j++) {
                    if (vv1[d][i] == x && vv2[d][j] == y) continue;
                    dfs(dfs, vv1[d][i], vv2[d][j], len + 2); 
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                res[i][j] = 0;
                continue;
            }

            if (g[i][j] != '-') {
                res[i][j] = 1;
                continue;
            }

            xx = i, yy = j;
            memset(vis, 0, sizeof(vis));
            dfs(dfs, i, j, 0);
            if (res[i][j] == INF) {
                res[i][j] = -1;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}
