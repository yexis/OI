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
 * 懒加载线段树
 * 线段树二分 统计区间最小值 和 最小值的数量
 * 
*/

struct Node {
    int mi; // 维护区间中最小的数
    int c;  // 维护区间中最小的数的个数
    int z;  // lazy标记
    Node() {
        mi = 0;
        c = 0;
        z = 0;
    }
    Node(int x) {
        mi = x;
        c = 1;
        z = 0;
    }
    Node operator+(const Node& b) const {
        Node res;
        if (mi < b.mi) {
            res.mi = mi;
            res.c = c;
        } else if (mi > b.mi) {
            res.mi = b.mi;
            res.c = b.c;
        } else {
            res.mi = mi;
            res.c = c + b.c;
        }
        return res;
    }
};

struct Seg {
    vector<int> a;
    Node tr[800010];
    Seg(vector<int> _a) {
        a = _a;
    }
    void build(int o, int l, int r) {
        if (l == r) {
            tr[o] = Node(a[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(o * 2, l, m);
        build(o * 2 + 1, m + 1, r);
        push_up(o);
    }
    void push_down(int o) {
        if (tr[o].z) {
            tr[o * 2].mi += tr[o].z;
            tr[o * 2].z += tr[o].z;

            tr[o * 2 + 1].mi += tr[o].z;
            tr[o * 2 + 1].z += tr[o].z;
            tr[o].z = 0;
        }
    }
    void push_up(int o) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (L <= l && R >= r) {
            tr[o].mi += u;
            tr[o].z += u;
            return;
        }

        push_down(o);
        int m = (l + r) >> 1;
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        push_up(o);
    }
    // 返回 [L, R]中第一个0的位置
    int ask(int o, int l, int r, int L, int R) {
        if (l > R || r < L || tr[o].mi > 0) {
            return -1;
        }
        if (l == r) return l;

        push_down(o);
        int m = (l + r) >> 1;
        int idx = ask(o * 2, l, m, L, R);
        if (idx < 0) {
            return ask(o * 2 + 1, m + 1, r, L, R);
        }
        return idx;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& e : a) cin >> e;

    ll cnt = 0, sum = 0;
    cnt = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cnt += a[i] - a[i - 1];
        }
        sum += a[i];
    }

    if (m < cnt || m > sum) {
        cout << -1 << "\n";
        return;
    }

    // m >= cnt
    vector<pii> ops;

    Seg seg(a);
    seg.build(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int c = 0;
        if (i == 0) {
            c = max(a[0], c);
        } else {
            c = max(a[i] - a[i - 1], c);
        }
        while (c--) {
            int j;
            int idx = seg.ask(1, 0, n - 1, i, n - 1);
            if (idx < 0) {
                j = n - 1;
            } else {
                j = idx - 1;
            }
            ops.push_back(pii(i, j));
            seg.add(1, 0, n - 1, i, j, -1);
        }
    }
    
    int delta = m - cnt;
    vector<pii> ops2;
    for (auto [l, r] : ops) {
        while (l < r && delta) {
            ops2.push_back(pii(l, l));
            l++;
            delta--;
        }
        ops2.push_back(pii(l, r));
    }
    for (auto& [l, r] : ops2) {
        cout << l + 1 << " " << r + 1 << "\n";
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









