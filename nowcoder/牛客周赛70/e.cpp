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
 * 
*/

ll cal(ll x) {
    ll y = x + 1;
    if (y % 4 == 0) {
        return 0;
    } else if (y % 4 == 1) {
        return x;
    } else if (y % 4 == 2) {
        return 1;
    } else {
        return x + 1;
    }
}

ll cal(ll x, ll y) {
    if (x == 0) return cal(y);
    return cal(y) ^ cal(x - 1);
}

void solve() {
    int n;
    cin >> n;
    int ans = cal(n);
    if (n & 1) {
        ans ^= 1;
    }
    cout << ans << "\n";
}

int main() {
    ios;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}




