#include <iostream>
using namespace std;
const int N = 1010,M = 20010;
int n,m;
int f[N][M];
int q[M],hh,tt;//队列和队列的头,队列的尾.
int main () {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int w,v,s;
        cin >> w >> v >> s;// w是每个物品的体积, v是价值, s是数量.
        for (int r = 0;r <= w - 1;r++) {//余数从0到w-1
            hh = 0,tt = -1;
            for (int j = r;j <= m;j += w) {//j遍历r+w的倍数这个集合.
                while (hh <= tt && q[hh] < j - w * s) hh++;
                while (hh <= tt && f[i - 1][q[tt]] + (j - q[tt]) / w * v <= f[i - 1][j]) tt--;
                q[++tt] = j;
                f[i][j] = f[i - 1][q[hh]] + (j - q[hh]) / w * v;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
//单调队列https://www.acwing.com/video/202/
// 作者：incra
// 链接：https://www.acwing.com/solution/content/156954/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。