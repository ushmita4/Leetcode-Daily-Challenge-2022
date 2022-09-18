class Solution {
public:
    int trap(vector<int>& arr) {
        int peak = 0;
    int ans = 0;
  int n=arr.size();

    if (n == 0) {
        return 0L;
    }

    int peakVal = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] >= peakVal) {
            peak = i;
            peakVal = arr[i];
        }
    }

    int maxSoFar = LONG_MIN;
    int countSubmerged = 0L;
    int submergedArea = 0L;

    for (int i = 0; i <= peak; i++) {
        if (arr[i] >= maxSoFar) {

            
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }
    maxSoFar = LONG_MIN;
    countSubmerged = 0L;
    submergedArea = 0L;

    for (int i = n - 1; i >= peak; i--) {
        if (arr[i] >= maxSoFar) {

            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    return ans;
    }
};
