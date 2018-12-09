#include <iostream>
#include <cstring>

bool reach(int row, int col, int& maxValue)
{
    int tmp = row/10 + row % 10 + col / 10 + col % 10;
    if(tmp > maxValue)
        return false;
    else
        return true;
}

int movingCountCore(int rows, int cols, int row, int col, int thredhold, bool* visited)
{
    int count = 0;
    if(row < rows && col < cols && row >= 0 && col >= 0 && reach(row, col, thredhold) && !visited[row*cols + col])
    {
        visited[row*cols + col] = true;
        count = 1 + movingCountCore(rows,cols, row-1, col, thredhold, visited)
                + movingCountCore(rows,cols, row+1, col, thredhold, visited)
                + movingCountCore(rows,cols, row, col-1, thredhold, visited)
                + movingCountCore(rows,cols, row, col+1, thredhold, visited);
    }
    return count;
}

int movingCount(int rows, int cols, int thredhold)
{
    if(rows <= 0 || cols <= 0 || thredhold < 0)
        return 0;

    auto* visited = new bool[rows * cols];
    int maxnum = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::memset(visited, 0, rows*cols);
            maxnum = std::max(maxnum, movingCountCore(rows, cols, row, col, thredhold, visited));
        }
    }
    return maxnum;
}

int main(void)
{
    int maxValue = 5;
    std::cout << movingCount(10, 10, maxValue) << std::endl;
    return 0;
}