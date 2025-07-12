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
 * yexiso-review
 * 筛法求质因数个数
*/
const int N = 1e6;
vector<int> prime;
// 是否为合数
bool not_prime[N + 1];
// f[i]表示i的质因数个数
int f[N + 1];
// 代表恰有2个质因数的数
vector<int> two;

void init() {
    for (int i = 2; i <= N; ++i) {
        if (!not_prime[i]) {
            f[i] = 1;
            prime.push_back(i);
        }
        for (int p : prime) {
            if (i * p > N) break;
            not_prime[i * p] = true;
            if (i % p == 0) {
                f[i * p] = f[i];
                // i % p == 0
                // 换言之，i 之前被 p 筛过了
                // 由于 prime 里面质数是从小到大的，所以 i 乘上其他的质数的结果 一定会被 p 筛掉
                // 就不需要在这里先筛一次，所以这里直接 break 掉就好了
              	// 证明：
              	// 假设 i / p = k，设 q 为质数，且 q > p 
              	// 那么，m = i * q = p * (k * q)，所以m一定会被 p 和 (k*q) 筛掉
                break;
            } else {
                f[i * p] = f[i] + 1;
            }
        }
    }
    for (int i = 0; i <= N; i++) {
        if (f[i] == 2) {
            two.push_back(i);
        }
    }
}

void solve() {
    int q;
    cin >> q;
    while (q--) {
        ll A;
        cin >> A;
        int k = lower_bound(two.begin(), two.end(), A, [&](const auto& aa, const ll& bb) {
            return 1ll * aa * aa <= bb;
        }) - two.begin() - 1;
        cout << 1ll * two[k] * two[k] << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    init();
    solve();
    return 0;
}









