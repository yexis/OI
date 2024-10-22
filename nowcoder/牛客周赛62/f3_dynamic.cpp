#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;

/*
 * 动态主席树（支持修改的主席树）
 * 树套树
 * 树状数组+权值线段树
 *
 * 思考：
 * - 支持单点修改的前缀和不就是树状数组吗？
*/
const int MAX = 100005;
struct DynamicPersistentSegmentTree {
    // 注意: 这里定义的seg数组非常大，一定要将其分配在堆上
    // 即 auto tr = new DynamicPersistentSegmentTree(n, m, len);
    // 线段树的大小设置为 n * log(n)
    struct Node {
        // 左孩子和右孩子
        int left, right;
        // 节点值
        int val;
    } seg[MAX * 400];

    // n:原数组的长度
    int n;
    // 权值线段树的长度(离散化后数组的长度)
    int len;
    // 保存每个版本的根节点
    // 内置类型如果不加{}，会没有默认值
    int root[MAX]{};
    // 全局id分配器
    int tot;

    // 树状数组部分 开始
    // 记录需要计算的log棵树
    int l_cnt, r_cnt;
    // log(n)的长度
    int l_tmp[30]{}, r_tmp[30]{};
    static int lb(int x) {
        return x & -x;
    }
    // 树状数组部分 结束

    DynamicPersistentSegmentTree(int _n, int _len) : n(_n), len(_len), tot(0), l_cnt(0), r_cnt(0) {
        memset(root, 0, sizeof(root));
        memset(l_tmp, 0, sizeof(l_tmp));
        memset(r_tmp, 0, sizeof(r_tmp));
    }

    // 注意: 这里是引用&
    void _add(int& now, int l, int r, int pos, int val) {
        if (!now) {
            now = ++tot;
        }
        if (l == r) {
            seg[now].val += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            _add(seg[now].left, l, mid, pos, val);
        } else {
            _add(seg[now].right, mid + 1, r, pos, val);
        }
        seg[now].val = seg[seg[now].left].val + seg[seg[now].right].val;
    }

    /*
     * idx: 版本号(元素索引，从1开始)
     * pos: 权值
     * val: 加几
     */
    void add(int idx, int pos, int val) {
        for (int i = idx; i <= n; i += lb(i)) {
            _add(root[i], 1, len, pos, val);
        }
    }

    /*
     * l: 当前节点代表的区间左端点
     * r: 当前节点代表的区间右端点
     * k: 询问第几大
     * 此时需要遍历的数都已经保存在l_tmp和r_tmp中
     */
    int _ask(int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = (l + r) >> 1;
        int sum = 0;
        for (int i = 0; i < l_cnt; i++) sum -= seg[seg[l_tmp[i]].left].val;
        for (int i = 0; i < r_cnt; i++) sum += seg[seg[r_tmp[i]].left].val;
        if (k <= sum) {
            // 进入左子树
            for (int i = 0; i < l_cnt; i++) l_tmp[i] = seg[l_tmp[i]].left;
            for (int i = 0; i < r_cnt; i++) r_tmp[i] = seg[r_tmp[i]].left;
            return _ask(l, mid, k);
        } else {
            // 进入右子树
            for (int i = 0; i < l_cnt; i++) l_tmp[i] = seg[l_tmp[i]].right;
            for (int i = 0; i < r_cnt; i++) r_tmp[i] = seg[r_tmp[i]].right;
            return _ask(mid + 1, r, k - sum);
        }
    }

    int ask(int start, int end, int k) {
        memset(l_tmp, 0, sizeof(l_tmp));
        memset(r_tmp, 0, sizeof(r_tmp));
        l_cnt = 0, r_cnt = 0;
        for (int i = start - 1; i > 0; i -= lb(i)) {
            l_tmp[l_cnt++] = root[i];
        }
        for (int i = end; i > 0; i -= lb(i)) {
            r_tmp[r_cnt++] = root[i];
        }
        return _ask(1, len, k);
    }
};
// 以上是模板部分

// 询问部分
struct Operation {
    int op;
    int l, r, k;
    int idx, v;
} qs[MAX];
// 询问部分

int n, m, len;
void solve() {
    cin >> n >> m;
    vector<int> a(n);
    vector<int> ob;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ob.emplace_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        char opt;
        cin >> opt;
        if (opt == 'C') {
            qs[i].op = 0;
            cin >> qs[i].idx >> qs[i].v;
            qs[i].idx--;
            ob.emplace_back(qs[i].v);
        } else if (opt == 'Q') {
            qs[i].op = 1;
            cin >> qs[i].l >> qs[i].r >> qs[i].k;
            qs[i].l--, qs[i].r--;
        }
    }

    // 离散化
    sort(ob.begin(), ob.end());
    ob.erase(unique(ob.begin(), ob.end()), ob.end());
    auto get = [&](int x) {
        return lower_bound(ob.begin(), ob.end(), x) - ob.begin();
    };
    len = ob.size();
    // 离散化

    auto tr = new DynamicPersistentSegmentTree(n, len);
    // 这里为什么是i + 1 和 pos + 1
    // 因为这里是树状数组套线段树，其中：树状数组的索引和原数组a一一对应，树状数组的每个节点是一颗线段树的根节点
    // i是外层树状数组的索引，与a[i]对应，树状数组的
    // pos是内层权值线段树的索引
    for (int i = 0; i < n; i++) {
        int pos = get(a[i]);
        tr->add(i + 1, pos + 1, 1);
    }
    for (int i = 0; i < m; i++) {
        const auto& q = qs[i];
        if (q.op) {
            // 询问
            cout << ob[tr->ask(q.l + 1, q.r + 1, q.k) - 1] << "\n";
        } else {
            // 修改
            int pos = get(a[q.idx]);
            tr->add(q.idx + 1, pos + 1, -1);
            a[q.idx] = q.v;
            pos = get(a[q.idx]);
            tr->add(q.idx + 1, pos + 1, 1);
        }
    }
}

int main() {
    int T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}