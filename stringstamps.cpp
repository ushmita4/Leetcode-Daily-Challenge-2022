/*
    Time Complexity : O(N * M) 
    Space Complexity: O(N * M)

    Where 'N', 'M' is the size of the 'TARGET' and the size of the 'STAMP', respectively.
*/

#include <unordered_set>
#include <stack>

vector<int> stringStamps(int n, int m, string &target, string &stamp){    
    // Declaring the unordered set.    
    unordered_set<int> unmatched[n];
    int done[n] = {0};

    // Declaring the stack.
    stack<int> s;

    // Vector to store the answer.
    vector<int> ans;
    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < m; j++){
            if(target[i + j] != stamp[j]){
                unmatched[i].insert(i + j);
            }
        }

        if(unmatched[i].size() == 0){
            ans.push_back(i);
            for(int j = i; j < i + m; j++){
                if(done[j] == 0){
                    done[j] = 1;
                    s.push(j);
                }
            }
        }
    }

    // Iterate till stack is not empty.
    while(s.size() != 0){
        int idx = s.top();
        s.pop();

        // Remove this position from all unmatched arrays.
        for(int i = max(0, idx - m + 1); i < idx + 1; i++){
            if(unmatched[i].size() == 0){
                continue;
            }
            if(unmatched[i].find(idx) != unmatched[i].end()){
                unmatched[i].erase(idx);
            }

            if(unmatched[i].size() == 0){
                ans.push_back(i);

                for(int j = i; j < min(i + m, n); j++){
                    // Process each position only once.
                    if(done[j] == 0){
                        done[j] = 1;
                        s.push(j);
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(done[i] == 0){
            ans.clear();
            ans.push_back(-1);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
