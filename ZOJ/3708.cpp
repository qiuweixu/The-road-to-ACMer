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

int a[500], b[500];
bool G[505][505];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        int cnt = 0;
        clr(G, 0);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) scanf("%d", a + i);
        for (int i = 0; i < m; i++) scanf("%d", b + i);
        for (int i = 0; i < m; i++)
        {
            if (G[a[i]][b[i]] || G[b[i]][a[i]]) continue;
            G[a[i]][b[i]] = 1;
            cnt++;
        }
        double ans = cnt * 1.0 / n;
        printf("%.3f\n", ans);
    }
    return 0;
}
