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
    string s, t; cin >> s >> t;

    int good_b = 0, good_r = 0, bad = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == 'B') good_b++;
        else if (s[i] == '1' && t[i] == 'R') good_r++;
        else bad++;
    }

    ll a = 0, b = 0;
    a += (bad + 1) / 2, b += bad / 2;
    int mi = min(good_r, good_b), mx = max(good_r, good_b);
    int rst = mx - mi;
    a += mi, b += mi;

    auto cal = [&]() {
        if (a > b) {
            cout << "Rainbow" << "\n";
        } else if (a < b) {
            cout << "Flower" << "\n";
        } else {
            cout << "Draw" << "\n";
        }
    };

    if (good_b == good_r) {
        cal();
        return;
    }

    if (bad & 1) {
        // F -> R
        if (good_b > good_r) a += rst / 2;
        else if (good_b < good_r) b += (rst + 1) / 2;
    } else {
        // R -> F
        if (good_b > good_r) a += (rst + 1) / 2;
        else if (good_b < good_r) b += rst / 2;
    }
    cal();
    
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









