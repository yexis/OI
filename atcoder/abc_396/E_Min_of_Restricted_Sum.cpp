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
 * 给定图中一些点和边，每条边都存在权值，代表需要满足val[u] ^ val[v] = w;
 * 问，如何设置每个点的权值，能使得每条边的
 *
 * 
 *
 * 
 *
 * 
 *
*/


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> X(m), Y(m), Z(m);
    for (int i = 0; i < m; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--, Y[i]--;
    }
    vector<vector<pii> > g(n);
    for (int i = 0; i < m; i++) {
        int x = X[i], y = Y[i], w = Z[i];
        g[x].push_back(pii(y, w));
        g[y].push_back(pii(x, w));
    }

    // 第一步：判断是否有解
    int vis[n], val[n];
    memset(vis, 0, sizeof(vis));
    memset(val, 0, sizeof(val));
    unordered_map<int, vector<int> > un;
    function<bool(int, int)> dfs = [&](int rt, int u) -> bool {
        un[rt].push_back(u);
        for (auto& [v, w] : g[u]) {
            if (vis[v]) {
                // 检查
                if ((val[u] ^ w) != val[v]) {
                    return false;
                }
                continue;
            }
            vis[v] = true;
            val[v] = val[u] ^ w;
            if (!dfs(rt, v)) {
                return false;
            }
        }
        return true;
    };
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        bool ok = dfs(i, i);
        if (!ok) {
            cout << -1 << "\n";
            return;
        }
    }

    // 第二步: 寻找最优解
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (!un.count(i)) continue;
        auto& ps = un[i]; 
        int rt = 0;
        // 1的个数
        for (int d = 30; d >= 0; d--) {
            int cnt0 = 0, cnt1 = 0;
            for (auto& e : ps) {
                if (val[e] >> d & 1) {
                    cnt0++;
                } else {
                    cnt1++;
                }
            }
            if (cnt1 < cnt0) {
                rt |= 1 << d;
            }
        }
        
        for (auto& e : ps) {
            res[e] = val[e] ^ rt;
        }
    }

    for (auto& e : res) {
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









