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
 * https://ac.nowcoder.com/acm/contest/121395/B
 * 题意：给定一个入栈序列a，构造一个出栈序列b，对于每个 (i % K = 1) 的位置，累加 a[i]，使得最终的累加和最大
 * 贪心思路：答案为序列a中最大的 cl = (n + K - 1) / K 个元素
 * 关键是 如何构造这 cl 个元素呢 ？
 * 结论：对于已知的最大的 cl 个元素，一定存在一种出栈序列使得每个元素都位于 (i % K == 1) 的位置
 * 构造方法：
 *  - 维护 状态S[i] 表示元素i是否被选择，S[i] = 1被选择，S[i] = 0不被选择
 *  - 维护一个栈，如果当前栈顶元素的状态 为当前需要的状态，出栈；否则从a中选取元素压栈
 * 
 * key-point:
 * - 贪心
 * - 出栈序列
 * - 牛客挑战赛
*/

void solve() {
    int n, K; cin >> n >> K;
    vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> I(n + 1); for (int i = 1; i <= n; i++) I[i] = i; 
    sort(I.begin() + 1, I.end(), [&](const auto& aa, const auto& bb) {
        return a[aa] > a[bb];
    });

    int cl = (n + K - 1) / K;
    ll sum = 0;
    vector<int> S(n + 1);  // 表示被选择
    for (int i = 1; i <= cl; i++) {
        sum += a[I[i]];
        S[I[i]] = 1;
    }
    cout << sum << "\n";
    
    int cur = 1; vector<int> stk;
    // k: 枚举当前位置(出栈序列)需要什么状态的数
    for (int k = 1; k <= n; k++) {
        // nd = 0: 不被选择元素
        // nd = 1: 被选择元素
        int nd = 0; if (k % K == 1) nd = 1;
        if (stk.size() && S[stk.back()] == nd) {
            cout << a[stk.back()] << " ";
            stk.pop_back();
            continue;
        }
        while (cur <= n) {
            if (S[cur] == nd) {
                cout << a[cur] << " ";
                cur++;
                break;
            }
            stk.push_back(cur);
            cur++;
        }
    }

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









