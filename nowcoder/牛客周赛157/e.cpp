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
    int n, q; cin >> n >> q;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;
    
    vector<ll> pre(n + 1); for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (s[i] == '+' ? a[i] : -a[i]);
    vector<ll> min_pre(n, 2e18), min_suf(n, 2e18);
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) min_pre[i] = min(pre[i + 1], min_pre[i - 1]);
        else min_pre[i] = pre[i + 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) min_suf[i] = min(pre[i + 1], min_suf[i + 1]);
        else min_suf[i] = pre[i + 1];
    }
    // cout << "OK" << endl;

    bool base = true;
    for (int i = 0; i < n; i++) {
        if (pre[i + 1] < 0) {
            base = false;
            break;
        }
    }

    while (q--) {
        int p; char c; cin >> p >> c; p--;
        ll old = (s[p] == '+' ? a[p] : -a[p]);
        ll curr = (c == '+' ? a[p] : -a[p]);
        ll delta = curr - old;
        if (delta == 0) {
            if (base) cout << "YES" << "\n";
            else cout << "NO" << "\n";
            continue;
        }

        if ((p - 1 < 0 || min_pre[p - 1] >= 0) && 
            min_suf[p] + delta > 0
        ) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
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









