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
const int mod = 998244353;
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
 * 题目：https://ac.nowcoder.com/acm/contest/139209/D
 * 本题本来是一个非常复杂的计算公式，但是拆位之后异或的这一项要么是0，要么是1，所以可以转化成统计深度和
 * 
 * 树形DP
 * 异或 拆位
 * 位运算 一定要拆位考虑
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> g[n]; for (int i = 0; i < n - 1; i++) { int u, v; cin >> u >> v; u--, v--; g[u].push_back(v), g[v].push_back(u); }

    // 结论：
    // 子树内的所有点 与 根节点u的 深度差 和： s - c * dep_u

    // cnt0: u的子树中权值的第d位是0的节点数
    // cnt1: u的子树中权值的第d位是1的节点数
    // dep: u的深度
    // dep0: u的子树中权值的第d位是0的节点的深度和
    // dep1: u的子树中权值的第d为是1的节点的深度和
    ll cnt0[n], cnt1[n], dep[n], dep0[n], dep1[n], tmp = 0;
    auto reset = [&]() -> void {
        tmp = 0; 
        for (int i = 0; i < n; i++) {
            dep[i] = 0, cnt0[i] = 0, cnt1[i] = 0, dep0[i] = 0, dep1[i] = 0;
        }
    };
    auto dfs = [&](auto&& dfs, int u, int o, int d, int x) -> void {
        if ((a[u] >> d) & 1) dep1[u] = dep[u], cnt1[u] += 1;
        else dep0[u] = dep[u], cnt0[u] += 1;;

        for (auto& v : g[u]) if (v != o) {
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u, d, x);
            cnt0[u] += cnt0[v];
            cnt1[u] += cnt1[v];
            dep0[u] += dep0[v];
            dep1[u] += dep1[v];
        }
        if (((a[u] >> d) & 1) ^ x) {
            tmp += dep0[u] - cnt0[u] * dep[u];
        } else {
            tmp += dep1[u] - cnt1[u] * dep[u];
        }
        
    };

    ll ans = 0;
    int B = 31;
    for (int d = 0; d <= B; d++) {
        reset();
        dfs(dfs, 0, -1, d, 0);
        ll x = tmp;

        reset();
        dfs(dfs, 0, -1, d, 1);
        ll y = tmp;

        if (x < y) {   
            ans += x % mod * power(2, d) % mod; ans %= mod;
        } else {
            ans += y % mod * power(2, d) % mod; ans %= mod;
        }
    }
    cout << ans << "\n";
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









