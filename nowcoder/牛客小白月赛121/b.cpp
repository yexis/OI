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

void solve() {
    ll n, t; cin >> n >> t;
    vector<ll> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(n); for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> index(n); for (int i = 0; i < n; i++) index[i] = i; 
    sort(index.begin(), index.end(), [&](const auto& aa, const auto& bb) {
        return a[aa] < a[bb];
    });

    ll sum = 0; for (int i = 0; i < n; i++) sum += a[i];
    if (sum >= t) {
        cout << 0 << "\n"; 
        return;
    }

    ll r = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll aa = a[index[i]];
        ll bb = b[index[i]];
        if (aa == 0) continue;
        if (sum + aa * bb < t) {
            sum += aa * bb;
            r += bb;
        } else {
            ll rr = (t - sum + aa - 1) / aa;
            sum += aa * rr;
            r += rr;
        }
    }
    if (sum < t) {
        cout << -1 << "\n";
        return;
    }
    cout << r << "\n";
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









