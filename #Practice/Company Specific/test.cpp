#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int getAnagramPeriod(std::string input_str) {
        int n = input_str.length();
        
        // Helper function to check if a substring is a valid period
        auto is_valid_period = [&](int period) 
        {
            if (n % period != 0) {
                return false;
            }
            
            // Count characters in the first segment
            std::unordered_map<char, int> segment_count;
            for (int i = 0; i < period; ++i) {
                segment_count[input_str[i]]++;
            }
            
            // Check if all segments have the same character count
            for (int i = period; i < n; i += period) {
                std::unordered_map<char, int> curr_count;
                for (int j = i; j < i + period; ++j) {
                    curr_count[input_str[j]]++;
                }
                if (curr_count != segment_count) {
                    return false;
                }
            }
            
            return true;
        };
        
        // Find all factors of the string length
        std::vector<int> factors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i != n / i) {
                    factors.push_back(n / i);
                }
            }
        }
        
        // Sort factors in ascending order
        std::sort(factors.begin(), factors.end());
        
        // Check factors in ascending order
        for (int factor : factors) {
            if (is_valid_period(factor)) {
                return factor;
            }
        }
        
        // If no valid period found, return the length of the string
        return n;
    }
};