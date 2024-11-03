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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
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
 *
*/

set<ll> A;
set<ll> B;
set<array<ll, 4>> st;
void cal2(int x1, int y1, int x2, int y2) {
    // dy / dx
    ll dx = x2 - x1;
    ll dy = y2 - y1;

    // 垂直，中线为水平线
    if (dx == 0) {
        B.insert((y1 + y2) / 2);
        return;
    }
    // 水平，中线为垂直线
    if (dy == 0) {
        A.insert((x1 + x2) / 2);
        return;
    }
    if (dy < 0) {
        dx = -dx, dy = -dy;
    }
    ll g = gcd(abs(dx), abs(dy));
    dx /= g, dy /= g;

    ll c = dx, d = y1 * dx - x1 * dy;
    g = gcd(abs(c), abs(d));
    c /= g, d /= g;

    st.insert({dy, dx, d, c});
}

void cal(int x1, int y1, int x2, int y2) {
    // dy / dx
    ll dx = x2 - x1;
    ll dy = y2 - y1;

    // 垂直，中线为水平线
    if (dx == 0) {
        B.insert((y1 + y2) / 2);
        return;
    }
    // 水平，中线为垂直线
    if (dy == 0) {
        A.insert((x1 + x2) / 2);
        return;
    }

    // 有斜率
    ll mdy = -dx, mdx = dy;
    if (mdy < 0) {
        mdx = -mdx, mdy = -mdy;
    }
    ll g = gcd(abs(mdx), abs(mdy));
    mdx /= g, mdy /= g;

    ll xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
    ll c = mdy, d = ym * mdx - xm * mdy;
    g = gcd(abs(c), abs(d));
    c /= g, d /= g;

    st.insert({mdy, mdx, c, d});
}

void solve() {
    int n;
    cin >> n;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
    }
    vector<pll> pr;
    for (int i = 0; i < n; i++) {
        pr.emplace_back(X[i] * 2, Y[i] * 2);
    }

    A.clear();
    B.clear();
    st.clear();
    for (int i = 0; i < n; i++) {
        ll x1 = pr[i].first, y1 = pr[i].second;
        for (int j = i + 1; j < n; j++) {
            ll x2 = pr[j].first, y2 = pr[j].second;
            cal(x1, y1, x2, y2);
        }
    }

    cout << A.size() + B.size() + st.size() << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}