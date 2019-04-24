class Solution {
public:
    //n solution with stack
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int area = 0 , maxa = 0;
        if(!n)
            return 0;
        
        stack<int> s;
        s.push(0);
        
        int i = 1;
        
        while(i<n)
        {
            if(s.empty() || heights[i]>=heights[s.top()])
            {
                s.push(i);
                //cout<<"push "<<i<<" ";
                i++;
            } 
            else
            {
                int indx = s.top();
                //cout<<"pop "<<indx<<" ";
                s.pop();
                area = heights[indx] * ((s.empty())?(i):(i-s.top()-1));
                //cout<<endl<<"area: "<<area<<endl;
                maxa = max(area,maxa);
            }
        }
    
        while(!s.empty())
        {
            int indx = s.top();
            //cout<<"pop "<<indx<<" ";
            s.pop();
            area = heights[indx] * ((s.empty())?(i):(i-s.top()-1));
            //cout<<endl<<"area: "<<area<<endl;
            maxa = max(area,maxa);
        }
    
        return maxa;
    
    /*
    int getMin(vector<int> &arr, int l,int r)
    {
        if(l==-1) return r;
        if(r==-1) return l;
        
        return (arr[l]<arr[r])? l: r;
    }
    int constructSt(vector<int> &arr, vector<int> &st,int l,int r,int pos)
    {
        //if(l>r)
          //return numeric_limits<int>::max();
        cout<<l<<r<<endl;
        if(l==r)
        {
            st[pos] = l;
            //cout<<"st:"<<l<<endl;
            return st[pos];
        }
        
        int mid = l + (r-l)/2;
        int lft =  constructSt(arr,st,l,mid,2*pos+1);
        int rght = constructSt(arr,st,mid+1,r,2*pos+2);
        
        st[pos] = getMin(arr,lft,rght);
        
        return st[pos];
                
    }
    
    vector<int> constructSgmnt(vector<int>& arr)
    {
        
        int n = arr.size();
        
        int x = (int)(ceil(log2(n)));
        int s = 2*(int)pow(2,x) - 1;
        
        vector<int> st(s,0);
        
        constructSt(arr,st,0,n-1,0);
        return st;
    }
    
    int RMQ(vector<int>& arr, vector<int>& st, int ns, int ne, int qs,int qe, int pos)
    {
        //cout<<ne<<ns<<endl;
        
        if(ne<qs || qe<ns)
            return -1;
        else if(qs<=ns && ne<=qe)
            return st[pos];
        
        int mid = ns + (ne-ns)/2;
        int lft =  RMQ(arr,st,ns,mid,qs,qe,2*pos+1);
        int rght = RMQ(arr,st,mid+1,ne,qs,qe,2*pos+2);
        
        return getMin(arr,lft,rght);    
    }
    
    int rectArea(vector<int>& arr, vector<int>& st, int l, int r)
    {
        if(l>r)
            return INT_MIN;
        
        if(l==r)
            return arr[l];
        
        int size = arr.size();
        int minIndex = RMQ(arr,st,0,size-1,l ,r , 0);
        
        int lft = rectArea(arr,st,l,minIndex-1);
        int rght = rectArea(arr,st,minIndex+1,r);
        int curr = arr[minIndex] * (r-l+1);
        
        return max(max(lft,rght),curr);
        
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int size = heights.size();
        
        if(!size)
            return 0;
        
        vector<int> st = constructSgmnt(heights);
        
        return rectArea(heights,st,0,size-1);
        */
        
        /* n2 solution statr with each bar as starting point keep a track of maximum area
        if(!heights.size())
            return 0;
        
        int max = -1;
        int counter;
        int min_tillnow;
        
        for(int i = 0;i<heights.size();i++)
        {
            counter = 0;
            min_tillnow = heights[i];
            
            for(int j = i;j<heights.size();j++)
            {
               counter++;
                
               if(min_tillnow>heights[j])
                   min_tillnow = heights[j];
                
               if(max< counter*min_tillnow)
                   max = counter*min_tillnow;
                
            }   
        }
        
        return max;*/
    }
};
