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

struct DJ {
    int n;
    vector<int> fa;
    vector<int> count;
    DJ(int nn) {
        n = nn;
        fa = vector<int>(n);
        iota(fa.begin(), fa.end(), 0);
        count = vector<int>(n, 1);
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        fa[ry] = rx;
        count[rx] += count[ry];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    unordered_map<int, vector<int>> um;
    for (int i = 0; i < n; i++) {
        um[b[i]].push_back(i);
    }

    DJ dj(n);
    for (auto& [k, vs] : um) {
        if (vs.size() == 1) {
            cout << -1 << "\n";
            return 0;
        }
        for (int i = 0; i < vs.size() - 1; i++) {
            dj.merge(vs[i], vs[i + 1]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ri = dj.find(i);
        if (ri != i) continue;
        int c = dj.count[ri];
        if (c & 1) {
            ans += c / 2 + 1;
        } else {
            ans += c / 2;
        }
    }
    cout << ans << "\n";

    return 0;
}