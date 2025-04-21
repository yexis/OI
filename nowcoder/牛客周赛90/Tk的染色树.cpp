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
 * 操作一：操作一个节点i，代价为2 * a_i，将节点i变黑
 * 操作二：任意选择两个 不同 的节点i和j，代价为 a_i + a_j 将其简单路径上的所有点变黑
 * 
 * 很明显，在任何情况下都是 操作二 优于 操作一；（除非树只有一个节点）
 * 证明，对于任意两个不同的节点i,j，操作一的代价为 2 * a_i + 2 * a_j，而操作二的代价为 a_i + a_j，同时还能将i,j简单路径上的点染黑（额外收益）
 * 
 * - 对于节点数=1的情况，使用操作一
 * - 对于节点数>1的情况，使用操作二即可
 * 考虑所以叶子，由于每个叶子都要染黑，所以将所以叶子节点两两合并操作（使用操作二）
 * - 如果叶子节点个数是偶数，直接返回答案即可，所有叶子节点的代价
 * - 如果叶子节点个数是奇数，存在一个节点需要与其他节点相连（这个点就是树中代价最小的节点，这个点一定能被选到）
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (n == 1) {
        cout << 2 * a[0] << "\n";
        return;
    }
    if (n == 2) {
        cout << a[0] + a[1] << "\n";
        return;
    }

    // n >= 3
    int root = -1;
    vector<int> leaf;
    for (int u = 0; u < n; u++) {
        if (deg[u] == 1) {
            leaf.push_back(u);
        } else if (root == -1) {
            root = u;
        }
    }
    // 按照 a_i 大小排序
    sort(leaf.begin(), leaf.end(), [&](const auto& aa, const auto& bb) {
        return a[aa] < a[bb];
    });
    
    ll ans = 0;
    for (auto& e : leaf) {
        ans += a[e];
    }
    if (leaf.size() % 2 == 0) {
        cout << ans << "\n";
        return;
    }
    ll mi = LLINF;
    for (auto& e : a) {
        mi = min(mi, (ll)e);
    }
    ans += mi;
    cout << ans << "\n";
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









