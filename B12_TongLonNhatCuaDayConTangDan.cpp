#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ; cin >> n;
    int a[n] , dp[n];
    for(int i = 0 ;i  < n ;i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i <n ;i++)
    {
        dp[i] = a[i];
        for(int j = 0 ; j < i ; j++)
        {
            if(a[i] > a[j])
            {
                dp[i] = max(dp[j] + a[i] , dp[i]);
            }
        }
    }
    cout << *max_element(dp , dp + n);
}
