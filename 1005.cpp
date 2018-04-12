//#include "stdio.h"
//
//int function(int A, int B, int n)
//{
//	//int result;
//	//if (n < 3)
//	//{
//	//	result = 1;
//	//}
//	//else
//	//	result = (A * function(A, B, n-1) + B * function(A, B, n-2))%7;
//	//return result;
//
//	int i, result;
//	int f1 = 1, f2 = 1;
//	if (n < 3)
//	{
//		result = 1;
//	}
//	else
//	{
//		for (i = 3; i <= n; i++)
//		{
//			result = (A * f2 + B * f1)%7;
//			f1 = f2;
//			f2 = result;
//		}
//	}
//	return result;
//}
//
//int main(void)
//{
//	int value = 0;
//	int A, B, n;
//	while(scanf("%d %d %d", &A, &B, &n) != EOF)
//	{
//		if (A && B && n)
//		{
//			value = function(A, B, n);
//			printf("resullt: %d\n", value);
//		}
//	}
//	return 0;
//}
//
//#include<stdio.h> 
//int main() 
//{      
//	long int a,b,n,T,s[101];      
//	while(scanf("%ld%ld%ld",&a,&b,&n)&&(a!=0&&b!=0&&n!=0))      
//	{         
//		int i,j,T;         
//		s[0]=1;         
//		s[1]=1;         
//		for(i=2;i<101;i++)
//		{//第一个循环
//			s[i]=(a*s[i-1]+b*s[i-2])%7;             
//			for(j=1;j<i-1;j++)//第二个循环             
//			{                 
//				if(s[j-1]==s[i-1]&&s[j]==s[i])
//				{                    
//					T=i-j;                     
//					break;                 
//				}             
//			}        
//		}         
//		n = n%T;        
//		printf("%ld\n",s[n-1]);     
//	}      
//	return 0;
//}

#include <iostream>

using namespace std;

int main()
{
	int a,b,n;
	int f[50];
	while(cin>>a>>b>>n)
	{
		if(a==0&&b==0&&n==0)break;

		if(n==1||n==2)
		{
			cout<<"1"<<endl;
			continue;
		}
		//给f[1]=1,f[2]=1
		for(int j=1; j<3; j++)
		{
			f[j]=1;
		}
		//大于3的n,执行该循环，n%49求出n在周期内的数
		for(int i=3; i<=n%49; i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;

		}
		cout << f[n%49]<< endl;
	}
	return 0;
}