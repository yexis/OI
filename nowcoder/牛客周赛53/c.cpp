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
    string s;
    cin >> s;
    int x, y, z;
    cin >> x >> y >> z;
    int one = 0, zero = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zero++;
            ans = min(zero, one);
        } else {
            one++;
        };
    }
    cout << min(ans, y) << "\n";
    return 0;
}