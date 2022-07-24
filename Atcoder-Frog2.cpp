#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

ll n, k;
ll dp[N], a[N];
ll solve(ll i)
{
    if(i == n-1)return 0;
    ll &ret = dp[i];
    if(ret!=-1)
        return ret;
    ret = OO;
    for(int x=1;x<=k;x++)
    {
        if(i+x>=n)continue;
        ret = min(ret, solve(i+x)+ abs(a[i+x] - a[i]));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << solve(0);
    return 0;
}
