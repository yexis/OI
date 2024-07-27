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
    int k;
    string s;
    cin >> k;
    cin >> s;

    int n = s.size();
    vector<int> fac;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            fac.push_back(i);
        }
    }

    auto check = [&](int loop) {
        int used = 0;
        for (int i = 0; i < loop; i++) {
            int sum = 0;
            vector<int> cnt(26);
            for (int j = i; j < n; j += loop) {
                sum++;
                cnt[s[j] - 'a']++;
            }
            int mx = 0;
            for (int jj = 0; jj < 26; jj++) {
                mx = max(mx, cnt[jj]);
            }
            used += sum - mx;
        }
        return used <= k;
    };

    int nn = fac.size();
    int ans = nn - 1;
    int l = 0, r = nn - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(fac[mid])) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << fac[ans] << "\n";
    return 0;
}