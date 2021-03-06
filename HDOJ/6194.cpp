// string string string, 2017 ACM/ICPC Asia Regional Shenyang Online, HDU6194

/*Sample Input
2
2
abcabc
3
abcabcabcabc
*/

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

const int maxn = 1 << 17;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], rnk[maxn], height[maxn];
void build_sa(int m, int n)
{ //  m为字符集大小(0~m-1)，n为字符串的长度
    n++;
    int *x = t, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 0; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
    int k = 0;
    n--;
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[rnk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rnk[i]] = k;
    }
}

int dp[maxn][30];
void initrmq(int n)
{
    for (int i = 1; i <= n; i++)
        dp[i][0] = height[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r)
{
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int lcp(int a, int b)
{
    a = rnk[a], b = rnk[b];
    if (a > b) swap(a, b);
    a++;
    return rmq(a, b);
}

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
        int k;
        scanf("%d", &k);
        scanf("%s", s);
        int n = strlen(s);
        build_sa(128, n);
        ll ans = 0;
        height[n + 1] = 0;
        if (k == 1)
            for (int i = 1; i <= n; i++)
                ans += max(0, n - sa[i] - max(height[i], height[i + 1]));
        else
        {
            initrmq(n);
            for (int i = 1; i <= n - k + 1; i++)
                ans += max(0, rmq(i + 1, i + k - 1) - max(height[i], height[i + k]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
