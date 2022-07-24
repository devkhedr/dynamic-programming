#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e2+4, M = 10001;

ll n, a[N];
bool sp[N], con[N];
ll dp[N][3];
int check(int i, int prev)
{
    if(i>= n)
        return 0;
    ll &ret = dp[i][prev];
    if(ret != -1)
        return ret;
    ll choice1= check(i+1, 0), choice2=0, choice3 = 0;
    if(prev == 0)
    {
        if(sp[i])choice2 = 1+check(i+1, 1);
        if(con[i])choice3 = 1+check(i+1, 2);
    }
    else if(prev == 1)
    {
        if(con[i])choice3 = 1+check(i+1, 2);
    }
    else if(prev == 2)
    {
        if(sp[i])choice2 = 1+check(i+1, 1);
    }
    ret = max(choice1, choice2);
    ret = max(ret, choice3);
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
        cin >> a[i];
        if(a[i] == 0)continue;
        if(a[i] == 1)
            con[i] = 1;
        else if(a[i] == 2)
            sp[i] = 1;
        else
            con[i] = sp[i] = 1;
    }
    cout << n-check(0, 0);
    return 0;
}
