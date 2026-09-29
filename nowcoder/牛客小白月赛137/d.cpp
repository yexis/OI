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
    int n; cin >> n;
    if (n <= 5) {
        cout << "No" << "\n";
        return;
    }
    // 1 2 3 4 5 6 
    cout << "Yes" << "\n";
    set<int> st1, st2; for (int i = 1; i <= n; i++) { st1.insert(i); st2.insert(i); }

    vector<int> g[2]; g[0].resize(n); g[1].resize(n);

    int x = 2, idx = 0;
    while (x <= n) {
        if (x != 6) {
            g[0][idx++] = x;
            st1.erase(x);
        }
        x += 2;
    }
    g[0][idx++] = 6; g[0][idx] = 3;
    st1.erase(6); st1.erase(3);
    
    g[1][idx++] = 3; g[1][idx++] = 6;
    st2.erase(6); st2.erase(3);
    x = 2;
    while (x <= n && idx < n) {
        if (x != 6) {
            g[1][idx++] = x;
            st2.erase(x);
        }
        x += 2;
    }
    for (int i = 0; i < n; i++) {
        if (g[0][i] == 0) {
            g[0][i] = *st1.begin(); 
            st1.erase(st1.begin());
        }
        if (g[1][i] == 0) {
            g[1][i] = *st2.begin();
            st2.erase(st2.begin());
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
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









