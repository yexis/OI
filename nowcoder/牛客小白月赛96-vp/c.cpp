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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int xf = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }

    ll ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        int i2 = lower_bound(sum.begin() + 1, sum.end(), -1, [&](const auto& aa, const auto& bb) {
            // lower_bound:返回第一个不满足的条件
            // 例如：a < b，则返回第一个 >=a 的位置
            return aa - sum[i + 1] <= sum[i + 1];
        }) - sum.begin();
        if (i2 == sum.size()) {
            continue;
        }

        int i3 = lower_bound(sum.begin() + i2, sum.end(), -1, [&](const auto& aa, const auto& bb) {
            // 第一个不满足的条件
            return aa - sum[i + 1] <= sum[n] - aa;
        }) - sum.begin();
        ans += max(0, n - i3);
    }
    cout << ans << "\n";
    return 0;
}