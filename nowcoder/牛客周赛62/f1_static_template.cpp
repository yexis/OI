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
struct StaticPersistentSegmentTree {
    struct Node {
        int left, right;
        int val;
    } seg[N]{};
    // 全局编号
    int tot;
    int root[N]{};
    StaticPersistentSegmentTree() : tot(0) {

    }
    /*
     * pre: 上一个版本的线段树
     * now: 当前版本的线段树
     * l: 节点所表示的区间左端点
     * r:节点所表示的区间右端点
     * tot: 操作的位置
     * val: 变化量
     */
    void add(int pre, int& now, int l, int r, int pos, int val) {
        if (!now) {
            now = ++tot;
        }
        if (l == r) {
            seg[now].val = seg[pre].val + val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            seg[now].right = seg[pre].right;
            add(seg[pre].left, seg[now].left, l, mid, pos, val);
        } else {
            seg[now].left = seg[pre].left;
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
        int sum = seg[seg[now].left].val - seg[seg[pre].left].val;
        if (k <= sum) {
            return ask(seg[pre].left, seg[now].left, l, mid, k);
        } else {
            return ask(seg[pre].right, seg[now].right, mid + 1, r, k - sum);
        }
    }
};

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

    auto tr = new StaticPersistentSegmentTree();
    for (int i = 0; i < n; i++) {
        int p = get(a[i]);
        tr->add(tr->root[i], tr->root[i + 1], 1, len, p + 1, 1);
    }

    while (m--) {
        int l, r, k;
        std::cin >> l >> r;
        l--, r--;
        // 中位数是第几个
        k = (r - l + 1 + 1) / 2;
        std::cout << b[tr->ask(tr->root[l], tr->root[r + 1], 1, len, k) - 1] << "\n";
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