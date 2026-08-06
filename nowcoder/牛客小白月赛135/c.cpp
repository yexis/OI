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
    
    vector<int> a(n); for (auto& e : a) cin >> e;
    if (n == 1) { if (a[0] % 9 == 0) cout << 0 << "\n"; else cout << 9 - a[0] % 9 << "\n"; return; }
    
    // has 9
    for (int i = 0; i < n; i++) { if (a[i] % 9 == 0) { cout << 0 << "\n"; return; } }
    
    // has 2 * 3
    vector<int> b(n); for (int i = 0; i < n; i++) b[i] = a[i] % 3;
    vector<int> cnt(3); for (auto& e : b) cnt[e]++; if (cnt[0] >= 2) { cout << 0 << "\n"; return; }

    int ans = 8;
    vector<int> b2(n); for (int i = 0; i < n; i++) b2[i] = a[i] % 9;
    for (int i = 0; i < n; i++) ans = min(ans, 9 - b2[i]);

    if (cnt[0] == 1) {
        if (cnt[2]) ans = min(ans, 1);
        if (cnt[1]) ans = min(ans, 2);
    } else { // cnt[0] == 0
        if (cnt[2] >= 2) ans = min(ans, 2);
        else if (cnt[2] >= 1) {
            if (cnt[1]) ans = min(ans, 3);
        } else {
            if (cnt[1] >= 2) ans = min(ans, 4);
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









