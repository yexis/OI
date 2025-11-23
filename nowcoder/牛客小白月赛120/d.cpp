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
    int n, m; cin >> n >> m;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m); for (int i = 0; i < m; i++) cin >> b[i];

    vector<pii> pa;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        pa.push_back(pii(a[i], j - i));
        i = j - 1;
    }

    vector<pii> pb;
    for (int i = 0; i < m; i++) {
        int j = i;
        while (j < m && b[j] == b[i]) {
            j++;
        }
        pb.push_back(pii(b[i], j - i));
        i = j - 1;
    }
//     for (auto e : pa) cout << e.first << " " << e.second << "\n";
//     for (auto e : pb) cout << e.first << " " << e.second << "\n";

    if (pa.size() != pb.size()) {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < pa.size(); i++) {
        if (pa[i].first != pb[i].first || pa[i].second > pb[i].second) {
            cout << -1 << "\n";
            return;
        }
    }

    int ans = 0;
    for (int i = 0; i < pa.size(); i++) {
        auto [k1, v1] = pa[i];
        auto [k2, v2] = pb[i];
        int t = 0;
        while (v1 < v2) {
            v1 <<= 1, t++;
        }
        ans = max(ans, t);
    }
    cout << ans << "\n";
    return;
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









