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
        return Map[head];//return clone of head 
    }
};
