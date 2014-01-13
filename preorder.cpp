#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string s;
	Node *left;
	Node *right;
};

Node *new_node(string s)
{
	Node *temp = new Node();
	temp->s = s;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool add_edge(Node *root, Node *father, Node *child)
{
	if (root == NULL) {
		return false;
	}
	if (root->s == father->s) {
		if (root->left == NULL) {
			root->left = child;
			return true;
		}
		else {
			root->right = child;
			return true;
		}
	}
	if (!add_edge(root->left, father, child)) {
		return add_edge(root->right, father, child);
	}
	return true;
}

void pre_order(Node *root)
{
	if (root == NULL) {
		return;
	}
	cout << root->s << endl;
	pre_order(root->left);
	pre_order(root->right);
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		string s1, s2;
		cin >> s1 >> s2;
		Node *tree = new_node(s1);
		Node *left = new_node(s2);
		tree->left = left;
		while (--k) {
			cin >> s1 >> s2;
			add_edge(tree, new_node(s1), new_node(s2));
		}
		pre_order(tree);
	}
	return 0;
}
