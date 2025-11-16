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
    int n;
    vector<int> fa;
    vector<ll> weight;
    DJ(int _n) {
        n = _n;
        fa.resize(n);
        weight.resize(n, 0);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (x != fa[x]) {
            // 这里注意：这里先保存x的父亲
            // 因为递归完后，x的父亲可能会变
            int ori = fa[x];
            fa[x] = find(fa[x]);
            // 更新weight
            weight[x] += weight[ori];
        }
        return fa[x];
    }
    // x - y = v
    // x -> y 默认将y设置成x的父亲
    ll merge(int x, int y, ll v) {
        int rx = find(x);
        int ry = find(y);
        ll nd = weight[y] + v - weight[x];
        // 如果已经处于相同联通块，说明ru == rv
        // 那么weight[x]必须是0
        if (rx == ry) {
            if (nd != 0) return 0;
            return v;
        }
    
        fa[rx] = ry;
        // 更新 weight
        weight[rx] = nd;
        return v;
    }
    bool conn(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    DJ dj(n + 4);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            ll u, v, k; cin >> u >> v >> k;
            int ret = dj.merge(u, v, k);
            if (ret) {
                cout << "OK" << "\n";
            } else {
                cout << "CONTRADICTION" << "\n";
            }
        } else if (op == 2) {
            ll u, k; cin >> u >> k;
            // 赋值操作
            // 就是将节点u与虚拟节点n+1合并
            // 且 dis[u] = k;
            int ret = dj.merge(u, n + 1, k);
            if (ret) {
                cout << "OK" << "\n";
            } else {
                cout << "CONTRADICTION" << "\n";
            }
        } else if (op == 3) {
            ll u, v; cin >> u >> v;
            if (dj.conn(u, v)) {
                cout << dj.weight[u] - dj.weight[v] << "\n";
            } else {
                cout << "UNKNOWN" << "\n";
            }

        }
    }  
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









