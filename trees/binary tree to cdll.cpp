https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1


/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

void inorder(Node *root, Node** head, Node** temp){
    if(root){
        inorder(root->left, head, temp);
        Node *t = root->right;
        
        // check if head of the list is null or not
        // if NULL means this is the first node of the list mark it head and tail also
        if(!(*head)){
            root->left = NULL;
            root->right = NULL;
            *head=root;
            *temp=root;
        }
        
        // if head is not null then add the folling node at the end of the doubly linked list and mark the tail accordingly
        else{
            (*temp)->right = root;
            root->left = *temp;
            root->right = NULL;
            *temp = (*temp)->right;
        }
        inorder(t, head, temp);
    }
}

Node *bTreeToCList(Node *root){

    // just traverse the tree in inorder fashion and keep track of head pointer of the list and tail of the list
    Node *head=NULL, *temp=NULL;
    inorder(root, &head, &temp);
    
    // make the list circular
    temp->right = head;
    head->left = temp;
    
    return head;
    return head;
}
