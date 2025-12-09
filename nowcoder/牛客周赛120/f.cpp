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
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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
const int mod = 998244353;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

// 等比数列求和
ll cal(ll a1, ll q, ll n) {
    if (q == 1) {
        return n * q % mod;
    } else {
        return a1 * (power(q, n) - 1) % mod * power(q - 1, mod - 2) % mod;      
    }
}

/*
 * 无穷无尽的数：https://ac.nowcoder.com/acm/contest/123788/F
 * 对于无限长的重复的字符串，，需要截取其中的一段[l, r]，进行计算
 * 可以将 [l, r]分为三个部分，设循环节为s
 * part-1：s的一个后缀
 * part-2：若干个s拼接而成
 * part-3：s的一个前缀
 * 其中，
 * - part-2可能为空
 * - part-1 和 part-3 可能重合
 * 
 * 
 * 
 * 费马小定理：
 * (x^n) % p，当快速幂的指数x很大时，不能直接对n模p
 * 也就是说 (x^n) mod p != x^(n mod p) 不相等!!!
 * 根据费马小定理，x^(p-1) = 1 (mod p)
 * 则， x^n = x^(q(p-1) + r)(mod p) = (x^(p-1))^q * x^r (mod p) = 1^q * x^r (mod p)
 * 所以 x^n = x^(n % (p - 1)) (mod p)
*/

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 0 1 2 3 4 5 0 1 2 3 4 5 0 1 2 3 4  5
// 1 9 1 9 1 8 1 9 1 9 1 8 1 9 1 9 1  8
void solve() {
    ll n, l, r; cin >> n >> l >> r; l--, r--;
    string s; cin >> s;

    ll base = 10;
    ll H[n], P[n];
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            P[i] = 1;
            H[i] = s[i] - '0'; H[i] %= mod;
        } else {
            P[i] = P[i - 1] * base; P[i] %= mod;
            H[i] = H[i - 1] * base + s[i] - '0'; H[i] %= mod;            
        }

    }
    auto get = [&](int l, int r) -> ll {
        if (l == 0) {
            return H[r];
        }
        return (H[r] - H[l - 1] * P[r - l + 1] % mod + mod) % mod;
    };

    ll Lc = l / n, Lr = l % n; 
    ll Rc = r / n, Rr = r % n;

    ll len_l = n - Lr;
    ll cnt_m = Rc - Lc - 1; ll len_m = cnt_m * n % (mod-1);
    ll len_r = Rr + 1;
    
    ll ans = 0;
    if (Lc == Rc) {
        ll t1 = get(Lr, Rr);
        ll h1 = t1 % mod;
        ans += h1; ans %= mod;
        cout << ans << "\n";
        return;
    }
    
    // Lc < Rc
    // left 后缀
    ll t1 = get(Lr, n - 1);
    ll h1 = t1 * power(10, len_m + len_r) % mod;
    ans += h1; ans %= mod;

    // mid 完整
    if (cnt_m > 0) {
        ll t2 = get(0, n - 1);
        ll h2 = cal(t2, power(10, n), cnt_m);
        h2 *= power(10, len_r); h2 %= mod;
        ans += h2; ans %= mod;
    }

    // right 前缀
    if (Rc > Lc) {
        ll h3 = get(0, Rr);
        ans += h3; ans %= mod;
    }
    
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









