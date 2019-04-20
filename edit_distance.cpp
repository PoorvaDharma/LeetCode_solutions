static int fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int r = word1.length();
        int c = word2.length();
        
        if(!r)
            return c;
        
        if(!c)
            return r;
        
        //int a[r+1][c+1];
        
        vector<vector<int>> a(r+1,vector<int>(c+1,0));
        
        a[0][0] = 0;
        
        for(int i=1;i<c+1;i++)
           a[0][i] = a[0][i-1] +1;
        
        for(int i=1;i<r+1;i++)
           a[i][0] = a[i-1][0] +1;
        
        for(int i = 1;i<r+1;i++)
        {
            for(int j=1;j<c+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    a[i][j]= a[i-1][j-1];
                }
                else
                {
                    int k = min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]));
                    a[i][j] = k+1;
                }
            }
        }
        
        return a[r][c];
    }
};
