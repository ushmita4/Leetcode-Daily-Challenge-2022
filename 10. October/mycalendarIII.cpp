class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int og=0,t=0;
        for(pair<int,int>it:mp)
        {
            t=max(t,og+=it.second);
        }
        return t;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
