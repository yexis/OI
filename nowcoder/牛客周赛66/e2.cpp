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
 * 链式并查集
*/

struct DJ {
    int n;
    vector<int> fa;
    vector<int> count;
    vector<double> sum;
    DJ(int nn, vector<double>& a) {
        n = nn;
        fa.resize(n);
        count.resize(n);
        sum.resize(n);
        iota(fa.begin(), fa.end(), 0);
        for (int i = 0; i < n; i++) {
            sum[i] = a[i];
            count[i] = 1;
        }
    }
    int lb(int x) {
        return x & -x;
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        if (rx > ry) {
            swap(rx, ry);
        }
        fa[rx] = ry;
        count[ry] += count[rx];
        sum[ry] += sum[rx];
    }
    double get_sum(int x) {
        int rx = find(x);
        return sum[rx];
    }
    int get_count(int x) {
        int rx = find(x);
        return count[rx];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    DJ dj(n, a);
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            while (l + 1 < n && l + 1 <= r) {
                dj.merge(l, l + 1);
                l = dj.find(l);
            }
        } else if(op == 2) {
            int x;
            cin >> x;
            x--;
            double ss = dj.get_sum(x);
            int cc = dj.get_count(x);
            cout << ss / cc << "\n";
        }
    }
}

int main() {
    cout << fixed << setprecision(15);
    solve();
    return 0;
}