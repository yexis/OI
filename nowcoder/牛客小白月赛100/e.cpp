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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int N = *max_element(a.begin(), a.end());;
    vector<int> b(N + 1);
    for (auto& e : a) {
        b[e] = 1;
    }

    vector<int> R(N + 1);
    int right = N;
    for (int i = N; i >= 0; i--) {
        if (b[i]) {
            right = i;
        }
        R[i] = right;
    }


    int fi = right;
    auto cal = [&](int d) -> int {
        int ans = d;
        int t = fi;
        while (t <= N) {
            t += d + 1;
            if (t <= N) t = R[t];
            ans += 1;
        }
        return ans;
    };

    int ans = N;
    for (int d = 0; d <= N; d++) {
        int ts = cal(d);
        ans = min(ans, ts);
    }
    cout << ans << "\n";
    return 0;
}