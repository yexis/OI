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

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

// 2^0 = 1
// 2^10 = 10000000000
/*
 * | : 记录所有出现的1的位
 * & : 记录每一位都是1的位
 *
 * 第i位是1在[l,r]中出现过，但不能每个数的第i位都是1
 *
 * [k1, k2 - 1] 任意以为是1都可以
 * 1 :0
 * 1 2: 3
 * 1 2 5: 7
 */

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>h(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<pair<int, int>> pr;
    for (int i = 0; i < n; i++) {
        pr.emplace_back(x[i], h[i]);
    }
    sort(pr.begin(), pr.end());

    deque<pair<int, int>> he;
    he.emplace_back(n - 1, n - 1);
    for (int i = n - 2; i >= 0; i--) {
        auto [xi, hi] = pr[i];
        int k = lower_bound(pr.begin(), pr.end(), xi + hi, [&](const auto& aa, const auto& bb) {
            return aa.first <= bb;
        }) - pr.begin();
        k--;
        if (k < i) continue;
        // k >= i ===== max[i, k]
        int mx = i;
        while (he.size() && he.front().first <= k) {
            mx = max(mx, he.front().second);
            he.pop_front();
        }
        he.emplace_front(i, mx);
    }

    int hm = he.size();
    if (hm <= m) {
        cout << n << "\n";
        return;
    }
    priority_queue<int> pq;
    for (int i = 0; i < hm; i++) {
        pq.emplace(he[i].second - he[i].first + 1);
    }

    int ans = 0;
    while(m--) {
        auto x = pq.top();
        ans += x;
        pq.pop();
    }
    cout << ans << "\n";
    return;

}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}

/*
1
5 4
1 4 1 1 2
1 2 3 6 8

1
6 1
1 1 1 3 2 1
4 3 2 7 9 11
 */