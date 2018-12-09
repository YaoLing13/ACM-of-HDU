#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

int count_substring(string& a, string& b)
{
    if(a.length() < 1 || b.length() < 1)
        throw logic_error("Input number is invalid!");
    if(a.length() > b.length())
        return 0;
    int count_number = 0;
    string b_substr;
    int temp_index_b = 1;
    for (int i = 0; i < b.length(); i = temp_index_b) {
        b_substr = b.substr(i,a.length());
        if(a.compare(b_substr) == 0)
        {
            ++count_number;
            temp_index_b = i+a.length()+1;
        }
        int j;
        for (j = 1; j < b_substr.length(); ++j) {
            if(a[0] == b_substr[j])
                break;
        }
        temp_index_b = i + j;
    }
    return count_number;
}

int main() {
    int n;  // 1 <= n <= |a|
    cin >> n;
    if(n < 1)
        throw logic_error("Input number is invalid!");
    string a,b;
    cin >> a;
    if(a.length() < n)
        throw logic_error("Input string A error!");
    cin >> b;

    string a_substr;
    vector<string> a_substring_vec;
    int all_count_number = 0;
    a_substring_vec.resize(0);  // init
    for (int i = 0; i <= a.length()-n; ++i) {
            a_substr = a.substr(i,i+n);
            int flag_re = 0;
            if(a_substring_vec.empty())
                a_substring_vec.push_back(a_substr);
            for (int k = 0;a_substring_vec.size() > 1 &&  k < a_substring_vec.size(); ++k) {
                if(a_substr.compare(a_substring_vec[k]) == 0)
                {
                    flag_re = 1;
                    break;
                }
            }
            if(flag_re)
                break;
            a_substring_vec.push_back(a_substr);
            all_count_number += count_substring(a_substr, b);
    }
    cout << all_count_number << endl;
}

/*
int main() {
    int q_score, niu_score;
    cin >> q_score; // 0 < q_score < 10^12
    cin >> niu_score;

    int all_score = q_score + niu_score;

}
 */