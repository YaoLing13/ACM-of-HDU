/*
 * Discribe: Loop print
 * Author: Yaoling
 * Time: 2018-07-27
 */


#include <iostream>
#include <algorithm>

int get_number(int& row, int& col, int& n)
{
	int n_1 = n - 1;
	int loop1 = std::min(row, col);
	int loop2 = std::min(n_1-row, n_1-col);
	int loop = std::min(loop1, loop2);	// min(row, col, n_1-row, n_1-col)，确定目前属于哪一圈
	int line, index_in_line;	// line表示目前处于一圈的第几条线上; index_in_line表示处在线上的几个位置
	if (col == loop && row != loop)
	{
		line = 3;
		index_in_line = (n_1 - loop) -row;
	}
	else if (n_1 - row == loop)
	{
		line = 2;
		index_in_line = (n_1 - loop) - col;
	}
	else if (n_1 - col == loop)
	{
		line = 1;
		index_in_line = row - loop;
	}
	else if(row == loop)
	{
		line = 0;
		index_in_line = col - loop;
	}
	int line_length = n_1 - loop * 2;	// 最外圈每根线上数字为n-1个，每靠内一圈，线上数字减2个
	int index_in_loop = line * line_length + index_in_line;	// 本圈线上的数字
	int before_loop = 4 * (n_1 - loop + 1) * loop;	// 上一圈的数字总和
	return before_loop + index_in_loop + 1;	//上一圈的数字+本圈前面的数字+1
}

void print_square(int n)
{
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			int number = get_number(row, col, n);
			std::cout << number << " ";
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
