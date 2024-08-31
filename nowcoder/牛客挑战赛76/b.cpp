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
    string s;
    cin >> n;
    cin >> s;
    vector<ll> f(n);
    vector<int> see(26);
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        int d = s[i] - 'a';
        cnt[d]++;
        if(i - 1 >= 0) f[i] = f[i - 1];
        if (not see[d]) {
            f[i] += 1;
        }
        see[d] = true;
    }

    ll ans = 0;
    vector<int> se(26);
    for (int i = n - 1; i >= 0; i--) {
        int d = s[i] - 'a';
        if (not se[d]) {
            ans += f[i];
        }
        se[d] = true;
    }
    for (int d = 0; d < 26; d++) {
        if (cnt[d] > 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}