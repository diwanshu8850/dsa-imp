//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/

pair<int, int> maxSum(Node *root){
    if(root){
        pair<int, int> l = maxSum(root->left);
        pair<int, int> r = maxSum(root->right);
        
        pair<int, int> p;
        
        // if we include the root->data then we need to exclude its child data which means we need to pick the data of second inside the pair
        // as it represents the sum which we get after excluding the childs data
        p.first = root->data+l.second+r.second;
        
        // if we exclude the root->data then we have two choices either to pick from child's included sum or from child's excluded sum
        // so we will take maximum of both for both of the child and add them together
        p.second = max(l.first, l.second) + max(r.first, r.second);
        return p;
    }
    return {0,0};
}

//This function returns the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) {

    // it will represent the values which are if we include the particular nodes data or not
    pair<int, int> p;
    p = maxSum(root);
    
    // max of included and excluded will give us out result
    return max(p.first, p.second);
}
