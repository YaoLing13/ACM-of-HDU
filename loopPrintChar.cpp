/*
 * Discribe: Loop print letter
 * Author: Yaoling
 * Time: 2018-07-27
 */
/* 思路： 找规律
 * 把该输出划分为多个环，每个环上有4根线，分别为0,1,2,3号。最外层的环每根线上有n-1个数字，每靠内一层，线上数字少2个;
 * 计算每个位置(row, col)对应的环、线、线内索引，进而求出环内索引和全局索引。在该位置打印全局索引即可。
 */

#include <algorithm>
#include <iostream>
#include <iomanip>

char get_letter(int row, int col, int n)
{
	int n_1 = n - 1;
	int loop = std::min(std::min(row, col), std::min(n_1-col, n_1-row));	// 确定该点属于第几圈
	int line=0;
	int index_in_line=0;

	// 确定该点属于一圈中的哪根线
	if (row == loop)	// 第一根线
	{
		line = 0;
		index_in_line = col-loop;	//确定该点为该圈的该线上的哪个数
	}
	else if((n_1-col) == loop)
	{
		line = 1;
		index_in_line = row-loop;
	}
	else if((n_1-row) == loop )
	{
		line = 2;
		index_in_line = n_1 - col - loop;
	}
	else if(col == loop )
	{
		line =3;
		index_in_line = n_1-row - loop;
	}

	int number_in_a_line = n_1 - loop*2;	// 确定该圈中每一根线上有几个数
	int number_in_before_loop = 4*(loop*n_1 - loop*(loop-1));	//确定前面圈的总数量
	int number_global = number_in_before_loop + number_in_a_line*line + index_in_line;	// 确定该点为全局中的哪个数
	char global_letter = (number_global)%26 + 65;	// 将数字转换为字母
	return global_letter;
}

void print_square(int n)
{
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			char letter = get_letter(row, col, n);
			std::cout << letter << " ";
		}
		std::cout << std::endl;
	}
}

int main () {
	int n = 0;
	std::cin >> n;
	print_square(n);
	printf( "\n");
	return 0;
}


