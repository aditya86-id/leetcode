class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        int totalCandies = n;
        int i=1;

        while(i<n){
            if(rating[i]==rating[i-1]){
                i++;
                continue;
            }
            int currentpeak = 0;
            while(i<n&&rating[i]>rating[i-1]){
                currentpeak++;
                totalCandies += currentpeak;
                i++;
            }
            if (i == n) {
                return totalCandies;
            }
           int currentValley = 0;
            while (i < n && rating[i] < rating[i - 1]) {
                currentValley++;
                totalCandies += currentValley;
                i++;
            

        }
        totalCandies -= min(currentpeak,currentValley);
        }

        return totalCandies;
    }
};