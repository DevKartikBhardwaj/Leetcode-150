//brute force
class Solution {
public:
    unordered_map<char,int>mp,hash;
    bool isValidWindow(){
        for(auto elem:mp){
            char ch=elem.first;
            int freq=elem.second;
            if(hash.count(ch)==0||hash[ch]<freq)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        for(char ch:t)mp[ch]++;
        int a=0,b=0,minLen=INT_MAX,left=-1,right=-1;
        while(b<s.size()){
            char currentChar=s[b];
            if(mp.count(currentChar))hash[currentChar]++;
            while(isValidWindow()){
                
                char prevChar=s[a];
                if(hash.count(prevChar))hash[prevChar]--;
                if(minLen>b-a+1){
                    minLen=b-a+1;
                    left=a,right=b;
                }
                minLen=min(minLen,b-a+1);
                a++;

            }
            b++;
        }
        if(left==-1)return "";
        return s.substr(left,right-left+1);
    }
};
