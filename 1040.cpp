/*
 * HDU ACM 1040
 * hash table
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int N;
    while(n--)
    {
        cin >> N;
        int hash[1001];
        memset(hash, 0, sizeof(hash));
        int tem;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &tem);
            hash[tem]++;
        }

        for (int j = 1; j < 1001; ++j) {
            if (hash[j] != 0)
                printf("%d ", j);
        }
        printf("\n");

    }
    return 0;
}