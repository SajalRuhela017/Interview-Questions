// Given two binary strings a and b, return their sum as a binary string.
 
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
 
// Constraints:
// 1 <= a.length, b.length <= 10^4
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

//Solution
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){
            a = string(b.size()-a.size(),'0') + a;
        }else if(a.size()>b.size()){
            b = string(a.size()-b.size(),'0') + b; 
        }
        int carry =0;
        string result="";
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]=='1' and b[i]=='1'){
                if(carry==0){
                    result = '0'+ result;
                    carry =1;
                }else{
                    result = '1' + result;
                    carry = 1;
                }
            }else if(a[i]=='0' and b[i]=='0'){
                if(carry==1){
                    result = '1'+result;
                    carry=0;
                }else{
                    result = '0'+result;
                }
            }else if((a[i]=='0' and b[i]=='1') or (a[i]=='1' and b[i]=='0')){
                if(carry==1){
                    result = '0'+result;
                }else{
                    result = '1'+ result;
                }
            }
        }
        if(carry==1)    result = '1'+result;
        return result;
    }
};