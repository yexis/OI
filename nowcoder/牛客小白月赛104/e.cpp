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
 * 
*/
const int N = 200010;
const int M = 200010;
struct edge {
    // 对端
    int v;
    // 下一条边
    int ne;
} e[M];

int h[N];
int vis[N];
int match[N];
int idx = 0;

void add(int a, int b) {
    e[++idx] = {b, h[a]};
    h[a] = idx;
}

bool dfs(int u) {
    for (int i = h[u]; i; i = e[i].ne) {
        int v = e[i].v;
        if (vis[v]) {
            continue;
        }
        vis[v] = 1;
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int ii = 0 ; ii < cnt; ii++) {
            int x;
            cin >> x;
            add(i, n + x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) {
            ans++;
        }
    }
    if (ans < n) {
        cout << "kou is angry" << "\n";
        return;
    }

    for (int i = n + 1; i <= n + n; i++) {
        cout << match[i] << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}




