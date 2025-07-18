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
 * 
*/

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    auto cal = [&](int l, int r) {
        string t = s;
        for (int i = 0; i < n; i++) {
            if (t[i] == '?') {
                if (i >= l && i <= r) {
                    t[i] = 'v';
                } else {
                    t[i] = 'o';
                }
            } 
        }
        int o = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == 'o') o++;
        }

        int left = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == 'o') {
                left++;
            } else {
                ans += left * (o - left);
            }
        }
        return ans;
    };

    ll ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l - 1; r < n; r++) {
            if (r < 0) continue;
            ans = max(ans, cal(l, r));
        }
    }
    cout << ans << "\n";
}



int main() {
    ios;
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









