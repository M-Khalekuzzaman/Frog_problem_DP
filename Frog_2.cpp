#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int h[N];
int dp[N];
int ans[N] = {0};
int n,k;

int stone(int n)
{
    // 1.base case
    if(n == 1) return 0;
    // 2. check stone is already stored in memory
    if(dp[n] != -1) return dp[n];
    // 3. store height
    for(int i = 1; i<=k; i++)
    {
        ans[i] = stone(n-i) + abs(h[n] - h[n-i]);
    }
    int min = ans[1];
    for(int i = 2; i<=k; i++)
    {
        if(n-i <= 0) break;
        if(ans[i] < min)
        {
            min = ans[i];
        }
    }
    dp[n] = min;
    return dp[n];

}
int main()
{
    cin>>n>>k;

    for(int i = 1; i<=n; i++)
    {
        cin>>h[i];
    }
    for(int i = 1; i<=n; i++)
    {
        dp[i] = -1;
    }

    cout<<stone(n)<<endl;



    return 0;
}
