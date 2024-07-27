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
    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }

    vector<int> neg, pos;
    for (auto& e : a) {
        if (e <= 0) {
            neg.push_back(e);
        } else {
            pos.push_back(e);
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    // 全正数
    if (neg.size() == 0) {
        cout << pos.back() << "\n";
        return 0;
    }

    // 全负数，没有正数
    if (pos.size() == 0) {
        // 全0的情况
        if (neg[0] == 0 && neg.back() == 0) {
            cout << 0 << "\n";
            return 0;
        }

        // 负数 + 0
        int max_neg = -1e9;
        for (auto& e : neg) {
            if (e < 0) {
                max_neg = max(max_neg, e);
            }
        }
        cout << max_neg << "\n";
        return 0;
    }


    // 正数 + 负数 + 0
    unordered_set<int> st{0};
    for (int i = 0; i < pos.size() - 1; i++) {
        auto cp = st;
        for (auto& e : cp) {
            st.insert(e + pos[i]);
        }
    }

    vector<int> v{st.begin(), st.end()};
    sort(v.begin(), v.end());

    unordered_set<int> tt{neg[0]};
    for (int i = 1; i < neg.size(); i++) {
        auto cp = tt;
        for (auto& e : cp) {
            tt.insert(e + neg[i]);
        }
    }

    int ans = neg[0];
    for (auto r : tt)  {
        r = -r;
        // 0忽略
        int k = upper_bound(v.begin(), v.end(), r) - v.begin();
        k--;
        int diff = abs(r - v[k]);
        ans = max(ans, pos.back() - diff);
    }
    cout << ans << "\n";
    return 0;
}
/*
6
0 0 0 0 0 90

3
-1 -1 -2

 5
 1 1 1 -2 -2
 4
 100 -101 200 -199

5
98 -40 -60 1 100
 */