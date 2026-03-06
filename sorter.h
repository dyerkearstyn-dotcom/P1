/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 *
 * For more details, see the commentary at the top of
 *   tests/header-sans-using-namespace.h
 * in this project repo.
 */

template <class T>
void sorter(std::vector<T> &items, std::size_t k) {  
	using namespace std;
	
	if(items.size()<=1){
		return;
	}


	size_t mod = items.size()%k;
	size_t siz = items.size()/k;

	size_t start=0;

	vector<vector<T>> matrix;

	for(size_t i=0;i<k ;i++){
		size_t current_size = siz +(i<mod ? 1:0);
		vector<T> subvec;
		for (size_t j=0;j<current_size;j++){
			subvec.push_back(items[start+j]);
		}

		sorter(subvec,k);
		matrix.push_back(subvec);
		start+= current_size;
	}
	vector<size_t> indices(k,0);

	items.clear();

	while(true){
		size_t min_index = k;
		T min_value;
		
		for(size_t i=0;i<k;i++){
			if(indices[i]<matrix[i].size()){
				if (min_index ==k || matrix[i][indices[i]]<min_value){
					min_index = i;
					min_value = matrix[i][indices[i]];
				}
			}
		}

		if (min_index == k){
			break;
		}

		items.push_back(min_value);
		indices[min_index]++;

	}
	
}
#endif
