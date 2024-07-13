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

int main() {
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k1 >= 62) {
        cout << 0 << "\n";
        return 0;
    }
    k1 = min(k1, 62ll);
    k2 = min(k2, 62ll);

    auto cal = [&](ll k) -> ll {
        ll ans = 0;
        vector<int> L(64, -1);
        for (int i = 0; i < n; i++) {
            auto CL = L;
            for (int d = 0; d < 62; d++) {
                if (i == 0) {
                    L[d] = -1;
                } else {
                    if ((a[i] >> d & 1) == (a[i - 1] >> d & 1)) {
                        L[d] = CL[d];
                    } else {
                        L[d] = i - 1;
                    }
                }
            }
            int aa = -1, bb = -1;
            for (int d = 0; d < 62; d++) {
                if (d < k) {
                    aa = max(aa, L[d]);
                } else {
                    // d >= k
                    bb = max(bb, L[d]);
                }
            }
            ans += max(0, aa - bb);
        }
        return ans;
    };

    cout << cal(k2) - cal(k1) << "\n";
    return 0;
}