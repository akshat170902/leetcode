class WordDictionary {
public:
    class Trie{
        public:
        bool end;
        Trie *v[26];
        Trie(){
            end = false;
            for(int i = 0; i < 26; i++){
                v[i] = NULL;
            }
        }
    };
    Trie *node = new Trie();
    WordDictionary() {
    }
    
    void addWord(string word) {
        Trie *p = node;
        for(auto &i: word){
            if(p->v[i-'a']==NULL){
                p->v[i-'a'] = new Trie();
            }
            p = p->v[i-'a'];
        }
        p->end = true;
    }
    bool solve(Trie *node,string &str,int i){
        if(i==str.length()){
            return node->end;
        }
        bool ans = false;
        if(str[i]=='.'){
            for(int j = 0; j < 26; j++){
                if(node->v[j])
                ans |= solve(node->v[j],str,i+1);
                if(ans)return true;
            }
        }else{
            if(node->v[str[i]-'a'])
            ans = solve(node->v[str[i]-'a'],str,i+1);
        }
        return ans;
    }
    bool search(string word) {
        return solve(node,word,0);
    }
};