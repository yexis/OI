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

// not pass
// 1 3 5
// 2 4 6
void solve() {
    int n;
    cin >> n;
    int s1 = 0, s2 = 0;
    set<int> st1, st2;
    int mi1 = -1, mx1 = -1;
    int mi2 = -1, mx2 = -1;

    vector<int> a(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        s2 += i;
    }
    mi2 = 1, mx2 = n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = 0;
        if (x == mx2) {
            while (x >= 1 && a[x] == 0) {
                x--;
            }
        }
        mx2 = x;
    }
    cout << ans << "\n";
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}