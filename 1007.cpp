#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point
{
	double x;
	double y;
};

int main(void)
{
	int n,m;
	std::vector<Point> node;
	Point newnode;
	while (std::cin>>n)
	{
		node.resize(0);
		if (!n)
		{
			break;
		}
		m = n;
		for(int i=0;i<m;i++)
		{
			std::cin>>newnode.x;
			std::cin>>newnode.y;
			node.push_back(newnode);
		}
		double mindis = 1000000000;
		double dis = 0;
		int leng = node.size();
		for (int i=0; i<(leng-1); i++)
		{
			for (int j=i+1; j<leng; j++)
			{

				dis = pow(fabs(node[i].x - node[j].x), 2) + pow(fabs(node[i].y - node[j].y), 2);
				mindis = mindis < dis ?  mindis : dis;
			}
		}
		std::cout<<std::setprecision(2)<<sqrt(mindis)/2<<std::endl;

	}
	return 0;
}
