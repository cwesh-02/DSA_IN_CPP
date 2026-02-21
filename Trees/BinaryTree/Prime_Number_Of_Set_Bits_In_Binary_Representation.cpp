class Solution {
public:

bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false; 
        
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int setcount(int n) {
        int count = 0;
        while (n > 0) {
            // Check the last bit
            if (n & 1) count++; 
            // Shift right by 1 to check the next bit
            n >>= 1; 
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) 
    {
        int count=0;
        for(int i = left ; i<=right;i++)
        {
            if(isPrime(setcount(i))) count++;
        }

        return count;
    }
};