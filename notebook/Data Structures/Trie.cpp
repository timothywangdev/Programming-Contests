class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *child[26];
    bool is_end;
    TrieNode() {
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        is_end=false;
    }
    void insert(string &word, int idx){
        if(idx<word.length()){
            if(!child[word[idx]-'a'])
                child[word[idx]-'a']=new TrieNode();
            child[word[idx]-'a']->insert(word,idx+1);
        }
        else{
            is_end=true;
        }
    }
    bool search(string &word, int idx, bool prefix){
        if(idx<word.length()){
               if(!child[word[idx]-'a'])return false;
               return child[word[idx]-'a']->search(word,idx+1,prefix);
        }
        else{
            return !prefix?is_end:true;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        root->insert(word,0);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return root->search(word,0,false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return root->search(prefix,0,true);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
