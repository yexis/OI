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
 *
 *
 *
 *
 *
 * f_3 在 f_2的基础上，将区间进行奇偶分离，即奇数点和偶数点分开计算
 * 比如 区间[1,10] 分成 区间[1,3,5,7,9] 和 [2,4,6,8,10]
 * 这样好串可以定义为 奇区间全为0，偶区间全为1   或者   奇区间全为1，偶区间全为0   
 * 这样，在使用线段树进行区间询问时，只需要维护区间中0的数量和1的数量即可
 *
 *
 *
 *
 *
*/

struct Node {
    // v[0]: 区间中0的数量
    // v[1]: 区间中1的数量
    int v[2];
    // z[0]: 操作1的标记
    // z[1]: 操作2的标记
    int z[2];
    // len: 区间长度
    int len;
    Node() {
        len = 0;
        v[0] = v[1] = 0;
        z[0] = z[1] = 0;
    }
    Node(int _len) {
        len = _len;
        v[0] = len, v[1] = 0;
        z[0] = z[1] = 0;
    }
    Node operator+(const Node& b) {
        Node c;
        c.len = len + b.len;
        c.v[0] = v[0] + b.v[0];
        c.v[1] = v[1] + b.v[1];
        return c;
    };
    // 操作一：全部置为1
    void op1() {
        v[0] = 0, v[1] = len;
        z[0] = 1, z[1] = 0;
    }
    // 操作二：区间取反
    void op2() {
        swap(v[0], v[1]);
        z[1] ^= 1;
    }
};

// 1 11 13 17 21 101 
// 2 10 12 16 22 102 
struct SegTree {
    vector<pii> a;
    vector<Node> tr;
    SegTree(vector<pii>& _a) {
        a = _a;
        int n = a.size();
        tr.resize(n * 4 + 10);
        // 如果数组为空，则不需要构建线段树
        if (n < 1) return;
        build(1, 1, n);
    }

    void build(int o, int l, int r) {
        if (l == r) {
            auto& [li, ri] = a[l - 1];
            // 这里为什么要除2，因为进行了奇偶分离
            // 区间内部实际的数的个数要除以2
            // 比如区间[10,16)实际只有10,12,14三个数
            tr[o] = Node((ri - li) >> 1);
            return;
        }
        int m = (l + r) >> 1;
        build(o * 2, l, m);
        build(o * 2 + 1, m + 1, r);
        push_up(o);
    }

    // 本题的关键是：两个操作是存在优先级的，置1操作 优于 取反操作
    // 对于节点i，
    // 进行置1时，如果z中存在取反操作，则可以直接取消，因为取反已经失效
    // 进行取反时，如果z中存在置1操作，则不能取消，因为可以在1的基础上进行取反
    void push_down(int o, int l, int r) {
        if (tr[o].z[0]) {
            tr[o * 2].op1();
            tr[o * 2 + 1].op1();
            tr[o].z[0] = 0;
        }
        if (tr[o].z[1]) {
            tr[o * 2].op2();
            tr[o * 2 + 1].op2();
            tr[o].z[1] = 0;
        }
    }

    void push_up(int o) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }

    void add1(int o, int l, int r, int L, int R, int u) {
        if (L > R) return;
        if (L <= l && R >= r) {
            tr[o].op1();
            return;
        }
        int m = (l + r) >> 1;
        push_down(o, l, r);
        if (L <= m) {
            add1(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add1(o * 2 + 1, m + 1, r, L, R, u);
        }
        push_up(o);
    }

    void add2(int o, int l, int r, int L, int R) {
        if (L > R) return;
        if (L <= l && R >= r) {
            tr[o].op2();
            return;
        }
        int m = (l + r) >> 1;
        push_down(o, l, r);
        if (L <= m) {
            add2(o * 2, l, m, L, R);
        }
        if (R > m) {
            add2(o * 2 + 1, m + 1, r, L, R);
        }
        push_up(o);
    }

    Node ask(int o, int l, int r, int L, int R) {
        if (L > R) return Node(0);
        if (L <= l && R >= r) {
            return tr[o];
        }
        Node ans;
        int m = (l + r) >> 1;
        push_down(o, l, r);
        if (L <= m) {
            ans = ans + ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
};

// odd: 1 101 11 21 13 17
// even: 2 102 10 22 12 16

// *** 注意 ***
// 有一点需要注意的是，在进行区间奇偶分离后
// 可能会存在特殊情况，区间中没有奇数或者没有偶数
// 比如区间[100,100]，很显然区间中只有100一个偶数，没有奇数
// 这样生成[l_odd, r_odd]会是什么形式？ r_odd会小于l_odd
// 这样是不能直接进行线段树询问的，所以在在线段树中增加了 if (L > R) return; 的判断

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pii> a;
    using ar3 = array<int, 3>;
    vector<ar3> qs(q);
    vector<int> ob;
    for (auto& [op, l, r] : qs) {
        cin >> op >> l >> r;
    }

    vector<int> sep_odd;
    vector<int> sep_even;
    for (auto& [_, l, r] : qs) {
        sep_odd.push_back(l & 1 ? l : l + 1);
        sep_even.push_back(l & 1 ? l + 1 : l);
        // 这里为什么是 r + 2，是因为要将区间右边界右移一位
        // 比如 右边界是11，那么存的右边界应该是13
        sep_odd.push_back(r & 1 ? r + 2 : r + 1);
        sep_even.push_back(r & 1 ? r + 1 : r + 2);
    }

    // 区间离散化
    sort(sep_odd.begin(), sep_odd.end());
    sep_odd.erase(unique(sep_odd.begin(), sep_odd.end()), sep_odd.end());
    sort(sep_even.begin(), sep_even.end());
    sep_even.erase(unique(sep_even.begin(), sep_even.end()), sep_even.end());
    auto get = [&](vector<int>& ab, int x) {
        return lower_bound(ab.begin(), ab.end(), x) - ab.begin() + 1;
    };

    // 将区间转化成点
    auto topii = [&](vector<int>& ab) -> vector<pii> {
        vector<pii> pr;
        for (int i = 1; i < (int)ab.size(); i++) {
            pr.emplace_back(ab[i - 1], ab[i]);
        }
        return pr;
    };

    auto pii_odd = topii(sep_odd);
    auto pii_even = topii(sep_even);
    int n_odd = pii_odd.size();
    int n_even = pii_even.size();
    SegTree seg_odd(pii_odd);
    SegTree seg_even(pii_even);

    for (auto& [op, l, r] : qs) {
        int l_odd = get(sep_odd, l & 1 ? l : l + 1);
        int l_even = get(sep_even, l & 1 ? l + 1 : l);
        int r_odd = get(sep_odd, r & 1 ? r + 2 : r + 1) - 1;
        int r_even = get(sep_even, r & 1 ? r + 1 : r + 2) - 1;

        if (op == 1) {
            seg_odd.add1(1, 1, n_odd, l_odd, r_odd, 1);
            seg_even.add1(1, 1, n_even, l_even, r_even, 1);
        } else if (op == 2) {
            seg_odd.add2(1, 1, n_odd, l_odd, r_odd);
            seg_even.add2(1, 1, n_even, l_even, r_even);
        } else if (op == 3) {
            Node ans_odd = seg_odd.ask(1, 1, n_odd, l_odd, r_odd);
            Node ans_even = seg_even.ask(1, 1, n_even, l_even, r_even);
            int ans = min(ans_odd.v[0] + ans_even.v[1], ans_odd.v[1] + ans_even.v[0]);
            cout << ans << "\n";
        }
    }

    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}