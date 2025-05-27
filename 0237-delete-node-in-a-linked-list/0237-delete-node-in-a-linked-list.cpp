
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value from the next node
        node->val = node->next->val;
        // Save the next node to delete it later
        ListNode* temp = node->next;
        // Skip the next node
        node->next = node->next->next;
        // Delete the next node to free memory
        delete temp;
    }
};