
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;           // Make room for next bit
            result |= (n & 1);      // Add least significant bit of n
            n >>= 1;               // Move to next bit
        }
        
        return result;
    }
};