#include "library.hpp"

namespace template_library {
    int longest_duplicate_subarray(const std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int low = 1;
        int high = nums.size() - 1;
        int max_length = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            std::unordered_set<std::string> seen_subarrays;
            bool duplicate_found = false;

            for (int i = 0; i <= static_cast<int>(nums.size()) - mid; ++i) {
                std::string subarray_str;
                for (int j = i; j < i + mid; ++j) {
                    subarray_str += std::to_string(nums[j]) + ",";
                }

                if (seen_subarrays.find(subarray_str) != seen_subarrays.end()) {
                    duplicate_found = true;
                    break;
                }
                seen_subarrays.insert(subarray_str);
            }

            if (duplicate_found) {
                max_length = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return max_length;
    }
}