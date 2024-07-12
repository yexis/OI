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
    int n, L, R;
    cin >> n >> L >> R;
    string s;
    cin >> s;

    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '1');
    }

    int dp[n][n];
    memset(dp, -1, sizeof(dp));
    auto dfs = [&](auto&& dfs, int i, int j) {
        if (j - i <= 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        for (int k = i; k < j; k++) {
            int left = (k - i + 1) - (sum[k + 1] - sum[i]);
            int right = sum[j + 1] - sum[k + 1];
            int diff = abs(left - right);
            if (diff >= L && diff <= R) {
                ans = max(ans, 1 + dfs(dfs, i, k) + dfs(dfs, k + 1, j));
            }
        }
        return dp[i][j] = ans;
    };
    cout << dfs(dfs, 0, n - 1) << "\n";
    return 0;
}