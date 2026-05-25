/*
Pattern: Final State Thinking
Subpattern: Misplaced Count / 2

Trigger:
- minimum swaps
- alternating string

Observation:
1 swap = 2 mismatches fix

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int cntswap(char start , string& s){
        char expected = start;
        int misMatch = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != expected)misMatch++;

            expected = (expected == '0') ? '1' : '0';
        }

        return misMatch/2;   
    }
    int minSwaps(string s) {
        int n = s.size();

        int cnt1 = 0;
        int cnt0 = 0;

        for(char &ch :s){
            if(ch == '0')cnt0++;
            else cnt1++;
        }

        //impossible case
        if(abs(cnt0 - cnt1) > 1) return -1;
        
        char start;
        int minS = 0;
        //case1; if 0 jyada to 0 se start hoga
        if(cnt0 > cnt1){
            start = '0';
            minS = cntswap(start , s);
        }else if(cnt1 > cnt0){
        //case2; if 1 jyada to 1 se start hoga
            start = '1';
            minS = cntswap(start , s);
        }
        else{
            minS = min(cntswap('0',s) , cntswap('1' , s));
        }

       return minS;
    }
};
