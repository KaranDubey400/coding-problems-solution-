
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case: if the list is empty or has only one node, no duplicates possible
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head; // Start from the head of the list

        // Traverse the list
        while (current != nullptr && current->next != nullptr) {
            // If the current node's value is equal to the next node's value (duplicate found)
            if (current->val == current->next->val) {
                ListNode* duplicateNode = current->next; // Store the duplicate node to be deleted
                current->next = current->next->next;    // Bypass the duplicate node
                delete duplicateNode;                     // Free the memory of the duplicate node
            } else {
              
                current = current->next;
            }
        }
        
        return head; // Return the head of the modified list
    }
};