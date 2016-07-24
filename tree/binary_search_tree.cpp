#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *lchild, *rchild, *father;
	Node(int _data, Node *_father = NULL) {
		data = _data;
		lchild = NULL;
		rchild = NULL;
		father = _father;
	}
	~Node() {
		if (lchild != NULL) {
			delete lchild;
		}
		if (rchild != NULL) {
			delete rchild;
		}
	}
	void insert(int value) {
		if (value == data) {//value已经存在直接返回
			return;
		}
		else if (value > data) {
			if (rchild == NULL) {//右子树为空
				rchild = new Node(value, this);//插入节点
			}
			else {
				rchild->insert(value);//右子树非空，继续递归
			}
		}
		else {
			if (lchild == NULL) {
				lchild = new Node(value, this);
			}
			else {
				lchild->insert(value);
			}
		}
	}

	//查找权值为value的节点
	Node* search(int value) {
		if (data == value) {
			return this;
		}
		else if (value > data) {
			if (rchild == NULL) {
				return NULL;
			}
			else {
				return rchild->search(value);
			}
		}
		else {//value < data
			if (lchild == NULL) {
				return NULL;
			}
			else {
				return lchild->search(value);
			}
		}
	}

	Node* predecessor() {//找前驱节点
		Node *temp = lchild;//左子树
		while (temp != NULL && temp->rchild != NULL) {//temp不为空且有右子树
			temp = temp->rchild;//一路找到底
		}
		return temp;
	}

	Node* successor() {//找后继节点
		Node *temp = rchild;
		while (temp != NULL && temp->lchild != NULL) {//temp不为空且有左子树
			temp = temp->lchild;//一路找到底
		}
		return temp;
	}

	//删除度为0或1的节点，这是一种特殊情况，操作简单
	void remove_node(Node *delete_node) {
		Node *temp = NULL;
		if (delete_node->lchild != NULL) {
			temp = delete_node->lchild;
			temp->father = delete_node->father;
			delete_node->lchild = NULL;
		}
		if (delete_node->rchild != NULL) {
			temp = delete_node->rchild;
			temp->father = delete_node->father;
			delete_node->rchild = NULL;
		}
		if (delete_node->father->lchild == delete_node) {
			delete_node->father->lchild = temp;
		}
		else {
			delete_node->father->rchild = temp;
		}
		delete delete_node;
	}

	//删除权值为value的任意节点，会用到remove_node()
	bool delete_tree(int value) {
		Node *delete_node, *current_node;
		current_node = search(value);
		if (current_node == NULL) {//不存在权值为value节点
			return false;
		}
		if (current_node->lchild != NULL) {//找前驱节点
			delete_node = current_node->predecessor();
		}
		else if (current_node->rchild != NULL) {//没有前驱找后继
			delete_node = current_node->successor();
		}
		else {//叶子节点
			delete_node = current_node;
		}
		current_node->data = delete_node->data;//改变权值
		remove_node(delete_node);//前驱和后继度为0或1，叶子节点度为0
		return true;

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

	//插入权值为value的节点
	void insert(int value) {
		if (root == NULL) {//根为空，即树是空的
			root = new Node(value);//直接把节点加入
		}
		else {
			root->insert(value);
		}
	}

	//查找权值为value的节点
	bool find(int value) {
		if (root->search(value) == NULL) {
			return false;
		}
		else {
			return true;
		}
	}

	//删除权值为value的节电
	bool delete_tree(int value) {
		return root->delete_tree(value);
	}
};
int main() {
	BinaryTree binarytree;
	int arr[10] = { 8, 9, 10, 3, 2, 1, 6, 4, 7, 5 };
	for (int i = 0; i < 10; ++i) {
		binarytree.insert(arr[i]);
	}

	int value;
	cin >> value;
	if (binarytree.find(value)) {
		cout << "search success!" << endl;
	}
	else {
		cout << "search failed!" << endl;
	}

	cin >> value;//删除节点
	if (binarytree.delete_tree(value)) {
		cout << "delete success!" << endl;
	}
	else {
		cout << "delete failed!" << endl;
	}

	return 0;
}
