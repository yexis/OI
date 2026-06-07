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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

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
    int n;
    vector<int> fa;
    DJ(int nn) {
        n = nn;
        fa.resize(n);
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
        if (rx == ry) return;
        fa[ry] = rx;
    }
    bool conn(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pii> > pr(4);
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--; 
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
        pr[w].push_back(pii(u, v));
    }

    vector<pii> res;
    auto check = [&](int x, int y) -> bool {
        res.clear();
        bool used_x = false, used_y = false;
        vector<int> last(n, -1);
        DJ dj(n);
        unordered_set<int> has;
        for (auto& [u, v] : pr[x]) {
            if (dj.conn(u, v)) continue;
            dj.merge(u, v);
            has.insert(u);
            has.insert(v);
            last[u] = res.size();
            last[v] = res.size();
            res.push_back(pii(u, v));
            used_x = true;
        }
        
        int del = -1;
        for (auto& [u, v] : pr[y]) {
            if (dj.conn(u, v)) {
                if (!used_y) {
                    del = last[u];
                    res.push_back(pii(u, v));
                    used_y = true;
                }
                continue;
            }
            dj.merge(u, v);
            has.insert(u);
            has.insert(v);
            last[u] = res.size();
            last[v] = res.size();
            res.push_back(pii(u, v));
            used_y = true;
        }
        if (has.size() == n && used_x && used_y) {
            for (int i = 0; i < res.size(); i++) {
                if (i == del) continue;
                auto u = res[i].first, v = res[i].second;
                cout << u + 1 << " " << v + 1 << "\n";
            }
            return true;
        }
        return false;
    };
    
    if (check(0, 1)) {
        return;
    }
    if (check(0, 2)) {
        return;
    }
    if (check(1, 2)) {
        return;
    }
    if (check(1, 0)) {
        return;
    }
    if (check(2, 0)) {
        return;
    }
    if (check(2, 1)) {
        return;
    }
    cout << -1 << "\n";
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









