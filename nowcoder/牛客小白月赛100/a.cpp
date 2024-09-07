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

bool check(vector<ll> v) {
    sort(v.begin(), v.end());
    return v[0] + v[1] > v[2];
}

int main() {
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];
    for (int i = 0; i < 3; i++) {
        v[i] *= 2;
        if (check(v)) {
            cout << "Yes" << "\n";
            return 0;
        }
        v[i] /= 2;
    }
    cout << "No" << "\n";

    return 0;
}