
//https://www.acwing.com/problem/content/description/4/
/* 
4. 多重背包问题 I
   题目
   提交记录
   讨论
   题解
   视频讲解

有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100
0<vi,wi,si≤100
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10


 */





// 
#include<iostream>
using namespace std;
const int N = 110;
int f[N][N];
int v[N],w[N],s[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)  //物品序列让他从1开始.
    {
        cin>>v[i]>>w[i]>>s[i];
    }

    for(int i = 1 ; i<=n ;i++)
    for(int j = 0 ; j<=m ;j++)//j是体积所以从0开始.
    {
        for(int k = 0 ; k<=s[i] && k*v[i]<=j ; k++)//k是当前物品能放的最大数量.
            f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
    }

    cout<<f[n][m]<<endl;
}
