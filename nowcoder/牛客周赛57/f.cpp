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

/*
 * 
*/

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

void solve() {

}

// 线段树
int f[500010];
// 原数组
int a[100010];

void init() {
    memset(f, INF, sizeof(f));
}

void add(int o, int l, int r, int i, int u) {
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
    f[o] = min(f[o * 2], f[o * 2 + 1]);
}

int ask(int o, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return f[o];
    }

    int ans = INF;
    int m = (l + r) >> 1;
    if (L <= m) {
        ans = min(ans, ask(o * 2, l, m, L, R));
    }
    if (R > m) {
        ans = min(ans, ask(o * 2 + 1, m + 1, r, L, R));
    }
    return ans;
}

int main() {
    init();

    int n;
    cin >> n;
    vector<int> g[n];
    vector<multiset<int>> ms(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            g[i].push_back(x);
            ms[i].insert(x);
        }
        add(1, 1, n, i + 1, *ms[i].begin());
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int ii, jj, x;
            cin >> ii >> jj >> x;
            ii--, jj--;
            int val = g[ii][jj];
            ms[ii].erase(ms[ii].find(val));
            ms[ii].insert(x);
            int mi = *ms[ii].begin();
            add( 1, 1, n, ii + 1, mi);
        } else if (op == 2) {
            int y;
            cin >> y;
            y--;
            cout << ask(1, 1, n, 1, y + 1) << "\n";
        }
    }
    return 0;
}