https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

Node *traverse(Node *root, map<Node *, Node *> &m){
    if(root){
    
        // create a new node with the root node data
        Node *head = new Node(root->data);
        
        // recursively call the same for the left and right tree
        head->left = traverse(root->left, m);
        head->right = traverse(root->right, m);
        
        // store the value inside the map
        m[root] = head;
        return head;
    }
    return NULL;
}

/* The function should clone the passed tree and return 
   root of the cloned tree */
Node* cloneTree(Node* tree){

    // to store node which is further used to set random pointers
    map<Node *, Node *> m;
    
    // traverse to copy the tree without random pointers
    traverse(tree, m);
    
    // set random pointers
    for(auto i=m.begin();i!=m.end();i++){
        i->second->random = m[i->first->random];
    }
    return m[tree];
}
