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
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int sum = 0;
    int n0 = 0, nm = 0;
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (int j = 0; j < m; j++) {
            sm += g[i][j] == '1';
        }
        n0 += sm == 0;
        nm += sm == m;
        row[i] = sm;
        sum += sm;
    }

    if (sum == 0) {
        cout << "YES" << "\n";
        return;
    }
    int m0 = 0, mn = 0;
    for (int j = 0; j < m; j++) {
        int sm = 0;
        for (int i = 0; i < n; i++) {
            sm += g[i][j] == '1';
        }
        m0 += sm == 0;
        mn += sm == n;
        col[j] = sm;
    }

    if (nm == 2 && nm + n0 == n) {
        cout << "YES" << "\n";
        return;
    }
    if (mn == 2 && mn + m0 == m) {
        cout << "YES" << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '0') {
                if (row[i] == m - 1 && col[j] == n - 1 && row[i] + col[j] == sum) {
                    cout << "YES" << "\n";
                    return;
                }
            }
        }
    }
    
    cout << "NO" << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









