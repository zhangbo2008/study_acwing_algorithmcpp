acwing-839. 模拟堆
维护一个集合，初始时集合为空，支持如下几种操作：

I x，插入一个数 x；
PM，输出当前集合中的最小值；
DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
D k，删除第 k 个插入的数；
C k x，修改第 k 个插入的数，将其变为 x；
现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

输入格式#
第一行包含整数 N。

接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

输出格式#
对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

数据范围#
1≤N≤105
−109≤x≤109
数据保证合法。

输入样例：#
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
输出样例：#
-10
6
方法一：#
模拟堆，没什么技巧，麻烦的地方在于要维护第k个插入的数在堆中的下标，以及在堆中下标n的数是第几个插入的数...代码菜鸡调了一小时bug

#include <bits/stdc++.h>

using namespace std;
//cnt表示堆中一共有多少个数据.
int n, nums[100010], cnt,   i2n[100010], n2i[100010], // i2n: 第i个插入的数在堆中位置    n2i: 在堆中n位置的数是第几个插入idx;   

void down(int u) {
    while (true) {// u这个位置跟他的子节点进行比较.
        int t = u;
        if (2 * u <= cnt && nums[t] > nums[2 * u]) t = 2 * u;
        if (2 * u + 1 <= cnt && nums[t] > nums[2 * u + 1]) t = 2 * u + 1;
        if (t == u) break;

        swap(nums[u], nums[t]);
        swap(n2i[u], n2i[t]);
        swap(i2n[n2i[u]], i2n[n2i[t]]);
        u = t;
    }
}

void up(int u) {//把索引位置u的向上移动维护堆.
    while (u/2 > 0 && nums[u/2] > nums[u]) {// 当索引合法,并且父节点大于本节点.那么就进行交换.
        swap(nums[u/2], nums[u]);//那么子父交换.
        swap(n2i[u/2], n2i[u]); //同时也维护n2i 和i2n2个记录点.
        swap(i2n[n2i[u/2]], i2n[n2i[u]]);
        u >>= 1;//然后继续维护父节点.
    }
}





//小根堆的插入函数.
void insert(int x) {
    nums[++cnt] = x;//首先要把数据放到堆低最大索引. //注意我们存储索引是从1开始的.
    ++idx;//idx是表示他是第几个插入的.
    i2n[idx] = cnt;
    n2i[cnt] = idx;
    up(cnt);
}












void del(int k) {
    int nh = i2n[k];
    i2n[n2i[cnt]] = nh;
    n2i[nh] = n2i[cnt];
    nums[nh] = nums[cnt--];

    down(nh);
    up(nh);
}

void update(int k, int x) {
    int nh = i2n[k];
    nums[nh] = x;

    down(nh);
    up(nh);
}

void delmin() {
    n2i[1] = n2i[cnt];
    i2n[n2i[1]] = 1;
    nums[1] = nums[cnt--];

    down(1);
}

int main() {
    char op[3];
    scanf("%d", &n);
    while (n--) {
        int k, x;
        scanf("%s", op);
        if (op[0] == 'I') {
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'P') {
            printf("%d\n", nums[1]);
        } else if (op[0] == 'D' && op[1] == 'M') {
            delmin();
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            del(k);
        } else if (op[0] == 'C') {
            scanf("%d%d", &k, &x);
            update(k, x);
        }
    }
}