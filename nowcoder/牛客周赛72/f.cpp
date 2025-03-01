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

struct Node {
    int tag[2];
    ll v[2];
    ll len;
    Node() : len(0) {
        v[0] = v[1] = 0;
        tag[0] = tag[1] = 0;
    }
    Node(int l) {
        len = l;
        v[0] = l / 2;
        v[1] = l - v[0];
        tag[0] = tag[1] = 0;
    }
    Node(int v0, int v1, int l) {
        v[0] = v0;
        v[1] = v1;
        len = l;
        tag[0] = tag[1] = 0;
    }
    Node operator+(const Node& b) {
        Node c;
        c.v[0] = v[0] + ((len & 1) ? b.v[1] : b.v[0]);
        c.v[1] = v[1] + ((len & 1) ? b.v[0] : b.v[1]);
        c.len = len + b.len;
        return c;
    }
    // 将所有元素修改为 1
    void op1() {
        v[1] = len / 2;
        v[0] = len - v[1];
        tag[0] = 1;
        tag[1] = 0;

    }
    // 区间取反
    void op2() {
        tag[0] = 0;
        tag[1] ^= 1;
        swap(v[0], v[1]);
    }
};

const int N = 1e6;
struct SegTree {
    int cnt;
    Node tr[N];
    int ls[N];
    int rs[N];
    SegTree() {
        cnt = 0;
    }

    void push_down(int o) {
        if (tr[o].tag[0]) {
            tr[ls[o]].op1();
            tr[rs[o]].op1();
            tr[o].tag[0] = 0;
        }
        if (tr[o].tag[1]) {
            tr[ls[o]].op2();
            tr[rs[o]].op2();
            tr[o].tag[1] = 0;
        }
    }

    void push_up(int o) {
        tr[o] = tr[ls[o]] + tr[rs[o]];
    }

    void add1(int& o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            tr[o].op1(u);
            return;
        }
        int m = (l + r) >> 1;
        if (!ls[o]) {
            tr[ls[o]] = Node(r - l + 1);
        }
        if (!rs[o]) {
            tr[rs[o]] = Node(r - l + 1);
        }
        push_down(o);
        if (L <= m) {
            add1(ls[o], l, m, L, R, u);
        }
        if (R > m) {
            add1(rs[o], m + 1, r, L, R, u);
        }
        push_up(o);
    }

    void add2(int& o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            tr[o].op2();
            return;
        }
        int m = (l + r) >> 1;
        if (!ls[o]) {
            tr[ls[o]] = Node(r - l + 1);
        }
        if (!rs[o]) {
            tr[rs[o]] = Node(r - l + 1);
        }
        push_down(o);
        if (L <= m) {
            add2(ls[o], l, m, L, R);
        }
        if (R > m) {
            add2(rs[o], m + 1, r, L, R);
        }
        push_up(o);
    }

    Node ask(int o, int l, int r, int L, int R) {
        // if (!o) {
        //     // 未出现过，说明为全0
        //     return Node();
        // }
        if (L <= l && R >= r) {
            return tr[o];
        }
        int m = (l + r) >> 1;
        if (!ls[o]) {
            tr[ls[o]] = Node(r - l + 1);
        }
        if (!rs[o]) {
            tr[rs[o]] = Node(r - l + 1);
        }
        push_down(o);

        Node ans;
        if (L <= m) {
            ans = ans + ask(ls[o], l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(rs[o], m + 1, r, L, R);
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    int root = 0;
    SegTree seg;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        int l, r;
        cin >> l >> r;
        if (op == 1) {
            seg.add1(root, 1, n, l, r, 1);
        } else if (op == 2) {
            seg.add2(root, 1, n, l, r);
        } else {
            node res = seg.ask(root, l, r);
            cout << min(res.v[0], res.v[1]) << "\n";
        }
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}