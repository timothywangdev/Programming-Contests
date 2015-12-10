/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
        O(m+n) m=len(A), n=len(B)
        First find difference in lengths
        Suppose A is longer than B
        move curA to A+diff, curB=headB
        now they are equidistant from their ends, then we move one step at a time for
        both curA and curB till curA==curB or one of them is NULL(no intersection)
        
        Note that the largest diff is the length of intersection(when B starts at the intersection)
        
        a--a---a
                \
                ab--ab--ab
                
        Thus curA will can only be moved to as far as the starting point of the intersection.
        Therefore both curA and curB are at a point <= the starting point of the intersection, thus
        we are guarentee to find the intersection(if exists)
    */  
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return NULL;
        ListNode *curA=headA,*curB=headB;
        int cA=0,cB=0;
        while(curA){
            curA=curA->next;
            cA++;
        }
        while(curB){
            curB=curB->next;
            cB++;
        }
        int diff=abs(cA-cB);
        curA=headA;
        curB=headB;
        cout<<diff<<" "<<cA<<" "<<cB<<endl;
        if(cA>cB){
            for(int i=0;i<diff;i++){
                curA=curA->next;
            }
        }
        else if(cA<cB){
            for(int i=0;i<diff;i++){
                curB=curB->next;
            }
        }
        while(curA!=curB){
            if(!curA||!curB)return NULL;
            curA=curA->next;
            curB=curB->next;
        }
        return curA;
    }
};
