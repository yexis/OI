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
    int n, m, K; cin >> n >> m >> K;
    // n 行 m 列
    if (K > n * m) { cout << "No" << "\n"; return; }
    
    int grid[n][m]; for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) grid[i][j] = 0;

    int need = 0;
    for (int i = 1; i < n; i += 2) {
        for (int j = 1; j < m; j += 2) {
            need += 1;
            grid[i][j] = 1;
        }
    }
    if (K < need || K > n * m - need) { cout << "No" << "\n"; return; }
    
    // 一定可以
    bool rever = false;
    if (m * n - K < K) { K = m * n - K; rever = true; }
    
    K -= need;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0 && K) { 
            bool ok1 = true;
            if (i - 1 >= 0 && j - 1 >= 0) {
                int c = 0; 
                c += grid[i - 1][j] == 1;
                c += grid[i][j - 1] == 1;
                c += grid[i - 1][j - 1] == 1;
                if (c == 3) ok1 = false;
            }
            bool ok2 = true;
            if (i - 1 >= 0 && j + 1 < m) {
                int c = 0; 
                c += grid[i - 1][j] == 1;
                c += grid[i][j + 1] == 1;
                c += grid[i - 1][j + 1] == 1;
                if (c == 3) ok2 = false;
            }
            bool ok3 = true;
            if (i + 1 < n && j - 1 >= 0) {
                int c = 0; 
                c += grid[i + 1][j] == 1;
                c += grid[i][j - 1] == 1;
                c += grid[i + 1][j - 1] == 1;
                if (c == 3) ok3 = false;
            }
            bool ok4 = true;
            if (i + 1 < n && j + 1 < m) {
                int c = 0; 
                c += grid[i + 1][j] == 1;
                c += grid[i][j + 1] == 1;
                c += grid[i + 1][j + 1] == 1;
                if (c == 3) ok4 = false;
            }
            if (ok1 && ok2 && ok3 && ok4) { grid[i][j] = 1; K--; }
        }
    }
    // if (K) { cout << "No" << "\n"; return; }    

    cout << "Yes" << "\n";
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            if (!rever) cout << grid[i][j]; 
            else cout << !grid[i][j]; 
        }
        cout << "\n"; 
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









