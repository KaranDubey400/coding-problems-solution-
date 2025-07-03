class Solution {
public:
    char kthCharacter(int k) {
       
        int num = k - 1;
        
       
        int setBits = 0;
        while (num > 0) {
            num &= (num - 1); 
            setBits++;
        }
        
        
        return (char)('a' + setBits);
    }
};