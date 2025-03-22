#ifdef MYLIBRARY_EXPORTS
    #define MYLIBRARY_API __declspec(dllexport)
#else
    #define MYLIBRARY_API __declspec(dllimport)
#endif

#pragma once
#include <string>
#include <queue>
#include <map>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

namespace template_library {
    class MYLIBRARY_API EventScheduler {
        std::map<int, std::string> events;
        std::priority_queue<int, std::vector<int>, std::greater<>> time_queue;

    public:
        void add_event(int time, const std::string& event);
        std::string process_next();
    };
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif