/*
 * https://www.jianshu.com/p/b98a49ae55ad
 * 图的邻接表
 */

#include <memory>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <stack>
#include <cfloat>

using namespace std;

//图用邻接表方式表示
class EWDigraph
{
private:
    int vex_;   //图中顶点数;
    int edge_;  //图中边数
    map<char, bool> mapIsInQue_;    //当前顶点是否在队列中,可以变成局部变量,但可能会增加内存分配和释放的次数
    map<char, double> mapDistance_; //顶点V到出发点S的最短距离
    map<char, char> mapPath_;       //顶点V到出发点S的最短路径
    map<char, vector<pair<char, double >>> ewd_;    //图的邻接表

public:
    //构造函数,传入顶点.边数和<顶点1,顶点2,边权值>元组的数组
    //参数中的const是向编译器承诺在函数中不对该参数进行修改。如果该参数在函数体内被改变，则会收到编译器报错。
    //如果不是明确地需要在函数中修改传入的参数，最好将所有传入的参数都标记成const。顺便说一句，Google在其开源项目风格指南中明确规定，所有按引用传递的参数必须加上 const.
    EWDigraph(const int vex, const int edge, const vector<tuple<char, char, double >>&);
    //打印邻接表
    void Print();
    //计算出发点start到图中所有点的最短距离
    void Dijkstra(const char start);
    //计算出发点start到终点end的最短距离并且打印最短路径
    void Dijkstra(const char start, const char end);
    //获取当前图中的所有顶点
    //函数最后的const是向编译器承诺函数返回值不会被修改
    vector<char> GetNodes() const;
    //检查输入的顶点是否在顶点列表中
    bool IsValidVex(const char vex) const;
    //从出发点start开始对图进行广度优先遍历 Breadth First Search Traversal
    void BFST(const char start);
    //从出发点start开始对图进行深度优先遍历 Depth First Search Traversal
    void DFST(const char start);

private:
    //初始化 mapIsInQue_, mapDistance_, mapPath_
    void InitVecs();
    //打印出发点start到图中所有点的最短距离和最短路径
    void PrintDij(const char start);
    //打印出发点start到终点end的最短距离和最短路径
    void PrintDij(const char start, const char end);

};

EWDigraph::EWDigraph(const int vex, const int edge, const vector<tuple<char, char, double>>   &v)
        :vex_(vex),
         edge_(edge)
{
    //把vector<tuple<char,char,double>> 转换成map<char,<char,double>>
    //get<0>(v[i])是元组tuple的特殊用法
    for (int i = 0; i < edge_; i++)
        ewd_[get<0>(v[i])].push_back(make_pair(get<1>(v[i]), get<2>(v[i])));
}

void EWDigraph::Print(){
    for(auto a:ewd_)
    {
        cout << a.first << " | ";
        for (auto it : ewd_[a.first]) {
            cout << a.first << "->" << it.first << " : " << it.second << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * GetNodes函数: 获得邻接表顶点
 * 输出: vector<char>
 */
vector<char> EWDigraph::GetNodes() const {
    vector<char> vRet;
    for (auto it:ewd_) {
        vRet.push_back(it.first);
    }
    return vRet;
}

/*
 * BFST函数: 广度优先遍历
 * 思路:
 *    1.从出发点压入队列
 *    2.读取队列头,将该顶点标记为"已访问"
 *    3.把队列头指向的所有未访问的顶点压入队尾
 *    4.重复第2,3步,直到队列为空
 *    5.检查是否还有顶点未访问(非连通顶点),如果是,则将该顶点入队列,重复2,3,4,5
 */
void EWDigraph::BFST(const char start) {
    std::deque<char> q;
    map<char, bool> vVisited;
    for (auto i : GetNodes()) {
        vVisited[i] = false; // 所有顶点标记为未访问
    }

    //1.出发点入队列
    q.push_front(start);
    cout << "BFST(" << start << "):"<<endl;
    while(!q.empty())
    {
        //读取队列头
        char node = q.front();
        q.pop_front();
        if(!vVisited[node])
        {
            //将队列头设置为已访问
            vVisited[node] = true;
            //打印顶点
            cout << node << "-";
        }
        for(auto j : ewd_[node])
        {
            //把队列头指向的所有未访问的顶点压入队尾
            if(!vVisited[j.first]){
                q.push_back(j.first);
            }
        }

        //
        if(q.empty()){
            //检查图中是否还有顶点未访问。如果是，则将该顶点入队列
            for(auto i : GetNodes())
            {
                if(!vVisited[i])
                {
                    q.push_back(i);
                    break;
                }
            }
        }
    }

    cout << "end";
    cout << endl;
}

/*
 * DFST函数: 深度优先遍历
 * 思路:
 *    1.把当前图中所有顶点压入栈 （防止有非联通顶点未被遍历）
 *    2.出发点入栈
 *    3.读取栈顶，将该顶点标记为“已访问”
 *    4.把栈顶指向的所有未访问的顶点入栈
 *    5.重复第3，4步，直到栈为空
 */
void EWDigraph::DFST(const char start) {
    std::stack<char> s;
    map<char, bool> vVisited;
    // 1.把当前图中所有顶点压入栈 （防止有非联通顶点未被遍历）
    for(auto i : GetNodes()){
        vVisited[i] = false;
        s.push(i);
    }

    //2.出发点入栈,位于栈顶
    s.push(start);
    cout << "DFST(" << start << "):"<<endl;
    while(!s.empty())
    {
        // 3.读取栈顶，将该顶点标记为“已访问”
        char node = s.top();
        s.pop();
        if(!vVisited[node])
        {
            // 设置栈顶为已访问
            vVisited[node] = true;
            //打印顶点
            cout << node << "-";
        }
        for (auto i : ewd_[node]) {
            //栈顶指向的所有未访问的顶点入栈
            if(!vVisited[i.first]){
                s.push(i.first);
            }
        }

    }
    cout << "end";
    cout << endl;

}

void EWDigraph::InitVecs(){
    for (auto i : GetNodes()){
        //map<char, char> mapPath_
        mapPath_[i] = '0';
        //map<char, bool> mapIsInQue_
        mapIsInQue_[i] = false;
        //DBL_MAX = 2^1024
        mapDistance_[i] = DBL_MAX;
    }
}

void EWDigraph::PrintDij(const char start){
    for (auto im:ewd_){
        cout << im.first << ":" << mapDistance_[im.first] << "  |  Path = " ;
        std::stack<char> spath;
        for (int j = im.first; j != start; j = mapPath_[j]){
            if (j == '0'){
                cout << "unreachable " ;
                break;
            }
            else{
                spath.push(j);
            }
        }
        spath.push(start);
        while (spath.size()>0){
            cout << spath.top();
            if (spath.top() != im.first)
                cout << "->";
            spath.pop();
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * Dijkstra函数: Dijkstra最短路径(不支持路径为负)
 * 思路:
 *     1.将出发点(标记为S)到自己的距离设为0，到所有其他顶点的距离设为无穷大，所有其他顶点路径标记为“不可达到”
 *     2.出发点压入队列，将出发点标记为“已在队列中”
 *     3.读取队列头(标记为H)，将其标记为“未在队列中”
 *     4.遍历所有与队列头相邻的顶点(标记为N1,N2,...)。如果S到N1(N2,...)的距离(初始值是无穷大) > S到H的距离+H到N1(N2,...)的距离时，记录：S到N1的距离=S到H距离+H到N1(N2,...)的距离
 *     5.使用mapPath_记录当前状态下S到N1(N2,...)的最短路径必须经过顶点H，该状态在后续的遍历中可能会改变
 *     6.检查N1,N2,...是否在队列中，如果不在，则将其压入队列
 *     7.重复3，4，5，6，直到队列为空
 */
void EWDigraph::Dijkstra(const char start){
    InitVecs();
    //出发点到自身的距离为0
    mapDistance_[start] = 0;
    std::queue<char> q;

    //出发点入队列
    q.push(start);
    mapIsInQue_[start] = true;
    while (!q.empty())
    {
        //队列头出队列
        int node = q.front();
        q.pop();
        mapIsInQue_[node] = false;
        for (auto it : ewd_[node]) {
            //遍历所有与当前顶点(队列头顶点)相邻的顶点
            if(mapDistance_[it.first] > mapDistance_[node] + it.second){
                mapDistance_[it.first] = mapDistance_[node] + it.second;
                mapPath_[it.first] = node;
                if (!mapIsInQue_[it.first]){
                    //如果这些与当前顶点相邻的顶点不在队列中，则将其压入队列
                    q.push(it.first);
                    mapIsInQue_[it.first] = true;
                }
            }
        }
    }
    PrintDij(start);
}

void EWDigraph::Dijkstra(const char start, const char end){
    //指定起点和终点的最短路径查找，思路同前
    InitVecs();
    cout << start << "->" << end << ":";
    mapDistance_[start] = 0;
    std::queue<char> q;
    q.push(start);
    mapIsInQue_[start] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        mapIsInQue_[node] = false;
        for (auto it : ewd_[node]){
            if (mapDistance_[it.first] > mapDistance_[node] + it.second){
                mapDistance_[it.first] = mapDistance_[node] + it.second;
                mapPath_[it.first] = node;
                if (!mapIsInQue_[it.first]){
                    q.push(it.first);
                    mapIsInQue_[it.first] = true;
                }
            }
        }
    }
    PrintDij(start, end);
}

void EWDigraph::PrintDij(const char start, const char end){
    cout << mapDistance_[end] << "  |  Path = ";
    std::stack<char> spath;
    for (int j = end; j != start; j = mapPath_[j]){
        if (j == '0'){
            cout << "unreachable";
            break;
        }
        else{
            spath.push(j);
        }
    }
    spath.push(start);

    while (spath.size()>0){
        cout << spath.top();
        if (spath.top() != end)
            cout << "->";
        spath.pop();
    }
    cout << endl;
    cout << endl;
}

bool EWDigraph::IsValidVex(const char vex) const{
    //检查输入的顶点是否合法
    return (ewd_.find(vex) != ewd_.end());
}

int main(void)
{
    vector<tuple<char, char, double >> g = {
            make_tuple('E', 'F', 0.35),
            make_tuple('F', 'E', 0.35),
            make_tuple('E', 'H', 0.37),
            make_tuple('F', 'H', 0.28),
            make_tuple('H', 'F', 0.28),
            make_tuple('F', 'B', 0.32),
            make_tuple('A', 'E', 0.38),
            make_tuple('A', 'C', 0.26),
            make_tuple('H', 'D', 0.39),
            make_tuple('B', 'D', 0.29),
            make_tuple('C', 'H', 0.34),
            make_tuple('G', 'C', 0.40),
            make_tuple('D', 'G', 0.52),
            make_tuple('G', 'A', 0.58),
            make_tuple('G', 'E', 0.93),
            make_tuple('I', 'J', 0.5),
            make_tuple('J', 'J', 0)
    };

    auto ewd = make_shared<EWDigraph>(10, 17, g);
    ewd->Print();

    //使用广度优先遍历
    for(auto it : ewd->GetNodes())
    {
        ewd->BFST(it);
        ewd->DFST(it);
        cout << "Start Point: " << it << endl;
        ewd->Dijkstra(it);
        cout << endl;
    }

    cout << "Processing end!" << endl;
    return 0;
}