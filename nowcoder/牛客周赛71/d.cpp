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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto cal = [&](vector<int>& tar) -> ll {
        ll ans = LLINF;
        ll f[n + 1][3];
        // memset是按照字节进行赋值即 0x3f 8个bit
        memset(f, LLINF, sizeof(f));
        f[0][0] = f[0][1] = f[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            int co = s[i - 1] - '0';
            for (int j = 0; j < 3; j++) {
                int cost = (tar[j] == co ? 0 : a[i - 1]);
                f[i][j] = f[i - 1][j] + cost;
                if (j >= 1) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + cost);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            ans = min(ans, f[n][i]);
        }
        return ans;
    };

    ll ans = LLINF;
    vector<vector<int>> tar = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };
    for (int i = 0; i < tar.size(); i++) {
        ans = min(ans, cal(tar[i]));
    }
    cout << ans << "\n";
}

int main() {
    ios;
    solve();
    return 0;
}




