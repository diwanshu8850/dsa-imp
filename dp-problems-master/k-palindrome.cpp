https://practice.geeksforgeeks.org/problems/k-palindrome/1


/*You are required to complete this function*/
bool is_k_palin(string s,int k){
    
    //Your code here
    int n=s.length();
    
    // as string of length 1 will always be a palindrom so we require to delete 0 elements 
    vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
    
    // for the remaining lengths
    for(int i=2;i<=n;i++){
        for(int j=0;j<=(n-i);j++){
        
            // if the extreme characters are equal then the number of characters to be removed will be equal the 
            // number of characters required to be removed from the string of length (current_length-2)
            if(s[j]==s[j+i-1]){
                dp[j][j+i-1] = dp[j+1][j+i-2];
            }
            
            // if the extremes are not equal then the number of characters to be removed will be equal to the
            // number of characters required to be removed from the string of length (current_length-1) + 1
            // as (current_length-1) length can be formed by two ways either by removing the first character or by removing the last character
            // we will take min of these two
            else{
                dp[j][j+i-1] = min(dp[j][j+i-2], dp[j+1][j+i-1])+1;
            }
        }
    }
    if(dp[0][n-1]<=k){
        return true;
    }
    return false;
}
