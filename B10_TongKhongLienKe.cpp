#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n ; cin >> n ;
    int a[n];
    for(int i= 0 ; i < n; i++) 
    {
        cin >>a[i];
    }
    int sum[n + 1];
    sum[0] = a[0];
    sum[1] = max(a[1] , a[0]);
    for(int i = 2 ; i < n ; i++)
    {
        sum[i] = max(sum[i - 2] + a[i] , sum[i - 1]);
    }
    cout << sum[n - 1];
}
