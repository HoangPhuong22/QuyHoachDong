#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ; cin >> n;
    int dp[n + 1];
    memset(dp , 0 , sizeof(dp));
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        dp[i] = INT_MAX;
        for(char x : to_string(i))
        {
            if(i >= x - '0')
            {
                dp[i] = min(dp[i] , dp[i - (x - '0')] + 1);
            }
        }
    }
    cout << dp[n];
}
