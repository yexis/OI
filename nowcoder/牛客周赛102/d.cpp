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
    int n; cin >> n;
    string s; cin >> s;

    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '1');
    }

    // 1010
    auto cal1 = [&](string t) -> int {
        int ans = INF;
        for (int i = 0; i + 3 < n; i++) {
            int v1 = i + 1 - sum[i + 1];
            for (int j = i + 1; j + 2 < n; j++) {
                int v2 = sum[j + 1] - sum[i + 1];
                for (int k = j + 1; k + 1 < n; k++) {
                    int v3 = k - j - (sum[k + 1] - sum[j + 1]);
                    int l = k + 1;
                    int v4 = sum[n] - sum[k + 1];
                    ans = min(ans, v1 + v2 + v3 + v4);
                }
            }
        }
        return ans;
    };

    // 0101
    auto cal2 = [&](string t) -> int {
        int ans = INF;
        for (int i = 0; i + 3 < n; i++) {
            int v1 = sum[i + 1];
            for (int j = i + 1; j + 2 < n; j++) {
                int v2 = (j - i) - (sum[j + 1] - sum[i + 1]);
                for (int k = j + 1; k + 1 < n; k++) {
                    int v3 = sum[k + 1] - sum[j + 1];
                    int l = k + 1;
                    int v4 = (n - 1 - k) - (sum[n] - sum[k + 1]);
                    ans = min(ans, v1 + v2 + v3 + v4);
                }
            }
        }
        return ans;
    };
    cout << min(cal1(s), cal2(s)) << "\n";
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









