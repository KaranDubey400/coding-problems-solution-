class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min =prices[0]; 
        int index =0; 
        for(auto i=1 ; i < prices.size(); i++){
            if(prices[i]<min){
                min = prices[i]; 
               
            } else if ( prices[i]-min > index) {
                index  = prices[i] - min ; 
            }
        }

            return index;  
        } 
};