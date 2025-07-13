class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0; // player pointer
        int j = 0; // trainer pointer
        int count = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                // Match found
                count++;
                i++;
                j++;
            } else {
                // Try next trainer (current trainer too weak)
                j++;
            }
        }
        return count;
    }
};
