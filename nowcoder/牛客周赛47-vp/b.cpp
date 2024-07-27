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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> cnt(26);
    for (auto& ss : s) {
        int ex[26];
        memset(ex, 0, sizeof(ex));
        for (int i = 0; i < ss.size(); i++) {
            ex[ss[i] - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (ex[i]) {
                cnt[i]++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= n) {
            char ch = 'a' + i;
            cout << ch << "\n";
            return 0;
        }
    }
    return 0;
}