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
 * 循环节 (取模|拆位)
 * https://ac.nowcoder.com/acm/contest/107879/D
 * a 和 b 存在最小公倍串的前提是 a 和 b 拥有共同的循环节p
 * 即 a = p * x, b = p * y，那么 lcm(a, b) = lcm(x, y) * p
 * 
 * 
 * 为什么只需要考虑最大循环节g就可以了
 * A = abaaba
 * B = ababab
 * - len(p) = 6， aa | bb | aa | ab | ba | ab
 * - len(p) = 3， aaab | bbba | aaab 
 * 很明显，对于循环节3，只是将循环节为6时的多个部分进行了合并，
 * 而原本可以变成2个值的部分，现在合并后只能变成一个值了
 * 所以不可能导致结果更优！
*/

void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> vv;
    vector<string> ss(n);
    for (auto& s : ss) {
        cin >> s;
        vv.emplace_back(s.size());
        tot += s.size();
    }

    int g = 0;
    for (auto& v : vv) {
        g = gcd(g, v);
    }

    vector cnt(g, vector<int>(26));
    for (auto& s : ss) {
        for (int i = 0; i < s.size(); i++) {
            cnt[i % g][s[i] - 'a']++;
        }
    }
    int cur = 0;
    for (auto& e : cnt) {
        cur += *max_element(e.begin(), e.end());
    }
    cout << tot - cur << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









