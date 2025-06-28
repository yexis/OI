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
    ll sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << -1 << "\n";
        return;
    }

    ll sum2 = sum / 2;
    vector<int> a; iota(a.begin(), a.end(), 1);

    int dp[sum2 + 1]; memset(dp, 0, sizeof(dp)); dp[0] = 1;
    int dp2[sum2 + 1]; memset(dp, -1, sizeof(dp));
    for (auto& e : a) {
        for (int i = sum2; i >= e; i--) {
            if (dp[i - e]) {
                dp[i] = 1;
                dp2[i] = e;
            }
        }
    }

    if (!dp[sum]) {
        cout << -1 << "\n";
        return;
    }

    set<int> yet;
    int p = sum2;
    while(p > 0) {
        cout << p << " " << dp2[p] << endl;
        yet.insert(dp2[p]);
        p -= dp2[p];
    }
    for (auto& e : yet) cout << e << " "; cout << "\n";

    vector<int> res(yet.begin(), yet.end());
    for(int i = 1; i <= n; i++) {
        if (!yet.count(i)) {
            res.push_back(i);
        }
    }
    for (auto& e : res) {
        cout << e << " ";
    }
    cout << "\n";

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}









