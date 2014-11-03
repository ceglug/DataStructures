#include <stdio.h>
#include <stdlib.h>
struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

BSTree()
{
	root = NULL;
}

void add(int val)
{
	struct BSTreeNode *n, *p = root, *parent;

	n = (struct BSTreeNode *)malloc(sizeof(*n));

	n->val = val;
	n->left = NULL;
	n->right = NULL;

	if (root == NULL) {
		root = n;
		return;
	}

	while (p) {
		parent = p;
		if (val < p->val)
			p = p->left;
		else
			p = p->right;
	}

	if (val < parent->val)
		parent->left = n;
	else
		parent->right = n;
}

int search(int val)
{
	struct BSTreeNode *p = root;

	while (p) {

		if (val == p->val)
			break;
		else if (val < p->val)
			p = p->left;
		else
			p = p->right;
	}

	return (p != NULL);
}
void remove_node(struct BSTreeNode *p, struct BSTreeNode *parent)
{
	struct BSTreeNode *min;
	int tmp;

	if (p->right == NULL) { /* no right subtree */

		if (parent == NULL) /* root */
			root = p->left;
		else if (parent->left == p)
			parent->left = p->left;
		else
			parent->right = p->left;

		return;
	}

	/* find min node in the right subtree */
	min = p->right;
	parent = p;
	while (min->left) {
		parent = min;
		min = min->left;
	}

	/* swap values of p and min */
	tmp = p->val;
	p->val = min->val;
	min->val = tmp;

	/* remove the min node now */
	remove_node(min, parent);
}
void remove(int val)
{
	struct BSTreeNode *p = root, *parent = NULL;

	while (p) {
		if (val == p->val)
			break;
		else if (val < p->val) {
			parent = p;
			p = p->left;
		} else {
			parent = p;
			p = p->right;
		}
	}

	if (p == NULL) /* not found */
		return;

	remove_node(p, parent);
}
void do_postorder(struct BSTreeNode *p, int *arr, int *count)
{
	if (p == NULL)
		return;

	do_postorder(p->left, arr, count);
	do_postorder(p->right, arr, count);

	arr[*count] = p->val;
	(*count)++;
}
void get_postorder(int *arr, int *count)
{
	*count = 0;
	do_postorder(root, arr, count);
}
int do_get_height(struct BSTreeNode *p)
{
	int l, r;

	if (p == NULL)
		return -1;

	l = do_get_height(p->left);
	r = do_get_height(p->right);

	return (l > r) ? (l + 1) : (r + 1);
}
int get_height(void)
{
	return do_get_height(root);
}

