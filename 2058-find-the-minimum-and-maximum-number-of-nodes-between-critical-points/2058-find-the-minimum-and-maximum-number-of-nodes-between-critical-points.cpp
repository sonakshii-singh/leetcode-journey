class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int first = -1;       // first critical point
        int prev = -1;        // previous critical point
        int minDist = INT_MAX;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != NULL) {

            // Check if curr is a critical point
            if ((curr->val > prevNode->val && curr->val > curr->next->val) ||
                (curr->val < prevNode->val && curr->val < curr->next->val)) {

                if (first == -1) {
                    // First critical point
                    first = index;
                } 
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - prev);
                }

                prev = index;
            }

            prevNode = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than two critical points
        if (first == -1 || prev == first) {
            return {-1, -1};
        }

        int maxDist = prev - first;

        return {minDist, maxDist};
    }
};