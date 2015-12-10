class Solution {
public:
    /*
        we search for each i from 0...n such that the right end is v[i]
        we set j to n initially.
        
        for each i, we decrease j till v[i]+v[j]<=target, let such j be j'
        if v[i]+v[j']==target then we are done
        otherwise, we check i+1
        
        Now we prove that if i+1 is the smallest number of the solution, the right ending
        point <= j':
        
        v[i]+v[k>j']>target and v[i+1]>=v[i] => v[i+1]+v[k>j']>target
        
        so for k>j' we don't need to search again, so the right boundary must <=j'
        
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i<j){
            while(numbers[i]+numbers[j]>target)j--;
            if(numbers[i]+numbers[j]==target)return vector<int>{i+1,j+1};
            i++;
        }
    }
};
