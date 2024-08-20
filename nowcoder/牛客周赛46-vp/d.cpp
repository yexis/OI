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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int mx = max({a, b, c});

    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());

    if (k == v[0] || k == v[1] || k == v[2]) {
        cout << 0 << "\n";
        return;
    }

    if (k == 0) {
        cout << 1 << "\n";
    } else if (k == 1) {
        if (v[0] == 0 || v[1] == 0 || v[2] == 0) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    } else if (k == 2) {
        bool zero = (v[0] == 0 || v[1] == 0 || v[2] == 0);
        bool one = (v[0] == 1 || v[1] == 1 || v[2] == 1);
        if (zero && one) {
            cout << 1 << "\n";
        } else if (zero) {
            cout << 2 << "\n";
        } else if (one) {
            cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    } else {
        cout <<  -1 << "\n";
    }
    return;

}
int main() {

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}