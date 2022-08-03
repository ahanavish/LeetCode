class MyCalendar {
    map<int, int> mp;   // <endTime, statIme>
public:  
    bool book(int start, int end) {
        /*lookfor first endTIme that is larger than start time request. First condition checkes if the incoming request should be added to the list of booked slots.*/
        auto itr = mp.upper_bound(start);
        if(itr == mp.end() || end<= itr->second) {
            mp[end]=start;
            return true;
        } 
        else  return false;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */