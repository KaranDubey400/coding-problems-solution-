class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int totalDrunk = numBottles;
        
        int emptyBottles = numBottles;
       
        while (emptyBottles >= numExchange) {
            
          
            int newFull = emptyBottles / numExchange;
            
            
            int remainingEmpty = emptyBottles % numExchange;
      
            totalDrunk += newFull;
            
            emptyBottles = newFull + remainingEmpty;
        }
        
        return totalDrunk;
    }
};