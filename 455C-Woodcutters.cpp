#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3f3f3f3f3f3f3f3fLL;
const ll N  = 1e5+1, M = 10001;

ll n, dp[N][3];
pair<ll, ll> p[N];
ll solve(int i, int prev)
{
    if(i == n-1)
        return 0;
    ll &ret = dp[i][prev];
    if(~ret) return ret;
    ret = 0;
    //ch1 leave
    //ch2 left
    //ch3 right
    ll ch1 = 0, ch2 = 0, ch3 = 0;
    if(prev <= 1)
    {//leave or left
        if(p[i].first-p[i].second > p[i-1].first)
        {
            ch2 = 1 + solve(i+1, 1);
        }
        if(p[i].first+p[i].second < p[i+1].first)
        {
            ch3 = 1+solve(i+1, 2);
        }
        ch1 = solve(i+1, 0);
    }
    else if(prev == 2)
    {// right
        if(p[i].first-p[i].second > p[i-1].first+p[i-1].second)
        {
            ch2 = 1 + solve(i+1, 1);
        }
        if(p[i].first+p[i].second < p[i+1].first)
        {
            ch3 = 1+solve(i+1, 2);
        }
        ch1 = solve(i+1, 0);
    }
    ret =  max(ret, max(ch1, max(ch2, ch3))); 
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
        cin >> p[i].first >> p[i].second;
    }        
    sort(p,p+n);
    ll ans = min(2LL, n);
    if(n == 1)
        return cout << 1, 0;
    ans += solve(1,0);
    cout << ans;
    return 0;
}
