https://practice.geeksforgeeks.org/problems/edit-distance/0


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
	    ll n,m;
	    cin>>n>>m;
	    string s1, s2;
	    cin>>s1>>s2;
	    vector< vector<ll> > dp(n+1, vector<ll>(m+1, 0));
      
      // if string 1 is empty then we require the length of string 2 to convert string 1 to 2
	    for(ll i=1;i<=m;i++){
	        dp[0][i]=i;
	    }
      
      // if string 2 is empty then we need to remove chars from the string 1 to convert it to 2
	    for(ll i=1;i<=n;i++){
	        dp[i][0]=i;
	    }
	    for(ll i=1;i<=n;i++){
	        for(ll j=1;j<=m;j++){
          
              // if current char is equal then the distance will be the minimum distance
              // required to convert string 1 of length (i-1) to string 2 of length (j-1)
	            if(s1[i-1]==s2[j-1]){
	                dp[i][j] = dp[i-1][j-1];
	            }
              
              // if the current char is not equal then
              // we can insert one char in string 1, then we need to check for string 1 of length (i-1) and string 2 of length (j-1)
              // we can delete this char from string 1, then we need to check for string 1 of length (i-1) and string 2 of length (j)
              // we can replace this char in string 1, then we need to check for string 1 of length (i) and string 2 of length (j-1)
              // we will basically take min of the above 3 choices and add one to it as we are making one move 
              else{
	                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
	            }
	        }
	    }
	    cout<<dp[n][m]<<endl;
	}
	
	return 0;
}
