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

    // vector<int> sum(n + 1);
    // for (int i = 0; i < n; i++) {
    //     sum[i + 1] = sum[i] + (s[i] == '1');
    // }


    // // 每个0后面有多少个1
    // vector<int> a(n, -1);
    // // 每个1后面有多少个0
    // vector<int> b(n, -1);
    // for (int i = 0; i < n; i++) {
    //     if (s[i] == '0') {
    //         a[i] = sum[n] - sum[i];
    //     } else if (s[i] == '1') {
    //         int one = sum[n] - sum[i];
    //         b[i] = n - i - one;
    //     }
    //     int j = i;
    //     while (j < n && s[j] == s[i]) {
    //         j++;
    //     }
    //     i = j - 1;
    // }

    vector<int> res(n);
    int ans = 0;
    int cc = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (i == n - 1 || s[i] != s[i + 1]) {
            cc = 1;
        } else {
            cc++;
        }
        // cout << i << " " << cc << "\n";
        if (cc >= 2) {
            res[i] = 1;
            continue;
        }

        int o = 0, z = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '0') {
                z++;
            } else {
                o++;
            }
            if (o % 2 == 0 && z % 2 == 0) {
                res[i] = 1;
                break;
            }
        }

    }
    
    for (int i = 0; i < n; i++) {
        if (res[i]) {
            ans++;
        }
    }
    cout << (double) ans / n << "\n";
}


void solve2() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> res(n);
    map<int, int> mp;
    vector<int> dp(n + 1);
    dp[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') {
            dp[i] = dp[i + 1] ^ 1 << 1;
        } else {
            dp[i] = dp[i + 1] ^ 1;
        }
        if (mp.count(dp[i])) {
            res[i] = 1;
        }
        mp[dp[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (res[i]) ans++;
    }
    cout << (double) ans / n << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









