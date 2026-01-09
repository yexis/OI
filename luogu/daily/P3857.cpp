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
const int mod = 1e9 + 7;
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

/*
 * https://www.luogu.com.cn/problem/P3857
 * 异或线性基
*/

int n;
int row = 0; // row: 记录基向量的个数
vector<ll> b; // b: 记录每个基向量, b[0, row-1]表示所有基向量
vector<ll> bit; // bit: 记录第i位为1的基向量
void gauss(vector<ll>& a) {
    row = 0;
    n = a.size();
    b = a;
    bit = vector<ll>(64, 0);

    for (int i = 63; i >= 0; i--) {
        // 找到当前列(位)为1的行
        for (int j = row; j < n; j++) {
            if (b[j] >> i & 1) {
                swap(b[row], b[j]);
                break;
            }
        }
        // 不存在，跳过
        if ((b[row] >> i & 1) == 0) {
            continue;
        }
        // 将其他所有元素的该位的1消掉
        for (int j = 0; j < n; j++) {
            if (j != row && (b[j] >> i & 1)) {
                b[j] ^= b[row];
            }
        }
        // 第i位为1的线性基
        bit[i] = b[row];
        row++; 
        // 线性基的数量不可能超过n
        if (row == n) break;
    }
}

// 计算异或和的方案数
ll cal_cnt() {
    return (1ll << row) % 2008;
    // if (row < n) return (1ll << row) % 2008;
    // return ((1ll << row) + 2007) % 2008;
}

void solve() {
    int n, m; cin >> n >> m;
    
    vector<ll> a;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;    
        ll mask = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'O') {
                mask |= 1ll << j;
            }
        }
        a.push_back(mask);
    }
    gauss(a);
    cout << cal_cnt() << "\n";
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









