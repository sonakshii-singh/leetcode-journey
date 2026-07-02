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
     ListNode* reverseAll(ListNode* temp){
             if(temp==NULL || temp->next==NULL) return temp;
               ListNode* newHead= reverseAll(temp->next);
               ListNode* front= temp->next;
               front->next=temp;
               temp->next=NULL;
               return newHead;
     }
       ListNode* KthNode(ListNode* temp, int k){
        k-=1;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
       }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast= NULL;
        while(temp){
            ListNode* kthNode=KthNode(temp,k);
            if(kthNode==NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseAll(temp);
            if(temp==head)
            head= kthNode;
            else{
                prevLast->next=kthNode;
            }
            temp->next=nextNode;
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};