class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i=0;
        int a,b;
        vector<int> res;
        for(i=0;i<n;i++){
            if(arr[i]>x)
                break;
        }
        if(i==0){
            i++;
        }
        if(i==n){
            res.push_back(arr[i-1]);
            a = i-2;
            b = i;
             k--;
        }
        else{
            a = i-1;
            b = i;     
        }
        while(k!=0){
            if(a<0){
                res.push_back(arr[b++]);
            }
            else if(b==n){
                res.push_back(arr[a--]);
            }
            else{
                if(abs(arr[a]-x)==abs(arr[b]-x)){
                    if(arr[a]<arr[b]){
                        res.push_back(arr[a--]);
                    }
                    else{
                        res.push_back(arr[b++]);
                    }
                }
                else{
                    if(abs(arr[a]-x)>abs(arr[b]-x)){
                        res.push_back(arr[b++]);
                    }
                    else{
                        res.push_back(arr[a--]);
                    }
                }
            }
            k--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
