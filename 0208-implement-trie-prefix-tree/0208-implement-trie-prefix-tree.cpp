class TrieNode{
    public: 
        char nodeVal;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char nodeVal){
            this->nodeVal = nodeVal;
            for(int i = 0;i < 26;i++){
                this->children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie {
private:
    void insertHelper(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        TrieNode* child = NULL;
        
        if(root->children[index] == NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else{
            child = root->children[index];
        }

        insertHelper(child,word.substr(1));
    }

    bool searchHelper(TrieNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0]-'a';

        if(root->children[index] != NULL){
            TrieNode* child = root->children[index];
            return searchHelper(child,word.substr(1));
        }
        else{
            return false;
        }
    }

    bool startsWithHelper(TrieNode* root,string word){
        if(word.length() == 0){
            return true;
        }

        int index = word[0]-'a';

        if(root->children[index] != NULL){
            TrieNode* child = root->children[index];
            return startsWithHelper(child,word.substr(1));
        }
        else{
            return false;
        }
    }
public:
    TrieNode* root = NULL;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertHelper(root,word);
    }
    
    bool search(string word) {
        return searchHelper(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */