acwing826. 单链表(数组模拟)

.xuan.

已于 2023-02-07 10:09:21 修改

15
 收藏 1
分类专栏： 数据结构以及C++STL容器 文章标签： 链表 数据结构 算法
版权

数据结构以及C++STL容器
专栏收录该内容
6 篇文章0 订阅
订阅专栏
题目：

实现一个单链表，链表初始为空，支持三种操作：

向链表头插入一个数；
删除第 k 个插入的数后面的数；
在第 k 个插入的数后插入一个数。
现在要对该链表进行 M次操作，进行完所有操作后，从头到尾输出整个链表。

注意:题目中第 k个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…第 n 个插入的数。

输入格式
第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：

H x，表示向链表头插入一个数 x。
D k，表示删除第 k个插入的数后面的数（当 k为 0 时，表示删除头结点）。
I k x，表示在第 k个插入的数后面插入一个数 x（此操作中 k 均大于 0）。
输出格式
共一行，将整个链表从头到尾输出。

数据范围
1≤M≤100000
所有操作保证合法。

输入样例：
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
输出样例：
6 4 6 5
————————————————
版权声明：本文为CSDN博主「.xuan.」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_73569492/article/details/128696309










#include <iostream>
 
using namespace std;
 
const int N = 100010;
int e[N], ne[N], idx, head;
 
void init()//初始化  //初始化加3个操作.
{
    head = -1;
    idx = 0;
}
void add_to_head(int x)//在头节点处插入
{
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}
void remove(int k)//删去第k个数
{
    ne[k] = ne[ne[k]];
}
void add(int k, int x)//在第k个数后面插入
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}
int main()
{
    int m;
    cin >> m;
    init();//初始化
    while (m --)
    {
        char op;//操作
        int k, x;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        if (op == 'D')
        {
            cin >> k;
            if (!k) head = ne[head];
            remove(k - 1);
        }
        if (op == 'I')
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
}






