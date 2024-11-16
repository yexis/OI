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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

/*
 * not pass
*/

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        int d = s[i] - 'a';
        cnt[d]++;
    }

    int chd = 0;
    string res;
    for (int i = 0; i < 26; i++) {
        if (k > cnt[i]) {
            k -= cnt[i];
        } else {
            chd = i;
            res += (i + 'a');
            break;
        }
    }
    assert(cnt[chd] >= k);

    // cbaca
    vector<int> next(n, n);
    vector<int> R(26, -1);
    for (int i = n - 1; i >= 0; i--) {
        int d = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            if (d == j) continue;
            if (R[j] == -1) continue;
            next[i] = min(next[i], R[j]);
        }
        R[d] = i;
    }

    bool find = false;
    int rest = cnt[chd];
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a' + chd || find) {
            res += s[i];
        } else {
            // s[i] == chd
            int nxt = next[i];
            if (nxt == n) {
                find = true;
                continue;
            }

            int cc = nxt - i;
            int dd = rest - cc;
            if (s[nxt] < s[i]) {
                if (k <= cc) {
                    find = true;
                } else if (k > cc) {
                    res += s[i];
                }
            } else {
                // s[nxt] > s[i]
                if (k > dd) {
                    find = true;
                } else {
                    res += s[i];
                }
            }
            rest--;
        }
    }
    cout << res << "\n";
};
// abaabababacdfa
/*
 * aabab
 * aabaab
 *
 * abcde
 */
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}