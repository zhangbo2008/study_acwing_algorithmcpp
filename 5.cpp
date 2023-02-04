/* 



5. 多重背包问题 II
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
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10 */
//这个题目跟题目4比较,他的数据范围变量.是2000所以需要更快的算法.
//把多重背包问题转化为01背包来加速.

//复杂度NMlogs

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2010;
int f[N],n,m;
struct good
{
    int w,v; //w是价值.v是体积大小.
};

int main()
{
    cin>>n>>m;
    vector<good> Good;//首字母大写表示集合. 小写good表示元素.
    good tmp;

    //二进制处理
    for(int i = 1 ; i <= n ; i++ )
    {
        int v,w,s;
        cin>>v>>w>>s;
        //坑,k <= s //就是把数量二进制话, 然后创建good{kw,kv}这种新物品.从而复杂度变成n**2logn 比n立方快多了.基本是n放数量级.可以算完.
        for(int k = 1 ; k <= s ; k*=2 )
        {
            s-=k;//每次加入的都是2的次方.
            Good.push_back({k*w,k*v});
        }
        if(s>0) Good.push_back({s*w,s*v});//比如1011(B) 我们会写入k=1,k=10,k=100,k=1000,还要写入1011才行.
    }

    //01背包优化+二进制
    for(auto t : Good)
        for(int j = m ; j >= t.v ; j--)
            f[j] = max(f[j] , f[j-t.v]+t.w ); //这里就是f[j]


    cout<<f[m]<<endl;
    return 0;

}
