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
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    vector<int> w(m);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }

    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());

    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + b[i];
    }

    vector<ll> R(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) R[i] = sum[i + 1];
        else R[i] = max(sum[i + 1], (ll)R[i + 1]);
    }

    ll pre = 0;
    ll ans = max(R[0], 0ll);
    for (int i = 0; i < m; i++) {
        if (i + 1 > n) break;
        pre += w[i];
        ans = max(ans, pre + R[i]);
    }
    cout << ans << "\n";

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}

/*
5 -2 -5 10
8 4 1
*/








