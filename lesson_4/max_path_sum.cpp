/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int rec_finder(struct Node* root, int &M){
    if(root==NULL) return 0;
    int l=rec_finder(root->left, M);
    int r=rec_finder(root->right, M);
    M=max(l+r+root->data, M);
    return max(l,r)+root->data;
}
int maxPathSum(struct Node *root){
    int M=0;
    rec_finder(root, M);
    return M;
}
