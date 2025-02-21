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
 * 动态开点线段树
*/
constexpr static int N = 7000000;
struct Node {
    int v;
    Node() : v(0) {}
    Node(int vv) : v(vv) {}
    Node operator+(const Node& b) {
        Node res(0);
        Node a = *this;
        res.v = a.v + b.v;
        return res;
    } 
};

struct SegTree {
    int tot;
    Node tr[N];
    // 左孩子
    int lc[N];
    // 右孩子
    int rc[N];
    SegTree() {
        tot = 0;
    }
    Node e() {
        return Node(0);
    }
    void add(int& o, int l, int r, int i, int u) {
        if (!o) o = ++tot;
        if (l == r) {
            tr[o].v += u;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(lc[o], l, m, i, u);
        } else {
            add(rc[o], m + 1, r, i, u);
        }
        tr[o] = tr[lc[o]] + tr[rc[o]];
    }
    Node ask(int o, int l, int r, int L, int R) {
        if (!o) return e();
        if (L <= l && R >= r) {
            return tr[o];
        }
        Node ans(0);
        int m = (l + r) >> 1;
        if (L <= m) {
            ans = ans + ask(lc[o], l, m, L, R);
        } 
        if (R > m) {
            ans = ans + ask(rc[o], m + 1, r, L, R);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) {
        cin >> e;
    }

    int mi = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end()) + 1;

    const int N = 1e9;
    int root = 0;
    SegTree seg;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll lt = seg.ask(root, mi, mx, 1, a[i] + 1).v;
        ans += i - lt;
        seg.add(root, mi, mx, a[i] + 1, 1);
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}