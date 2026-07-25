class Solution {
public:
    int maxProduct(int n) {
        int largest = 0, secondLargest = 0;

        while (n > 0) {
            int d = n % 10;

            if (d >= largest) {
                secondLargest = largest;
                largest = d;
            } else if (d > secondLargest) {
                secondLargest = d;
            }

            n /= 10;
        }

        return largest * secondLargest;
    }
};
