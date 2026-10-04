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
 * SCC缩点
*/

struct TarjanSCC {
    int n;
    // 时间戳编号，强连通分量个数
    // 编号都从1开始
    int tot, cnt;

    // 原图
    vector<vector<pii>> g;

    // 缩点后的scc图
    vector<vector<pii>> ng;
    
    // 时间戳，追溯值
    vector<int> dfn, low; 

    // 模拟栈，是否在栈中
    vector<int> stk, in_stk;

    // 强连通分量编号，scc的大小
    vector<int> scc, siz; 

    // 记录强连通分量入度和出度
    vector<int> deg_in, deg_out;

    // 下列内容根据实际题目设置
    // 节点权值、强连通分量权值
    vector<int> w, nw, dp;

    TarjanSCC(int nn) {
        tot = cnt = 0; n = nn;
        g.resize(n); ng.resize(n);
        dfn.resize(n, -1); low.resize(n);
        in_stk.resize(n);
        scc.resize(n, -1), siz.resize(n);
        deg_in.resize(n); deg_out.resize(n);
    }
    void tarjan(int x) {
        dfn[x] = low[x] = tot++;
        stk.push_back(x); in_stk[x] = 1;
        for (auto& [y, _] : g[x]) {
            if (dfn[y] == -1) {
                tarjan(y);
                low[x] = min(low[x], low[y]);
            } else if (in_stk[y]) {
                low[x] = min(low[x], dfn[y]);
            }
        }
        // 若x是scc的根
        if (dfn[x] == low[x]) {
            int y;
            while (true) {
                y = stk.back(); stk.pop_back(); in_stk[y] = 0;
                scc[y] = cnt; ++siz[cnt];
                if (y == x) break;
            }
            cnt++;
        }
    }
    void add_edge(int u, int v, int w) {
        g[u].push_back(pii(v, w));
    }
    void add_new_edge(int u, int v, int w) {
        ng[u].push_back(pii(v, w));
        deg_out[v]++;
        deg_in[v]++;
    }
};


void solve() {
    int n, q; cin >> n >> q;
    
    TarjanSCC scc(n);

    while (q--) {
        int t, u, v; cin >> t >> u >> v; u--, v--;
        scc.add_edge(u, v, t);
    }

    for (int i = 0; i < n; i++) {
        if (scc.dfn[i] == -1) scc.tarjan(i);
    }

    // cout << "cnt:" << scc.cnt << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << "scc:" << i << " " << scc.scc[i] << "\n";
    // }
    
    
    // 根据题目要求而定
    for (int x = 0; x < n; x++) {
        for (auto [y, w] : scc.g[x]) {
            int nx = scc.scc[x], ny = scc.scc[y];
            

            if (nx == ny && w) {
                cout << "No" << "\n";
                return;
            }
            if (nx != ny) {
                scc.add_new_edge(nx, ny, 1);
            }
        }
    }

    vector<int> V(scc.cnt);
    queue<int> que;
    for (int i = 0; i < scc.cnt; i++) {
        if (scc.deg_in[i] == 0) {
            que.push(i);
            V[i] = 1;
        }
    }
    while (que.size()) {
        int u = que.front(); que.pop();
        for (auto [v, _] : scc.ng[u]) {
            if (--scc.deg_in[v] == 0) {
                que.push(v);
            }
            V[v] = max(V[v], V[u] + 1);
        }
    }

    cout << "Yes" << "\n";
    for (int i = 0; i < n; i++) {
        int ri = scc.scc[i];
        cout << V[ri] << " ";
    }
    cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









