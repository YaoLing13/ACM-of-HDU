
#include<iostream> 
#include<set> 
using namespace std; 

int majorityElement(vector<int>& nums) 
{ 
	map<int,size_t> value; 
	pair<map<int,size_t>::iterator,bool> ret; 
	for(int i=0;i<nums.size();i++) 
	{ 
		ret=value.insert({nums[i],1}); 
		if(!ret.second) 
		++ret.first->second; 
	} 
	auto map_it=value.begin(); 
	while(map_it!=value.end()) 
	{ 
	if ((map_it->second)>(floor(nums.size()/2))) 
		{ 
			break; 
		} 
	else 
		++map_it; 
	} 
	return map_it->first; 
}

 
int main() 
{ 
    //定义一个int型集合对象s,当前没有任何元素.由www.169it.com搜集整理
    map<int, int> s; 
    s.insert(8,1);  //第一次插入8，可以插入  
    s.insert(1); 
    s.insert(12); 
    s.insert(6); 
    s.insert(8);   //第二次插入8，重复元素，不会插入  
    set<int>::iterator it; //定义前向迭代器 
    //中序遍历集合中的所有元素  
    for(it=s.begin();it!=s.end();it++) 
    {	cout<<*it<<" num:"<< s.count(*it)<<endl;    
}
    return 0; 
}

