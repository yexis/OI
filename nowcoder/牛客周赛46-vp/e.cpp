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
using pil = pair<int, ll>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(b[i], i);
    }

    vector<array<ll, 3> > pr;
    pr.push_back({0, 0, sum});
    while (pq.size()) {
        int cs = sum;
        auto [b, i] = pq.top();
        while (pq.size() && pq.top().first == b) {
            auto [bb, ii] = pq.top();
            sum -= a[ii];
            pq.pop();
        }
        pr.push_back({b, pr.back()[1]+ (b - pr.back()[0]) * cs, sum});
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int d;
        cin >> d;
        int k = lower_bound(pr.begin(), pr.end(), d, [&](const auto& aa, const auto& bb) {
            return aa[0] <= bb;
        }) - pr.begin();
        ll ans = pr[k - 1][1] + (d - pr[k - 1][0]) * pr[k - 1][2];
        cout << ans << "\n";
    }

    return 0;
}