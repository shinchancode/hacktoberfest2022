//Unique Number of Occurrences(GFG)
//POTD Date:13/07/2023

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    { map<int,int>mp;
      set<int>st;
        for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
         for(auto x : mp)
        {
            if(st.find(x.second)!=st.end())
            {
                return false;
            }
            else
            {
                st.insert(x.second);
            }
        }
      return true;      
    }
};
