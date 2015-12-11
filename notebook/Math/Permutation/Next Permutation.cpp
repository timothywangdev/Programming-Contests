/*

Next Permutation 

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

    A naive O(n^2) solution works as follows:
    
    (1) from right to left find the first element nums[i] such that:
       there exist nums[j]>nums[i] where j>i, select smallest such j
       
    (2) swap nums[i] and nums[j], then sort nums[i+1..end] in non-decreasing order
    
    Theorem #1:
    First step is equivalent of finding first i from right to left such that
    nums[i]<nums[i+1].
    
    Proof:
    Suppose we have i from (1), since nums[i+1..end] is in non-increasing order, we know that
    nums[i+1] is the maximum from [i+1..end].
    
    Note that nums[i]<num[j] for j in [i+1..end] (def of (1) ) => nums[i]<nums[i+1]
    
    Now we prove that there's no such i' where nums[i']<nums[i'+1] for i'>i. We know that [i+1..end] is in non-increasing order,
    so i' cannot exist.
    
    Q.E.D.
    
    Next, we find smallest element nums[j]>nums[i] where j>i, and then swap nums[i] and nums[j].
    
    Theorem #2: 
    after swapping, [i+1..end] is in non-increasing order.
    
    Proof:
    We denote nums'[i], nums'[j] as the value of nums[i] and nums[j] after swapping.
    Suppose [i+1..end] is not in non-increasing order after swapping. 
    1. nums[j]<=nums[j-1] and nums'[j]<num[j] => nums[j-1]>=nums'[j] => the order preserves for [i+1..j]
    We now prove that nums'[j]>=num[j+1]. Assume nums'[j]<nums[j+1], note that nums[j]>=nums[j+1](non-increasing order),
    the algorithm should had selected nums[j+1] to swap since nums'[j]=num[i]<nums[j+1] and j+1>j, which is a 
    contradiction. Thus, nums'[j]>=nums[j+1], which implies the order preserves for [j+1..end]
    
    Q.E.D.
    
    Therefore, from Theorem #2, we only need to reverse [i+1..end] to achieve the same effect as (2)
    
    Overall time complexity O(n)
    
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            // maximum of [idx..end]  num[idx]<num[idx+1]>=... >=... >= end
            int minimum=nums[idx+1]+1,min_idx;
            for(int i=nums.size()-1;i>idx;i--){
                if(nums[i]>nums[idx]&&nums[i]<minimum){
                    minimum=nums[i];
                    min_idx=i;
                }
            }
            swap(nums[idx],nums[min_idx]);
            // now [idx+1..end] is in non-decreasing order, reverse then to make non-increasing order
            reverse(nums.begin()+idx+1,nums.end());
            return;
        }
        reverse(nums.begin(),nums.end());
    }
};
