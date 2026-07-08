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

void solve() {
    int n, m; cin >> n >> m;
    int a, b; cin >> a >> b;
    vector<string> g(n); for(auto& s : g) cin >> s;

    int wall[n + 1][m + 1]; for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) wall[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c = g[i - 1][j - 1];
            wall[i][j] = wall[i][j - 1] + wall[i - 1][j] - wall[i - 1][j - 1] + (c == '#');
        }
    }

    int start_i, start_j;
    int end_i, end_j;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (g[i][j] == 'S') start_i = i, start_j = j;
        if (g[i][j] == 'E') end_i = i, end_j = j;
    }

    auto valid = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    int arrived[n][m]; for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) arrived[i][j] = 0;
    auto dfs = [&](auto&& dfs, int i, int j) -> bool {
        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (!valid(ni, nj)) continue;
            if (!valid(ni + a - 1, nj)) continue;
            if (!valid(ni, nj + b - 1)) continue;
            if (!valid(ni + a - 1, nj + b - 1)) continue;

            int nni = ni + a - 1, nnj = nj + b - 1;
            if (wall[nni + 1][nnj + 1] - wall[nni + 1][nj] - wall[ni][nnj + 1] + wall[ni][nj] > 0) continue; 
            if (arrived[ni][nj]) continue;
            arrived[ni][nj] = 1;
            if (ni == end_i && nj == end_j) return true;
            dfs(dfs, ni, nj);
        }
        return false;
    };
    arrived[start_i][start_j] = 1;
    dfs(dfs, start_i, start_j);

    if (arrived[end_i][end_j]) cout << "YES" << "\n";
    else cout << "NO" << "\n"; 
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









