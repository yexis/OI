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

const int inf = 1e9;
int check(int a, int b) {
    if (a > 0 && a < b) {
        return -1;
    }
    if (a == 0 && b == 0) {
        return inf;
    } else if (a == 0) {
        return -1;
    } else if (b == 0) {
        return -1;
    }
    if (a % b == 0) {
        return  a / b;
    }
    return -1;
}

int main() {
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    int a = check(x, z);
    int b = check(y, w);

    if (a == -1 || b == -1) {
        cout << -1 << "\n";
        return 0;
    }
    if (a == inf) {
        cout << b << "\n";
        return 0;
    }
    if (b == inf) {
        cout << a << "\n";
        return 0;
    }
    if (a != b) {
        cout << -1 << "\n";
        return 0;
    }
    cout << a << "\n";
    return 0;
}