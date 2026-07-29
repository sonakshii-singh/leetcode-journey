class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        vector<long long> cnt(26,0);
        for (char c : s) cnt[c-'a']++;
        int h = n/2;
        char mid = 0;
        vector<long long> half(26,0);
        for (int i=0;i<26;i++){
            if (cnt[i]%2==1) mid = 'a'+i;
            half[i] = cnt[i]/2;
        }

        const long long CAP = 2000000LL;

        auto countArr = [&](vector<long long>& c)->long long{
            long long remaining=0, result=1;
            for (int i=0;i<26;i++){
                long long ci=c[i];
                if (!ci) continue;
                long long n2=remaining+ci, r=1;
                for (long long j=1;j<=ci;j++){
                    r = r*(n2-ci+j)/j;
                    if (r>CAP){ r=CAP+1; break; }
                }
                result *= r;
                if (result>CAP) return CAP+1;
                remaining += ci;
            }
            return result;
        };

        if (k > countArr(half)) return "";

        string res;
        vector<long long> rem = half;
        for (int pos=0; pos<h; pos++){
            for (int c=0;c<26;c++){
                if (!rem[c]) continue;
                rem[c]--;
                long long cnt2 = countArr(rem);
                if (k<=cnt2){ res.push_back('a'+c); break; }
                k -= cnt2;
                rem[c]++;
            }
        }
        string revHalf(res.rbegin(), res.rend());
        string result = res;
        if (mid) result.push_back(mid);
        result += revHalf;
        return result;
    }
};