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
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        multiset<int> s;  // 使用multiset方便进行数字的删除和查找操作

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);  // 将原始数字插入到multiset中
        }

        auto check = [&](int mid) {
            unordered_set<int> st;
            for (int i = 0; i < n; i++) {
                int t = a[i];
                while (t > mid) {
                    t /= 2;
                }
                while (t != 0 && st.count(t)) {
                    t /= 2;
                }
                st.insert(t);
            }
            return st.size() == mid + 1;
        };

        int ans = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans + 1 << "\n";

    }
    return 0;
}