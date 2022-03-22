#pragma once

#include <vector>


namespace ING {

	namespace Utils {

        template <typename T>
        std::vector<T> operator+(const std::vector<T>& A, const std::vector<T>& B)
        {
            std::vector<T> AB;
            AB.reserve(A.size() + B.size());               
            AB.insert(AB.end(), A.begin(), A.end());    
            AB.insert(AB.end(), B.begin(), B.end());    
            return AB;
        }

        template <typename T>
        std::vector<T>& operator+=(std::vector<T>& A, const std::vector<T>& B)
        {
            A.reserve(A.size() + B.size());            
            A.insert(A.end(), B.begin(), B.end());      
            return A;                                    
        }

	}

}