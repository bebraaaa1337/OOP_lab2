#include "library.hpp"

namespace template_library {
    int josephus_problem(const std::vector<int>& nums, int k) {
        if (nums.empty()) return -1; 

        std::deque<int> dq(nums.begin(), nums.end());

        while (dq.size() > 1) {
            for (int i = 1; i < k; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }

        return dq.front();
    }
}