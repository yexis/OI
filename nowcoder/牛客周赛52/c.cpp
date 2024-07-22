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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> b, c;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            c.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }

    unordered_map<int, int> cnt;
    for (auto& e : c) cnt[e]++;
    for (auto& [k, v] : cnt) v &= 1;
    c.resize(0);
    for (auto& [k, v] : cnt) {
        if (v) {
            c.push_back(k);
        }
    }
    sort(c.begin(), c.end());
    int nn = b.size(), mm = c.size();
    if (nn <= mm) {
        cout << mm - nn << "\n";
        return 0;
    }
    // nn >= mm
    nn -= mm;
    if (nn & 1) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}