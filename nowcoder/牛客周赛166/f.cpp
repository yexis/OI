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
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

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
    ll n, S; cin >> n >> S;
    vector<ll> A(n); for (int i = 0; i < n; i++) cin >> A[i];
    vector<ll> B(n); for (int i = 0; i < n; i++) cin >> B[i];

    auto check = [&](int mid) -> bool {
        vector<ll> dp(n, 0); 
        for (int k = 1; k <= mid; k++) {
            ll prev = LLINF;
            vector<ll> cdp(n, LLINF);
            for (int i = 0; i < n; i++) {
                if (i - 1 >= 0) cdp[i] = cdp[i - 1];
                if (k == 1) {
                    prev = min(prev, (i - 2 >= 0 ? dp[i - 2] : 0));
                } else {
                    prev = min(prev, (i - 2 >= 0 ? dp[i - 2] : LLINF));
                }
                cdp[i] = min(cdp[i], prev + A[i]);
            }
            dp.swap(cdp);
        }

        vector<ll> dp2(n, 0); 
        for (int k = 1; k <= mid; k++) {
            ll prev = LLINF;
            vector<ll> cdp(n, LLINF);
            for (int i = n - 1; i >= 0; i--) {
                if (i + 1 < n) cdp[i] = cdp[i + 1];
                if (k == 1) {
                    prev = min(prev, (i + 2 < n ? dp2[i + 2] : 0));
                } else {
                    prev = min(prev, (i + 2 < n ? dp2[i + 2] : LLINF));
                }
                cdp[i] = min(cdp[i], prev + B[i]);
            }
            dp2.swap(cdp);
        }

        for (int i = 0 ; i + 2 < n; i++) {
            if (dp[i] + dp2[i + 2] <= S) return true;
        }

        return false;
    };

    int l = 1, r = n / 2, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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









