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


/*
 * 题目：https://ac.nowcoder.com/acm/contest/98256/F
 * 动态开点线段树 + 区间更新(lazy懒加载)
 * 不传引用版本，将开点放到左右孩子 ls[o] 和 ls[o]
*/

struct Node {
    /* 
     * 懒加载标记
     * z[0] 表示操作一的次数
     * z[1] 表示操作二的次数
    */ 
    int z[2];
    /*
     * v[0] 表示形成以0开头的好串 需要修改的次数
     * v[1] 表示形成以1开头的好串 需要修改的次数
    */
    ll v[2];
    // 区间长度
    ll len;
    
    Node(): len(0) {
        z[0] = z[1] = 0;
        v[0] = v[1] = 0;
    };
    /*
    * 00000
    * 区间设置为全0，长度为len
    * v[0] 则为 len / 2
    * v[1] 则为 len - v[0]
    */
    Node(int l, int r) {
        len = r - l + 1;
        v[0] = len / 2;
        v[1] = len - v[0];
        z[0] = 0;
        z[1] = 0;
    }
    
    Node operator+(const Node& b) {
        Node c(0, 0);
        c.v[0] = v[0] + (len % 2 ? b.v[1] : b.v[0]);
        c.v[1] = v[1] + (len % 2 ? b.v[0] : b.v[1]);
        c.len = len + b.len;
        return c;
    }
    
    // 操作一：将所有元素修改为 1
    // 进行操作一后，之前留下的操作二作废
    void op1() {
        v[1] = len / 2;
        v[0] = len - v[1];
        z[0] = 1;
        // 如果有操作一了，将操作二取消，因为已经失效了
        z[1] = 0;
    }

    // 操作二：区间取反
    // 进行操作二之后，之前留下的操作一继续
    void op2() {
        // tag[0]不变
        z[1] ^= 1;
        swap(v[0], v[1]);
    }
};

const int N = 4e6 + 10;
struct SegTree {
    int cnt;
    Node tr[N];
    int ls[N];
    int rs[N];
    SegTree() {
        cnt = 0;
        memset(ls, 0, sizeof(ls));
        memset(rs, 0, sizeof(rs));
    }

    // 创建新节点
    int build(int l, int r) {
        int o = ++cnt;
        tr[o] = Node(l, r);
        return o;
    }

    // 标记下推
    // 必须先进行操作一
    void push_down(int o, int l, int r) {
        int m = (l + r) >> 1;
        if (tr[o].z[0]) {
            tr[ls[o]].op1();
            tr[rs[o]].op1();
            tr[o].z[0] = 0;
        }
        if (tr[o].z[1]) {
            tr[ls[o]].op2();
            tr[rs[o]].op2();
            tr[o].z[1] = 0;
        }
    }

    void push_up(int o) {
        tr[o] = tr[ls[o]] + tr[rs[o]];
    }

    void add1(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            tr[o].op1();
            return;
        }

        int m = (l + r) >> 1;
        if (!ls[o]) ls[o] = build(l, m);
        if (!rs[o]) rs[o] = build(m + 1, r);
        push_down(o, l, r);
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
        if (!ls[o]) ls[o] = build(l, m);
        if (!rs[o]) rs[o] = build(m + 1, r);
        push_down(o, l, r);
        if (L <= m) {
            add2(ls[o], l, m, L, R);
        }
        if (R > m) {
            add2(rs[o], m + 1, r, L, R);
        }
        push_up(o);
    }

    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        Node ans;

        int m = (l + r) >> 1;
        if (!ls[o]) ls[o] = build(l, m);
        if (!rs[o]) rs[o] = build(m + 1, r);
        push_down(o, l, r);
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

    SegTree seg;
    int root = seg.build(1, n);
    while (q--) {
        int op;
        cin >> op;
        int l, r;
        cin >> l >> r;
        if (op == 1) {
            seg.add1(root, 1, n, l, r, 1);
        } else if (op == 2) {
            seg.add2(root, 1, n, l, r);
        } else {
            Node res = seg.ask(root, 1, n, l, r);
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