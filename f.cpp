#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int T, N, A[200000];

int dp[200001], l[200000], r[200000];

int main()
{
    cin >> T;
    for (int _ = 0; _ < T; ++_)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        dp[0] = 0;
        fill(dp + 1, dp + N + 1, 2e9);
        fill(l, l + N, 0);

        for (int i = 0; i < N; ++i)
        {
            int idx = lower_bound(dp, dp + N + 1, A[i]) - dp;
            dp[idx] = A[i];
            l[i] = idx - 1;
        }

        dp[0] = 2e9;
        fill(dp + 1, dp + N + 1, 0);
        fill(r, r + N, 0);

        for (int i = N - 1; i >= 0; --i)
        {
            int idx = lower_bound(dp, dp + N + 1, A[i], greater<int>()) - dp;
            dp[idx] = A[i];
            r[i] = idx - 1;
        }

        const int x = *max_element(l, l + N);

        vector<int> ans;
        for (int i = 0; i < N; ++i)
            if (l[i] + r[i] == x)
                ans.push_back(i + 1);

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << (i < ans.size() - 1 ? '\t' : '\n');
    }
}
