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
#include <climits>
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using pii = pair<int, int>;
struct DJ {
    int n, count, mix;
    vector<int> fa;
    DJ(int nn) {
        n = nn;
        count = n;
        mix = INT_MAX;
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y, int z) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        fa[ry] = rx;
        mix = min(mix, z);
        count--;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[i] = array<int, 3>{z, x - 1, y - 1};
    }
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].first >> qs[i].second;
    }
    sort(e.begin(), e.end(), greater<>());

    const int inf = 1e9 + 10;
    vector<int> val(n, -inf);
    DJ dj(n);
    for (int i = 0; i < m; i++) {
        auto [z, x, y] = e[i];
        dj.merge(x, y, z);
        int cnt = dj.count;
        val[cnt] = max(val[cnt], dj.mix);
    }
    for (int i = 0; i < n; i++) {
        cout << val[i] << '\n';
    }

    for (auto [l, r] : qs) {
        if (val[r] == -inf) {
            cout << "NO ANSWER" << '\n';
        }  else {
            cout << val[r] << '\n';
        }
    }
    return 0;
}