//https://www.acwing.com/problem/content/2/ 
/* 

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。


f(i,j)表示用前i个物品,体积是j时候的最大价值.
那么f(i,j)=max(f(i-1,j-vi)+wi,f(i-1,j))



 */









//第0部分是必须写的代码头.2行.
#include<bits/stdc++.h>
using namespace std;



//第一部分开数组. 都是先来一个const int 加大写字母, 然后下面开需要的数组.
const int MAXN = 1005;
int v[MAXN];    // 体积
int w[MAXN];    // 价值 
int f[MAXN][MAXN];  // f[i][j], j体积下前i个物品的最大价值 

int main() 
{
    int n, m;   
    cin >> n >> m;//开始读入所有的数据.
    for(int i = 1; i <= n; i++) 
        cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
        {
            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            if(j < v[i]) 
                f[i][j] = f[i - 1][j];
            // 能装，需进行决策是否选择第i个物品
            else    
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }           

    cout << f[n][m] << endl;

    return 0;
}
