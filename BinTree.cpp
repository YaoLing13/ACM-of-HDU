/*
 *二叉树遍历算法
 */

#include <iostream>

#define stature(p) ((p) ? (p)->height : -1) //节点高度（与“空树高度为-1”的约定相统一）

/*******************************************************
    *BinNode状态与性质的判断
********************************************************/
#define IsRoot(x) (!((x).parent))  //判断x是否为根节点
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))  //判断x是否为左孩子节点
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))  //判断x是否为右孩子节点
#define HasParent(x) (!IsRoot(x))//判断x是否是根节点，若非根节点则有父节点。即判断x是否有父节点
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x)||HasRChild(x))//判断x是否有孩子节点
#define HasBothChild(x) (HasLChild(x)&&HasRChild(x))//判断x是否同时有2个孩子节点
#define IsLeaf(x) (!HasChild(x)) //判断x是否为叶子节点

/*******************************************************
    *与BinNode具有特定关系的节点及指针
********************************************************/
#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc) //兄弟
#define uncle(x) (IsLChild(*(x)) ? (x)->parent->parent->rc : (x)->parent->parent->lc) //叔叔
#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc ))  // 来自父亲的引用

typedef enum { RB_RED, RB_BLACK} RBColor; //节点颜色

template <class T> class BinNode { //二叉树节点模板类
public:
    T data; //数值
    BinNode<T>* parent;
    BinNode<T>* lc;
    BinNode<T>* rc; //父节点及左、右孩子
    int height; //高度（通用）
    int npl; //Null Path Length（左式堆，也可直接用height代替）
    RBColor color; //颜色（红黑树）


    // 构造函数
    BinNode() : parent ( NULL ), lc ( NULL ), rc ( NULL ), height ( 0 ), npl ( 1 ), color ( RB_RED ) { } // init
    BinNode ( T e, BinNode<T>* p = NULL, BinNode<T>* lc = NULL, BinNode<T>* rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED ) : data ( e ), parent ( p ), lc ( lc ), rc ( rc ), height ( h ), npl ( l ), color ( c ) { }
    //析构函数
    ~BinNode(){}

    // 操作接口
    int size(); //统计当前节点后代总数，亦即以其为根的子树的规模
    BinNode<T>* insertAsLC ( T const& ); //作为当前节点的左孩子插入新节点
    BinNode<T>* insertAsRC ( T const& ); //作为当前节点的右孩子插入新节点
    BinNode<T>* succ(); //取当前节点的直接后继
    template <class VST> void travLevel ( VST& ); //子树层次遍历
    template <class VST> void travPre ( VST& ); //子树先序遍历
    template <class VST> void travIn ( VST& ); //子树中序遍历
    template <class VST> void travPost ( VST& ); //子树后序遍历
    // 比较器、判等器（各列其一，其余自行补充）
    bool operator< ( BinNode const& bn ) { return data < bn.data; } //小于
    bool operator== ( BinNode const& bn ) { return data == bn.data; } //等于


};

// 插入孩子节点
// 约定：在插入左/右孩子节点之前，当前节点无左/右孩子节点
template <class T> BinNode<T>* BinNode<T>::insertAsLC(T const & e) {
    return lc = new BinNode(e, this);
}
template <class T> BinNode<T>* BinNode<T>::insertAsRC(T const & e) {
    return rc = new BinNode(e, this);
}

// 先序遍历：VLR  递归方法
template <class T, class VST>  void travPre_R(BinNode* x, VST& visit)
{
    if (!x) return; //NULL
    visit(x->data); // 根节点
    travPre_R(x->lc, visit); // 左子树
    travPre_R(x->rc, visit); // 右子树
};

// 先序遍历： 迭代版本
// 思路：先沿最左侧通路自顶向下访问沿途节点，然后，在自底而上依次访问这些节点的右子树
// 程序：从当前节点出发，沿左分支不断深入，直至没有左分支节点； 沿途节点遇到后立即访问
template  <class T, class VST> void visitAlongLeftBranch(BinNode<T>* x, VST& visit, Stack< BinNode<T>* >& s)
{
    while (x)
    {
        visit (x->data);
        s.push(x->rc);
        x = x->lc;
    }
}
template <class T, class VST>  void travPre_I(BinNode<T>* x, VST& visit)
{
    Stack< BinNode<T>* > S;
    while(true)
    {
        visitAlongLeftBranch(x, visit, S);
        if (S.empty()) break;
        x = S.pop();    // 弹出下一批的起点
    }

};


// 中序遍历：LVR  递归方法
template <class T, class VST>  void travIn_R(BinNode* x, VST& visit)
{
    if (!x) return; //NULL
    travIn_R(x->lc, visit); // 左子树
    visit(x->data); // 根节点
    travIn_R(x->rc, visit); // 右子树
};
// 中序遍历： 迭代版本1
// 思路：先到达左分支最底部，沿最左侧通路自底而上访问沿途节点及其右子树
// 程序：从当前节点出发，沿左分支不断深入，存入栈中，直至没有左分支节点
template  <class T, class VST> void goAlongLeftBranch(BinNode<T>* x, Stack< BinNode<T>* >& s)
{
    while (x)
    {
        s.push(x);
        x = x->lc;
    }
}
template <class T, class VST>  void travIn_I1(BinNode<T>* x, VST& visit)
{
    Stack< BinNode<T>* > S;
    while(true)
    {
        goAlongLeftBranch(x, S);    //到达左分支最底部,并把沿途经过的左节点都入栈
        if (S.empty()) break;
        x = S.pop();    // 访问左子树
        visit(x->data); // 根节点
        x = x->rc;  // 访问右节点
    }
};
// 中序遍历： 迭代版本2
// 思路：先到达左分支最底部，沿最左侧通路自底而上访问沿途节点及其右子树
// 程序：从当前节点出发，沿左分支不断深入，存入栈中，直至没有左分支节点
template <class T, class VST>  void travIn_I2(BinNode<T>* x, VST& visit)
{
    Stack< BinNode<T>* > S;
    while(true)
    {
        if(!x)
        {
            S.push(x);
            x = x->lc;
        }
        else if( !S.empty() )
        {
            x = S.pop();    // 作为祖先，
            visit(x->data); // 访问该祖先节点数据
            x = x->rc;  //遍历祖先的右子树
        } else
            break;
    }
};
// 中序遍历： 迭代版本3
// 思路：先到达左分支最底部，沿最左侧通路自底而上访问沿途节点及其右子树
// 程序：无需使用任何结构；总体需要O(1)的辅助空间，但是时间效率有所降低
// 辅助函数 { BinNode<T>* succ() } 函数：直接后继及定位
template <class T> BinNode<T>* BinNode<T>::succ() {
    BinNode<T>* s = this;   // 记录后继的临时变量，赋值地址
    if(rc)  //如果有右孩子，则直接后继必定在右子树中
    {
        s = rc; // 右子树
        while( HasLChild( *s ) )    // 最靠左的方法
            s = s->lc;  // 到达最分支最底部
    }
    else
    {
        while(IsRChild(*s)) s = s->parent;
        s = s->parent;
    }
    return s;
}
template <class T, class VST>  void travIn_I3(BinNode<T>* x, VST& visit) {
    bool  backtrack = false;

    while ()
}

// 后序遍历：LRV  递归方法
template <class T, class VST>  void travPost_R(BinNode* x, VST& visit)
{
    if (!x) return; //NULL
    travPost_R(x->lc, visit); // 左子树
    travPost_R(x->rc, visit); // 右子树
    visit(x->data); // 根节点
};

template <class T>
template <class VST>
void BinNode<T>::travIn(VST & visit) {
    travIn_R(this, visit);
}
