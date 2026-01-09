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
 * 分拆数
 * 互异分拆数
*/

// 互异分拆数: 自然数 n 的各部分互不相同的分拆方法数
// pd(n,k) = pd(n - k, k - 1) + pd(n - k, k)
ll pd[100005][500];
auto __ = []() -> int {
    memset(pd, 0, sizeof(pd));
    pd[0][0] = 1;
    for (int i = 1; i <= 100000; i++) {
        for (int k = 1; k <= 450; k++) {
            if (i - k >= 0) {
                pd[i][k] = pd[i - k][k - 1] + pd[i - k][k];
                pd[i][k] %= mod;
            }
        }
    }
    return 0;
}();
ll split_numbers_different(int n, int k) {
    return pd[n][k];
}

void solve() {
    int n, m; cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= 450; i++) {
        if (i * (i + 1) / 2 > n) break;
        ans += pd[n][i] * m % mod * power(m - 1, i - 1) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
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









