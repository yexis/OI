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
 * 
*/

struct Node {
    int len;
    ll z; // 懒加载
    ll v; // 区间值
    Node() { 
        v = 0; 
        len = 0;
        z = 0; 
    }
    Node(ll vv) { 
        v = vv; 
        len = 1;
        z = 0; 
    }
    // called by push_down
    void op(ll delta) {
        v += delta * len;
        v %= mod;
    }
};
// 自定义+
Node operator+(const Node& a, const Node& b) {
    Node res;
    res.len = a.len + b.len;
    res.v = a.v + b.v; res.v %= mod;
    return res;
}

struct SegTree {
    vector<ll> a;
    Node tr[800000];
    SegTree(vector<ll> aa) {
        a = aa;
    }
    void push_up(int o, int l, int r) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }
    void push_down(int o, int l, int r) {
        if (tr[o].z) {
            ll delta = tr[o].z;
            tr[o * 2].op(delta);
            tr[o * 2].z += tr[o].z;
            tr[o * 2 + 1].op(delta);
            tr[o * 2 + 1].z += tr[o].z;
            tr[o].z = 0;
        }
    }
    void build(int o, int l, int r) {
        if (l == r) {
          	// init 单个元素
            tr[o] = Node(a[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(o * 2, l, m);
        build(o * 2 + 1, m + 1, r);
        push_up(o, l, r);
    }
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            // upd 单个元素
            tr[o] = Node(u);
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        push_up(o, l, r);
    } 
    void add_lr(int o, int l, int r, int L, int R, ll u) {
        if (L <= l && R >= r) {
            // upd 区间
          	// 注意判断这里是否需要直接操作
          	// tr[o].z > 0 是为了操作子树 tr[o *2] 和 tr[o * 2 + 1]
          	// 如果只记录z可能会有问题
            // tr[o] = Node(u);
            mod_add(tr[o].z, u);
            mod_add(tr[o].v, u * tr[o].len);
            return;
        }
        push_down(o, l, r);
        int m = (l + r) >> 1;
        if (L <= m) {
            add_lr(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add_lr(o * 2 + 1, m + 1, r, L, R, u);
        }
        push_up(o, l, r);
    }
    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        push_down(o, l, r);
        int m = (l + r) >> 1;
        Node ans;
        if (L <= m) {
            ans = ans + ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int tot = 0;

    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) { int u, v; cin >> u >> v; u--, v--; g[u].push_back(v); g[v].push_back(u); }
    
    
    vector<int> dep(n);
    // 数的dfs序 L表示进入dfs序，R表示离开dfs序
  	// dfs序从 1 开始，[ L[u], R[u] ] 表示节点u的子树
    vector<int> L(n), R(n);
    vector<ll> M(n);
    auto dfs = [&](auto&& dfs, int u, int o, ll mask) -> void {
        if (s[u] == '1') M[u] = mod_add(mask, power(2, dep[u]));
        else M[u] = mask;

        L[u] = ++tot;

        for (auto& v : g[u]) if (v != o) {
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u, M[u]);
        }
        R[u] = tot;
    };
    dfs(dfs, 0, -1, 0);
    
    // 按照 L 构建线段树 [1, n]
    vector<ll> A(n + 1); for (int i = 0; i < n; i++) A[L[i]] = M[i];
    SegTree seg(A); seg.build(1, 1, n);

    while (q--) {
        char op; cin>> op;
        if (op == 'F') {
            int u; cin >> u; u--;
            int start = L[u], end = R[u];

            ll old = s[u] - '0', curr = old ^ 1;
            old = (old == 1 ? power(2, dep[u]) : 0);
            curr = (curr == 1 ? power(2, dep[u]) : 0);
            ll delta = mod + curr - old;  delta %= mod;

            seg.add_lr(1, 1, n, start, end, delta);
            s[u] = (s[u] == '0' ? '1' : '0');
        } else if (op == 'Q') {
            int u; cin >> u; u--;
            int pos = L[u];
            Node ans = seg.ask(1, 1, n, pos, pos);
            cout << ans.v << "\n";
        }
    }
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









