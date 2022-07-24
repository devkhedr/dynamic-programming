#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 4e5;

int n,k;
ll dp[N][2];
vector<int>a;
ll solve(int i, int prev)
{
    if(i>=n)
        return 0;
    ll &ret = dp[i][prev];
    if(~ret)return ret;
    ll choice1 = solve(i+1, prev), choice2 = 0;
    if(prev == 0)
    {
        choice2 = a[i] + solve(i+1, 1);
    }
    else if(prev == 1)
    {
        choice2 = -a[i]+solve(i+1, 0);
    }
    return ret = max(choice1, choice2);
}
void testCase()
{
    clr(dp, -1);
    cin >> n >> k;
    a = vector<int>(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << solve(0,0) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;    cin >> T;
    while(T--)
        testCase();
    return 0;
}
