题目信息
题目描述
 给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 -1。

输入格式
 第一行包含整数 N，表示数列长度。

 第二行包含 N 个整数，表示整数数列。

输出格式
 共一行，包含 N 个整数，其中第i个数表示第i个数的左边第一个比它小的数，如果不存在则输出 -1。

数据范围
1 ≤ N ≤ 1 0 5 10^5 105
1 ≤ 数列中元素 ≤ 1 0 9 10^9 109

输入样例
5
3 4 2 7 5

输出样例
-1 3 -1 2 2

题解



#include<iostream>
#include<stack>
using namespace std;
const int N = 100010;
int main() { 
    stack<int> stk;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { 
        int x;
        cin >> x;
        while (stk.size() && stk.top() >= x) stk.pop();//先维护栈.
        if (stk.size()) cout << stk.top() << ' ';
        else cout << -1 << ' ';
        stk.push(x);
    }
    return 0;
}








int main() { 
    stack<int> stk;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { 
        int x;
        cin >> x;
        if !stk.size() print(-1)

    }
    return 0;
}