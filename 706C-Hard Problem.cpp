#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 1e18;
const ll N  = 1e5+1, M = 10001;

ll n, c[N], dp[N][2];
string s[N], t[N];
ll solve(ll i, ll prev)
{
    if(i == n)return 0;
    ll &ret = dp[i][prev];
    if(~ret)return ret;
    ret = OO;
    if(i == 0)
    {
        ret = min(solve(i+1, 0), c[i]+solve(i+1,1));
    }
    else if(prev == 0)
    {
        if(s[i]>=s[i-1])ret = min(ret, solve(i+1, 0));
        if(t[i]>=s[i-1])ret = min(ret, c[i]+solve(i+1, 1));
    }
    else if(prev == 1)
    {
        if(s[i]>=t[i-1])ret = min(ret, solve(i+1, 0));
        if(t[i]>=t[i-1])ret = min(ret, c[i]+solve(i+1, 1));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        t[i] = s[i];
        reverse(t[i].begin(), t[i].end());
    }
    ll x = solve(0,0);
    if(x > 1e16)x=-1;
    cout << x;
    return 0;
}
