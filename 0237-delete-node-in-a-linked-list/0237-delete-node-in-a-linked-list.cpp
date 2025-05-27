class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        // Make current node point to next of next node.
        node->next = node->next->next;
    }
};