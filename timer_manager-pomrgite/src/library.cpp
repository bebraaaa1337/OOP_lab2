#include "library.hpp"
namespace template_library {

    void EventScheduler::add_event(int time, const std::string& event) {
        events[time]=event;
        time_queue.push(time);
    }

    std::string EventScheduler::process_next() {
        while (!time_queue.empty()){
            int time =time_queue.top();
            time_queue.pop();
            if (events.find(time)!=events.end()){
                return events[time];
            }
        }
        return "";
    }
}