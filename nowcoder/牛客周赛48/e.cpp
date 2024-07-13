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

void cal(string& s) {
    int n = s.size();
    ll all = 0;
    for (int len = 2; len <= n; len++) {
        all += 1ll * (n - len + 1) * (len >> 1);
    }

    vector<vector<int>> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'].push_back(i);
    }

    // 查询 最后一个n-a[index]>=dist的index
    auto bs = [&](vector<int>& a, int left, int right, int dist) {
        int pos = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (n - a[mid] >= dist) {
                left = mid + 1;
                pos = mid;
            } else {
                right = mid - 1;
            }
        }
        return pos;
    };

    for (int t = 0; t < 26; t++) {
        auto& v = cnt[t];
        int m = v.size();
        // 后缀
        vector<ll> sum(m);
        for (int i = m - 1; i >= 0; i--) {
            sum[i] = (i == m - 1 ? 0ll : sum[i + 1]) + (n - v[i]);
        }

        for (int i = 0; i < m; i++) {
            if (i + 1 >= m) {
                break;
            }
            ll delta = 0;
            ll dist = v[i] + 1;
            ll mid = bs(v, i + 1, m - 1, dist);
            if (mid == -1) {
                // 全部小于dist
                delta += sum[i + 1];
            } else {
                // mid != -1
                if (mid < m - 1) delta += sum[mid + 1];
                if (mid >= i + 1) {
                    delta += (mid - i) * dist;
                }
            }
            all -= delta;
        }
    }
    cout << all << "\n";
    return;
}

int main() {
    string s;
    cin >> s;
    cal(s);
    return 0;
}