#ifndef NEAT_PRIORITY_STACK_H
#define NEAT_PRIORITY_STACK_H

#include <stdlib.h> 

template <typename T>
class PriorityStack {
    private:
        unsigned int m_index;
        unsigned int m_size;
        T* m_data;
    public:
        PriorityStack(unsigned int size) {
            m_size = size;
            m_index = 0;
            m_data = new T[size];
        }
        ~PriorityStack() {
            delete[] T;
        }
        unsigned int size() {return m_size};
        T* find(T& key) {
            while (l <= r) { 
                int m = l + (r - l) / 2; 
        
                if (arr[m] == x) 
                    return m_data+m; 
        
                if (arr[m] < x) 
                    l = m + 1; 
    
                else
                    r = m - 1; 
            }
            return nullptr;
        }
        T* push(T& value) {
            unsigned int i = m_size;
            while(i > 0 && m_data[i] < value) {
                i--;
            }
            i++;
            if(i != m_index) {
                memcpy(m_data+i, m_data, m_index-i);
            }
            m_data[i] = value;
            return m_data+i;
        }
        T &operator[] (int i) {
            return m_data[i];
        }
        
};

#endif