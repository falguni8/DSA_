class Solution {
public:
    string minWindow(string s, string t) {
        int minl = INT_MAX;
        unordered_map <int, int> mp;
        for(auto ch: t) mp[ch]++;
        
        int c = 0;
        
        int start = 0;
        int minstart = 0;
        
        for(int end = 0; end<s.length(); end++)
        {
            if(mp[s[end]]>0) c++;
            mp[s[end]]--; 
            if(c==t.length())
            {

                while(start<end && mp[s[start]]<0){
                    mp[s[start]]++;
                    start++;
                }
                
                if(end-start+1<minl)
                {
                    minl = end-start+1;
                    minstart = start;
                }
                
                mp[s[start]]++;
                start++;
                c--;
            }
        }
        
        if(minl==INT_MAX) return "";
        return s.substr(minstart, minl);
    }
};