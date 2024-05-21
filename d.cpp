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

int x[4][2] = {{2, 1}, {1, 2}, {0, 1}, {1, 0}};

ll f(ll a, ll b, ll c, ll d)
{

    ll t = a / 4 * 4;
    a -= t;
    c -= t;
    while (a < 0)
    {
        a += 4;
        c += 4;
    }

    t = b / 2 * 2;
    b -= t;
    d -= t;
    while (b < 0)
    {
        b += 2;
        d += 2;
    }

    if (c - a <= 4 && d - b <= 2)
    {
        int v = 0;
        for (int i = a; i < c; ++i)
            for (int j = b; j < d; ++j)
                v += x[i % 4][j % 2];
        return v;
    }

    if (c > 4)
    {
        ll x = (a + 3) / 4 * 4;
        ll y = c / 4 * 4;
        return f(a, b, x, d) + (y - x) / 4 * f(0, b, 4, d) + f(y, b, c, d);
    }

    ll x = (b + 1) / 2 * 2;
    ll y = d / 2 * 2;
    return f(a, b, c, x) + f(a, 0, c, 2) * (y - x) / 2 + f(a, y, c, d);
}

ll A, B, C, D;

int main()
{

    cin >> A >> B >> C >> D;
    cout << f(A, B, C, D) << '\n';
}
