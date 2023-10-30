// O(N) space 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*ptr=head;
        unordered_map<Node*,Node*>Map;//MAP of type Node*
        while(ptr!=NULL){
            Map[ptr]=new Node(ptr->val);//Store Original Node in Map first and Duplicate in Map second (original ---> Duplicate )
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL){
         Map[ptr]->next=Map[ptr->next];// Duplicate->next = original->next
         Map[ptr]->random=Map[ptr->random];
         ptr=ptr->next;
        }
        // OR 
        for(auto it:Map){
         if(it.first -> next)it.second->next=Map[it.first->next];
         if(it.first -> random)it.second->random=Map[it.first->random];
        }
        return Map[head];//return clone of head 
    }
};
// O(1) Space Sol

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node*original=head;                                 
        Node*temp=nullptr;
     
        while(original!=NULL){                           // 1->2->3->4->5 
            temp=new Node(original->val);                //1->1c->2->2c->3->3c->4->4c->5->5c 
            temp->next=original->next;
            original->next=temp;
            original=temp->next;

        }
        original=head;
        Node* nhead = head->next;
        while(original!=NULL){                  //update random 
         if(original->random!=NULL){
             original->next->random=original->random->next;
            }
            else{
                original->next->random=nullptr;
            }
            original=original->next->next;
        }
        original=head;
        while(original!=NULL){
            temp = original->next; 
            original->next = temp->next; 
            original = original->next;

            if(original){
                temp->next = original->next;
            } else {
                temp->next = nullptr;
            }
        }
        return nhead;
    }
};
