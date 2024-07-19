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

    auto cal = [&](string& s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            ans += d;
            ans %= 3;
        }
        return ans;
    };
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ans += cal(s);
        ans %= 3;
    }
    if (ans == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}