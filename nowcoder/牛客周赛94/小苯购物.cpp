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
#define debug(x) cerr << (#x) << " = " << (x) << endl;

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
 * next_permutation 要求原始的数组是排序好的
*/

void solve() {
    int n; cin >> n;
    vector<pii> pr(3);
    for (auto& [a, b] : pr) cin >> a >> b;
    sort(pr.begin(), pr.end());

    int ans = n;
    do {
        for (int mask = 0; mask < (1 << 3); mask++) {
            int x = n;
            for (int i = 0; i < 3; i++) {
                if (mask >> i & 1) {
                    auto [a, b] = pr[i];
                    if (x >= a) {
                        x = max(x - b, 0);
                    }
                }
            }
            ans = min(ans, x);
        }
    } while (next_permutation(pr.begin(), pr.end()));

    cout << ans << "\n";
}



int main() {
    ios;
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









