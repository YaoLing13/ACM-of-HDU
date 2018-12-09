/********** 1 ************/
/********** 1 ************/
/********** 1 ************/

/*
 * 第一行输入近似多边形的边数：n

第二行输入多边形的n个顶点坐标：x1,y1,x2,y2,...,xn,yn

第三行输入芝麻的个数：m

第四行输入芝麻的坐标：X1,Y1,X2,Y2,...,Xm,Ym

所有的坐标x,y满足 -1000<= x,y <= 1000
 */

void justPos(int& n, float* &multiRects, int& m, float* &multiZhi)
{
    float x_min = 10000.0;
    float x_max = 0.0;
    float y_min = 10000.0;
    float y_max = 0.0;

    for (int j = 1; j <= n; ++j) {
        x_min = std::min(x_min, multiRects[2*j-1]);
        y_min = std::min(y_min, multiRects[2*j]);
        x_max = std::min(x_max, multiRects[2*j-1]);
        y_max = std::min(y_max, multiRects[2*j]);
    }

    int x;
    int y;
    int count_value = 0;
    for (int i = 1; i <= m; ++i) {
        x = multiZhi[2*i - 1];
        y = multiZhi[2*i];
        if( x < x_min || x > x_max || y < y_min || y > y_max)
            continue;
        printf("(%.2f,%.2f) ", x, y);
    }
    if(count_value == 0)
        std::cout << "No" << std::endl;
}

int main(int argc, char ** argv)
{
    int n;
    scanf("%d", &n); // 多边形的边数：n
    if(n <= 0)
        throw  std::logic_error("invalid input");

    float* multiRects = new float[2*n+1];
    memset(multiRects, 0, 2*n+1);

    char fuhao1, fuhao2;
    float m1, m2;
    int i;
    for (int i = 1; i <= n ; ++i) {
        if(i == n)
        {
            std::cin >> m1 >> fuhao1 >> m2;
            if(m1 >1000 || m1 < -1000 || m2 >1000 || m2 < -1000)
                throw  std::logic_error("invalid input");
            multiRects[2*i-1] = m1;
            multiRects[2*i] = m2;
            break;
        }
        std::cin >> m1 >> fuhao1 >> m2 >> fuhao2;
        if(m1 >1000 || m1 < -1000 || m2 >1000 || m2 < -1000)
            throw  std::logic_error("invalid input");
        multiRects[2*i-1] = m1;
        multiRects[2*i] = m2;
    }

    int m;
    scanf("%d", &m); // 多边形的边数：n
    if(m <= 0)
        throw  std::logic_error("invalid input");

    float* multiZhi = new float[2*m+1];
    memset(multiZhi, 0, 2*m+1);

    for (int i = 1; i <= m ; ++i) {
        if(i == m)
        {
            std::cin >> m1 >> fuhao1 >> m2;
            if(m1 >1000 || m1 < -1000 || m2 >1000 || m2 < -1000)
                throw  std::logic_error("invalid input");
            multiZhi[2*i-1] = m1;
            multiZhi[2*i] = m2;
            break;
        }
        std::cin >> m1 >> fuhao1 >> m2 >> fuhao2;
        if(m1 >1000 || m1 < -1000 || m2 >1000 || m2 < -1000)
            throw  std::logic_error("invalid input");
        multiZhi[2*i-1] = m1;
        multiZhi[2*i] = m2;
    }

    justPos(n, multiRects, m, multiZhi);

    delete[] multiRects;
    delete[] multiZhi;
    return 0;
}


/********** 2 ************/
/********** 2 ************/
/********** 2 ************/
int card_num(int length)
{
    if(length <= 0)
        return -1;
    if(length == 1)
        return 1;
    if(length == 2)
        return 2;

    // length flag
    int* legth_array = new int[length+1];
    std::memset(legth_array, 0, length+1);

    legth_array[0] = 0;
    legth_array[1] = 1;
    legth_array[2] = 2;

    int max_value = 0;
    for (int i = 3; i < length+1; ++i) {
        max_value = 0;
        for (int j = 1; j <= i/2; ++j) {
            max_value = std::max(max_value, legth_array[j]*legth_array[i-j]);
        }
        legth_array[i] = max_value;
    }
    int result_value = legth_array[length];
    delete[] legth_array;
    return result_value;
}

int main(void)
{
    int n;
    std::cin >> n;
    if(n <= 0)
        return -1;
    std::cout << card_num(n) << std::endl;
    return 0;
}