https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void heapify(vector<ll> &v, vector<ll> &dis, ll size, ll root){
    ll l = 2*root + 1;
    ll r = l+1;
    ll i = root;
    if(r<size && dis[v[r]-1]<dis[v[i]-1]){
        i=r;
    }
    if(l<size && dis[v[l]-1]<dis[v[i]-1]){
        i=l;
    }
    if(dis[v[i]-1]<dis[v[root]-1]){
        swap(v[i], v[root]);
        heapify(v, dis, size, i);
    }
}

void buildHeap(vector<ll> &v, vector<ll> &dis, ll n){
    for(ll i = (n/2)-1;i>=0;i--){
        heapify(v, dis, n, i);
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v, dis;
        v.push_back(1);
        dis.push_back(0);
        for(ll i=1;i<n;i++){
            v.push_back(i);
            dis.push_back(INT_MAX);
        }
        while(v.size()!=0){
            ll j = v[0];
            swap(v[0], v[v.size()-1]);
            v.pop_back();
            if(j+1<=n && dis[j]>dis[j-1]+1){
                dis[j]=dis[j-1]+1;
            }
            if((3*j)<=n && dis[(3*j)-1]>dis[j-1]+1){
                dis[(3*j)-1]=dis[j-1]+1;
            }
            buildHeap(v, dis, v.size());
        }
        // for(auto i:dis){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        cout<<dis[n-1]<<"\n";
    }
	return 0;
}
