#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 25;
int n, m;
ll a[maxn];
ll ans;

inline ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

void dfs(int now, ll x, int dep)
{
    x = lcm(a[now], x);
    if (dep & 1)ans += n / x;
    else ans -= n / x;
    for (int i = now + 1; i < m; i++)
        dfs(i, x, dep + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        ans = 0;
        for (int i = 0; i < m; i++)
            dfs(i, a[i], 1);
        cout << ans << endl;
    }
    return 0;
}
