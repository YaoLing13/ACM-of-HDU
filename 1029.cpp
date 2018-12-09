/*
 * HDU ACM 1029
 * hash table
 */
#include<stdio.h>
#include<string.h>
int main()
{
  int n,hash[50000],tem,j,i;
  while(scanf("%d",&n)!=EOF) {
      memset(hash, 0, sizeof(hash));
      i = n;
      while(i--)
      {
          scanf("%d", &tem);
          hash[tem]++;
          if(hash[tem] >= (n+1)/2)
              j = tem;
      }
      printf("%d\n", j);
  }
    return 0;
}

/*
 * HDU ACM 1029
 * 查找出现次数最多的，至少(n+1)/2在n中出现的次数肯定是最多的
 */
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ans, num, count, n;
    while (scanf("%d", &n) != EOF)
    {
        count = 0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d", &ans);
            if (count == 0)
            {
                num = ans;
                count ++;
            }
            else
            if (ans == num)
                count++;
            else count--;
        }
        printf("%d\n", num);
    }
    return 0;
}
 */