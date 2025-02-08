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
 * 
*/

void solve() {
    int N;
    cin >> N;
    vector<vector<int> > a(N);
    for (int i = 0; i < N; i++) {
        int cnt;
        cin >> cnt;
        a[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> a[i][j];
        }
    }

    vector<unordered_map<int, double> > mp(N + 1);
    for (int i = 0; i < N; i++) {
        auto& vec = a[i];
        int sz = vec.size();
        unordered_map<int, int> cnt;
        for (auto& e : vec) {
            cnt[e]++;
        }
        for (auto& [k, v] : cnt) {
            mp[i][k] = (double)v / sz;
        }
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double t = 0;
            auto& mp1 = mp[i];
            auto& mp2 = mp[j];
            for (auto& [k, v] : mp1) {
                if (mp2.count(k)) {
                    t += v * mp2[k];
                }
            }
            ans = max(ans, t);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(15);

    solve();
    return 0;
}