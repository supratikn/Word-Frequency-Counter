
* a6.cpp
* Name: Supratik Neupane
* Person number : 50160008
*
* 
* /

#include "a6.hpp"
#include<deque>
#include <queue>

void StringStore::insert(const std::string& str) {//O(l*log(n))
												  //get a pointer to a possible location of the string in the store
	auto it = store.find(str);

	if (it != store.end()) {

		it->second += 1;

		// insert a new string into the store with frequency 1 somewhere in the middle of the store

	}
	// insert a new string into the store with frequency 1 at the end of the store
	else {
		store.insert(std::make_pair(str, 1));
	}

}

size_t StringStore::getFrequency(const std::string& str) const {//O(l*log(n))
	auto it = store.find(str);
	//check if the string is in the store

	//if it is found, return its frequency else return 0
	return it != store.end() ? it->second : 0;
}

bool StringStore::removeString(const std::string& str) {//O(l*log(n))
	auto it = store.find(str);
	//check if the string is in the store
	if (it != store.end()) {
		//if it is found, then remove it and return true
		store.erase(it);
		return true;
	}
	//else return false if it was not found
	return false;
}

std::pair<std::string, size_t> StringStore::getMaxFrequency() const {//O(n)
																	 //if there are no strings in the store then return a pair of empty string and 0
	if (store.empty()) return std::make_pair("", 0);
	//an iterator to the first pair in the map
	auto it = store.begin();
	//initially the max frequency is the first element
	auto max = it;
	//move to the second pair
	it++;
	//loop from the second pair if it exists
	for (; it != store.end(); ++it) {
		//if the current pair has the greater frequency, change name and frequency
		max = it->second>max->second ? it : max;
	}
	//return the max pair of string and its frequency
	return *max;
}

std::vector<std::pair<std::string, size_t>> StringStore::getTopKFrequency(size_t k) const {//O(nlog(n) +klog(n))
																						   // O(n+klog(n))

	std::vector<std::pair<std::string, size_t>> retVal;
	//check if store is empty or not, if it is then return an empty vector
	if (!store.empty()) {
		/*  //a priority queue that has the string with the highest frequency at the top
		std::priority_queue<std::pair<std::string,size_t>,
		std::deque<std::pair<std::string,size_t>>, FrequencyComparator> tempMap(store.begin(),store.end());

		//push the top k elements of the heap into a vector
		for(unsigned int i=0; (i<k) && !(tempMap.empty());i++){
		retVal.push_back(tempMap.top());
		tempMap.pop();
		}*/

		//this approach might be slightly faster
		//a vector with all the elements in the store
		std::vector<std::pair<std::string, size_t>> tempMap(store.begin(), store.end());

		//a FrequencyComparator object
		FrequencyComparator comp;

		//make heap on the vector
		std::make_heap(tempMap.begin(), tempMap.end(), comp);
		//iterate while i<k and tempMap is not empty
		for (unsigned int i = 0; (i<k) && !(tempMap.empty()); ++i) {
			retVal.push_back(*(tempMap.begin()));
			//move the top element to the end
			std::pop_heap(tempMap.begin(), tempMap.end(), comp);
			//remove the element with the highest frequency
			tempMap.pop_back();
		}

	}
	return retVal;
}
