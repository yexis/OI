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

int a[200010];
int b[200010];
int st[501][200010];
int cnt[200010];
int n;
void solve() {
    cin >> n;
    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        us.insert(a[i]);
    }
    int z = us.size();
    // 对辅助数组进行排序并去重
    sort(b, b + n);  // 排序
    int zn = unique(b, b + n) - b;  // 去重，z 为去重后数组的长度
    auto get_id = [&](int x) -> int {
        return lower_bound(b, b + zn, x) - b;
    };
    for (int i = 0; i < n; i++) {
        a[i] = get_id(a[i]);
    }

    int sq = sqrt(n);
    for (int d = 1; d <= min(sq, z); d++) {
        int cur = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int l = 0, r = -1; l < n; l++) {
            while (r < n && cur <= d) {
                r++;
                if (r >= n) break;
                if (cnt[a[r]]++ == 0) {
                    cur++;
                }   
            }
            st[d][l] = r - 1;
            if (--cnt[a[l]] == 0) {
                cur--;
            }
        }
    }

    int f[n + 1];
    memset(f, INF, sizeof f);
    f[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int d = 1; d <= min(sq, z); d++) {
            int r = st[d][i];
            int len = r - i + 1;
            f[i] = min(f[i], min(d * d, len) + f[r + 1]);
            if (r == n - 1) {
                break;
            }
        }
    }

    cout << f[0] << "\n";
}

int main() {
    ios;
    solve();
    return 0;
}



