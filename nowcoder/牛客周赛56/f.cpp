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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 2147483647;


// 1. 字符串hash解法
// 单hash pass
constexpr static int N = 1e6;
const int base = 131;
ull h[N + 10], f[N + 10];
ull rh[N + 10], rf[N + 10];
ull th[N + 10], tf[N + 10];

void init(string& s, ull h[], ull f[]) {
    int n = s.size();
    f[0] = 1, h[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            h[i] = s[i];
            continue;
        }
        h[i] = (h[i - 1] * base % mod + s[i]) % mod;
        f[i] = f[i - 1] * base % mod;
    }
}

ull get(ull hh[], ull ff[], int l, int r) {
    if (l == 0) {
        return hh[r];
    }
    return (hh[r] - hh[l - 1] * ff[r - l + 1] % mod + mod) % mod;
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

    init(s, h, f);
    init(rs, rh, rf);
    init(t, th, tf);

    int mx = 0, ii = 1;
    for (int i = 0; i < n; i++) {
        ull x = get(rh, rf, n - 1 - i, n - 1);
        ull y = get(th, tf, 0, i);

        if (x == y) {
            int ans = i;
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(h, f, i + 1, mid) == get(th, tf, i + 1, mid)) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (ans + 1 > mx) {
                mx = ans + 1;
                ii = i + 1;
            }
        } else if (x != y) {
            int ans = -1;
            int l = 0, r = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(rh, rf, n - 1 - i, (n - 1 - i + mid)) == get(th, tf, 0, mid) ) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (ans + 1 > mx) {
                mx = ans + 1;
                ii = i + 1;
            }
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
