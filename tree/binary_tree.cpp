// Source : https://www.jisuanke.com/course/35/5835
// Author : RQY
// Date   : 2016-07-24
/**********************************************************************************
蒜头君最近在学习二叉树，可是心不在焉的他一会儿就学累了，于是他想休息会儿。蒜头君拿出镜子，对着镜子中的自己各种卖萌。蒜头君无意间看见镜子中出现了一棵二叉树，这不是他刚画的那棵二叉树么，在镜子里怎么左右颠倒了呀。

蒜头君觉得好神奇，现在蒜头君又随手画了一棵二叉树，他想知道这棵二叉树在镜子里是长什么样的。为了将问题简单，现在蒜头君告诉你这棵二叉树的先序遍历结果和中序遍历结果，求原始二叉树的后序遍历结果，以及镜子里的二叉树的后序遍历结果。

输入格式：

输入第一行是一个字符串 pre_str，代表原始二叉树的先序遍历结果；输入第二行是一个字符串 in_str，代表二叉树的中序遍历结果。每个字符代表结点的编号，结点的编号互不相同，字符仅由大小写字母组成。保证两个字符串长度相等，长度最大不超过 50，且保证可以通过先序遍历结果和中序遍历结果构造出一棵唯一的二叉树。

输出格式：

输出第一行，输出一个字符串，代表原始二叉树的后序遍历结果；

输出第二行，输出一个字符串，代表镜子里的二叉树的后序遍历结果。

样例输入

abdce
dbaec
样例输出

dbeca
ecdba
 **********************************************************************************/
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
		cout << static_cast<char>(data + '0');//建树的代码将字符串保存为整数值，所以此处若不修改，则输出相应的整数。
		//cout << data << " ";
	}
	Node * build(const string &pre_str, const string &in_str, int len) {//由二叉树先序遍历，中序遍历，来建树。
		Node *p = new Node(pre_str[0] - '0');
		int pos = in_str.find(pre_str[0]);
		if (pos > 0) {
			p->lchild = build(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
		}
		if (len - pos - 1 > 0) {
			p->rchild = build(pre_str.substr(pos + 1), in_str.substr(pos + 1), len - pos - 1);
		}
		return p;
	}
	Node *mirror(Node *root) {//将一棵二叉树变为它的镜像二叉树
		if (root == NULL) {//递归的边界
			return NULL;
		}
		Node *mleft = mirror(root->lchild);//对左子树求镜像
		Node *mright = mirror(root->rchild);//对右子树求镜像

		//交换左右子树
		root->lchild = mright;
		root->rchild = mleft;

		return root;//返回当前的节点
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
	BinaryTree(const string &pre_str, const string &in_str, int len) {
		root = root->build(pre_str, in_str, len);
	}
	void mirrorTree() {
		root = root->mirror(root);
	}
	void postorder() {
		root->postorder();
	}
};
int main() {
	//string pre_str = "136945827";
	//string in_str = "963548127";
	string pre_str, in_str;
	cin >> pre_str >> in_str;
	BinaryTree binarytree(pre_str, in_str, in_str.length());

	binarytree.postorder();
	cout << endl;
	binarytree.mirrorTree();
	binarytree.postorder();
	cout << endl;
	return 0;
}
