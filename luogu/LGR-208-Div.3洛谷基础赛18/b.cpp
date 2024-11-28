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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll base = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        base += mx;
    }
    if (k == 0) {
        cout << base << "\n";
        return;
    }
    // k > 0
    if (n == 2) {
        if (k & 1) {
            swap(a[0], a[1]);
            cout << a[0] + max(a[0], a[1]) << "\n";
        } else {
            cout << a[0] + max(a[0], a[1]) << "\n";
        }
        return;
    }

    int id;
    mx = 0, id = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
            id = i;
        }
    }
    cout << (ll)mx * n << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}