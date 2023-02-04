//完全背包问题.
//https://www.acwing.com/problem/content/description/3/
/* 
每种物品都有无限件可用。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。


f(i,j)表示用前i个物品,体积是j时候的最大价值.
那么f(i,j)=max(k取Zf(i-k,j-vi*k)+wi*k,f(i-1,j))



 */





// 
#include<iostream>
using namespace std;
const int N = 1010;
int f[N][N];
int v[N],w[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1 ; i<=n ;i++)
    for(int j = 0 ; j<=m ;j++)
    {
        for(int k = 0 ; k*v[i]<=j ; k++)//k是当前物品能放的最大数量.
            f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
    }

    cout<<f[n][m]<<endl;
}
