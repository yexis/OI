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

/*
 * 
*/

int K;
int m;
constexpr static int N = 61;
pll f[N + 1][N + 1];
string s;
void init(string& _s, int _K) {
    s = _s;
    K = _K;
    m = s.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            f[i][j] = pll(-1, -1);
        }
         
    }
}

// i : 表示当前遍历的位数
// mask: 表示当前已经遍历的状态，即高位出现的数字集合
// is_limit: 当前位i是否被限制。若is_limit = true, 则当前位最大取值为s[i]; 若is_limit=false, 则当前位最大取值为9
// is_num: 当前位i前面(高位)是否填了数字（能否跳过）
pll dfs(int i, int mask, int is_limit, int is_num) {
    if (i == m) {
        if (mask == K && is_num) {
            return pll(1, 0);
        } else {
            return pll(0, 0);
        }
    }
    if (!is_limit && is_num && f[i][mask] != pll(-1, -1) ) {
        return f[i][mask];
    }
    
    pll res(0, 0);
    // 若前面全部为 0, 可以跳过当前位（即 将当前位置为0）
    if (!is_num) {
        res = dfs(i + 1, mask, false, false);
    }
    // 设置当前位上限
    int up = is_limit ? s[i] - '0' : 1; 
    int d = is_num ? 0 : 1;
    for (; d <= up; d++) {
        // 注意 << 的优先级 小于 % 的优先级
        // 不能写成  ll pre = (d == 1 ? 1ll << (m - i - 1) % mod : 0);
        ll pre = (d == 1 ? (1ll << m - i - 1) % mod : 0);
        auto [cnt, sum] = dfs(i + 1, mask + (d == 1), is_limit && d == up, true);
        res.first += cnt; res.first %= mod;
        res.second += cnt * pre % mod + sum; res.second %= mod;
    }
    if (!is_limit && is_num) {
        f[i][mask] = res;
    }
    return res;
}

pair<string, int> divide(string& num, int x) {
    string q; int r = 0;
    for (char c : num) {
        int curr = r * 10 + (c - '0');
        q += (curr / x) + '0'; 
        r = (curr % x);
    }
    int pos = q.find_first_not_of('0');
    if (pos != string::npos) {
        q = q.substr(pos);
    } else {
        q = "0";
    }
    return make_pair(q, r);
}

string convert_10_to_n(string& p, int b) {
    string num = p;
    string res;
    while (num != "0") {
        auto [q, r] = divide(num, b);
        res += (char)('0' + r);
        num = q;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string n; cin >> n;
    int k;  cin >> k;
    n = convert_10_to_n(n, 2);
    // cout << "bitset:" << n << "\n";

    init(n, k);
    auto [cnt, sum] = dfs(0, 0, true, false);
    cout << sum << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









