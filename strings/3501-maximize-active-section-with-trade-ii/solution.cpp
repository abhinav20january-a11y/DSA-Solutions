class Solution {
public:

    class SegmentTree {
    public:
        int n;
        vector<int> tree;

        SegmentTree(vector<int>& arr) {
            n = arr.size();
            tree.resize(4 * max(1, n));

            if (n > 0) {
                build(1, 0, n - 1, arr);
            }
        }

        void build(int node, int left, int right, vector<int>& arr) {

            if (left == right) {
                tree[node] = arr[left];
                return;
            }

            int mid = left + (right - left) / 2;

            build(2 * node, left, mid, arr);
            build(2 * node + 1, mid + 1, right, arr);

            tree[node] = max(tree[2 * node],
                             tree[2 * node + 1]);
        }

        int query(int node, int left, int right,
                  int ql, int qr) {

            // No overlap
            if (right < ql || left > qr) {
                return 0;
            }

            // Complete overlap
            if (ql <= left && right <= qr) {
                return tree[node];
            }

            int mid = left + (right - left) / 2;

            return max(
                query(2 * node, left, mid, ql, qr),
                query(2 * node + 1, mid + 1, right, ql, qr)
            );
        }

        int query(int left, int right) {

            if (n == 0 || left > right) {
                return 0;
            }

            return query(1, 0, n - 1, left, right);
        }
    };


    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {

        int n = s.size();

        // -----------------------------------------
        // 1. Count total number of original ones
        // -----------------------------------------

        int totalOnes = 0;

        for (char ch : s) {
            if (ch == '1') {
                totalOnes++;
            }
        }


        // -----------------------------------------
        // 2. Store all zero blocks
        //
        // zeroStart[i] = starting index
        // zeroEnd[i]   = ending index
        // -----------------------------------------

        vector<int> zeroStart;
        vector<int> zeroEnd;

        int i = 0;

        while (i < n) {

            if (s[i] == '1') {
                i++;
                continue;
            }

            int start = i;

            while (i < n && s[i] == '0') {
                i++;
            }

            int end = i - 1;

            zeroStart.push_back(start);
            zeroEnd.push_back(end);
        }


        int m = zeroStart.size();

        // No useful trade if fewer than 2 zero blocks
        if (m < 2) {
            return vector<int>(queries.size(), totalOnes);
        }


        // -----------------------------------------
        // 3. gain[i]
        //
        // Trade between:
        //
        // zero block i
        //      +
        // zero block i+1
        //
        // Example:
        //
        // 000 111 00
        //
        // gain = 3 + 2 = 5
        // -----------------------------------------

        vector<int> gain(m - 1);

        for (int j = 0; j + 1 < m; j++) {

            int leftLength =
                zeroEnd[j] - zeroStart[j] + 1;

            int rightLength =
                zeroEnd[j + 1] - zeroStart[j + 1] + 1;

            gain[j] = leftLength + rightLength;
        }


        SegmentTree seg(gain);

        vector<int> answer;


        // -----------------------------------------
        // 4. Process every query
        // -----------------------------------------

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            /*
                Find first zero block whose END >= l
            */

            int L = lower_bound(
                        zeroEnd.begin(),
                        zeroEnd.end(),
                        l
                    ) - zeroEnd.begin();


            /*
                Find last zero block whose START <= r
            */

            int R = upper_bound(
                        zeroStart.begin(),
                        zeroStart.end(),
                        r
                    ) - zeroStart.begin() - 1;


            // Need at least TWO zero blocks
            if (L >= m || R < 0 || L >= R) {
                answer.push_back(totalOnes);
                continue;
            }


            int bestGain = 0;


            // =================================================
            // CASE 1:
            // First pair can be clipped by LEFT boundary
            //
            // zero[L] + zero[L+1]
            // =================================================

            {

                int leftZeros =
                    zeroEnd[L] - max(l, zeroStart[L]) + 1;

                int rightZeros =
                    min(r, zeroEnd[L + 1])
                    - zeroStart[L + 1] + 1;

                if (leftZeros > 0 && rightZeros > 0) {

                    // Middle 1-block must also be inside query
                    int middleStart = zeroEnd[L] + 1;
                    int middleEnd = zeroStart[L + 1] - 1;

                    if (middleStart >= l &&
                        middleEnd <= r) {

                        bestGain = max(
                            bestGain,
                            leftZeros + rightZeros
                        );
                    }
                }
            }


            // =================================================
            // CASE 2:
            // Last pair can be clipped by RIGHT boundary
            //
            // zero[R-1] + zero[R]
            // =================================================

            {

                int leftZeros =
                    zeroEnd[R - 1]
                    - max(l, zeroStart[R - 1]) + 1;

                int rightZeros =
                    min(r, zeroEnd[R])
                    - zeroStart[R] + 1;

                if (leftZeros > 0 && rightZeros > 0) {

                    int middleStart =
                        zeroEnd[R - 1] + 1;

                    int middleEnd =
                        zeroStart[R] - 1;

                    if (middleStart >= l &&
                        middleEnd <= r) {

                        bestGain = max(
                            bestGain,
                            leftZeros + rightZeros
                        );
                    }
                }
            }


            // =================================================
            // CASE 3:
            // Completely contained zero-block pairs.
            //
            // Segment tree handles all pairs:
            //
            // L+1 ... R-2
            // =================================================

            int leftPair = L + 1;
            int rightPair = R - 2;

            if (leftPair <= rightPair) {

                bestGain = max(
                    bestGain,
                    seg.query(leftPair, rightPair)
                );
            }


            // Cannot exceed total string length
            int result = min(
                n,
                totalOnes + bestGain
            );

            answer.push_back(result);
        }

        return answer;
    }
};
