
/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
*/
void heapSort(int arr[], int n)  {
    // first we need to build a max heap in order to do heapsort in ascending order
    buildHeap(arr, n);
    
    // after building max heap we need to extract max from the heap or simply replace last node with the root node
    // and decrease the size the heapify the remaining tree
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int A[], int n, int i)  {

    // just find the largest of both the child of current node
    int l = 2*i + 1;
    int r = l+1;
    int root=i;
    if(l < n && A[root] < A[l]){
        root = l;
    }
    if(r < n && A[root] < A[r]){
        root = r;
    }
    
    // if parent is largest among the three (2 child if present and the parent) don't do anything
    // else swap the parent value with the child's value and recursively call heapify over child
    if(A[i] < A[root]){
        swap(A[i], A[root]);
        heapify(A,n,root);
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int A[], int n)  {
    
    // as the leaf nodes do not have any child we can simply ignore
    // them and heapify out tree in bottom up manner
    // taking one parent at a time
    // requires o(n) time to heapify
    for(int i=(n/2)-1;i>=0;i--){
        heapify(A,n,i);
    }
}
