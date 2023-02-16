题目：
输入一个 n 行 m 列的整数矩阵，再输入 q 个操作，每个操作包含五个整数 x1 ,y1, x2, y2, c，其中 (x1, y1) 和 (x2, y2) 表示一个子矩阵的左上角坐标和右下角坐标。

每个操作都要将选中的子矩阵中的每个元素的值加上 c。

请你将进行完所有操作后的矩阵输出。

输入格式：
第一行包含整数 n, m, q。

接下来 n 行，每行包含 m 个整数，表示整数矩阵。

接下来 q 行，每行包含 5 个整数 x1, y1, x2, y2, c，表示一个操作。

输出格式：
共 n 行，每行 m 个整数，表示所有操作进行完毕后的最终矩阵。

数据范围：





矩
阵
内
元
素
的
值

样例：
输入：

3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
输出：

2 3 4 1
4 3 4 1
2 2 2 2
思路：
求一个二维的差分矩阵即可，再求一遍二维的前缀和得出最后矩阵。



//  首先我们定义差分矩阵的意义:假设我们最后要求的矩阵是res那么我们定义:a[i][j] 为他的差分矩阵:
// res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + a[i][j];
// 我们维护差分矩阵a[i][j] 就能反向生成res[i][j]矩阵了.



代码：
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1010;

int a[N][N], res[N][N];
int n, m, q;
// 让差分矩阵在点(x1,y1 , x2,y2)矩阵上加c
void insert(int x1, int y1, int x2, int y2, int c){
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;//遍历时候超过这个矩阵边界时候-c
    a[x2 + 1][y1] -= c; //这个遍历时候也-c
    a[x2 + 1][y2 + 1] += c;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);





    //首先我们读取矩阵是n行m列, q个操作.
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            int x;
            scanf("%d", &x);
            insert(i, j, i, j, x);
        }
    }












    
    
    while (q --){
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}