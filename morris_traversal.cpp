// Inorder Traversal in O(n) time with O(1) auxilary space

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> MorrisTraversal(TreeNode* a) {
	if(a == NULL)
		return res;

	TreeNode *temp = a, *pre;
	while(temp != NULL){
		if(!temp->left){
			cout<<temp->val<<" ";
			temp = temp->right;
		}
		else{
			// finding inorder predecessor of temp
			pre = temp->left;
			while(pre->right != NULL && pre->right != temp)
				pre = pre->right;

			// making temp/current node as right of its inorder predecessor
			if(pre->right == NULL){
				pre->right = temp;
				temp = temp->left;
			}
			else {
				pre->right = NULL;
				cout<<temp->val<<" ";
				temp = temp->right;
			}
		}
	}
}
// If we take a closer look, we can notice that every
// edge of the tree is traversed at most two times.
