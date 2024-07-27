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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 2) {
        if (a[0] == a[1]) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
        return 0;
    }

    // n >= 3
    ll mx = 0, sm = 0;
    for (ll e : a) {
        mx = max(mx, e);
        sm += e;
    }
    if (mx > sm / 2) {
        cout << 1 << "\n";
        return 0;
    }
    if (mx == sm / 2) {
        cout << 1 << "\n";
        return 0;
    }

    // 奇数
    if (sm & 1) {
        cout << n << "\n";
    } else {
        int gone = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 1) gone++;
        }
        cout << gone << "\n";
    }
    return 0;
}