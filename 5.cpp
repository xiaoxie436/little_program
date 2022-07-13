#include <iostream>
#include <cstring>
using namespace std;
int const maxn = 100010;
int t, n, k;
char s[maxn];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cin >> s;
        s[n + 1] = '0';
        for (int i = 0; i < n; ++i)
        {
            k = 10;
            if (s[0] == '9')
            {
                if (s[i] > '1')
                {
                    if (s[i + 1] <= '1')
                        k++;
                }
                else
                    k = 1;
            }
            else
                k--;
            printf("%d", k - (s[i] - '0'));
        }
        printf("\n");
    }
    return 0;
}