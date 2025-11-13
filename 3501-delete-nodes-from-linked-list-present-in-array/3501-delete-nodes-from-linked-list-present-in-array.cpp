class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> karn(nums.begin(), nums.end());

        while (head && karn.count(head->val))
            head = head->next;

        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->next && karn.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};