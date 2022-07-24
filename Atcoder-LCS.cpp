#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

string s,t;
int dp[3000][3000];
int solve(int i, int j)
{
    if(i == s.size() || j == t.size())
        return 0;
    int &ret = dp[i][j];
    if(~ret) return ret;
    if(s[i] == t[j])
        ret = solve(i+1,j+1) + 1;
    else
        ret = max(solve(i+1,j), solve(i, j+1));
    return ret;
}
string res;
void build(int i, int j)
{
    if(i == s.length() || j == t.length())
        return;
    if(s[i] == t[j])
    {
        res += s[i];
        build(i+1,j+1);
    }
    else
    {
        if(dp[i][j] == solve(i, j+1))
            build(i,j+1);
        else
            build(i+1,j);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> s >> t;
    int x = solve(0,0);
    build(0,0);
    cout << res;
    return 0;
}
