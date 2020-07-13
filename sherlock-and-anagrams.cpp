//https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

//anagrams hackrank link

int sherlockAndAnagrams(string s) {
    unordered_map<string,int> mp;
    vector<vector<string>> vv;
    vv.push_back(vector<string>{""});
    int ans=0;
    int len = s.length();

    for(int i=0;i<len;i++){
        vector<string> tmp = vv[i];
        for(auto &k:tmp){
            k += s[i];
            sort(k.begin(),k.end());
            if(mp.find(k)!=mp.end()){
                ans+=mp.at(k);
                ++mp.at(k);
            }else{
                mp.insert({k,1});
            }
        }
        tmp.push_back("");
        vv.push_back(tmp);
    }

    return ans;
}
