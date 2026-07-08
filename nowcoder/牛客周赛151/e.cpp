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
using lll = __int128;
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
 * https://ac.nowcoder.com/acm/contest/137267/E
 * O (n * log(n) * log(1e9) )
*/

void solve() {
    ll n, l, W; cin >> n >> l >> W;
    vector<int> xs(n), ws(n); for (int i = 0; i < n; i++) cin >> xs[i] >> ws[i];
    vector<pii> pr; for (int i = 0; i < n; i++) pr.push_back(pii(xs[i], ws[i]));
    sort(pr.begin(), pr.end());

    int mi = INF, mx =  0;
    vector<ll> sum_w(n + 1); 
    vector<lll> sum_wx(n + 1); 
    for (int i = 0; i < n; i++) {
        mi = min(mi, xs[i]);
        mx = max(mx, xs[i]);
        sum_w[i + 1] = sum_w[i] + pr[i].second;
        sum_wx[i + 1] = sum_wx[i] + 1ll * pr[i].first * pr[i].second;
    }

    auto check = [&](int p, int del) -> lll {
        // left - right
        int i = lower_bound(pr.begin(), pr.end(), p, [](const pii& aa, const int& bb) {
            return aa.first < bb;
        }) - pr.begin();
        lll left_v = 0, right_v = 0;
        // left : 0 ~ i -1 
        left_v += (lll)p * sum_w[i] - sum_wx[i];
        left_v -= (sum_wx[n] - sum_wx[i]) - (lll)p * (sum_w[n] - sum_w[i]);
        if (del < i) {
            left_v -= (lll)pr[del].second * (p - pr[del].first);
        } else {
            left_v += (lll)pr[del].second * (pr[del].first - p);
        }

        // right : i ~ n - 1
        right_v += W * l - 2 * W * p;
        return 2 * left_v - right_v;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int left = 0, right = l;
        while (left <= right) {
            int mid = (left + right) >> 1;
            lll tmp = check(mid, i);
            if (tmp > 0) {
                right = mid - 1;
            } else if (tmp < 0) {
                left = mid + 1;
            } else {
                ans++;
                break;
            }
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









