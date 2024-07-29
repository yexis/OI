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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    int target;
    cin >> target;

    unordered_set<int> st(a[0].begin(), a[0].end());
    for (int i = 1; i < n; i++) {
        unordered_set<int> cp;
        for (int j = 0; j < m; j++) {
            for (auto& e : st) {
                if (a[i][j] + e <= 5100) {
                    cp.insert(a[i][j] + e);
                }
            }
        }
        st = cp;
    }

    int ans = target;
    for (auto& v : st) {
        ans = min(ans, abs(v - target));
    }
    cout << ans << "\n";
    return 0;
}