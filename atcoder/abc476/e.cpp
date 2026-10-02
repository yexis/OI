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
    int z; // 懒加载
    int v; // 区间值
    int v2;
    Node() { 
        v = 0; 
        v2 = 0;
        z = 0; 
    }
    Node(int vv) { 
        v = vv; 
        v2 = vv;
        z = 0; 
    }
    // called by push_down
    void op() {

    }
};
// 自定义+
Node operator+(const Node& a, const Node& b) {
    Node res;
    res.v = max(a.v, b.v);
    res.v2 = min(a.v2, b.v2);
    return res;
}

struct SegTree {
    vector<int> a;
    Node tr[800010];
    SegTree(vector<int>& aa) {
        a = aa;
    }
    void push_up(int o, int l, int r) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }
    void push_down(int o, int l, int r) {
        if (tr[o].z) {
            tr[o * 2].op();
            tr[o * 2].z += tr[o].z;
            tr[o * 2 + 1].op();
            tr[o * 2 + 1].z += tr[o].z;
            tr[o].z = 0;
        }
    }
    void build(int o, int l, int r) {
        if (l == r) {
          	// init 单个元素
            tr[o] = Node(a[l - 1]);
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
    void add_lr(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            // upd 区间
          	// 注意判断这里是否需要直接操作
          	// tr[o].z > 0 是为了操作子树 tr[o *2] 和 tr[o * 2 + 1]
          	// 如果只记录z可能会有问题
            tr[o] = Node(u);
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
        ans.v = 0, ans.v2 = INF;

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
    int n, m; cin >> n >> m;
    vector<int> P(n); for (int i = 0; i < n; i++) cin >> P[i];
    vector<int> L(m), R(m);
    for (int i = 0; i < m; i++) cin >> L[i] >> R[i];

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) pos[P[i]] = i;

    SegTree seg(P); seg.build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int l = L[i], r = R[i];
        // --l, --r;
        Node node = seg.ask(1, 1, n, l, r);
        int lv = node.v2, rv = node.v;
        int lp = pos[lv], rp = pos[rv];

        P[lp] = rv, P[rp] = lv;
        pos[P[lp]] = lp, pos[P[rp]] = rp;

        seg.add(1, 1, n, lp + 1, P[lp]);
        seg.add(1, 1, n, rp + 1, P[rp]);
    }

    for (auto& e : P) cout << e << " "; cout << "\n";
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









