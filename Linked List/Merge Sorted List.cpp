class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode*zero=new ListNode(0);
        ListNode*zerohd=zero; //normal ptr movement 
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                zero->next=l1;
                zero=zero->next;
                l1=l1->next;
            }
            else {
                zero->next=l2;
                zero=zero->next;
                l2=l2->next;
            }
        }
        zero->next=l1?l1:l2;
        return zerohd->next;

    }
};
