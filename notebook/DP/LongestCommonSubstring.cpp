int longestCommonSubstring(string A, string B) {
        // write your code here
        int n=A.length(),m=B.length(),maximum=0;
        vector<vector<int>> LCS(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i]==B[j]){
                    if(i==0||j==0){
                        LCS[i][j]=1;
                    }
                    else{
                        LCS[i][j]=LCS[i-1][j-1]+1;
                    }
                }
                else{
                    LCS[i][j]=0;
                }
                maximum=max(LCS[i][j],maximum);
            }
        }
        return maximum;
    }
