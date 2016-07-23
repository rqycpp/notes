### 1. 概念

- 树是由若干个有限**节点**组成的一个具有层次关系的集合，每棵树有且仅有一个**根**。
- 节点拥有的子树个数我们称为节点的**度**。度为0的节点我们称为叶子。
- 树的深度就是节点的最大层数。

### 2. 性质

- 在一棵非空树上，一定会有根节点和叶子节点。
- 一棵非空且仅有一个根节点。
- 在树上，父节点有多个孩子节点，除根节点外，孩子节点有且仅有一个父节点。
- 在一棵树上，一个节点到另一个节点的路径是唯一的。

### 3. 二叉树

- 每个节点最多有两个子树。
- 二叉树的第i层最多有$2^{i-1}$个节点。
- 深度为k的二叉树最多有$2^k-1$个节点。$S_n=\left\{ \begin{array}{lcl} \frac {a_1-a_1q^n}{1-q}, & & (q \neq 1) \\ na_1, & & (q=1) \end{array} \right.$
- 任意一棵二叉树上，其叶子节点个数$n_0$比度为2的节点数$n_2$多1。(我们记树上结点总个数为 $n$，度为1的结点个数为$n_1$，则有$n=n_0+n_1+n_2$。另外我们可以发现一棵二叉树一共有$n - 1$条边，度为 2 的结点可以延伸出 2 条边，度为 1 的结点可以延伸出 1 条边，叶子结点没有边延伸出来，所以又有$n-1=n1+2*n_2$。结合以上两个式子，我们可以得到$n0 =n2+1$。)
- 满二叉树：深度为k，且有$2^k-1$个结点
- 完全二叉树：深度为k，从第一层到第k-1层该树是满二叉树，~~第k层的节点都集中在左边~~。（常用于算法的优化中）
- 完全二叉树上最多有1个度为1的节点。
- 先序遍历，中序遍历，后序遍历。（先根，中根，后根）

> 已知二叉树的先序遍历和中序遍历，求后续遍历
```cpp
#include<iostream>
#include<string>
using namespace std;
class Node {
public:
    int data;
    Node *lchild, *rchild;
    Node(int _data) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL) {
            delete lchild;
        }
        if (rchild != NULL) {
            delete rchild;
        }
    }
    void postorder() {
        if (lchild != NULL) {
            lchild->postorder();
        }
        if (rchild != NULL) {
            rchild->postorder();
        }
        cout << data << " ";
    }
    Node * build(const string &pre_str, const string &in_str, int len){
        Node *p = new Node(pre_str[0] - '0');
        int pos = in_str.find(pre_str[0]);
        if(pos > 0){
            p->lchild = build(pre_str.substr(1,pos), in_str.substr(0,pos), pos);
        }
        if(len - pos - 1 > 0){
            p->rchild = build(pre_str.substr(pos + 1),in_str.substr(pos + 1), len - pos - 1);
        }
        return p;
    }
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        if (root != NULL) {
            delete root;
        }
    }
    BinaryTree(const string &pre_str, const string &in_str, int len){
        root = root->build(pre_str, in_str, len);
    }
    void postorder() {
        root->postorder();
    }
};
int main() {
    string pre_str = "136945827";
    string in_str = "963548127";
    BinaryTree binarytree(pre_str, in_str, in_str.length());
    binarytree.postorder();
    cout<<endl;
    return 0;
}
```

### 4.哈夫曼编码

- 介绍：哈夫曼编码是 1952 年由 David A. Huffman 提出的一种无损数据压缩的编码算法。哈夫曼编码先统计出每种字母在字符串里出现的频率，根据频率建立一棵路径带权的二叉树，也就是哈夫曼树，树上每个结点存储字母出现的频率，根结点到结点的路径即是字母的编码，频率高的字母使用较短的编码，频率低的字母使用较长的编码，使得编码后的字符串占用空间最小。

- 建立哈夫曼树的步骤：
1. 从集合里取出两个根结点权值最小的树 a 和 b，构造出一棵新的二叉树 c，二叉树 c 的根结点的权值为 a 和 b 的根结点权值和，二叉树 c 的左右子树分别是 a 和 b。
2.将二叉树 a 和 b 从集合里删除，把二叉树 c 加入集合里。

- 带权路径长度WPL：就是每个叶子到根的距离乘以叶子权值结果之和。也是压缩后的比特总长度。

- 性质：
1. 在哈夫曼树上，相对来说，权值大的节点离根节点近，权值小的节点离根节点远。
2. 哈夫曼树的WPL，等于编码后字符串所占的比特数。
3. 哈夫曼树上不会存在只有一个孩子节点的节点。
4. 哈夫曼编码每次从集合里取出节点权值最小的两棵二叉树构成新的二叉树。
