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
using pii = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v{a, b, c};
    sort(v.begin(), v.end());
    int ans = 0;
    if (v[0] > 1) {
        ans = a * b * c;
    }  else {
        ans = (a + b) * c;
    }
    cout << ans << '\n';
    return 0;
}