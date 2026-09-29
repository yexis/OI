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
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * P8436
 * https://www.luogu.com.cn/problem/P8436
 * 
 * 病毒图
 * 桥 割边 边双
 * 
*/

struct EDCC {
    int n, m, tot;

    // 连通分量的根，判割点需要
    int root;

    // (u, v, id)
    int edge_id;
    vector<vector<pii>> g;

    // (u, v, id)
    int new_edge_id;
    vector<vector<pii>> ng;

    // 时间戳，追溯值
    vector<int> dfn, low;
    
    // 是否是割点
    vector<int> cut_point;

    // 是否是割边
    vector<int> cut_edge;

    // 模拟栈
    vector<int> stk;

    // cnt: 边双连通分量编号
    // edcc: 节点属于哪个边双连通分量
    int cnt;
    vector<int> edcc;
    vector<vector<int>> edcc_group;

    EDCC(int nn, int mm) {
        n = nn; m = mm; tot = 0; 
        edge_id = 0; g.resize(n); 
        new_edge_id = 0; ng.resize(n); 
        dfn.resize(n, -1); low.resize(n, -1);
        cut_point.resize(n), cut_edge.resize(m);
        cnt = 0; edcc.resize(n); edcc_group.resize(n);
    }

    void tarjan(int x, int last_id) {
        dfn[x] = low[x] = tot++; 
        stk.push_back(x);
        
        int child = 0; // 符合条件的子树个数
        for (auto [y, curr_id] : g[x]) {
            // 跳过返祖边，不是反边
            if (curr_id == last_id) continue;

            if (dfn[y] == -1) { // 若y尚未访问
                tarjan(y, curr_id);
                // 回x时，更新low，判割点
                // 注意这里取的是low[y]
                low[x] = min(low[x], low[y]);
                if (low[y] >= dfn[x]) {
                    child++;
                    if (x != root || child > 1) {
                        cut_point[x] = true;
                    }
                }
                // 判割边
                if (low[y] > dfn[x]) {
                    cut_edge[curr_id] = true;
                }
            } else { // 若y已经访问
                // 注意这里取的是dfn[y]
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            while(true) {
                int y = stk.back(); stk.pop_back();
                edcc[y] = cnt; edcc_group[cnt].push_back(y);
                if (y == x) break;
            }
            cnt++;
        }
    }
    void add_edge(int u, int v) {
        g[u].push_back(pii(v, edge_id));
        g[v].push_back(pii(u, edge_id));
        edge_id++;
    }
    void add_new_edge(int u, int v) {
        ng[u].push_back(pii(v, new_edge_id));
        ng[v].push_back(pii(u, new_edge_id));
        new_edge_id++;
    }
    void set_root(int rt) {
        root = rt;
    }
};


void solve() {
    int n, m; cin >> n >> m;
    
    EDCC edcc(n, m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        edcc.add_edge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (edcc.dfn[i] == -1) {
            edcc.set_root(i);
            edcc.tarjan(i, -1);
        }
    }
    
    // 判断方法一：相邻的边双size不能同时为1
    // for (int i = 0; i < n; i++) {
    //     for (auto& [j, id] : edcc.g[i]) {
    //         if (!edcc.cut_edge[id]) continue;
    //         int x = edcc.edcc[i], y = edcc.edcc[j];
    //         if (edcc.edcc_group[x].size() == 1 && edcc.edcc_group[y].size() == 1) {
    //             cout << "No" << "\n";
    //             return;
    //         }
    //     }
    // }
    // cout << "Yes" << "\n";
    
    // 判断方法二：二分图染色
    for (int i = 0; i < n; i++) {
        for (auto& [j, id] : edcc.g[i]) {
            int x = edcc.edcc[i], y = edcc.edcc[j];
            if (x != y) {
                edcc.add_new_edge(x, y);
            }
        }
    }
    vector<int> vis(edcc.cnt);
    auto dfs = [&](auto&& dfs, int u, int fg) -> bool {
        for (auto& [v, _] : edcc.ng[u]) {
            int fg2 = (edcc.edcc_group[v].size() > 1 ? 1 : 0);
            if (fg2 == 0 && fg == 0) return false;
            if (vis[v]) continue; vis[v] = true;
            if (!dfs(dfs, v, fg2)) return false;
        }
        return true;
    };
    for (int u = 0; u < edcc.cnt; u++) {
        if (vis[u]) continue; vis[u] = true;
        int fg = (edcc.edcc_group[u].size() > 1 ? 1 : 0);
        if (!dfs(dfs, u, fg)) {
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << "\n";
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









