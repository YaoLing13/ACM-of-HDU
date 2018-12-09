#include <iostream>
#include <vector>
#include <map>

void compare(std::vector<int>& input)
{
    std::map<int, int> record;
    for (int i = 0; i < input.size(); ++i) {
        record[input[i]] ++;
    }

    std::map<int, int>::iterator iter;
    for (iter = record.begin(); iter != record.end(); ++ iter) {
        if(iter->second)
        {
            if (iter->second >= 2)
                std::cout << iter->first << "," << iter->first << ",";
            else
                std::cout << iter->first << ",";
        }
    }

//    for (int j = 0; j < record.size(); ++j) {
//        if (record[j])
//        {
//            std::cout << j << ",";
//            record[j]--;
//            if(record[j])
//            {
//                std::cout << j << ",";
//                record[j]--;
//            }
//        }
//    }

}

std::vector<int> intersect(std::vector<int>& num1, std::vector<int>& num2)
{
    std::map<int, int> record;
    for (int i = 0; i < num1.size(); ++i) {
        if( record.find(num1[i]) == record.end())
            record.insert(make_pair(num1[i], 1));
        else
            record[num1[i]] ++;
    }

    std::vector<int> resultVector;
    for (int j = 0; j < num2.size(); ++j) {
        if (record[num2[j]] > 0){
            resultVector.push_back(num2[j]);
            record[num2[j]]--;
            if (record[num2[i]] == 0)
                record.erase( num2[i] );
        }
    }

    return resultVector;
}

int main(void)
{
    int n, num, m;
    std::cin >> n;
    std::vector<int> num1;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        num1.push_back(num);
    }

//    std::cin >> m;
//    std::vector<int> num2;
//    for (int i = 0; i < m; ++i) {
//        std::cin >> num;
//        num2.push_back(num);
//    }
//    std::vector<int> resultVector;
//    resultVector = intersect(num1, num2);
//    std::cout << "[";
//    for (int j = 0; j < resultVector.size(); ++j) {
//        if (!j)
//        {
//            std::cout << resultVector[j];
//            continue;
//        }
//        std::cout << "," << resultVector[j];
//    }
//    std::cout << "]" << std::endl;
    compare(num1);
    return 0;
}