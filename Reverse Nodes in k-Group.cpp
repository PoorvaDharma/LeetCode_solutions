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
    
    int size(ListNode *h)
    {
        int l = 0;
        while(h)
        {
            h = h->next;
            l++;
        }
        
        return l;
    }
    
    ListNode *reverseSub(ListNode *t,int k, ListNode *&p)
    {
        ListNode *h = t;
        ListNode *c=t;
        p=t;
       // cout << k;
        
        while(k)
        {
           //cout<<"poorva";
            c = p->next;
            p->next = c->next;
            c->next = h;
            h = c;
            k--;
        }
        
        return h;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head)
            return NULL;
        
        int n = size(head);
        int loop = n/k;
        
        if(!loop)
            return head;
        
        ListNode *prev = nullptr;
        
        head = reverseSub(head,k-1,prev);
        ListNode *temp;
        
        for(int i = 1;i<loop;i++)
        {
           // cout<<i<<" "<<loop<<endl;
            temp = prev;
            temp->next = reverseSub(temp->next,k-1,prev);
        }
        
        return head;
    }
};
