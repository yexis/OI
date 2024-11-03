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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    vector<int> cols(n, 0);

    vector<pii> pr;
    for (int i = 0; i < k; i++) {
        pr.emplace_back(a[i], i + 1);
    }


    sort(pr.begin(), pr.end());
    vector<vector<int> > res(n, vector<int>(m, 0));
    // 1 向下 -1 向上
    if (k <= n) {
        for (int i = 0; i < k; i++) {
            res[i][0] = a[i];
        }
    } else {
        // k > n
        int idx = 0;
        for (int i = 0; i < n && idx < k; i++) {
            for (int j = 0; j < m && idx < k; j++) {
                res[i][j] = pr[idx++].second;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}

/*
 * 6 5 4 3 2 1
 * 6 3 1
 * 5 4 2
 */