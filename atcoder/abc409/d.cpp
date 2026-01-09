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
 * 
*/
// accccddsssf
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> R(n, n);
    vector<int> pos(26, -1);
    for (int i = n - 1; i >= 0; i--) {
        int cur = n;
        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            if (pos[j] != -1) {
                cur = min(cur, pos[j]);
            } 
        }
        R[i] = cur;
        pos[s[i] - 'a'] = i;
    }
    // for (auto& e : R) cout << e << " "; cout << "\n";

    bool find = false;
    string ans;
    for (int i = 0; i < n - 1; i++) {
        char c1 = s[i], c2 = s[i + 1];
        if (c1 > c2) {
            ans += s.substr(0, i);   
            ans += s.substr(i + 1, R[i] - (i + 1));
            ans += c1;
            ans += s.substr(R[i]);
            find = true;
            break;
        }
    }
    if (!find) {
        cout << s << "\n";
        return;
    }
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









