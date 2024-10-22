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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


/*
 * 主席树
 * 可持久化线段树
 * 静态主席树
*/

const int N = 2e6 + 1000;
int root[N];
// 全局编号
int idx = 1;
struct Node {
    // 当前节点的左右孩子
    int left, right;
    // 当前节点所代表的区间左右端点
    int l, r;
    // 节点值
    int val;
} seg[N];


/*
 * id: 节点编号
 * l: 区间左右端点已经包含在节点中
 * r: 区间左右端点已经包含在节点中
 */
void build(int id) {
    if (seg[id].l == seg[id].r) {
        seg[id].val = 0;
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    // 生成左右孩子节点
    seg[id].left = ++idx;
    seg[id].right = ++idx;
    // 设置左右孩子代表区间的左右端点
    seg[seg[id].left].l = seg[id].l;
    seg[seg[id].left].r = mid;
    seg[seg[id].right].l = mid + 1;
    seg[seg[id].right].r = seg[id].r;
    // 递归
    build(seg[id].left);
    build(seg[id].right);
    seg[id].val = seg[seg[id].left].val + seg[seg[id].right].val;
}

/*
 * pre: 上一个版本的线段树
 * now: 当前版本的线段树
 * l: 区间左右端点已经包含在节点中
 * r: 区间左右端点已经包含在节点中
 * pos: 操作的位置
 * val: 变化量
 */
void add(int pre, int now, int pos, int val) {
    if (seg[now].l == seg[now].r) {
        seg[now].val = seg[pre].val + val;
        return;
    }
    int mid = (seg[now].l + seg[now].r) >> 1;
    seg[now].left = seg[pre].left;
    seg[now].right = seg[pre].right;
    if (pos <= mid) {
        seg[now].left = ++idx;
        seg[seg[now].left].l = seg[now].l;
        seg[seg[now].left].r = mid;
        add(seg[pre].left, seg[now].left, pos, val);
    } else {
        seg[now].right = ++idx;
        seg[seg[now].right].l = mid + 1;
        seg[seg[now].right].r = seg[now].r;
        add(seg[pre].right, seg[now].right, pos, val);
    }
    seg[now].val = seg[seg[now].left].val + seg[seg[now].right].val;
}

/*
 * pre: 上一个版本的线段树的根节点
 * now: 当前版本的线段树的根节点
 * l: 区间左右端点已经包含在节点中
 * r: 区间左右端点已经包含在节点中
 * k: 询问第k大的值
 */
int ask(int pre, int now, int k) {
    if (seg[now].l == seg[now].r) {
        return seg[now].l;
    }
    // 这里的mid已经没用
    // int mid = (seg[now].l + seg[now].r) >> 1;

    // 判断左孩子的元素数量是否大于k，这里等于二分，因为线段树的父节点的两个孩子是均分的
    int d = seg[seg[now].left].val - seg[seg[pre].left].val;
    if (k <= d) {
        return ask(seg[pre].left, seg[now].left, k);
    } else {
        return ask(seg[pre].right, seg[now].right, k - d);
    }
}
// 以上是主席树模板

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    // 对b的值域进行离散化
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto get = [&](int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin();
    };
    int len = b.size();

    // root[i]表示第i版线段树，第0版线段树为空树，便于求前缀和
    root[0] = 1;
    // 每次创建根节点时，设置区间左右端点
    seg[root[0]].l = 1;
    seg[root[0]].r = len;
    build(root[0]);

    for (int i = 0; i < n; i++) {
        int p = get(a[i]);
        root[i + 1] = ++idx;
        // 每次创建根节点时，设置区间左右端点
        seg[root[i + 1]].l = 1;
        seg[root[i + 1]].r = len;
        add(root[i], root[i + 1], p + 1, 1);
    }

    while (m--) {
        int l, r, k;
        std::cin >> l >> r;
        l--, r--;
        // 中位数是第几个
        k = (r - l + 1 + 1) / 2;
        std::cout << b[ask(root[l], root[r + 1], k) - 1] << "\n";
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