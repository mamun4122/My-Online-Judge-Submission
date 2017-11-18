class Solution {
public:
    #define ff first
    #define ss second
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        for(int i = 0; i < nums.size();i++)mp[nums[i]]++;
        for(auto &it: mp)v.push_back({it.ff, it.ss});
        sort(v.begin(),v.end());
        int len = v.size();
        vector<vector<int> > ans;
        for(int i = 0; i < len; i++)
        {
            int frst = v[i].ff;
            int koita = v[i].ss;
            if(koita > 1)
            {
                int val = frst + frst;
                cout << val << " " << frst << " " << koita << endl;
                if(-val != frst && mp[-val])ans.push_back({frst,frst,-val});
                else if(-val == frst && koita > 2)ans.push_back({frst,frst,-val});
            }
            for(int j = i+1; j < len; j++)
            {
                int val = -(frst + v[j].ff);
                if(val > v[j].ff && mp[val])ans.push_back({frst,v[j].ff,val});
            }
        }
        return ans;
    }
};
