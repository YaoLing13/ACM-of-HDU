/*
 * Discribe: 升序
 * Author: Yaoling
 * Time: 2018-08-02
 * URL: https://www.cnblogs.com/onepixel/articles/7674659.html
 */
#include <iostream>

// 冒泡排序
// 算法：循环遍历要排序的数列，如果相邻两个元素顺序错误，就将其换一下，直到n次遍历结束
// 时间复杂度: 最坏：O(n^2)， 最好：O(n)
// 空间复杂度：O(1)
// 排序：稳定
int* BubbleSort(int* input, int n)
{
	for(int j = 1; j < n; ++j)
	{
		for(int i = 1; i < n; ++i)
		{
			if(input[i] < input[i-1])
			{
				input[i]   = input[i] ^ input[i-1];
				input[i-1] = input[i] ^ input[i-1];
				input[i]   = input[i] ^ input[i-1];
			}
		}
	}
	return input;
}

// 选择排序
// 算法：在未排序的数列中找到最小(最大)的元素，将其(已排序)放在数列起始(末尾)位置，依次循环，直到全部排序完成。
// 时间复杂度: 最坏：O(n^2)， 最好：O(n^2)
// 空间复杂度：O(1)
// 排序：不稳定(?)
int* SelectSort(int* input, int n)
{
	int tempos;
	int minValue;
	for (int j = 0; j < n; ++j)
	{
		tempos = j;
		minValue = input[j];
		for(int i = j; i < n; ++i)
		{
			if(minValue > input[i])
			{
				minValue = input[i];
				tempos = i;
			}
		}
		if(tempos != j)
		{
			input[j]      = input[j] ^ input[tempos];
			input[tempos] = input[j] ^ input[tempos];
			input[j]      = input[j] ^ input[tempos];
		}
	}
	return input;	
}

// 插入排序
// 算法：通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
// 时间复杂度: 最坏：O(n^2)， 最好：O(n)
// 空间复杂度：O(1)
// 排序：稳定(?)
int* InsertSort(int* input, int n)
{
	for (int j = 1; j < n; ++j) {
		for(int i=j; i > 0; --i)
		{
			if(input[i] < input[i-1])
			{
				input[i]   = input[i] ^ input[i-1];
				input[i-1] = input[i] ^ input[i-1];
				input[i]   = input[i] ^ input[i-1];
			}
		}
	}
	return input;
}

// 希尔排序
// 算法：是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
// 时间复杂度: 最坏：O(n^2)， 最好：O(n)
// 空间复杂度：O(1)
// 排序：不稳定(?)
int* ShellSort(int* input, int n)
{
	int gap = n/2;
	while(gap)
	{
		for (int j = gap; j < n; j += gap)	// 一个间隔一个间隔进行比较
		{
			for (int i = j; i >= gap; i -= gap)	//
			{
				if(input[i-gap] > input[i])
				{
					input[i-gap] = input[i-gap] ^ input[i];
					input[i]     = input[i-gap] ^ input[i];
					input[i-gap] = input[i-gap] ^ input[i];
				}
			}
		}
		gap = gap / 2;	// 动态更改gap
	}
	return input;
}

// 归并排序
// 算法：将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
// 时间复杂度: 最坏：O(nlogn)， 最好：O(nlogn)
// 空间复杂度：O(n)
// 排序：稳定
void Merge(int* input, int* reg, int start, int end)
{
	if (start >= end)	return;
	int len = end - start;
	int midValue = (len >> 1) + start;
	int start1 = start, end1 = midValue;
	int start2 = midValue + 1, end2 = end;

	Merge(input, reg, start1, end1);
	Merge(input, reg, start2, end2);

	//两个序列一一比较,哪的序列的元素小就放进reg序列里面,然后位置+1再与另一个序列原来位置的元素比较
	//如此反复,可以把两个有序的序列合并成一个有序的序列
	int k = start;
	while(start1 <= end1 && start2 <= end2)
	{
		reg[k++] = input[start1] > input[start2] ? input[start2++] : input[start1++];
	}

	//然后这里是分情况,如果arr2序列的已经全部都放进reg序列了然后跳出了循环
	//那就表示arr序列还有更大的元素(一个或多个)没有放进reg序列,所以这一步就是接着放
	while (start1 <= end1)
	{
		reg[k++] = input[start1++];
	}
	//这一步和上面一样
	while (start2 <= end2)
	{
		reg[k++] = input[start2++];
	}

	for (int i = start; i <= end; ++i) {
		input[i] = reg[i];
	}
}
int* MergeSort(int* input, int n)
{
	int* reg = new int[n];	//临时变量，临时存放
	Merge(input, reg, 0, n-1);
	return input;
}

// 快速排序
// 算法：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。。
// 时间复杂度: 最坏：O(n^2)， 最好：O(nlogn)
// 空间复杂度：O(nlogn)
// 排序：不稳定
// 思想：从数列中挑出一个元素，称为 “基准”（pivot）；重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
void Quick(int* input, int left, int right)
{
	//快速排序之前先判断一下当前待排序数组元素个数是不是大于1 否则就没有必要排序
	if(left >= right) return;

	//开始进行快排算法
	//首先我们先保存left索引对应的数据  当前数据作为切割数组的基准
	int pivot = input[left];	// 作为基准
	int leftIndex = left;		// 临时变量存放数列2端
	int rightIndex = right;
	while (leftIndex < rightIndex)
	{
		//现在我们通过循环从右边开始搜索一个比基准小的数据
		while (leftIndex < rightIndex)
		{
			//如果右边的数大于当前的基准
			if (pivot <= input[rightIndex])
				rightIndex --; //右端索引指示器左移
			else
			{
				//说明我们右端出现比基准更小的数据
				//这个时候我们就可以把这个更小的数据填充到索引基准索引对应的地方
				input[leftIndex] = input[rightIndex];
				leftIndex++;
				//我们需要跳出循环了当前工作完毕
				break;
			}
		}

		//从左边开始搜索一个比基准更大的数填写上次留下的坑
		while (leftIndex < rightIndex)
		{
			//如果左边的数据小于基准 我们索引指示器就往右走
			if (pivot >= input[leftIndex])
				leftIndex++;
			else
			{
				//说明我们在左端找到了比轴值更大的数据
				input[rightIndex] = input[leftIndex];
				rightIndex--;
				break;
			}
		}
	}

	input[leftIndex] = pivot;

	Quick(input, left, leftIndex-1);
	Quick(input, rightIndex+1, right);
}
int* QuickSort(int* input, int n)
{
	Quick(input, 0, n-1);
	return input;
}

int main(int argc, char ** argv)
{
	int n = 0;	// number of input elements
	std::cin >> n;
	
	int* input = new int[n];
	// input
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
	}

	//input = BubbleSort(input, n);
	//input = SelectSort(input, n);
	//input = InsertSort(input, n);
	//input = ShellSort(input, n);
	//input = MergeSort(input, n);
	input = QuickSort(input, n);

	// print
	for (int i = 0; i < n; ++i)
	{
		std::cout << input[i] << " ";
	}

	return 0;	
}
