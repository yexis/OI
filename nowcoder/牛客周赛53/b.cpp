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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int a = s[i] - 'a', b = s[j] - 'a';
        if (a > b) swap(a, b);
        ans += min(b - a, a + 26 - b);
    }
    cout << ans << "\n";

    return 0;
}