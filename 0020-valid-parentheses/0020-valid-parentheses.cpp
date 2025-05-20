#include <stack>   
#include <map>  
#include <string>  


using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sp;      

      
        map<char, char> buket = {
           {')', '('}, 
           {'}', '{'}, 
           {']', '['}  
        };

        for (char c : s) {
        
            if (c == '{' || c == '[' || c == '(') {
                sp.push(c);
            }
          
            else if (c == ')' || c == '}' || c == ']') {
             
                if (sp.empty()) {
                    return false;
                }

                char kar = sp.top(); 
                sp.pop();            

               
                if (buket[c] != kar) {
                    return false;
                }
            }
        }

        // FIX 5: This line must be inside the isValid function, after the loop,
        // and outside any other conditional blocks.
        // After iterating through all characters, if the stack is empty,
        // all opening brackets have found their matching closing brackets.
        // Otherwise, some opening brackets were left unclosed.
        return sp.empty();
    }
};