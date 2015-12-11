class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string rv=to_string(strs.size());
        for(int i=0;i<strs.size();i++){
            rv=rv+" "+to_string(strs[i].length());
        }
        rv=rv+" ";
        for(int i=0;i<strs.size();i++){
            rv=rv+strs[i];
        }
        return rv;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> rv;
        istringstream iss(s);
        vector<int> len;
        int n,l;
        iss>>n;
        for(int i=0;i<n;i++){
            iss>>l;
            len.push_back(l);
        }
        // get the remainder of s
        getline(iss,s);
        // skip the last whitespace
        int last=1;
        for(int i=0;i<n;i++){
            if(len[i]==0){
                rv.push_back("");
            }
            else{
                rv.push_back(s.substr(last,len[i]));
            }
            last=last+len[i];
        }
        return rv;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
