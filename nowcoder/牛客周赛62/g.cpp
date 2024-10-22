#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

/*
 * 0/1背包
 * 动态规划逆推
 * dp逆推
 * 讲解：https://www.bilibili.com/video/BV1EYxkerEQN?spm_id_from=333.788.videopod.episodes&vd_source=a5e205ce7c5908e561eb8023831ffff2&p=4
 *
 * 向原点方向移动：x < 0时，只能往右移动；x > 0时，只能往左移动。
 * 实际上不需要考虑x的位置，因为如果存在一条路径能达到原点，假设移动的距离有[-x0,+x1,+x2,...,-xk]，其中+表示向右移动，-表示向左移动
 * 将 [-x0,+x1,+x2,...,-xk] 以任意顺序进行移动，最终都会达到原点；
 * 且[-x0,+x1,+x2,...,-xk]的所有排列中，一定存在一个排列满足题目要求 (向原点方向移动)
 *
 *
*/

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector dp(110, vector<int>(30010, INF));
    int sum = 0;
    set<int> s;
    vector pos(110, vector<int>());
    const int M = 10000;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(i);
        sum += a[i];
        pos[a[i]].emplace_back(i);
    }

    dp[0][M + x] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = -M; j <= M; j++) {
            dp[i + 1][M + j] = dp[i][M + j];
        }
        for (int j = -M; j <= M; j++) {
            if (j + a[i] <= M) {
                dp[i + 1][M + j + a[i]] = min(dp[i + 1][M + j + a[i]], dp[i][M + j] + a[i]);
            }
            if (j - a[i] >= -M) {
                dp[i + 1][M + j - a[i]] = min(dp[i + 1][M + j - a[i]], dp[i][M + j] + a[i]);
            }
        }
    }

    if (dp[n][M] == INF) {
        cout << sum << "\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << "\n";
        return;
    }

    cout << dp[n][M] << "\n";
    vector<int> to_left, to_right;
    int j = 0, val = dp[n][M];
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i][M + j] == dp[i + 1][M + j]) {
            continue;
        }
        // 从右边转移过来
        if (j + a[i] <= M && dp[i][M + j + a[i]] + a[i] == dp[i + 1][M + j]) {
            to_left.emplace_back(pos[a[i]].back());
            s.erase(pos[a[i]].back());
            pos[a[i]].pop_back();
            j += a[i];
            val -= a[i];
        }
        // 从左边转移过来
        if (j - a[i] >= -M && dp[i][M + j - a[i]] + a[i] == dp[i + 1][M + j]) {
            to_right.emplace_back(pos[a[i]].back());
            s.erase(pos[a[i]].back());
            pos[a[i]].pop_back();
            j -= a[i];
            val += a[i];
        }
    }

    vector<int> ans;
    while (x) {
        cout << x << " " << to_left.size() << " " << to_right.size() << "\n";
        if (x < 0) {
            x += a[to_right.back()];
            ans.emplace_back(to_right.back());
            to_right.pop_back();
        } else {
            x -= a[to_left.back()];
            ans.emplace_back(to_left.back());
            to_left.pop_back();
        }
    }
    for (auto& e : ans) {
        cout << e + 1 << " ";
    }
    for (auto& e : s) {
        cout << e + 1 << " ";
    }
    cout << "\n";
}


int main() {
    solve();
}