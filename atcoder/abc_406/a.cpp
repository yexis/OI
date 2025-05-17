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
 * 数位DP
*/
using ll = long long;
const int mod = 1e9 + 7;
int m;
string s;
vector<vector<ll> > f;
void init(int n) {
    s = to_string(n);
    m = s.size();
    f.assign(m, vector<ll>(1 << 10, -1));
}

// i : 表示当前遍历的位数
// mask: 表示当前已经遍历的状态，即高位出现的数字集合
// is_limit: 当前位i是否被限制。若is_limit = true, 则当前位最大取值为s[i]; 若is_limit=false, 则当前位最大取值为9
// is_num: 当前位i前面(高位)是否填了数字（能否跳过）
ll dfs(int i, int mask, int is_limit, int is_num) {
    if (i == m) return is_num;
    if (!is_limit && is_num && f[i][mask] >= 0) {
        return f[i][mask];
    }
    
    ll res = 0;
    // 若前面全部为 0, 可以跳过当前位（即 将当前位置为0）
    if (!is_num) {
        res = dfs(i + 1, mask, false, false);
    }
    // 设置当前位上限
    int up = is_limit ? s[i] - '0' : 9;
    int d = is_num ? 0 : 1;
    for (; d <= up; d++) {
        if ((mask >> d & 1) == 0) {
            res += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
            res %= mod;
        }
    }

    // is_limit时，不会进入记忆化
    // !is_num时，不会进入记忆化
    if (!is_limit && is_num) {
        f[i][mask] = res;
    }
    return res;
}


void solve() {

}

int main() {
    ios;
    cout << fixed << setprecision(20);

    return 0;
}









