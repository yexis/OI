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

string sub(string low) {
    reverse(low.begin(), low.end());
    int carry = 1;
    for (int i = 0; i < low.size(); i++) {
        if (carry) {
            if (low[i] == '0') low[i] = '9', carry = 1;
            else low[i]--, carry = 0;
        }
    }
    reverse(low.begin(), low.end());
    return low;
}
void solve() {
    int n, m; cin >> n >> m;
    string sa, sb; cin >> sa; cin >> sb;
    int lc = lcm(n, m);
    
    string ta; for (int i = 0; i < lc / n; i++) ta += sa;
    string tb;  for (int i = 0; i < lc / m; i++) tb += sb;

    // assert(ta.sizze() == tb.size());
    string tc;
    int borrow = 0;
    for (int i = lc - 1; i >= 0; i--) {
        int da = ta[i] - '0';
        int db = tb[i] - '0';
        if (da - borrow < db) {
            int delta = 10 + da - borrow - db;
            tc += char('0' + delta);
            borrow = 1;
        } else {
            int delta = da - borrow - db;
            tc += char('0' + delta);
            borrow = 0;
        }
    }
    reverse(tc.begin(), tc.end());
    if (ta[0] < tb[0]) {
        tc = sub(tc);        
    }

    cout << lc << "\n";
    cout << tc << "\n";
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
// 123123123123
// 454545454545
// 668577668578

// 2222222
// 3333333
// 8888889









