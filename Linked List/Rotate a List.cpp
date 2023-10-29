lass Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int n=1;
        ListNode*temp=head;
        while(temp->next!=NULL){
            n++;//calculate lenth of list and point to last node 
            temp=temp->next;
        }
        temp->next=head;//make circular LL

        k=k%n;//for case k>n 
        k=n-k;// for size 5 k=2 we need to go to 3rd node so n-k 
        
        while(k--){
            temp=temp->next;//go to break point node
        }
        head=temp->next;//new head and break connection
        temp->next =NULL;

        return head;
    }
};
