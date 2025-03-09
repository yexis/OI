#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

// 快速幂计算逆元
ll modPow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    // 计算陡峭值的期望
    ll total = 0;
    for (int i = 0; i < n; i++) {
        total = (total + a[i] * i) % MOD;         // 正向贡献
        total = (total - a[i] * (n - i - 1)) % MOD; // 逆向贡献
    }

    // 计算最终结果
    total = (total * 2 % MOD + MOD) % MOD;  // 防止负数
    ll invN = modPow(n, MOD - 2, MOD);      // n 的逆元
    cout << total * invN % MOD << endl;

    return 0;
}
