/**
* a6.cpp
* Name: Supratik Neupane
* Person number: 50160008
*
*
*/

#ifndef A6_STRINGSTORE_HPP
#define A6_STRINGSTORE_HPP

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
class StringStore {
	// an unordered_map to store the pairs of string and frequency
private: std::unordered_map<std::string, size_t> store;
		 //a comparator to help sort the strings in non-decreasing order of frequency
		 class FrequencyComparator {
		 public:
			 bool operator()(const std::pair<std::string, size_t>& lhs, const std::pair<std::string, size_t>& rhs) {
				 return lhs.second<rhs.second;
			 }
		 };

public:
	void insert(const std::string& str);
	size_t getFrequency(const std::string& str) const;
	bool removeString(const std::string& str);
	std::pair<std::string, size_t> getMaxFrequency() const;
	std::vector<std::pair<std::string, size_t>> getTopKFrequency(size_t k) const;


};

#endif //A6_STRINGSTORE_HPP
