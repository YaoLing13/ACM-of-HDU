#include "stdio.h"
#include "string.h"

typedef struct BALLOON	//旧版C语言使用结构体
{
	char name[15];
	int num;
}BALLO;

int main(void)
{
	int n, m, i;
	BALLO ball[1000];
	while(scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			continue;
		}
		m = 0;
		int maxnum=0;
		int seq;
		while(m<n)
		{
			scanf("%s", ball[m].name);
			for (i=0; i < m; i++)
			{
				if (strcmp(ball[m].name, ball[i].name) == 0)
				{
					ball[i].num++;
					ball[m].num = 0;
					break;
				}
				else
					ball[m].num = 1;
			}
			m++;
		}

		for (i = 0; i<m; i++)
		{
			if(ball[i].num > maxnum)
			{
				maxnum = ball[i].num;
				seq = i;
			}
		}
		printf("%s\n", ball[seq].name);
	}
	return 0;
}