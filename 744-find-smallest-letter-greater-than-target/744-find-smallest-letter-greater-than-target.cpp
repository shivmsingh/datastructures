class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = -1;
        int low = 0;
        int high = letters.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(letters[mid] <= target){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans == -1 ? letters[0] : letters[ans];
    }
};