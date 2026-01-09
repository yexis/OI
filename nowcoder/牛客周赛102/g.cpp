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
#define debug(x) cerr << (#x) << " = " << (x) << endl;
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

// 摩尔投票的线段树
// 基于pair<int, int> 的实现
typedef pair<int, int> pii;
pii operator+(const pii& a, const pii& b) {
    pii res = a;
    if (a.first == b.first) {
        res.second = a.second + b.second;
    } else if (a.second >= b.second) {
        res.second = a.second - b.second;
    } else {
        res.first = b.first;
        res.second = b.second - a.second;
    }
    return res;
};

static constexpr int N = 1000010;
pii f[N + 1];
void init() {
    for (int i = 0; i < N; i++) {
        f[i] = pii();
    } 
}

void add(int o, int l, int r, int i, int u) {
    if (l == r) {
        f[o] = pii(u, 1); 
        return;
    }
    int m = (l + r) >> 1;
    if (i <= m) {
        add(o * 2, l, m, i, u);
    } else {
        add(o * 2 + 1, m + 1, r, i, u);
    } 
    f[o] = f[o * 2] + f[o * 2 + 1];
}

pii ask(int o, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return f[o];
    }
    pii ans;
    int m = (l + r) >> 1;
    if (L <= m) {
        ans = ans + ask(o * 2, l, m, L, R);
    }
    if (R > m) {
        ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
    }
    return ans;
}

// 最大最小
struct SegmentTree {
    // 线段树
    int f[1000010]; // 最大值
    int g[1000010]; // 最小值

    SegmentTree() {
        memset(f, 0, sizeof(f));
        memset(g, INF, sizeof(g));
    }

    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            // 注意
            f[o] = max(f[o], u);
            g[o] = min(g[o], u);
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        f[o] = max(f[o * 2], f[o * 2 + 1]);
        g[o] = min(g[o * 2], g[o * 2 + 1]);
    }

    pii ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return pii(f[o], g[o]);
        }

        int ff = 0, gg = INF;
        int m = (l + r) >> 1;
        if (L <= m) {
            auto [lf, lg] = ask(o * 2, l, m, L, R);
            ff = max(ff, lf);
            gg = min(gg, lg);
        }
        if (R > m) {
            auto [lf, lg] = ask(o * 2 + 1, m + 1, r, L, R);
            ff = max(ff, lf);
            gg = min(gg, lg);
        }
        return pii(ff, gg);
    }
};

// 统计区间中小于等于k的元素个数
// 主席树模板 开始
int root[N];
struct PresidentTree {
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

    // 计算now版本的线段树中，小于等于k的元素数量
    int ask(int now, int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return seg[now].val;
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans += ask(seg[now].left, o * 2, l, m, L, R);
        }
        if (R > m) {
            ans += ask(seg[now].right, o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
};
// 主席树模板 结束


/*
1. 区间所有元素的频率为2
2. 区间最小值为1，最大值为N
*/

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& e : a) cin >> e;
    vector<vector<int>> qs(q); 
    for (auto& e : qs) {
        e.resize(2);
        cin >> e[0] >> e[1]; 
        e[0]--, e[1]--;
    }
    
    int block_size = ceil(n / sqrt(q * 2));

    // 记录所有元素出现的频率
    int cnt[250010]; memset(cnt, 0, sizeof(cnt));
    int ms[250010]; memset(ms, 0, sizeof(ms));
    int min_val = INF, max_val = 0;
    auto add = [&](int x) {
        int c1 = cnt[x];
        int c2 = ++cnt[x];
        if (c1 > 0) {
            ms[c1]--;
        }
        ms[c2]++;
        min_val = min(min_val, x);
        max_val = max(max_val, x);
    };

    vector<int> ans(q);
    
    struct Query {
        int bid;
        int l, r;
        int qid;
    };
    vector<Query> pr;
    for (int i = 0; i < q; i++) {
        auto& e = qs[i];
        int l = e[0], r = e[1] + 1, len = r - l;
        if (len & 1) {
            ans[i] = 0;
            continue;
        }
        if (r - l > block_size) {
            pr.emplace_back(l / block_size, l, r, i);
            continue;
        }
        for (int j = l; j < r; j++) {
            add(a[j]);
        }
        int lb = 1, rb = len / 2;
        if (min_val == lb && max_val == rb && 
            ms[2] == rb) {
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
        // 这里不能直接memset，因为如果全部是小区间
        // 理论复杂度会退化到 O(nq)
        for (int j = l; j < r; j++) {
            ms[cnt[a[j]]]--;
            if (--cnt[a[j]]) ms[cnt[a[j]]]++;
        }
        min_val = INF, max_val = 0;
    }

    sort(pr.begin(), pr.end(), [&](const auto& lhs, const auto& rhs) {
        if (lhs.bid == rhs.bid) {
            return lhs.r < rhs.r;
        }
        return lhs.bid < rhs.bid;
    });


    int r;
    for (int i = 0; i < pr.size(); i++) {
        auto& p = pr[i];
        int l0 = (p.bid + 1) * block_size;
        int lb = 1, rb = (p.r - p.l) / 2;
        if (i == 0 || p.bid > pr[i - 1].bid) {
            // 这里可以memset的原因是
            // 最多会跨越不同块 sqrt(n) 次
            r = l0;
            memset(cnt, 0, sizeof(cnt));
            memset(ms, 0, sizeof(ms));
            min_val = INF, max_val = 0;
        }
        for (; r < p.r; r++) {
            add(a[r]);
        }
        int tmp_min_val = min_val, tmp_max_val = max_val;
        for (int j = p.l; j < l0; j++) {
            add(a[j]);
        }
        if (min_val == lb && max_val == rb && 
            ms[2] == rb) {
            ans[p.qid] = 1;
        } else {
            ans[p.qid] = 0;
        }
        for (int j = p.l; j < l0; j++) {
            int c1 = cnt[a[j]];
            int c2 = --cnt[a[j]];
            ms[c1]--;
            if (c2 > 0) {
                ms[c2]++;
            }
        }
        min_val = tmp_min_val, max_val = tmp_max_val;
    }
    
    for (auto& e : ans) {
        if (e) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
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









