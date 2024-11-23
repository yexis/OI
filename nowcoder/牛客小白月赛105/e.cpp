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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
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
 * 树状数组
 * cc: 对于一个数组数组，当要反向计算区间[pos,n]的元素和时，使用bit.ask(n) - bit.ask(pos)
*/

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) {
        this->n = n;
        tree.resize(n + 1);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    }

    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 2 * n;


    stack<int> stk;
    vector<int> index(m);
    vector<int> P(m);
    int idx = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '(') {
            index[i] = ++idx;
            stk.push(i);
        } else if (s[i] == ')') {
            if (stk.size() <= 0) {
                cout << -1  << "\n";
                return;
            }
            auto u = stk.top();
            stk.pop();
            index[i] = index[u];
            P[u] = i;
        }
    }

    BIT bit(m);
    vector<int> res(n + 1);
    for (int i = 0; i < m; i++) {
        if (s[i] == ')') {
            bit.add(i + 1, -1);
            continue;
        }
        int p = P[i];
        res[index[i]] = n - 1 - (bit.ask(m) - bit.ask(p));
        bit.add(p + 1, 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}