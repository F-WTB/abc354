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

int N;

int main()
{
    cin >> N;
    vector<pair<pr, int>> v;
    for (int i = 0; i < N; ++i)
    {
        int A, C;
        cin >> A >> C;
        v.emplace_back(make_pair(C, A), i);
    }
    sort(v.begin(), v.end());

    vector<int> ans;
    int x = -1;

    for (int i = 0; i < N; ++i)
    {
        if (v[i].first.second < x)
            continue;
        ans.push_back(v[i].second);
        chmax(x, v[i].first.second);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << (i < ans.size() - 1 ? '\t' : '\n');
}
