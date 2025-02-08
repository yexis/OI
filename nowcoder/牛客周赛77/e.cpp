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
 * 
*/

struct Node {
    ll one;
    ll zero0;
    ll zero1;
    ll pre_zero0;
    ll pre_zero1;
    ll v;
    ll len;
    Node() {
        one = 0;
        v = 0;
        len = 0;
        zero0 = 0;
        zero1 = 0;
        pre_zero0 = 0;
        pre_zero1 = 0;
        
    }
};
Node operator+(const Node& a, const Node& b) {
    Node res;
    res.one = a.one + b.one;
    res.len = a.len + b.len;
    res.zero0 = b.zero0 + (b.one > 0 ? 0 : a.zero0);
    res.zero1 = b.zero1 + (b.one > 0 ? a.zero0 + a.zero1 : a.zero1);
    res.pre_zero0 = a.pre_zero0 + (a.one > 0 ? 0 : b.pre_zero0);
    res.pre_zero1 = a.pre_zero1 + (a.one > 0 ? b.pre_zero0 + b.pre_zero1 : b.pre_zero1);

    res.v = a.v + b.v + (a.one + a.zero1) * b.len + a.zero0 * (b.one + b.pre_zero1);
    return res;
}

struct Seg {
    Node tr[800010]{};
    Seg() {

    }
    void add(int o, int l, int r, int i, int u) {
        if (l == r) {
            tr[o].len = 1;
            tr[o].v = (u == 1);
            tr[o].one = (u == 1);
            tr[o].zero0 = (u == 0);
            tr[o].zero1 = (u == 0);
            tr[o].pre_zero0 = (u == 0);
            tr[o].pre_zero1 = (u == 0);
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, u);
        } else {
            add(o * 2 + 1, m + 1, r, i, u);
        }
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }

    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        Node res;
        int m = (l + r) >> 1;
        if (L <= m) {
            res = res + ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            res = res + ask(o * 2 + 1, m + 1, r, L, R);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    Seg seg;
    for (int i = 0; i < n; i++) {
        int v = (s[i] == '1' ? 1 : 0);
        seg.add(1, 1, n, i + 1, v);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        Node ans = seg.ask(1, 1, n, l + 1, r + 1);
        cout << ans.v << "\n";
    }

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}