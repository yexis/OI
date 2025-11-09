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
 * 构造题：限制深度的合法括号子串
 * 
 * --- 本题主要没有考虑到深度超过k的子串
 * 可以使用()包裹一个深度为在k的子串，形成深度为k+1的子串，这样不会与周围的其他子串组成新的子串
 * 比如 ((()))((()))其中只有2个深度为2的合法子串
 * 然后在每个单独的深度k+1的子串内部，去组装若干个深度为k的子串
 * 
 * 而后发现，在一个深度为k的括号串左右两边，分别追加若干个1深度()括号串，可以形成 (x+1) * (y+1) 个k深度的括号子串
 * 如果令两边的1深度()括号串数量相等呢，则可以形成 x^2个k深度的括号子串
 * 
 * 所以题目变成将x变成若干个完全平方数的和
 * 
 * 同时本题x的范围是10^10，也是一个往 sqrt(n) 思考的线索
*/

void solve() {
    int k; cin >> k;
    ll x; cin >> x;

    // x = t_1^2 + t_2^2 + , ... , + t_n^2
    vector<int> v;
    auto cal = [&](ll mx) -> ll {
        ll q = sqrtl(mx);
        v.push_back(q);
        return mx - q * q;
    };

    while (x) {
        auto nx = cal(x);
        if (nx == 0) break;
        x = nx;
    }

    for (auto t : v) {
        // 最外层包括，使得深度为k+1
        cout << "(";        
        // 左侧t个1深度括号
        int nt = t; while(--nt) cout << "()"; 
        // 中间部分
        nt = k; while(nt--) cout << "(";
        nt = k; while(nt--) cout << ")";
        // 深度t个1深度括号
        nt = t; while(--nt) cout << "()";
        cout << ")";
    }
    
    cout <<  "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









