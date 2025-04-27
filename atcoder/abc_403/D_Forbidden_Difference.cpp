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
 * https://atcoder.jp/contests/abc403/tasks/abc403_d
 * 打家劫舍
*/

void solve() {
    int N, D;
    cin >> N >> D;
    vector<int> a(N);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());

    if (D == 0) {
        a.erase(unique(a.begin(), a.end()), a.end());
        cout << N - (int)a.size() << "\n";
        return;
    }

    // D >= 1
    int mx = a.back();
    vector<int> cnt(1000010);
    for (int i = 0; i < N; i++) {
        cnt[a[i]]++;
    }

    vector<int> vis(mx + 1);
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        int x = a[i];
        if (vis[x]) continue;
        while (x <= mx) {
            if (cnt[x]) {
                mp[a[i]].push_back(x);
                vis[x] = true;
            } else {
                break;
            }
            x += D;
        }
    }

    // 背包DP 选与不选
    auto cal = [&](auto& b) -> int {
        int bn = b.size();
        int dp[bn + 1]; dp[0] = 0;
        for (int i = 1; i <= bn; i++) {
            int x = b[i - 1];
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], (i - 2 >= 0 ? dp[i - 2] : 0) + cnt[x]);
        }
        return dp[bn];
    };
    int ans = 0;
    for (auto& [k, b] : mp) {
        int bn = b.size();
        if (bn == 0) continue;
        int tot = 0; 
        for (auto& e : b) tot += cnt[e];
        int t = cal(b);
        ans += tot - t;
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}










