class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int totalw=n*n;
        int mw=maxWeight/w;
        return min(totalw,mw);
    }
};