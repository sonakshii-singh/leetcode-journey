class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int m=n;
         int digiSum=0;
            int digiPro=1;
        while(n>0){
            int rem=n%10;
           
            digiSum+=rem;
            digiPro*=rem;
            n/=10;
        }
        sum=digiSum+digiPro;
         return m%sum==0;
    }
};