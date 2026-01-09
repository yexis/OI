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
using arr = array<ll, 3>;
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

struct DJ {
    vector<int> fa;
    vector<int> ra;
    vector<int> cnt; // 每个连通分量的大小
  	int v; // 联通块的总数
    int n;
    DJ(int _n) {
        n = _n;
      	v = _n;
        fa.resize(n);
        ra.resize(n);
        cnt.resize(n);
        iota(fa.begin(), fa.end(), 0);
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
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
      	v--;
        fa[ry] = rx;
        cnt[rx] += cnt[ry];
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }

  	bool conn(int x, int y) {
    	return find(x) == find(y);
    }

    void add() {
        n++;
        v++;
        fa.resize(n);
        fa[n - 1] = n - 1;
    }
};

void solve() {
    int m = 0;
    int n, q; cin >> n >> q;
    vector<pll> po(n);
    for (int i = 0; i < n; i++) {
        cin >> po[i].first >> po[i].second;
    }
    m = po.size();

    vector<arr> qs(q);
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            qs[i] = {op, x, y};
            m++;
        } else if (op == 2) {
            qs[i] = {op, 0, 0};
        } else if (op == 3) {
            int u, v; cin >> u >> v;
            qs[i] = {op, u, v};
        }
    }

    // cout << "m:" << m << "\n";
    DJ dj(m);

    set<arr> A;
    for (int i = 0; i < n; i++) {
        auto [x1, y1] = po[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = po[j];
            ll dist = abs(x1 - x2) + abs(y1 - y2);
            A.insert({dist, i, j});
        }
    }

    for (int i = 0; i < q; i++) {
        auto [op, x1, y1] = qs[i];
        if (op == 1) {
            for (int j = 0; j < po.size(); j++) {
                auto [x2, y2] = po[j];
                ll dist = abs(x1 - x2) + abs(y1 - y2);
                A.insert({dist, (ll)po.size(), j});
            }
            po.emplace_back(x1, y1);
        } else if (op == 2) {
            
            auto [k, no1, no2] = *A.begin();
            while (A.size()) {
                auto [k1, u, v] = *A.begin();
                if (k1 > k) break;
                dj.merge(u, v);
                A.erase(A.begin());
            }
            cout << k << "\n";
        } else if (op == 3) {
            int u = x1, v = y1;
            u--, v--;
            if (dj.conn(u, v)) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









