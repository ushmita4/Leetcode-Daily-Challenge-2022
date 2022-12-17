class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> stn;
        for (const auto& s : tokens) {
            if(s.size()>1 || isdigit(s.front())) {
                stn.push(stoi(s));
                continue;
            }
            long x2=stn.top(); stn.pop();
            long x1=stn.top(); stn.pop();
            switch(s.back()) {
                case '+': x1+=x2; break;
                case '-': x1-=x2; break;
                case '*': x1*=x2; break;
                case '/': x1/=x2; break;
            }
            stn.push(x1);
        }
        return stn.top();
    }
};
