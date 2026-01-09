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

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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
    int z;
    int v;
    Node() { v = 0; z = 0; }
    Node(int _v) { v = _v; z = 0; }
    // called by push_down
    void op() {

    }
};
Node operator+(const Node& a, const Node& b) {
    Node res;
    res.v = max(a.v, b.v);
    return res;
}

struct SegTree {
    vector<int> a;
    Node tr[800000];
    SegTree(vector<int> _a) {
        a = _a;
    }
    void push_up(int o, int l, int r) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }
    void push_down(int o, int l, int r) {
        if (tr[o].z) {
            tr[o * 2].op();
            tr[o * 2].z = tr[o].z;
            tr[o * 2 + 1].op();
            tr[o * 2 + 1].z = tr[o].z;
            tr[o].z = 0;
        }
    }
    void build(int o, int l, int r) {
        if (l == r) {
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
            // upd
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
            // upd
            tr[o] = Node(u);
            tr[o].z = u;
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
    // 找到第一个等于target的下标
    int ask_index(int o, int l, int r, int L, int R, int target) {
        if (R < l || L > r || tr[o].v < target) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        push_down(o, l, r);
        int m = (l + r) >> 1;
        int idx = ask_index(o * 2, l, m, L, R, target);
        if (idx == -1) {
            return ask_index(o * 2 + 1, m + 1, r, L, R, target);
        }
        return idx;
    }
};


void solve() {
    int n, K; cin >> n >> K;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    SegTree seg(a); seg.build(1, 1, n);

    int mx = 0; for (int i = 0; i < n; i++) mx = max(mx, a[i]);
    if (K >= n - 1) {
        for (int i = 0; i < n; ++i) cout << mx << " "; cout << "\n";
        return;
    }
    // K < n - 1
    int last = -1;
    int i = 0;
    while (i < n && K > 0) {
        Node tmp = seg.ask(1, 1, n, i + 1, i + K + 1);
        if (tmp.v >= last) {
            int idx = seg.ask_index(1, 1, n, i + 1, i + K + 1, tmp.v);
            for (int j = i; j <= idx - 1; ++j) a[j] = tmp.v;
            K -= idx - 1 - i;
            i = idx;
            last = tmp.v;
        } else if (tmp.v < last) {
            for (int j = i; j < i + K; j++) a[j] = last;
            K = 0;
        }
    }
    for (int& e : a) cout << e << " "; cout << "\n";
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









