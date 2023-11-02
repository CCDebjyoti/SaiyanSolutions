 Node* merge(Node* l1,Node* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        Node*zero=new Node(0);
        Node*zerohd=zero;
        while(l1!=NULL && l2!=NULL){
            if(l1->data<l2->data){
                zero->bottom=l1;
                zero=zero->bottom;
                l1=l1->bottom;
            }
            else {
                zero->bottom=l2;
                zero=zero->bottom;
                l2=l2->bottom;
            }
        }
        if(l1!=NULL){
            zero->bottom=l1;
        }
        if(l2!=NULL){
            zero->bottom=l2;
        }
        return zerohd->bottom;
 }

Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL){
       return root;
   }
   Node* ans=merge(root,root->next);
   Node* curr=root->next->next;
   while(curr!=NULL){
       ans=merge(curr,ans);
       curr=curr->next;
   }
   return ans;
}
