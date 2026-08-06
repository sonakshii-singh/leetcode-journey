class Solution {
public:
    int digitProduct(int x) {
        int p = 1;
        while (x > 0) {
            p *= (x % 10);
            x /= 10;
        }
        return p;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (digitProduct(n) % t == 0)
                return n;
            n++;
        }
    }
};