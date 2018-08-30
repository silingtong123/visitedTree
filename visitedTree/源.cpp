#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct Bitree {
	int data;
	Bitree *lchild;
	Bitree *rchild;
	Bitree(int i, Bitree *l = NULL, Bitree *r = NULL): data(i),lchild(l),rchild(r){

	}
};

Bitree *Insert(Bitree *root,int data) {
	if (!root)
		root = new Bitree(data);
	else
	{
		Bitree  *cur = root;
		if (cur->data > data) {
			root->lchild = Insert(root->lchild, data);
		}
		else {
			root->rchild = Insert(root->rchild, data);
		}
	}
	return root;
}

void preOrder(Bitree * root) {
	if (root) {
		cout << root->data<<endl;
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

void inOrder(Bitree * root) {
	if (root) {
		
		inOrder(root->lchild);
		cout << root->data<<endl;
		inOrder(root->rchild);
	}
}


void postOrder(Bitree * root) {
	if (root) {
		
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout << root->data<<endl;
	}
}


void pre_order(Bitree * root) {
	if (root) {
		stack<Bitree *> s;
		s.push(root);
		while (!s.empty())
		{
			Bitree *cur = s.top();
			cout << cur->data << endl;
			s.pop();
			
			if(cur->rchild)
				s.push(cur->rchild);
			if (cur->lchild)
				s.push(cur->lchild);
		}
	}
}

void in_order(Bitree * root) {
	if (root) {
		stack<Bitree *> s;
		s.push(root);
		Bitree *cur = s.top();
		while (!s.empty()) {
			
			while (cur->lchild) {
				cur = cur->lchild;
				s.push(cur);
			}
			if (!s.empty()) {
				cur = s.top();
				cout << cur->data << endl;
				s.pop();
				cur = cur->rchild;
			}
		}
	}
}

void post_order(Bitree * root) {
	if (root) {
		stack<Bitree *> s;
		s.push(root);
		while (!s.empty())
		{
			Bitree *cur = s.top();
			cout << cur->data << endl;
			s.pop();
			if (cur->lchild)
				s.push(cur->lchild);
			if (cur->rchild)
				s.push(cur->rchild);
			
		}
	}
}
int main() {
	Bitree * root=NULL;
	root = Insert(root, 5);
	root = Insert(root,3);
	root = Insert(root, 4);
	root = Insert(root, 7);
	root = Insert(root, 6);
	cout << "µÝ¹éÇ°Ðò" << endl;
	preOrder(root);
	cout << "µÝ¹éÖÐÐò" << endl;
	inOrder(root);
	cout << "µÝ¹éºóÐò" << endl;
	postOrder(root);

	cout << "·ÇµÝ¹éºóÐò" << endl;
	pre_order(root);
	cout << "·ÇµÝ¹éºóÐò" << endl; 
	in_order(root);
	cout << "·ÇµÝ¹éºóÐò" << endl;
	post_order(root);
	return 0;
}