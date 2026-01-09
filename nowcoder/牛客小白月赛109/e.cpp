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

ll inv(ll x) {
    return power(x, mod - 2);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& e : a) cin >> e;

    ll ans = 0;
    ll f0 = 0, f1 = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] % 25 == 0) {
            a[i] /= 25;
        }
        bool inc5 = (a[i] % 5 == 0);
        
        ll g0 = f0, g1 = f1;
        if (inc5) {
            ans += (1ll * f1 % mod * (a[i] / 5) % mod); ans %= mod;
            ans += 1ll * f0 * a[i]; ans %= mod;
            ans += a[i]; 
            ans %= mod;

            f0 = g1 * a[i] / 5;
            f0 %= mod;
            f1 = (g0 * a[i] + a[i]); 
            f1 /= 5;
            f1 %= mod;
        } else {
            ans += (1ll * a[i] * (f0 + (f1 * 5)));
            ans %= mod;
            ans += a[i];
            ans %= mod;
            
            f0 = (g0 * a[i] + a[i]);
            f0 %= mod;
            f1 = (g1 * a[i]);
            f1 %= mod;
        }
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









