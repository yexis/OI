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
// 1: 结尾的最大值
// 2: 内部的最大值
// 3: 和

// TLE
using ll = long long;
const int mod = 1e9 + 7;
struct Node {
    vector<ll> v;
    Node() {
        v.assign(4, 0);
    }
    Node(int a, int b, int c, int d) {
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(c);
        v.emplace_back(d);
    }
    Node operator+ (const Node& r) {
        const Node& l = *this;
        Node res;
        res.v[0] = max(l.v[0], l.v[3] + r.v[0]);
        res.v[1] = max(r.v[1], r.v[3] + l.v[1]);
        res.v[2] = max(max(l.v[2], r.v[2]), l.v[1] + r.v[0]);
        res.v[3] = l.v[3] + r.v[3];
        return res;
    }
    ll get() {
        return v[2];
    }
};

const ll inf = 1e18;
constexpr static int maxn = 2000010;
vector<Node> ff;
vector<Node> gg;
void init(int n) {
    ff = vector<Node>(4 * n + 10);
    gg = vector<Node>(4 * n + 10);
}
void build(vector<Node>& f, vector<int>& a, int o, int l, int r) {
    if (l == r) {
        int v = a[l - 1];
        int mx = max(a[l - 1], 0);
        f[o] = Node{v, mx, mx, v};
        return;
    }
    int m = (l + r) >> 1;
    build(f, a, o * 2, l, m);
    build(f, a, o * 2 + 1, m + 1, r);
    f[o] = f[o * 2] + f[o * 2 + 1];
}

Node ask(vector<Node>& f, int o, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return f[o];
    }
    Node ans;
    int m = (l + r) >> 1;
    if (L <= m) {
        ans = ans + ask(f, o * 2, l, m, L, R);
    }
    if (R > m) {
        ans = ans + ask(f, o * 2 + 1, m + 1, r, L, R);
    }
    return ans;
}

int main() {

    int n;
    cin >> n;
    init(n);

    vector<int> a(n);
    vector<int> ra(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(ff, a, 1, 1, n);

    for (int i = 0; i < n; i++) {
        ra[i] = -a[i];
    }
    build(gg, ra, 1, 1, n);

    int q;
    cin >> q;
    vector<pair<int, int>> qs(q);
    for (ll i = 0; i < q; ++i) {
        cin >> qs[i].first >> qs[i].second;

    }
    for (auto& [c, d] : qs) {
        auto x = ask(ff, 1, 1, n, c, d);
        auto y = ask(gg, 1, 1, n, c, d);
        ll ans = max(x.get(), y.get());
        cout << ans <<  "\n";
    }

    return 0;
}