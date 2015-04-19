//
//  poj1636.cpp
//  console
//
//  Created by yuanrui on 15-4-8.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define  maxn 500
#define Clear(a,b) memset(a,b,sizeof(a))

vector <int> links[maxn];

bool dp[maxn][maxn];
int vis[maxn],mark[maxn],sum[2],wy[maxn],wx[maxn];

int dfs(int k)
{
    if (vis[k]) return 0;
    vis[k] = 1;
    sum[mark[k]]++;
    size_t m = links[k].size();
    for(size_t i = 0;i < m;i++) {
        dfs(links[k][i]);
    }
    return 0;
}

int work()
{
    int m,i,j,k,a,b,n,e,len = 0;
    
    Clear(vis,0);
    Clear(mark,0);
    Clear(dp,0);
    printf("%lu", sizeof(dp)) ;
    Clear(wx,0);
    Clear(wy,0);
    scanf("%d%d",&m,&e);
    
    for(i = 1;i <= m*2;i++) links[i].clear();
    
    for(i = 1;i <= m;i++) {mark[i] = 0;mark[i+m] = 1;}
    for(i = 1;i <= e;i++) {
        scanf("%d%d",&a,&b);
        b += m;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    for(i = 1;i <= m*2;i++) {
        Clear(sum,0);
        dfs(i);
        if (sum[0] > 0 || sum[1] > 0) {
            wx[++len] = sum[0];
            wy[len] = sum[1];
        }
    }
    n = m / 2;
    dp[0][0] = 1;
    for(i = 1;i <= len;i++)
        for(j = n;j >= wx[i];j--)
            for(k = n;k >= wy[i];k--)
                dp[j][k] = dp[j][k] || dp[j-wx[i]][k-wy[i]];
    i = n;
    
    while(dp[i][i] != 1) i--;
    printf("%d\n",i);
    return 0;
}

int mainPOJ1636()
{
    int t;
    
    scanf("%d",&t);
    while(t--) work();
    return 0;
}
