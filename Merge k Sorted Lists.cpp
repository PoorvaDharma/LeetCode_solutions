static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp
{
    bool operator() (const ListNode *p,const ListNode *q)
    {
        return p->val>q->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *h = nullptr;
        ListNode *t = h;
        if(!lists.size())
            return h;
        
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;
        
        
        for( auto i: lists)
            if(i)
              pq.push(i);
        
        //cout<<pq.size();
        
        while(!pq.empty())
        {
            ListNode * temp = pq.top();
            //cout<<temp->val;
            if(!t)
            {
                t = temp;
                h = t;
            }
            else
            {
                t->next = temp;
                t = t->next;
            }
            pq.pop();
            
            if(temp->next)
                pq.push(temp->next);
        }
        
        return h;
        /*
        if(!lists.size())
            return NULL;
        
        ListNode *t,*h;
        map<int,int> map;
        
        for(auto v : lists)
        {
            t = v;
            while(t)
            {
                map[t->val]++;
                t = t->next;
            }
        }
        
        t = new ListNode(0);
        h = t;
        for(auto m : map)
        {
            int c = m.second;
            while(c)
            {
               t->next = new ListNode(m.first);
               t = t->next; 
               c--; 
            }
             
        }
        
        return h->next;
        */
    }
};
