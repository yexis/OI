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
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    vector<pair<ll, ll>> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].first >> qs[i].second;
    }


    // cal
    ll pre[105][n + 1];
    ll sum[n + 1];
    memset(sum, 0, sizeof(sum));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 100; j++) {
            pre[j][i + 1] = pre[j][i] + (a[i] == j);
        }
        sum[i + 1] = sum[i] + max(0ll, -a[i]);
    }

    for (auto& p : qs) {
        int x = 0, ans = 0;
        auto [l, r] = p;
        l--;
        ll now = sum[r] - sum[l];
        for (int j = 1; j <= 100; j++) {
            ll val = pre[j][r] - pre[j][l];
            if (val * j <= now) {
                now -= j * val;
                ans += val;
            } else {
                ans += now / j;
                break;
            }
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}
