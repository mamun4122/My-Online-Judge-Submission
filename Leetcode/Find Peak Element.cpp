class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int low=0,high=nums.size()-1;
        int ans=-1;
        int sz=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid-1>=0&&mid+1<=sz)
            {
                if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
                if(nums[mid]<nums[mid-1])high=mid-1;
                else low=mid+1;
            }
            else if(mid-1<0)
            {
                if(mid+1>sz)return mid;
                if(nums[mid]>nums[mid+1])return mid;
                else low=mid+1;
            }
            else
            {
                if(mid-1<0)return mid;
                if(nums[mid]>nums[mid-1])return mid;
                else high=mid-1;
            }
        }

        return 0;
    }
};
