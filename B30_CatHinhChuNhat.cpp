#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 1;
int dp[505][505];
int main()
{
    int a , b ; cin >> a >> b;
    for(int i = 1 ; i <= a ; i++)
    {
        for(int j = 1 ; j <= b ; j++)
        {
            dp[i][j] = MOD;
        }
    }
    for(int i = 1 ; i < 501 ; i++)
    {
        dp[i][i] = 0;
    }
    for(int i = 1 ; i <= a ; i++)
    {
        for(int j = 1 ; j <= b ; j++)
        {
            for(int k = 1 ; k < i ; k++)
            {
                dp[i][j] = min(dp[i][j],dp[k][j] + dp[i -k][j] + 1);
            }
            for(int k = 1 ; k < j ; k++) 
            {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b];
}
