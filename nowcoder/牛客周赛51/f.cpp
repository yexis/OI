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
using pii = pair<ll, ll>;

// 0：开头的最大值
// 1: 开头的最小值
// 2: 结尾的最大值
// 3: 结尾的最小值
// 4: 内部的最大值
// 5: 内部的最小值
// 6: 和



// TLE
using ll = long long;
const int mod = 1e9 + 7;
struct Node {
    vector<ll> v;
    Node() {
        v.assign(7, 0);
    }
    Node(ll& a, ll& b, ll& c, ll& d, ll& e, ll& f, ll& g) {
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(c);
        v.emplace_back(d);
        v.emplace_back(e);
        v.emplace_back(f);
        v.emplace_back(g);
    }
    Node operator+ (const Node& r) {
        const Node& l = *this;
        Node res;
        res.v[0] = max(l.v[0], l.v[6] + r.v[0]);
        res.v[1] = min(l.v[1], l.v[6] + r.v[1]);

        res.v[2] = max(r.v[2], r.v[6] + l.v[2]);
        res.v[3] = min(r.v[3], r.v[6] + l.v[3]);

        res.v[4] = max(max(l.v[4], r.v[4]), l.v[2] + r.v[0]);
        res.v[5] = min(min(l.v[5], r.v[5]), l.v[3] + r.v[1]);
        res.v[6] = l.v[6] + r.v[6];
        return res;
    }

    ll get() {
        return max({abs(v[0]), abs(v[1]), abs(v[2]), abs(v[3]), abs(v[4]), abs(v[5])});
    }
};

const ll inf = 1e18;
constexpr static int maxn = 2000010;
Node f[maxn] = {};
void build(vector<int>& a, int o, int l, int r) {
    if (l == r) {
        ll v = a[l - 1];
        ll mx = max(v, 0ll);
        ll mi = min(v, 0ll);
        f[o] = Node(mx, mi, mx, mi, v, v, v);
        return;
    }
    int m = (l + r) >> 1;
    build(a, o * 2, l, m);
    build(a, o * 2 + 1, m + 1, r);
    f[o] = f[o * 2] + f[o * 2 + 1];
}

void add(int o, int l, int r, int i, Node& u) {
    if (l == r) {
        f[o] = u;
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

Node ask(int o, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return f[o];
    }
    Node ans{0ll, 0ll, 0ll, 0ll, -inf, inf, 0};
    int m = (l + r) >> 1;
    if (L <= m) {
        ans = ans + ask(o * 2, l, m, L, R);
    }
    if (R > m) {
        ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(a, 1, 1, n);

    int q;
    cin >> q;
    vector<pair<int, int>> qs(q);
    for (ll i = 0; i < q; ++i) {
        cin >> qs[i].first >> qs[i].second;

    }
    for (auto& [c, d] : qs) {
        auto ans = ask(1, 1, n, c, d);
        cout << ans.get() <<  "\n";
    }

    return 0;
}