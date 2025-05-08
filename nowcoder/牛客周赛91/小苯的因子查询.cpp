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
#define debug(x) cerr << (#x) << " = " << (x) << endl;

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

ll inv(ll x, int m = mod) {
    return power(x, m - 2);
}

/*
 * 
*/

static constexpr int N = 1e6;

// 因子的数量
ll f[N + 10];
// 除2外的因子数量
ll g[N + 10];
// 质因数累计的个数
ll num[N + 10];

vector<int> prime;
bool not_prime[N + 1];
// smallest prime factor
int spf[N + 1];
void init() {
    for (int i = 2; i <= N; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
            spf[i] = i; // 质数的最小质因数是自己
        }
        for (int p : prime) {
          	int m = i * p;
            if (m > N) break;
            not_prime[m] = true;
            spf[m] = p;
            if (i % p == 0) {
                // i % p == 0
                // 换言之，i 之前被 p 筛过了
                // 由于 prime 里面质数是从小到大的，所以 i 乘上其他的质数的结果 一定会被 p 筛掉
                // 就不需要在这里先筛一次，所以这里直接 break 掉就好了
              	// 证明：
              	// 假设 i / p = k，设 q 为质数，且 q > p 
              	// 那么，m = i * q = p * (k * q)，所以m一定会被 p 和 (k*q) 筛掉
                break;
            }
        }
    }

    auto factorize = [&](int x, map<int, int>& mp) {
        while (x > 1) {
            mp[spf[x]]++;
            x /= spf[x];
        }
    };

    for (int i = 2; i <= N; i++) {
        ll delta_f = i > 2 ? f[i - 1] : 1;
        ll delta_g = i > 2 ? g[i - 1] : 1;
        int x = i;
        map<int, int> mp;
        factorize(x, mp);

        // update f[i]
        for (auto& [k, _] : mp) {
            int c = num[k];
            if (c == 0) continue;
            delta_f *= inv(c + 1);
            delta_f %= mod;
        }

        // update g[i]
        for (auto& [k, _] : mp) {
            if (k == 2) continue;
            int c = num[k];
            if (c == 0) continue;
            delta_g *= inv(c + 1);
            delta_g %= mod;
        }

        // update
        for (auto& [k, v] : mp) {
            num[k] += v;
        }

        for (auto& [k, v] : mp) {
            int c = num[k];
            delta_f *= c + 1;
            delta_f %= mod;
            if (k == 2) continue;
            delta_g *= c + 1;
            delta_g %= mod;
        }
        f[i] = delta_f;
        g[i] = delta_g;
        // cout << "i:" << i << "(f:" << f[i] << " g:" << g[i] << " ans:" << g[i] * power(f[i], mod - 2) % mod << ")\n"; 
    }
}


void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    // n >= 2
    // ans = g[n] / f[n]
    cout << g[n] * power(f[n], mod - 2) % mod << " ";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    init();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}









