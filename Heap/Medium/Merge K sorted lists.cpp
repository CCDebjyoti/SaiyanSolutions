class Solution {
public:// let n=list[i].size() avg and k=list.size()
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int,ListNode*> li;
        priority_queue<li,vector<li>,greater<li>>pq;//imp prioty queue cant sort ll so use int 
        for(auto it:lists){ //push first node (head) of LL on pq // as only using heads so pq size is k push opr is logk
            if(it)pq.push({it->val,it});
        }
        ListNode*d=new ListNode(0);
        ListNode*dhd=d;
         while(!pq.empty()){
            d->next=pq.top().second;//we remove the top node join chain our ll and push the next node of head onto ll
            if(pq.top().second->next)pq.push({pq.top().second->next->val,pq.top().second->next});
             d=pq.top().second;//so we at max only use k size of the pq 
             pq.pop();
        }
        return dhd->next;
    }
};
