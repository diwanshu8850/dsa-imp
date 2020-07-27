// the array elements are at most k position away from their actual position in the sorted array

// simply the idea is to form a min heap of size k and then push the root element inside our ans vector
// then replace the root with the next element in the array which after k elements and do the same procedure


void heapify(int A[], int n, int root){
    int l = 2*root + 1;
    int r = l+1;
    int i=root;
    if(l<n && A[l]<A[i]){
        i=l;
    }
    if(r<n && A[r]<A[i]){
        i=r;
    }
    
    if(A[i]<A[root]){
        swap(A[i], A[root]);
        heapify(A,n,i);
    }
}

void buildHeap(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(A,n,i);
    }
}

vector <int> nearlySorted(int arr[], int n, int k){
    // Your code here
    vector<int> v;
    if(k==n){
        buildHeap(arr,n);
       int i=0;
        while(i<k){
            v.push_back(arr[0]);
            arr[0]=arr[k-i-1];
            heapify(arr,k-i-1,0);
            i+=1;
        }
    } else{
        buildHeap(arr,k+1);
        int i=k+1;
        while(i<n){
            v.push_back(arr[0]);
            arr[0]=arr[i];
            heapify(arr,k+1,0);
            i+=1;
        }
        i=0;
        while(i<=k){
            v.push_back(arr[0]);
            arr[0]=arr[k-i];
            heapify(arr,k-i,0);
            i+=1;
        }
    }
    return v;
}
