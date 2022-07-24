#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

ll n;
ll dp[N], a[N];
ll sol(ll i)
{
    if(i == n-1)return 0;
    ll &ret = dp[i];
    if(ret!=-1)
        return ret;
    ret = OO;
    if(i+1<n)ret = min(ret, sol(i+1) + abs(a[i+1]-a[i]));
    if(i+2<n)ret = min(ret, sol(i+2) + abs(a[i+2]-a[i]));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << sol(0);
    return 0;
}
