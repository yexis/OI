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
using lll = __int128;
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

void scan(lll &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}

void print(lll x)//输出
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x/10);
    putchar(x%10 + '0');
}

void println(ll x) {
    print(x);
    putchar('\n');
}


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

unordered_map<int, unordered_map<int, bitset<100> > > Div;

void solve() {
    Div.clear();
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> fa(n, -1);
    vector<vector<int> > g(n);

    vector<bitset<100> > DI(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        fa[v] = u;
        cin >> DI[v];
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }


    auto dfs = [&](auto&& dfs, int u, int o) -> void {
        for (auto& v : g[u]) {
            if (v == o) {
                continue;
            }
            DI[v] = DI[u] ^ DI[v];
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1);

    bitset<100> ans = 0;
    if (m & 1) {
        ans ^= DI[a[0]];
        ans ^= DI[a[m - 1]];
    } else {
        for (int i = 1; i < m - 1; i++) {
            ans ^= DI[a[i]];
        }
    }

    string ss = ans.to_string().substr(100 - L, L);
    cout << ss << "\n";
}

int main() {
    solve();
    return 0;
}