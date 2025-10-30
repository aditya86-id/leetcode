class Solution {
public:
    string getPermutation(int n, int k) {
     string ans = "";
     vector<int>nums;
     int rem = 1;



     for(int i=1;i<n;i++){
         rem*=i;
         nums.push_back(i);
     }

     nums.push_back(n);
     k--;


     while(true){
        ans+=to_string(nums[k/rem]);
        nums.erase(nums.begin()+k/rem);

        if(nums.size()==0){
            break;
        }

        k=k%rem;
        rem = rem/nums.size();
     }   

     return ans;
    }
};