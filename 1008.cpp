/************************************************************************/
/* Title: HDU ACM-1008   http://acm.hdu.edu.cn/                           */
/* Time: 2018-04-10                                                     */
/* Author: YaoLing                                                      */
/************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int n,m;
	while( cin >> n )
	{
		if (!n)
		{
			break;
		}

		vector<int> eleNumber;	//Init variables
		eleNumber.resize(0);
		int number = 0;
		int delatEleN = 0;
		int needTime = 0;

		eleNumber.push_back(0);	//0th

		m=n;
		for(int i=0; i<m; i++)	//input some elevator number
		{
			cin >> number;
			eleNumber.push_back(number);
		}

		for (size_t i=0; (i != eleNumber.size()-1); ++i)
		{
			delatEleN = eleNumber.at(i+1) - eleNumber.at(i);
			needTime += MAX(0,delatEleN) * 6 - 4* MIN(0,delatEleN) + 5;
		}
		cout << needTime << endl;
	}
	return 1;
}