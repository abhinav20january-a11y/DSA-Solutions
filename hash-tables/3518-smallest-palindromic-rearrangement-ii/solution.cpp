class Solution {
public:
    static const int LIM = 1000001;

    int C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIM) return LIM;
        }
        return (int)ans;
    }

    int countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ans = 1;

        for (int x : cnt) {
            if (x == 0) continue;
            ans *= C(rem, x);
            if (ans >= LIM) return LIM;
            rem -= x;
        }

        return (int)ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2)
                mid.push_back(char(i + 'a'));
            cnt[i] /= 2;
        }

        if (countWays(cnt) < k)
            return "";

        string left = "";

        int len = 0;
        for (int x : cnt) len += x;

        while (len--) {
            for (int c = 0; c < 26; c++) {
                if (cnt[c] == 0) continue;

                cnt[c]--;

                int ways = countWays(cnt);

                if (ways >= k) {
                    left.push_back(char(c + 'a'));
                    break;
                }

                k -= ways;
                cnt[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
