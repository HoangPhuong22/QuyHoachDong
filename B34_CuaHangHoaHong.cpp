#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ; 
    int a[n];
    for(int i = 0 ; i < n;i++) cin >> a[i];
    vector<int>job1(n , 1) ; vector<int>job2(n , 1);
    int ans = 0;
    for(int i = 1 ; i < n  ;i++)
    {
        if(a[i - 1] < a[i])
        {
            job1[i] = job1[i - 1] + 1;
        }
        ans = max(ans , job1[i]);
    }
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        if(a[i] < a[i + 1])
        {
            job2[i] = job2[i + 1] + 1;
        }
        ans = max(ans , job2[i]);
    }
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(a[i -1] < a[i + 1])
        {
            ans = max(ans , job1[i - 1] + job2[i + 1]);
        }
    }
    cout << ans;
}
