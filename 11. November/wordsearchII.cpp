class Trie {
public:
bool last = false ; 
 array<Trie *, 26 > Next  = {} ;
    Trie() {}
    
    void insert(string word) {
        auto curr = this ;
        for ( auto c : word ) {
            c -= 'a';
            if( curr->Next[c] == nullptr ) curr->Next[c] = new Trie() ;
            curr = curr->Next[c] ;
        }
        curr->last = true ; 
    }

};

class Solution {
private : 
    int m , n ;
    vector<string> ans ;
    vector<pair<int,int>>dir = {{0,1} , {1,0} , {-1, 0} , {0, -1}} ;
public:

    void dfs( vector<vector<char>>& board ,  int i , int j , Trie *curr , string &word_to_add){
        word_to_add.push_back(board[i][j]) ;
        char temp = board[i][j] ;
        
        if(curr->last) {
            ans.push_back(word_to_add) ;
            curr->last = false ;
        }

        board[i][j] = '*';

        for ( auto &[x,y] : dir){
            int nx = x + i , ny = y + j ;
            if ( nx < 0 or ny < 0 or nx >= m or ny >= n or board[nx][ny] == '*') continue ;
            char c = board[nx][ny] - 'a' ;
            if( curr->Next[c]) dfs( board , nx , ny , curr->Next[c] , word_to_add );
        }

        board[i][j] = temp ;
        word_to_add.pop_back() ;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size()  , n = board[0].size() ;
        Trie * Try = new Trie() ;

        for ( auto &word: words) { 
            Try->insert(word) ; 
        }
        
        for(int i = 0 ; i < m ; i ++ ){
            for (int j = 0 ; j < n ; j++){
                string word ;
                int c = board[i][j] - 'a' ;
                if( Try->Next[c] ) dfs( board , i , j , Try->Next[c] , word ) ;
            }
        }

        return ans ;    
    }
};
