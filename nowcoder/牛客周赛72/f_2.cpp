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
 * 区间离散化
 * 
 * 将区间抽象成点，线段树的每个节点代表实际的区间左闭右开
 * 对所有点进行排序，将相邻点之间的所有点省略掉，将相邻点的区间缩成点，一个点代表一个左闭右开的区间
 * 比如询问 [1, 100], [10, 20], [12, 15]
 * 取出所有点 1 101 10 21 12 16，排序后就是 1 10 12 16 21 100
 * 那么就可以形成5个节点: 1代表区间[1,10), 2代表区间[10, 12), 3代表区间[12, 16), 4代表区间[16, 21), 5代表区间[21, 100)
 * 
 * 这里为什么要将右边界加1呢？
 * 这是一个区间缩点的技巧，考虑一下不加1，那么排序后变成 1 10 12 15 20 100
 * 左闭右开: 1-[1, 10) 2-[10, 12) 3-[12, 15) 4-[15, 20) 5-[20, 100)
 * 当我要询问 [10, 20]时，是无法对应到节点范围的，两种
 * 左闭右闭: 1-[1, 10] 2-[10, 12] 3-[12, 15] 4-[15, 20] 5-[20, 100]
 * 明显不行，边界有问题，10属于哪个区间呢？
 *
 * 所以这就是将区间抽象成点的技巧，将右边界+1，或者将左边界-1，这样不仅能保证区间连续，还可以将区间完美对应到点 
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
        tag[0] = 0;
        tag[1] = 0;
    }
    Node(int v0, int v1, int l) {
        v[0] = v0;
        v[1] = v1;
        len = l;
        tag[0] = tag[1] = 0;
    }
    Node operator+(const Node& b) {
        Node c;
        c.v[0] = v[0] + (len % 2 ? b.v[1] : b.v[0]);
        c.v[1] = v[1] + (len % 2 ? b.v[0] : b.v[1]);
        c.len = len + b.len;
        return c;
    }
    void op0() {
        v[0] = len / 2;
        v[1] = len - v[1];
        tag[0] = 0;
        tag[1] = 0;
    }
    // 将所有元素修改为 1
    // 操作一之前不能进行操作二
    void op1() {
        v[1] = len / 2;
        v[0] = len - v[1];
        tag[0] = 1;
        // 如果有操作一了，将操作二取消
        tag[1] = 0;
    }

    // 区间取反
    // 操作二之前可以进行操作一
    void op2() {
        tag[1] ^= 1;
        swap(v[0], v[1]);
    }
};

const int N = 1e6 + 10;
struct SegTree {
    int cnt;
    int n;
    vector<pii> a;
    Node tr[N];
    SegTree(vector<pii>& _a) {
        a = _a;
        n = a.size();
        cnt = 0;
        build(1, 1, n);
    }

    // 必须先进行操作一
    void push_down(int o) {
        if (tr[o].tag[0]) {
            tr[o * 2].op1();
            tr[o * 2 + 1].op1();
            tr[o].tag[0] = 0;
        }
        if (tr[o].tag[1]) {
            tr[o * 2].op2();
            tr[o * 2 + 1].op2();
            tr[o].tag[1] = 0;
        }
    }

    void push_up(int o) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }

    void build(int o, int l, int r) {
        if (l == r) {
            auto& [li, ri] = a[l - 1];
            tr[o] = Node(ri - li);
            return;
        }
        int m = (l + r) >> 1;
        build(o * 2, l, m);
        build(o * 2 + 1, m + 1, r);
        push_up(o);
    }

    void add1(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            tr[o].op1();
            return;
        }
        int m = (l + r) >> 1;
        push_down(o);
        if (L <= m) {
            add1(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add1(o * 2 + 1, m + 1, r, L, R, u);
        }
        push_up(o);
    }

    void add2(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            tr[o].op2();
            return;
        }
        int m = (l + r) >> 1;
        push_down(o);
        if (L <= m) {
            add2(o * 2, l, m, L, R);
        }
        if (R > m) {
            add2(o * 2 + 1, m + 1, r, L, R);
        }
        push_up(o);
    }

    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        
        Node ans;
        int m = (l + r) >> 1;
        push_down(o);
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
    int n, q;
    cin >> n >> q;

    vector<pii> a;
    using ar3 = array<int, 3>;
    vector<ar3> qs(q);
    vector<int> ob;
    for (auto& [op, l, r] : qs) {
        cin >> op >> l >> r;
        r++;
        ob.push_back(l);
        ob.push_back(r);
    }
    
    sort(ob.begin(), ob.end());
    ob.erase(unique(ob.begin(), ob.end()), ob.end());
    int m = ob.size();
    auto get = [&](int x) {
        return lower_bound(ob.begin(), ob.end(), x) - ob.begin();
    };
    for (int i = 0; i + 1 < m; i++) {
        a.push_back(pii(ob[i], ob[i + 1]));
    }
    int m1 = a.size();

    SegTree seg(a);
    for (auto& [op, l, r] : qs) {
        l = get(l);
        r = get(r) - 1;
        l++, r++;

        if (op == 1) {
            seg.add1(1, 1, m1, l, r, 1);
        } else if (op == 2) {
            seg.add2(1, 1, m1, l, r);
        } else {
            Node res = seg.ask(1, 1, m1, l, r);
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