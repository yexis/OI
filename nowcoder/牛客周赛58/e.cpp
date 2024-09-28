#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

/*
 * index: 1   2   3   4   5
          0   0   0   0   0
          0   0   0   0   4
          0   0   0   3   3
          0   0   2   2   2
          0   1   1   1   1 or 5 (这里还能取5的原因是，a_5已经是最后一个元素，所以a_i不用满足a_i<i这个条件)
 */
void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n + 1 << "\n";
    } else if (m == 2) {
        cout << n << "\n";
    } else if (m == 3) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}