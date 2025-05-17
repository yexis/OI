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
 * 
*/

void solve() {
    int n, m;
    cin >> n >> m;
    bool exchange = false;
    if (n > m) {
        exchange = true;
        swap(n, m);
    }
    int sum = 0;
    for (int i = 1; i <= n + m; i++) {
        sum ^= i;
    }
    if (sum != 0) {
        cout << -1 << "\n";
        return;
    }
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        g[i][i] = i;
    }
    int pre = 0;
    for (int j = n + 1; j < m; j++) {
        g[n][j] = j;
    }
    for (int i = 1; i < n; i++) {
        g[i][m] = i ^ (m + i);
        pre ^= g[i][m];
    }
    g[n][m] = m ^ pre;
    if (!exchange) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << g[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << g[j][i] << " ";
            }
            cout << "\n";
        }
    }

    // n < m;

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









