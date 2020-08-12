#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void heapify(vector<ll> &v, vector<ll> &dis, ll size, ll root){
    ll l = 2*root + 1;
    ll r = l+1;
    ll i = root;
    if(r<size && dis[v[r]]<dis[v[i]]){
        i=r;
    }
    if(l<size && dis[v[l]]<dis[v[i]]){
        i=l;
    }
    if(dis[v[i]]<dis[v[root]]){
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

	ll n,m;
	cin>>n>>m;
	vector< pair<ll, ll> > A[n];
	vector<ll> dis(n, 10e9), v;
	dis[0]=0;
	for(ll i=0;i<n;i++){
		v.push_back(i);
	}
	for(ll i=0;i<m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		A[x-1].push_back({y-1, w});
	}
	while(v.size()!=0){
		ll j = v[0];
		swap(v[v.size()-1], v[0]);
		v.pop_back();
		for(auto i:A[j]){
			if(dis[i.first]>dis[j]+i.second){
				dis[i.first]=dis[j]+i.second;
			}
		}
		buildHeap(v, dis, v.size());
	}
	for(ll i=1;i<n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
}
