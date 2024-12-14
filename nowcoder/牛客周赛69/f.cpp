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
 * 线段树
 * red
*/
struct Node {
    ll r, re, red, e, ed, d;
    Node() {
        r = re = red = e = ed = d = 0;
    }
};
Node operator+(const Node& a, const Node& b) {
    Node res;
    res.r = a.r + b.r;
    res.re = a.re + b.re + a.r * b.e;
    res.red = a.red + b.red + a.r * b.ed + a.re * b.d;
    res.e = a.e + b.e;
    res.ed = a.ed + b.ed + a.e * b.d;
    res.d = a.d + b.d;
    return res;
}

struct Seg {
    Node tr[800010];
    Seg() {
       
    }
    void add(int o, int l, int r, int i, char ch, int u) {
        if (l == r) {
            if (ch == 'r') {
                tr[o].r += u;
            } else if (ch == 'e') {
                tr[o].e += u;
            } else if (ch == 'd') {
                tr[o].d += u;
            }
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            add(o * 2, l, m, i, ch, u);            
        } else {
            add(o * 2 + 1, m + 1, r, i, ch, u);   
        }
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }   
    Node ask(int o, int l, int r, int L, int R) {
        if (L <= l && R >= r) {
            return tr[o];
        }
        Node ans;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans = ans + ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    } 
};


void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s;
    cin >> t;
    Seg gs, gt;
    for (int i = 0; i < n; i++) {
        gs.add(1, 1, n, i + 1, s[i], 1);
        gt.add(1, 1, n, i + 1, t[i], 1);
    }
    
    for (int i = 0; i < q; i++) {
        int idx;
        cin >> idx;
        idx--;
        char ch1 = s[idx], ch2 = t[idx];
        // 查询
        gs.add(1, 1, n, idx + 1, ch1, -1);
        gs.add(1, 1, n, idx + 1, ch2, 1);
        gt.add(1, 1, n, idx + 1, ch2, -1);
        gt.add(1, 1, n, idx + 1, ch1, 1);
        auto na = gs.ask(1, 1, n, 1, n);
        auto nb = gt.ask(1, 1, n, 1, n);
        cout << na.red - nb.red << "\n";
        // 赋值
        s[idx] = ch2, t[idx] = ch1;
    }
}

int main() {
    solve();
    return 0;
}