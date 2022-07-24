#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = 0x3F3F3F3F;
const int N  = 7500, M = 10001;

int a[5] = {1,5,10,25,50};
int n;
int memo[N][10];
int solve(int n, int prev)
{
    if(n == 0) return 1;
    int &ret  = memo[n][prev];
    if(~ret) return ret;
    ret = 0;
    for(int i=0;i<5;i++)
    {
        if(n>=a[i] && a[i] >= a[prev])  ret += solve(n-a[i], i);
    }
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(memo, -1, sizeof memo);
    int ans = solve(7489,0);
    while(cin >> n)
    {
        cout << memo[n][0] << endl;
    }
    return 0;
}
