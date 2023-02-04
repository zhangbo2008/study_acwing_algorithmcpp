#include <iostream>
//背包问题总结:
//完全背包:f[j] = max(f[j], f[j - v[i]] + w[i]);  //完全是要跑完,所以要从钱往后遍历.
//0,1 f[j] = max(f[j], f[j - s[i] * v[i]] + s[i] * w[i]);//记忆0,1是前面的数.所以我们要从后往前遍历
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N], s[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; ++ i)
    {
        //完全背包
        if (!s[i])
        { 
            for (int j = v[i]; j <= m; ++ j)
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
        else
        {
            //把多重背包用二进制优化
            //这样就变成做多个01背包了
            if (s[i] == -1) s[i] = 1;
            //二进制优化
            for (int k = 1; k <= s[i]; k *= 2)
            {
                for (int j = m; j >= k * v[i]; -- j)
                {
                    f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
                }
                s[i] -= k;
            }
            if (s[i])
            {
                for (int j = m; j >= s[i] * v[i]; -- j)
                {
                    f[j] = max(f[j], f[j - s[i] * v[i]] + s[i] * w[i]);
                }
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}