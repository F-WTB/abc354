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

int N, A[18], B[18];

vector<int> op;

map<int, bool> b;
map<int, bool> m;

bool f(int x)
{
    if (b[x])
        return m[x];
    b[x] = 1;
    for (int y : op)
        if ((x & y) == y && !f(x ^ y))
        {
            m[x] = 1;
            return 1;
        };

    return 0;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (A[i] == A[j] || B[i] == B[j])
                op.push_back(1 << i | 1 << j);

    cout << (f((1 << N) - 1) ? "Takahashi" : "Aoki") << '\n';
}
