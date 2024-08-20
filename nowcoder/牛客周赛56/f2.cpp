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

// 1. 字符串 双hash解法
// 双hash pass
using ull = unsigned long long;
constexpr static int N = 1e6 + 5;
struct Hash {
    vector<array<ull, 2>> h, f;
    ull b1, m1;
    ull b2, m2;
    Hash(string& s, int base1 = 131, int mod1 = 2147483647, int base2 = 13331, int mod2 = 1000000007) {
        this->b1 = base1;
        this->m1 = mod1;
        this->b2 = base2;
        this->m2 = mod2;

        int n = s.size();
        h.resize(n);
        f.resize(n);

        h[0][0] = h[0][1] = 0;
        f[0][0] = f[0][1] = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                h[i][0] = h[i][1] = s[i];
                continue;
            }
            h[i][0] = (h[i - 1][0] * b1 % m1 + s[i]) % m1;
            h[i][1] = (h[i - 1][1] * b2 % m2 + s[i]) % m2;
            f[i][0] = f[i - 1][0] * b1 % m1;
            f[i][1] = f[i - 1][1] * b2 % m2;
        }
    }
    puu get(int l, int r) {
        if (l == 0) {
            return {h[r][0], h[r][1]};
        }
        return {
                (h[r][0] - h[l - 1][0] * f[r - l + 1][0] % m1 + m1) % m1,
                (h[r][1] - h[l - 1][1] * f[r - l + 1][1] % m2 + m2) % m2
        };
    }
};

void solve() {
    int n;
    cin >> n;
    string s, rs;
    string t;
    cin >> s;
    cin >> t;
    rs = s;
    reverse(rs.begin(), rs.end());

    Hash hs(s);
    Hash hr(rs);
    Hash ht(t);

    int mx = 0, ii = 1;
    for (int i = 0; i < n; i++) {
        auto x = hr.get(n - 1 - i, n - 1);
        auto y = ht.get(0, i);

        if (x == y) {
            int ans = i;
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (hs.get(i + 1, mid) == ht.get(i + 1, mid)) {
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
                if (hr.get(n - 1 - i, (n - 1 - i + mid)) == ht.get(0, mid) ) {
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
