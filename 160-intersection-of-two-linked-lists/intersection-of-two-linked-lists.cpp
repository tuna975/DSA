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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    
        int len1=0,len2=0;
        ListNode*n1=head1, *n2=head2;
        while(n1){
            len1++;
            n1=n1->next;
        }
        while(n2){
            len2++;
            n2=n2->next;
        }
        int diff=abs(len1-len2);
        n1=head1,n2=head2;
        if(len2>len1){
            for(int i=1;i<=diff;i++){
                n2=n2->next;
            }
            while(n1!=NULL && n2!=NULL){
                if(n2==n1)
                return n2;

                n2=n2->next;
                n1=n1->next;
            }
        }
        else{
            for(int i=1;i<=diff;i++){
                n1=n1->next;
            }

            while(n1!=NULL && n2!=NULL){
                if(n2==n1)
                return n2;

                n2=n2->next;
                n1=n1->next;
            }
        }
        return NULL;
    }
};