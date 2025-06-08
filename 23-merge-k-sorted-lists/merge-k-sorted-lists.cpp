/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;


        for(auto it : lists)
        {
            ListNode* root = it;
            while(root!= NULL)
            {
                pq.push(root);
                root = root->next;
            }
        }


        ListNode* dummy = new ListNode();

        ListNode* curr = dummy;

        while(!pq.empty())
        {
            ListNode* neww = pq.top();
            pq.pop();

            curr->next = new ListNode(neww->val);
            curr = curr->next;


        }

        return dummy->next;

        
    }
};