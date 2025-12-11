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
 * 
*/

void solve() {
    int n, K; cin >> n >> K;
    if (K == n - 1) {
        cout << "Yes" << "\n";
        for (int i = 2; i <= n; i++) cout << 1 << " " << i << "\n";
        return;
    }
    // 点个数=n，边个数=n-1，度数为2n-2
    if (K == 1) {
        // 最大公因数是1时，构造出度数分别是2和3的两个非叶节点
        // 剩余的节点，形成一条链，都是度数为2的非叶节点
        // 少于5个节点时无解
        if (n < 5) {
            cout << "No" << "\n";
            return;
        }
        // n >= 5 有解
        cout << "Yes" << "\n";
        vector<int> g[n];
        g[0].push_back(1); 
        g[1].push_back(2); 
        g[2].push_back(3); 
        g[2].push_back(4);
        for (int i = 5; i < n; i++) {
            g[i - 1].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            for (auto& j : g[i]) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    } else {
        // K, 2K, 3K ... yK
        // x个叶子节点度为1的点，总度数为 x
        // y个非叶子结点，总度数为 2n - 2 - x
        // n - x = y，非叶子度数为 2n - 2 - (n - y) = y + n - 2
        // y + n - 2需要是K的倍数，且最大公因数为K
        for (int y = 2; y <= n - 2; y++) {
            int degs = y + n - 2;
            if (degs % K == 0) {
                int y1 = degs / K; // 最多能组成几个组
                if (y1 < y) {
                    continue;
                }
                vector<int> g[n];
                int idx = y;
                for (int i = 0; i < y; i++) {
                    if (i + 1 < y) g[i].push_back(i + 1);
                    int up = (i == 0 || i == y - 1) ? K - 1 : K - 2;
                    while (up--) {
                        g[i].push_back(idx); idx++;
                    }
                }
                while (idx < n) {
                    g[0].push_back(idx);
                    idx++;
                }
                cout << "Yes" << "\n";
                for (int i = 0; i < y; i++) {
                    for (auto& j : g[i]) {
                        cout << i + 1 << " " << j + 1 << "\n";
                    }
                }
                return;
            }
        }
        cout << "No" << "\n";
    }
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









