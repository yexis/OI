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
    auto bs = [&](ll l, ll r, int i) {
        ll pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sum[mid + 1] - sum[i] > sum[n] - sum[mid + 1]) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    };

    ll ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        int i2 = upper_bound(sum.begin(), sum.end(), 2ll * sum[i + 1]) - sum.begin();
        if (i2 == sum.size()) {
            continue;
        }
        i2--;

        int i3 = bs(i2, sum.size() - 1, i + 1);
        if (i3 == -1 || i3 >= n - 1) {
            continue;
        }
        ans += n - 1 - i3;
    }
    cout << ans << "\n";
    return 0;
}