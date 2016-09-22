/*
Given a string s="CABBCC"
index:            654321

Let f(i) be the column number of a substring s[i,...,1], c(i)=s(i)-'A'+1
then
f(i) = [c(i)-1]*26^(i-1) + f(i-1)
        number of strings  "CAAAAA"<=number of strings<="CABBCC"
        starting with
        c(i)-1 and length
        i
       
        Example:
        "AAAAAA"
          ...
        "AZZZZZ"
          ...
        "BZZZZZ"

We also have consider all strings with length < n, so the total number
sum = f(n)+sigma_{i=1}^{n-1} 26^i 

sigma_{i=1}^{n-1} 26^i can be put inside f(i) so that they can be calculated simultaneously:

f(i) = [c(i)-1]*26^(i-1) + f(i-1) +26^(i-1) = c(i)*26^(i-1) + f(i-1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int toNumber(string s) {
        int sum=0, base=1;
        for(int i=s.length()-1;i>=0;i--){
            sum+=(s[i]-'A'+1)*base;
            base*=26;
        }
        return sum;
    }
  string toStr(int n) {
    string rv;
    while(n){
      if(n%26==0) rv=rv+'Z';
      else
        rv=rv+(char)('A'+n%26-1);
      n/=26;
    }
    reverse(rv.begin(),rv.end());
    return rv;
  }
};

int main(){
  Solution s;
  cout<<s.toStr(705)<<endl;
  return 0;
}
