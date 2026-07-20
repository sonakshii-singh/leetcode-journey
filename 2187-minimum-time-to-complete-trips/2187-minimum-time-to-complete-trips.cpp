class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0;
        long long high =
            1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while (low <= high) {
            long long trip = 0;
            long long mid = low + (high - low) / 2;
            for (int i = 0; i < time.size(); i++) {
                trip += mid / time[i];

                if (trip >= totalTrips)
                    break;
            }
            if (trip >= totalTrips) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};