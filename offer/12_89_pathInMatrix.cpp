#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

#if 1
bool findChar(char* matrix, int rows, int cols, int row, int col, char* dst, int& pathLength, bool* visited, std::stack<int>& place)
{
    if(dst[pathLength] == '\0')
        return true;
    bool haspath = false;
    if(matrix[row*cols + col] == dst[pathLength] && !visited[row*cols+col] &&
       col < cols && col >= 0 && row < rows && row >= 0) // 该点对
    {
        // 然后对相邻的进行查找
        ++ pathLength;
        haspath = findChar(matrix, rows, cols, row-1, col, dst, pathLength, visited, place)
                  || findChar(matrix, rows, cols, row+1, col, dst, pathLength, visited, place)
                  || findChar(matrix, rows, cols, row, col-1, dst, pathLength, visited, place)
                  || findChar(matrix, rows, cols, row, col+1, dst, pathLength, visited, place);
        if(!haspath)
        {
            --pathLength;
            visited[row*cols + col] = false;
        }
        else
            place.push(row*cols + col);

    }
    return haspath;
}

bool pathInMatrix(char* matrix, int rows, int cols, char* dst, std::stack<int>& place)
{
    bool* visited = new bool[rows*cols];
    int pathLength = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(findChar(matrix, rows, cols, i, j, dst, pathLength, visited, place))
                return true;
        }
    }
    return false;
}


#endif

#if 0
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col < cols && col >= 0
       && matrix[row * cols + col] == str[pathLength]
       && !visited[row*cols + col])
    {
        ++pathLength;
        visited[row*cols + col] = true;
        hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);

        if(!hasPath)
        {
            --pathLength;
            visited[row*cols + col] = false;
        }
    }
    return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == nullptr || rows < 1 || cols <1 || str== nullptr)
        return false;

    bool *visited = new bool[rows * cols];
    std::memset(visited, 0, rows*cols);

    int pathLength = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if(hasPathCore(matrix, rows, cols, row,col, str, pathLength, visited))
                return true;
        }
    }

    delete[] visited;
    return false;
}
#endif

int main(void)
{
    char matrix[16] = {'a', 'b', 't', 'g',
                'c', 'f', 'c', 's',
                'j', 'd', 'e', 'h'
    };
    char str[4] = {'b', 'f', 'c', 'e'};
    std::stack<int> place;  //由于是递归，所以首先存入的是最后的字符，最后存入的是首字符
    if(pathInMatrix(matrix, 3, 4, str, place))
    {
        std::cout << "Find: "<<place.size()<< std::endl;
        while (place.size() > 0) {
            std::cout << matrix[place.top()] << " ";
            place.pop();
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Not Find"<< std::endl;
    return 0;
}



