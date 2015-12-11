class Solution {
public:
    int p[9]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    string getPermutation(int n, int k) {
        if(n==0)return "";
        int a=(k-1)/p[n-1];
        char ch='1'+a;
        string t=getPermutation(n-1,k-a*p[n-1]);
        for(int i=0;i<t.length();i++){
            if(t[i]>=ch){
                t[i]++;
            }
        }
        return ch+t;
    }
};
