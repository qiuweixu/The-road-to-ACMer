#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto& t : v) cin >> t;
    ll ans = accumulate(v.begin(), v.end(), 0LL);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum * 2 >= ans) return cout << i + 1, 0;
    }
    return 0;
}