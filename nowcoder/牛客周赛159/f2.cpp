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
 * 区间修改 + 单点查询
 * 静态询问（最后询问结果）：使用差分数组即可
 * 动态询问（任意时刻询问结果）：使用树状数组维护差分数组 good idea
*/
typedef long long K;
class BIT {
private:
	int n;
    vector<K> tr;
public: 
	BIT(int n) {
        this->n = n;
        tr.resize(n + 1);
	}
	int lowbit(int x) {
		return x & -x;
	}
	void add(int x, K u) {
		for (int i = x; i <= n; i += lowbit(i)) {
            tr[i] += (u + mod); tr[i] %= mod;
		}
	} 
    // BIT表示差分数组时
    // upd: 将区间[l, r]整体添加u
    void add_lr(int l, int r, K u) {
        add(l, u);
        add(r + 1, -u);
    }
	K ask(int x) {
		K ans = 0;
        if (x == 0) return 0;
		for (int i = x; i > 0; i -= lowbit(i)) {
			ans += (tr[i] + mod); ans %= mod;
		}
		return ans;
	}
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int tot = 0;

    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) { int u, v; cin >> u >> v; u--, v--; g[u].push_back(v); g[v].push_back(u); }

    vector<ll> P(n + 1); P[0] = 1; for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % mod;

    vector<int> dep(n);
    // 数的dfs序 L表示进入dfs序，R表示离开dfs序
  	// dfs序从 1 开始，[ L[u], R[u] ] 表示节点u的子树
    vector<int> L(n), R(n);
    vector<ll> M(n);
    auto dfs = [&](auto&& dfs, int u, int o, ll mask) -> void {
        if (s[u] == '1') M[u] = mod_add(mask, P[dep[u]]);
        else M[u] = mask;

        L[u] = ++tot;

        for (auto& v : g[u]) if (v != o) {
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u, M[u]);
        }
        R[u] = tot;
    };
    dfs(dfs, 0, -1, 0);

    // 按照 L 构建线段树 [1, n]
    BIT bit(n + 1);

    for (int i = 0; i < n; i++) if (s[i] == '1') bit.add_lr(L[i], R[i], P[dep[i]]);

    while (q--) {
        char op; cin>> op;
        if (op == 'F') {
            int u; cin >> u; u--;
            s[u] ^= 1;
            if (s[u] == '1') bit.add_lr(L[u], R[u], P[dep[u]]); // 0 -> 1
            else bit.add_lr(L[u], R[u], -P[dep[u]]);            // 1 -> 0
        } else if (op == 'Q') {
            int u; cin >> u; u--;
            int pos = L[u];
            ll ans = bit.ask(pos);
            cout << ans << "\n";
        }
    }
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









