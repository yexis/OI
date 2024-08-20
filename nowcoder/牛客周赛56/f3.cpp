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
using puu = pair<ull, ull>;
using pii = pair<int, int>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;

// 3. dp + z函数解法
// pass
vector<int> z_kmp(string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - l], r - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i;
            r = i + z[i] - 1;
            z[i]++;
        }
    }
    return z;
}

void solve() {
    int n;
    cin >> n;
    string s, rs;
    string t;
    cin >> s;
    cin >> t;
    rs = s;
    reverse(rs.begin(), rs.end());

    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[i]) {
            dp[i] = dp[i + 1] + 1;
        } else {
            dp[i] = 0;
        }
    }

    string r = t + rs;
    auto z = z_kmp(r);

    int mx = 0, ii = 1;
    for (int i = 0; i < n; i++) {
        int j = 2 * n - 1 - i;
        int ans = 0;
        if (z[j] == i + 1) {
            ans = z[j] + dp[i + 1];
        } else {
            ans = z[j];
        }
        if (ans > mx) {
            mx = ans;
            ii = i + 1;
        }
    }
    cout << mx << " " << ii << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
