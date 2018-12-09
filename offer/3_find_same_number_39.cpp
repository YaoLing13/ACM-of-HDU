#include <iostream>
#include <vector>

void find_same_number(std::vector<int>& input)
{
    int temp;
    for (int i = 0; i < input.size(); ++i) {
        while(input[i] != i){
            if(input[i] != input[input[i]])
            {
                temp = input[i];
                input[i] = input[input[i]];
                input[temp] = temp;
            }
            else
            {
                std::cout << input[i] << " ";
                break;
            }
        }
    }
}

int main(void) {
    std::cout << "number of input elements is same as array number !" << std::endl;
    int n, num, m;
    std::cin >> n;
    std::vector<int> num1;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        num1.push_back(num);
    }

    find_same_number(num1);

    return 0;
}