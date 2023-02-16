//https://www.acwing.com/activity/content/introduction/11/        原始地址.

#include <bits/stdc++.h>
using namespace std;
// 快速排序算法模板 —— 模板题 AcWing 785. 快速排序
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
 
    int i = l - 1, j = r + 1, x = q[l + r >> 1]; //找到中心点x,中心点取什么无所谓,但是一般取数列中心点会更大概率取的好.
    //因为14,15行代码是先加加.所以这里面边界要提前先左右偏移一个单位.
    while (i < j)
    {
        do i ++ ; while (q[i] < x);//找到第一个大于等于i的,因为我们最后效果是最后停到的点左边小于=他,中心点右边大于=他.
        do j -- ; while (q[j] > x);//找到最后一个小鱼等于i的
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}




// 归并排序算法模板 —— 模板题 AcWing 787. 归并排序
const int N = 1e6 + 10;
int tmp[N];//辅助空间,用来存数.

void merge_sort(int q[], int l, int r){
	if(l >= r) return;
	
	int mid = l + r >> 1;
	
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	
    //下面进行2个有序数组的合并.
	int i = l, j = mid + 1, k = 0;//合并算法就是双指针. 一个i, 一个j
	while(i <= mid && j <= r){
		if(q[i] <= q[j]) tmp[k ++] = q[i ++];//每次比较2个指针的数的大小.
        //如果左边小的话,那就是把左边的数q[i]写入tmp里面,然后两个指针k和i都++
		else tmp[k ++] = q[j ++];//反之就写入右边的数到tmp里面,然后两个指针k和i都++
	}
	//上面2个数组 有一个放完了,那么把剩余的数组都放入即可.
	while(i <= mid) tmp[k ++] = q[i ++];//查询指针是否到边界即可.不到边界的都放入tmp中.
	while(j <= r) tmp[k ++] = q[j ++];
//最后把tmp里面的数据都放入q里面.
	for(int i = l, j = 0; j < k;i ++, j ++){
		q[i] = tmp[j];
	}
	
}














// 整数二分算法模板 —— 模板题 AcWing 789. 数的范围
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
//也就是每次查找如果我们要把符合的东西, 在他左边继续找.那么mid成功了我们就区间变成[l,mid]
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;//取一半偏左的.因为只有这样才分得均匀. 否则你取中间偏右一点的. 那么 [l,mid] 就明显比 [mid+1,r] 长度大. 分得均匀越不容易出错.
        if (check(mid)) r = mid;    // check()判断mid是否满足性质,我们就在他左边继续找.
        else l = mid + 1;
    }
    return l;
}






// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

// 作者：yxc
// 链接：https://www.acwing.com/blog/content/277/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。







// 浮点数二分算法模板 —— 模板题 AcWing 790. 数的三次方根
bool check(double x) {/* ... */} // 检查x是否满足某种性质
double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}






// 高精度加法 —— 模板题 AcWing 791. 高精度加法
// C = A + B, A >= 0, B >= 0  # 数组[ 9, 1,2,3,4 ] 表示的数是4319
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t); //都加完还可能有进位.
    return C;
}








// 高精度减法 —— 模板题 AcWing 792. 高精度减法
// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;//t表示触发进位.
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();//如果最高位是0,那么把0去掉.
    return C; //vector.end() vector末尾元素  //  back() 函数返回当前vector最末一个元素的引用
}








// 高精度乘低精度 —— 模板题 AcWing 793. 高精度乘法
// C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}







// 高精度除以低精度 —— 模板题 AcWing 794. 高精度除法
// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )//从最高位开始除.
    {
        r = r * 10 + A[i]; //上一次的余数.
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}






// 一维前缀和 —— 模板题 AcWing 795. 前缀和
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]


// 二维前缀和 —— 模板题 AcWing 796. 子矩阵的和


// 以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
 S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]



// 一维差分 —— 模板题 AcWing 797. 差分   这里面B表示的是差分矩阵. B[i]=A[i]-A[i-1]
// 给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c




// 二维差分 —— 模板题 AcWing 798. 差分矩阵
// 给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：
S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c




// 位运算 —— 模板题 AcWing 801. 二进制中1的个数
// 求n的从左到右的第k位数字: n >> k & 1
// 返回n的最后一位1：
lowbit(n) = n & -n
//证明这个: 之前位置是1.那么我们取反后加一再&, 就是1.
//zhiqia_位置是0, 那么我们取反后,加一再&,就是0.这时候考虑进位问题:
    //如果这里不进位说明之前的不是0,那么无所谓.
    //如果进位说明之前的是0,一起往前进位没问题.
    //举例子 000  他取反是111加一等于最高位向上进一位.变成1000.最后这个1表示这个连续
    //的000...000多少个0都变成他前面加1.所以没问题.







区间合并 —— 模板题 AcWing 803. 区间合并
// 将所有存在交集的区间合并

//  PII是pair int的意思.表示 (int, int)这种类.
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());//sort默认是按照pair的first升序排序，如果first相同，则按照second进行升序排序，

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});//如果是一个合法的我们就加入res中
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);//如果ed>=seg.first说明有重合.把上一个ed进行拓展即可.

    if (st != -2e9) res.push_back({st, ed});//最后如果还剩就再看是不是合法,合法就加入即可.

    segs = res;
}

作者：yxc
链接：https://www.acwing.com/blog/content/277/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。








// 单链表: head--->data,next---->data2,next2---->null

单链表 —— 模板题 AcWing 826. 单链表
// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点

//head头, e表示entity  ne表示next entity. 这里面用2个数组来模拟链表. 比普通链表的速度更快.
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}

// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}

作者：yxc
链接：https://www.acwing.com/blog/content/404/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。















队列 —— 模板题 AcWing 829. 模拟队列
1. 普通队列：
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

// 向队尾插入一个数
q[ ++ tt] = x;

// 从队头弹出一个数
hh ++ ;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt)
{

}






2. 循环队列  //我感觉用mod写更快.
// hh 表示队头，tt表示队尾的后一个位置
int q[N], hh = 0, tt = 0;

// 向队尾插入一个数
q[tt ++ ] = x;
if (tt == N) tt = 0;//这个来做循环, 如果末尾添加的已经满了,就重头再覆盖.

// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh != tt)
{

}















单调栈 —— 模板题 AcWing 830. 单调栈
常见模型：找出每个数左边离它最近的比它大/小的数   2部曲: 维护栈, 写入栈
int tt = 0; //栈顶索引.
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;  //先 维护单调栈. 把没必要的pop掉.
    stk[ ++ tt] = i;  //再写入新的数据.
}






//单调队列 —— 模板题 AcWing 154. 滑动窗口
常见模型：找出滑动窗口中的最大值/最小值
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{//3部曲: 维护队列的头,维护队列的尾, 写入队列.
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口  // 先维护队列.

        //hh<=tt 表示队列非空. 并且
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}








KMP —— 模板题 AcWing 831. KMP字符串
// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}








Trie树 —— 模板题 AcWing 835. Trie字符串统计. kmp的升级版.
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;//如果son[p][u]已经到字符串末尾了,那么我们就把他写入数字idx
        p = son[p][u];
    }
    cnt[p] ++ ;
}
// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

作者：yxc
链接：https://www.acwing.com/blog/content/404/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。






并查集 —— 模板题 AcWing 836. 合并集合, AcWing 837. 连通块中点的数量
(1)朴素并查集：

    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);


(2)维护size的并查集：

    int p[N], size[N];
    //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    // 合并a和b所在的两个集合：
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);


(3)维护到祖宗节点距离的并查集：

    int p[N], d[N];
    //p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x)
        {
            int u = find(p[x]);
            d[x] += d[p[x]];
            p[x] = u;
        }
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        d[i] = 0;
    }

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);
    d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量






// 堆 —— 模板题 AcWing 838. 堆排序, AcWing 839. 模拟堆
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N], size;

// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

// O(n)建堆
for (int i = n / 2; i; i -- ) down(i);

// 作者：yxc
// 链接：https://www.acwing.com/blog/content/404/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。














#数组来模拟哈希表.
(1) 拉链法
    int h[N], e[N], ne[N], idx; //指针用ne数组来实现. e给索引返回数据的值, h是哈希数据,存入的是数据的索引.

    // 向哈希表中插入一个数
    void insert(int x)
    {
        int k = (x % N + N) % N;//哈希值是k
        e[idx] = x;   //
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }

    // 在哈希表中查询某个数是否存在
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;

        return false;
    }

(2) 开放寻址法
    int h[N];

    // 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x) 
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }

作者：yxc
链接：https://www.acwing.com/blog/content/404/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




字符串哈希 —— 模板题 AcWing 841. 字符串哈希
核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

作者：yxc
链接：https://www.acwing.com/blog/content/404/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。








C++ STL简介
vector, 变长数组，倍增的思想
    size()  返回元素个数
    empty()  返回是否为空
    clear()  清空
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    支持比较运算，按字典序

pair<int, int>
    first, 第一个元素
    second, 第二个元素
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）

string，字符串
    size()/length()  返回字符串长度
    empty()
    clear()
    substr(起始下标，(子串长度))  返回子串
    c_str()  返回字符串所在字符数组的起始地址

queue, 队列
    size()
    empty()
    push()  向队尾插入一个元素
    front()  返回队头元素
    back()  返回队尾元素
    pop()  弹出队头元素

priority_queue, 优先队列，默认是大根堆
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    定义成小根堆的方式：priority_queue<int, vector<int>, greater<int>> q;

stack, 栈
    size()
    empty()
    push()  向栈顶插入一个元素
    top()  返回栈顶元素
    pop()  弹出栈顶元素

deque, 双端队列
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []

set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
    size()
    empty()
    clear()
    begin()/end()
    ++, -- 返回前驱和后继，时间复杂度 O(logn)

    set/multiset
        insert()  插入一个数
        find()  查找一个数
        count()  返回某一个数的个数
        erase()
            (1) 输入是一个数x，删除所有x   O(k + logn)
            (2) 输入一个迭代器，删除这个迭代器
        lower_bound()/upper_bound()
            lower_bound(x)  返回大于等于x的最小的数的迭代器
            upper_bound(x)  返回大于x的最小的数的迭代器
    map/multimap
        insert()  插入的数是一个pair
        erase()  输入的参数是pair或者迭代器
        find()
        []  注意multimap不支持此操作。 时间复杂度是 O(logn)
        lower_bound()/upper_bound()

unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
    和上面类似，增删改查的时间复杂度是 O(1)
    不支持 lower_bound()/upper_bound()， 迭代器的++，--

bitset, 圧位
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  返回有多少个1

    any()  判断是否至少有一个1
    none()  判断是否全为0

    set()  把所有位置成1
    set(k, v)  将第k位变成v
    reset()  把所有位变成0
    flip()  等价于~
    flip(k) 把第k位取反

作者：yxc
链接：https://www.acwing.com/blog/content/404/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。











int main (){
    int a[]={12,3,4,5,77};
    merge_sort(a,0,4);
    for (int i=0;i<=4;i++){
        cout <<a[i]<<' ';
    }
}




















// 作者：yxc
// 链接：https://www.acwing.com/blog/content/277/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。






























