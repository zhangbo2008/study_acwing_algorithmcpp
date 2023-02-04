/* 11. 背包问题求方案数
   题目
   提交记录
   讨论
   题解
   视频讲解

有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7 的结果。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示 方案数 模 109+7 的结果。

数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
输出样例：
2 */





#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int w[N], v[N];//每一个物品的体积和价值
int f[N], g[N]; // 体积恰好是N的时候的最大价值是f[N], 方案数是g[N]

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> v[i] >> w[i];



    g[0] = 1;
    for (int i = 1; i <= n; ++ i)//最外层永远是遍历所有物品.
    {
        for (int j = m; j >= v[i]; -- j)//0, 1背包所以逆向遍历总体积.
        {
            int temp = max(f[j], f[j - v[i]] + w[i]), c = 0;
            if (temp == f[j]) c = (c + g[j]) % mod;
            if (temp == f[j - v[i]] + w[i]) c = (c + g[j - v[i]]) % mod;
            f[j] = temp, g[j] = c;
        }
    }



    int res = 0;
    for (int j = 0; j <= m; ++ j)
    {
        if (f[j] == f[m])
        {
            res = (res + g[j]) % mod;
        }
    }
    cout << res << endl;
    return 0;
}

// 作者：一只野生彩色铅笔
// 链接：https://www.acwing.com/solution/content/54273/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。