//O(N) recursive sol
class Solution {
public:
    void solve(ListNode* head, int k,int cnt) {
        if(head==NULL || cnt<k)return head;
        ListNode*prev=NULL,*nex=NULL,*curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            count++;
        }
        if(nex!=NULL)head->next=solve(nex,k,cnt-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      /*   int t=0; // Another way to break and stop if not reach k
        ListNode* prev=nullptr, *check=curr;
        while(t<k && check!=nullptr) check=check->next,t++;
        if(t<k) return curr; */
        int cnt=0;
        ListNode*ptr=head;
        while(ptr!=NULL){
            ptr=ptr->next;
            cnt++;
        }
        return solve(head,k,cnt);
    }
};


//Optimal O(1)


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k==0)return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=dummy,*pre=dummy,*nex=dummy;
        int count =0;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        while(count>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=0;i<k-1;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            count=count-k;
        }
        return dummy->next;
    }
};
