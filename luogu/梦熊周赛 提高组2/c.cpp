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


bool fg = false;
constexpr static int maxn = 5010;
vector<int> fac[maxn];
void init(){
    for (int i = 1; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            fac[j].push_back(i);
        }
    }
}

int main() {
    if (!fg) {
        init();
        fg = true;
    }
    int n, p;
    cin >> n >> p;


    auto tos = [&](vector<ll>& mask) -> string {
        string s;
        for (auto& e : mask) {
            s += to_string(e) + "_";
        }
        return s;
    };
    auto check = [&](vector<ll>& mask, int v) -> bool {
        int c = v / 64;
        int r = v % 64;
        if (mask[c] >> r & 1) {
            return true;
        }
        return false;
    };

    unordered_map<string, unordered_map<int, ll> > dp;
    auto dfs = [&](auto&& dfs, int v, vector<ll>& mask) -> ll {
        if (v == 1) {
            return 1;
        }
        string s = tos(mask);
        if (dp.count(s) && dp[s].count(v)) {
            return dp[s][v];
        }

        ll ans = 0;
        // 向上
        if (v + 1 <= n && !check(mask, v + 1)) {
            int c = (v + 1) / 64, r = (v + 1) % 64;
            mask[c] |= (1ll << r);
            ans += dfs(dfs, v + 1, mask);
            ans %= p;
            mask[c] ^= (1ll << r);
        }
        // 向下
        if (v - 1 >= 1 && !check(mask, v - 1)) {
            int c = (v - 1) / 64, r = (v - 1) % 64;
            mask[c] |= (1ll << r);
            ans += dfs(dfs, v - 1, mask);
            ans %= p;
            mask[c] ^= (1ll << r);
        }

        // 因子
        for (auto& fa : fac[v]) {
            if (check(mask, fa)) continue;
            if (fa == v) continue;
            int c = fa / 64, r = fa % 64;
            mask[c] |= (1ll << r);
            ans += dfs(dfs, fa, mask);
            ans %= p;
            mask[c] ^= (1ll << r);
        }
        return dp[s][v] = ans;
    };

    int nn = n / 64 + 1;
    vector<ll> mask(nn);
    int c = n / 64, r = n % 64;
    mask[c] |= (1 << r);
    cout << dfs(dfs, n, mask) % p << "\n";
}