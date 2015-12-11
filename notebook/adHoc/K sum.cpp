/*

[TWO SUM PROOF]

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

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> rv;
    void Ksum(int start,int K, int target, vector<int>& nums){
        // Not enough elements to select
        if(start+K>nums.size())return;
        if(K==2){
            int i=start,j=nums.size()-1;
            while(i<j){
                // we don't want duplicated results
                if(i>start&&nums[i]==nums[i-1]){
                    i++;
                    continue;
                }
                while(i<j&&nums[i]+nums[j]>target)j--;
                if(i<j&&nums[i]+nums[j]==target){
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    rv.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                }
                i++;
            }
            return;
        }
        else{
            
            for(int i=start;i+K<=nums.size();i++){
                // we don't want duplicated results
                if(i>start&&nums[i]==nums[i-1])continue;
                tmp.push_back(nums[i]);
                Ksum(i+1,K-1,target-nums[i],nums);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        Ksum(0,3,0,nums);
        return rv;
    }
};
