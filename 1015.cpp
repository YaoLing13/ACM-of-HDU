///************************************************************************/
///* Title: HDU ACM-1015   http://acm.hdu.edu.cn/                         */
///* Time: 2018-04-11                                                     */
///* Author: YaoLing                                                      */
///* Methods: for or DFS                                                 */
///************************************************************************/
//
///************************************************************************/
///* Method: for循环                                                      */
///************************************************************************/
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <cmath>
////
////bool sortType(int i, int j)
////{
////	return (i>j);	//降序
////}
////
////int main(void)
////{
////	int n, m_target;
////	while( std::cin >> n)
////	{
////		if (n == 0)
////		{
////			char endLetter[12]="";
////			std::cin >> endLetter;
////			break;
////		}
////		m_target = n;
////		char m_letter[12]="";
////		std::cin>>m_letter;
////
////		std::vector<int> intLetters;
////		std::vector<int> trueLetters;
////		intLetters.resize(0);
////		trueLetters.resize(0);
////
////		for(size_t i=0; i < strlen(m_letter); ++i)
////			intLetters.push_back(m_letter[i]-64);
////		
////		std::sort(intLetters.begin(), intLetters.end(), sortType);
////		int flag1=0;
////		int flag2=0;
////		int flag3=0;
////		int flag4=0;
////		int flag5=0;
////		int sumval= 0;
////		for (size_t r1=0; r1 != intLetters.size(); ++ r1)
////		{
////			for (size_t r2=0; r2 != intLetters.size(); ++ r2)
////			{
////				if(r1 == r2)
////					continue;
////				for (size_t r3=0; r3 != intLetters.size(); ++ r3)
////				{
////					if(r1 == r3 || r2 == r3)
////						continue;
////					for (size_t r4=0; r4 != intLetters.size(); ++ r4)
////					{
////						if(r1 == r4 || r2 == r4 || r3 == r4)
////							continue;
////						for (size_t r5=0; r5 != intLetters.size(); ++ r5)
////						{
////							if(r1 == r5 || r2 == r5 || r3 == r5 || r4 == r5)
////								continue;
////							sumval = (int)(intLetters[r1] - pow((double)intLetters[r2], 2) + pow((double)intLetters[r3], 3) - pow((double)intLetters[r4], 4) + pow((double)intLetters[r5], 5));
////							if (sumval == m_target)
////							{
////								flag5 = 1;
////								trueLetters.push_back(intLetters[r1]);
////								trueLetters.push_back(intLetters[r2]);
////								trueLetters.push_back(intLetters[r3]);
////								trueLetters.push_back(intLetters[r4]);
////								trueLetters.push_back(intLetters[r5]);
////								break;
////							}
////						}
////						if (flag5)
////						{
////							flag4 = 1;
////							break;
////						}
////					}
////					if (flag4)
////					{
////						flag3 = 1;
////						break;
////					}
////				}
////				if (flag3)
////				{
////					flag2 = 1;
////					break;
////				}
////			}
////			if (flag2)
////			{
////				flag1 = 1;
////				break;
////			}
////		}
////		if (flag1)
////		{
////			std::cout<<static_cast<char>(trueLetters[0]+64)<<static_cast<char>(trueLetters[1]+64)<<static_cast<char>(trueLetters[2]+64)<<static_cast<char>(trueLetters[3]+64)<<static_cast<char>(trueLetters[4]+64)<<std::endl;
////		}
////		else
////			std::cout<<"no solution"<<std::endl;
////
////	}
////	
////	return 0;
////}
//
///************************************************************************/
///* Method: DFS深度优先遍历                                              */
///************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool sortType(int i, int j)
{
	return (i>j);	//降序
}

int cal(int v,int w,int x,int y,int z)
{
	return (v - (int)pow((double)w, 2) + (int)pow((double)x, 3) - (int)pow((double)y, 4) + (int)pow((double)z, 5));
}

bool mincal(int m_tar, int m_max, int m_min)
{
	if (m_tar > cal(m_max, m_min, m_max, m_min, m_max))
	{
		return true;
	}
	return false;		
}

bool judge(int m_tar, int v,int w,int x,int y,int z)
{
	if (m_tar == cal(v, w, x, y, z))
	{
		return true;
	}
	return false;		
}

bool DFS(std::vector<int>& intLetters, std::vector<int>& visited, std::vector<int>& dealLetters, std::vector<int>& trueLetters, int m_tar, int num)
{
	if (num == 5)	//判断是否到达终点
	{
		if (judge(m_tar, dealLetters[0], dealLetters[1], dealLetters[2], dealLetters[3], dealLetters[4]))
		{
			dealLetters.swap(trueLetters);
			return true;
		}
		else
			return false;
	}

	//尝试每一个可走的方向
	for (size_t i=0; i != intLetters.size(); ++i)	//不可走，尝试其他的未走过的节点/方向
	{
		//判断是否可走，可走则尝试递归调用下一步
		if (!visited[i])
		{
			dealLetters[num] = intLetters[i];
			visited[i]=1;
			if (DFS(intLetters, visited, dealLetters, trueLetters, m_tar, num+1))
			{
				return true;
			}
			visited[i]=0;	
		}
	}

	return false;
}

int main(void)
{
	std::vector<int> intLetters;
	std::vector<int> visited;
	std::vector<int> trueLetters;
	std::vector<int> dealLetters;
	int n, m_target;
	while( std::cin >> n)
	{
		if (n == 0)
		{
			char endLetter[12]="";
			std::cin >> endLetter;
			break;
		}
		m_target = n;
		char m_letter[15]="";
		std::cin>>m_letter;
		
		intLetters.resize(0);

		for(size_t i=0; i < strlen(m_letter); ++i)
			intLetters.push_back(m_letter[i]-64);

		std::sort(intLetters.begin(), intLetters.end(), sortType);	//降序

		if (mincal(m_target, intLetters[0], intLetters[(int)intLetters.size()-1]))
		{
			std::cout << "no solution" << std::endl;
			break;
		}

		visited.resize((int)intLetters.size(), 0);	
		trueLetters.resize(5, 0);
		dealLetters.resize(5, 0);

		if (DFS(intLetters, visited, dealLetters, trueLetters, m_target, 0))
		{
			std::cout<<static_cast<char>(trueLetters[0]+64)<<static_cast<char>(trueLetters[1]+64)<<static_cast<char>(trueLetters[2]+64)<<static_cast<char>(trueLetters[3]+64)<<static_cast<char>(trueLetters[4]+64)<<std::endl;
			visited.clear();
			trueLetters.clear();
			dealLetters.clear();
		}
		else
		{
			std::cout<<"no solution"<<std::endl;	
			visited.clear();
			trueLetters.clear();
			dealLetters.clear();
		}
	}

	
	return 0;
}