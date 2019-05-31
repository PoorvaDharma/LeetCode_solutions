class Solution {
    
    int res;
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
            res++;            
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
    
    int totalNQueens(int n) {
        
        N = n;
        res = 0;
             
        if(n==1 || n==0)
            return 1;
        
        if(n<4)
            return 0;
        
        vector<int> board(n,numeric_limits<int>::min());
        
        nqueens(board,0);
        
        return res;
        
        
    }
};
