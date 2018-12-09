#include <iostream>
#include <set>

using namespace std;
int main(void)
{
    string str = "associative";
    set<char> charstr;
    set<char>::iterator iter;
    for (int i = 0; i < str.length(); ++i) {
        charstr.insert(str[i]);
    }

    cout << charstr.size() << endl;

    iter = charstr.begin();
    for (int j = 0; j < charstr.size(); ++j) {
        cout << *iter << "-" << charstr.count(*iter) << " ";
        ++ iter;
    }
    cout << endl;

    if(charstr.count('t') == 1)
    {
        cout << "Erase 't' from the set " << endl;
        charstr.erase('t');
    }

    iter = charstr.find('s');
    cout << *iter << " " << charstr.count('s') << endl;
    charstr.erase(iter);

    charstr.erase(charstr.begin(), charstr.end());

    return 0;
}