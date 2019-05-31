class Solution {
    
    vector<vector<string>> res;
    int N;
public:
    
    bool issafe(vector<int> &board,int row,int col)
    {
        int i, j;
        //check for row to the left  
        for(i = 0 ; i<col ;i++)
            if(board[i]==row)
                return false;
        
        //check for left up diagonal
        for(i=row,j=col; i>=0 && j>=0;i--,j--)
            if(board[j]==i)
                return false;
        for(i=row,j=col;i<N,j>=0;i++,j--)
            if(board[j]==i)
                return false;
        
        return true;
    }
    
    void nqueens(vector<int> &board, int col)
    {
        if(col==N)
        {
            //ready the solution and send
            vector<string> resrow;
            for(int i=0;i<N;i++)
            {
                string t(N,'.');
                t[board[i]] = 'Q';
                resrow.push_back(t);
            }
            res.push_back(resrow);
            
            return;
        }
        
        for(int i=0;i<N;i++)
        {
            if(issafe(board,i,col))
            {
                board[col] = i;
                nqueens(board,col+1);
                board[col] = numeric_limits<int>::min();
            }
        }
            
    }
    vector<vector<string>> solveNQueens(int n) {
        
        N = n;
        
        res.clear();
        if(!n)
            return {{}};
        
        if(n==1)
            return {{"Q"}};
        
        if(n<4)
            return res;
        
        vector<int> board(n,numeric_limits<int>::min());
        
        nqueens(board,0);
        
        return res;
        
        
    }
};

