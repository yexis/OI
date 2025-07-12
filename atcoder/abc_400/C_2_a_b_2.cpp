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
 * X = 2 ^ a * b ^ 2
 * double的精度范围 大约为 10^15
 * 超过 10^15 数据范围时，使用long double
 * sqrt(x)只能支持到10^15次方数据范围
 * sqrtl(x)能支持到10^18次方数据范围
*/

// 有问题
ll solve2(ll n) {
    ll ans = 0;
    ans += (ll)sqrt(n / 2);
    ans += (ll)sqrt(n / 4);
    return ans;
}

ll solve3(ll n) {
    ll ans = 0;
    ans += ll(sqrtl(n / 2));
    ans += ll(sqrtl(n / 4));
    return ans;
}

ll mysqrt(ll x) {
    ll p = sqrt(x);
    if (p * p > x) {
        p--;
    } 
    return p;
}

ll solve4(ll n) {
    return mysqrt(n / 2) + mysqrt(n / 4);
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    ll n;
    cin >> n;
    cout << solve4(n) << "\n";
    return 0;
}







