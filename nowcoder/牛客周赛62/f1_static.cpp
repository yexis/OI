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
int tot = 1;
struct Node {
    int left, right;
    int val;
} seg[N];

/*
 * id: 节点编号
 * l: 节点所表示的区间左端点
 * r: 节点所表示的区间右端点
 */
void build(int id, int l, int r) {
    if (l == r) {
        seg[id].val = 0;
        return;
    }
    int mid = (l + r) >> 1;
    seg[id].left = ++tot;
    seg[id].right = ++tot;
    build(seg[id].left, l, mid);
    build(seg[id].right, mid + 1, r);
    seg[id].val = seg[seg[id].left].val + seg[seg[id].right].val;
}

/*
 * pre: 上一个版本的线段树
 * now: 当前版本的线段树
 * l: 节点所表示的区间左端点
 * r:节点所表示的区间右端点
 * tot: 操作的位置
 * val: 变化量
 */
void add(int pre, int now, int l, int r, int pos, int val) {
    if (l == r) {
        seg[now].val = seg[pre].val + val;
        return;
    }
    int mid = (l + r) >> 1;
    seg[now].left = seg[pre].left;
    seg[now].right = seg[pre].right;
    if (pos <= mid) {
        seg[now].left = ++tot;
        add(seg[pre].left, seg[now].left, l, mid, pos, val);
    } else {
        seg[now].right = ++tot;
        add(seg[pre].right, seg[now].right, mid + 1, r, pos, val);
    }
    seg[now].val = seg[seg[now].left].val + seg[seg[now].right].val;
}

/*
 * pre: 上一个版本的线段树的根节点
 * now: 当前版本的线段树的根节点
 * l: 节点所表示的区间左端点
 * r: 节点所表示的区间右端点
 * k: 询问第k大的值
 */
int ask(int pre, int now, int l, int r, int k) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    // 判断左孩子的元素数量是否大于k，这里等于二分，因为线段树的父节点的两个孩子是均分的
    int d = seg[seg[now].left].val - seg[seg[pre].left].val;
    if (k <= d) {
        return ask(seg[pre].left, seg[now].left, l, mid, k);
    } else {
        return ask(seg[pre].right, seg[now].right, mid + 1, r, k - d);
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

    // root[tot]表示第i版线段树，第0版线段树为空树，便于求前缀和
    root[0] = 1;
    build(root[0], 1, len);

    for (int i = 0; i < n; i++) {
        int p = get(a[i]);
        root[i + 1] = ++tot;
        add(root[i], root[i + 1], 1, len, p + 1, 1);
    }

    while (m--) {
        int l, r, k;
        std::cin >> l >> r;
        l--, r--;
        // 中位数是第几个
        k = (r - l + 1 + 1) / 2;
        std::cout << b[ask(root[l], root[r + 1], 1, len, k) - 1] << "\n";
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