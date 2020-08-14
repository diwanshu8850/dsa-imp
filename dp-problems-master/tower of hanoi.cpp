https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0


========================================================METHOD 1 (Recursion)==================================================
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll moves(ll n, ll A, ll B, ll C){
    if(n==1){
        cout<<"move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
        return 1;
    }
    
    // move (n-1) disk from A to B
    ll a = moves(n-1, A, C, B);
    cout<<"move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
    
    // then move 1 disk from A to C
    a+=1;
    
    // then move (n-1) disks from again B to C
    a+=moves(n-1, B, A, C);
    return a;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    cout<<moves(n, 1, 2, 3)<<endl;
	}
	
	return 0;
}





============================================METHOD 2 (dp)========================================================
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	
	int dp[17]={0};
	for(ll i=1;i<=16;i++){
  
      // as we are moving (i-1) disks 2 times so the number of moves required to move the (i-1) disks will be twice
      // and total moves will be (2*moves required to move (i-1)) + 1 moving one disk from A to C
	    dp[i] = (2*dp[i-1]) + 1;
	}
	while(t--){
	    ll n;
	    cin>>n;
	    cout<<dp[n]<<endl;
	}
	
	return 0;
}
