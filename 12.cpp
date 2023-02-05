#include <iostream>
using namespace std;
const int N = 1010;
int n,m;
int w[N],v[N];
int f[N][N];//f[i][j] 表示用 大于等于i索引的那些物品最大体积j时的最优价值.
int main () {



    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> w[i] >> v[i];
    for (int i = n;i >= 1;i--) {
        for (int j = 0;j <= m;j++) {
            f[i][j] = f[i + 1][j];
            if (j >= w[i]) f[i][j] = max (f[i][j],f[i + 1][j - w[i]] + v[i]);//如果j能放下当前物品, 那么我们第一种情况是f[i + 1][j]也就是不用当前物品, 第二种情况是用当前物品.f[i + 1][j - w[i]] + v[i]. 当前价值加上f[i+1][j-wi]即可.
        }



    }





    for (int i = 1,j = m;i <= n;i++) {
        if (j >= w[i] && f[i][j] == f[i + 1][j - w[i]] + v[i]) {
            //如果我们使用了当前索引.如果j能放入当前物体.
            cout << i << ' ';
            j -= w[i];
        }
    }




    return 0;
}

// 作者：incra
// 链接：https://www.acwing.com/solution/content/146614/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。