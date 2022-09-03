class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        queue<pair<int,int>> q;
				for(int i=1;i<=9;i++){   
            q.push({i,1});
            while(!q.empty()){
                pair<int, int> curr=q.front();
                q.pop();
                int num=curr.first;
                int length=curr.second;
                if(length==n){
                    result.push_back(num);
                    continue;
                }
                int last_digit=num%10;
                if(k==0)
                    q.push({num*10+last_digit, length+1});
                else{
                    if(last_digit+k<10)
                        q.push({num*10+last_digit+k, length+1});
                    if(last_digit-k>=0)
                        q.push({num*10+last_digit-k, length+1});
                }
            }
        }
        return result;
    }
};
