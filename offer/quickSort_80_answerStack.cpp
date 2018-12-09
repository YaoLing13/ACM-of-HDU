#include <iostream>
#include <stack>
using namespace std;

void Swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i] = a[j];
    a[j] = temp;
}
int Partition(int a[],int low, int high)
{
    int pivot=a[low];

    while(low<high)
    {
        while(low<high && a[high]>pivot)
            high--;
        Swap(a,low,high);
        while(low<high&& a[low]<=pivot)
            low++;
        Swap(a,low,high);
    }
    return low;
}

int QuickSort_NonRecursive(int a[],int low, int high)
{
    stack<int> s;
    if(low<high)
    {
        int mid = Partition(a,low,high);
        if (low<mid-1)
        {
            s.push(low);
            s.push(mid-1);
        }
        if (mid+1<high)
        {
            s.push(mid+1);
            s.push(high);
        }
        while(!s.empty())
        {
            int h = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            int m = Partition(a,l,h);
            if (l<m-1)
            {
                s.push(l);
                s.push(m-1);
            }
            if (m+1<h)
            {
                s.push(m+1);
                s.push(h);
            }
        }
    }
    return 0;
}

int main()
{
    int a[]={4,3,6,9,7,5,1,10,2,15,8,7,6};
    QuickSort_NonRecursive(a,0,sizeof(a)/sizeof(a[0])-1);

    cout<<"after quick sort:"<<endl;
    for(int i=0; i<sizeof(a)/sizeof(a[0]);i++)
    {
        cout<<a[i]<<" ";
    }
    //system("pause");
    return 0;
}


/*
void QuickSortNotR(std::vector<int>& input, int left, int right)
{
    std::stack<int> s;
    s.push(left);
    s.push(right);//后入的right，所以要先拿right
    while(!s.empty())//栈不为空
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        int index = basicIndex_right(input,left,right);
        if((index - 1) > left)//左子序列
        {
            s.push(left);
            s.push(index - 1);
        }
        if(((index) + 1) < right)//右子序列
        {
            s.push(index + 1);
            s.push(right);
        }
    }
}
*/
