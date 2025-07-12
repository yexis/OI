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

// 为什么这里用array要比vector快
using ull = unsigned long long;
using puu = pair<ull, ull>;
constexpr static int N = 1e6 + 5;
struct Hash {
    vector<array<ull, 2>> h, f;
    ull b1, m1;
    ull b2, m2;
    Hash(string& s, int base1 = 13331, int mod1 = 1000000007, int base2 = 131, int mod2 = 2147483647) {
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
  	
  	// 将二维转换成一维
  	ull cal(puu x) {
        return x.first * m2 + x.second;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    string t = s;
    reverse(t.begin(), t.end());
    Hash ha1(s);
    Hash ha2(t);
    int mx = 1;
    for (int i = 0; i < n; i++) {
        puu p1 = ha2.get(0, i);
        puu p2 = ha1.get(n - i - 1, n - 1);
        if (p1 == p2) {
            mx = max(mx, i + 1);
        }
    }

    string ans = s;
    for (int i = n - mx - 1; i >= 0; i--) {
        ans += s[i];
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









