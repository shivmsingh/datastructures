/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakIndex( MountainArray &mountainArr){
        int low = 0;
        int high = mountainArr.length() - 1;
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        return low;
    }
    
    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool ascend){
         while(low <= high){
            int mid = low + (high - low)/2;
            int element = mountainArr.get(mid);
            if(element == target){
                return mid;
            }else if(element < target){
                if(ascend) low = mid + 1;
                else high = mid - 1;
            }else{
               if(ascend) high = mid - 1;
                else low = mid + 1;
            }
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int index = findPeakIndex(mountainArr);
        int ans = binarySearch(0,index,target,mountainArr,true);
        if(ans != -1) return ans;
        ans = binarySearch(index+1,mountainArr.length() - 1,target,mountainArr,false);
        if(ans != -1) return ans;
        return -1;
    }
};