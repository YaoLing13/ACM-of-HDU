#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
/*
int count_ways(int n, int m)
{
    if(m == 1)
        return 1;
    if(n == 1)
        return 1;

    // length flag
    int* legth_array = new int[n+1];
    std::memset(legth_array, 0, n+1);

    legth_array[1] = 1;

    for (int i = 2; i < n+1; ++i) {
        for (int j = 1; j <= m; ++j) {
            legth_array[]
        }
    }
    int result_value = legth_array[n];
    delete[] legth_array;
    return result_value;
}


int main() {
    int a,b;
    cin >> a >> b;
    if(a < 1 || b < 1 || a < b)
        throw std::range_error("Input error");
    std::cout << count_ways(4,3) << std::endl;
}*/
/*
#include <iostream>
#include <cstring>
#include <exception>
#include <stdexcept>
using namespace std;

int gcd(int n, int m)
{
    int* b = new int[n+1];
    memset(b, 0, n+1);
    for (int j = 1; j <= m ; ++j) {
        b[j] = j;
    }
    for(int i=m; i<=n; i++)
    {
        b[i] = 0;
        for (int k = 0; k <= m; ++k) {
            b[i] += b[i - k];
        }
    }

    return b[n]+1;
}
int main()
{
    int n,m;
    cin >> n >> m;
    if(n < 1 || n < 1 || n < m)
        throw std::range_error("Input error");
    std::cout << gcd(n,m)%10007 << std::endl;
    return 0;
}*/

#include <iostream>
#include <cstring>
#include <exception>
#include <stdexcept>
using namespace std;

int main()
{
    int num;
    cin >> num;
    if(num < 1)
        throw range_error("Input error");
    while(num -- )
    {

    }
}