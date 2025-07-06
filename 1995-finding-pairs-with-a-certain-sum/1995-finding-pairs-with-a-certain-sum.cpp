class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    // Constructor
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1;
        nums2 = _nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    // Add val to nums2[index]
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;         // Remove old value
        if (freq2[oldVal] == 0) freq2.erase(oldVal);

        nums2[index] += val;
        freq2[nums2[index]]++;   // Add new value
    }

    // Count number of pairs that sum up to tot
    int count(int tot) {
        int result = 0;
        for (int num1 : nums1) {
            int complement = tot - num1;
            if (freq2.count(complement)) {
                result += freq2[complement];
            }
        }
        return result;
    }
};
