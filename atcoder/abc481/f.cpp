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
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

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
const int mod = 998244353;
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
 * 分组 BFS
 * Trie BFS
 * 字典序 BFS
 * 要点：同一个组内点的分数相同
 * 
 * 排序方式：
 * 1. 路径长度: BFS天然支持
 * 2. 长度相同时，分数字典序：分组 + 分桶
 * 
 * 
 * 思路：
 * - 在遍历的过程中，将分数相同的节点放到一组进行处理
 * - 保证分数小的组优先处理；如何保证：从小到大的边开始处理，同一组内，保证入队列时，权值小的边优先
 * 
 * 
 * 时间复杂度：
 * O(n); 每个节点入队列一次
*/

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> g[n];
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        g[u].push_back({v, w});
    }

    vector<int> vis(n, 0), ans(n, 0);
    queue<vector<int>> q;
    q.push({0}); ans[0] = 0; vis[0] = true;
    while (q.size()) {
        auto nodes = move(q.front()); q.pop();
        ll sc = ans[nodes[0]];

        // 分桶
        vector<int> buckets[10];
        for (int u : nodes) {
            for (auto [v, w] : g[u]) {
                if (vis[v]) continue;
                buckets[w].push_back(v);
            }
        }

        // 必须按照桶号从小到大创建新组
        for (int w = 1; w <= 9; w++) {
            vector<int> nxt;
            for (int u : buckets[w]) {
                if (vis[u]) continue;
                ans[u] = (sc * 10 + w) % mod;
                vis[u] = true;
                nxt.push_back(u);
            }
            if (nxt.size() > 0) q.push(move(nxt));
        }
    }
    for (int i = 1; i < n; i++) cout << ans[i] << "\n";
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









