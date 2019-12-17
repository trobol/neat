#ifndef NEAT_VECTOR_H
#define NEAT_VECTOR_H


template <typename T>
class Vector {
    private:
        unsigned int m_size;
        T* m_data;
        unsigned int m_index;
        void swap(T* a, T* b) {
            int temp = *a; 
            *a = *b; 
            *b = temp; 
        }   
        //src https://www.geeksforgeeks.org/iterative-quick-sort/
        int partition(int l, int h) 
        { 
            T x = m_data[h]; 
            int i = (l - 1); 
        
            for (int j = l; j <= h - 1; j++) { 
                if (m_data[j] <= x) { 
                    i++;
                    swap(&m_data[i], &m_data[j]); 
                } 
            } 
            swap(&arr[i + 1], &arr[h]); 
            return (i + 1); 
        } 
        
        void quickSort(int l, int h) 
        { 
            if (l < h) { 
                int p = partition(l, h); 
                quickSort(l, p - 1); 
                quickSort(p + 1, h); 
            } 
        } 
        
    public:
        void size(unsigned int size) : m_size(size) {};
        unsigned int size() { return m_size; };
        T &operator[](int index) {
            return m_data[index];
        };
        unsigned int push(T value) {
            m_data[m_index] = value;
            return m_index++;
        }
        void sort() {
            quickSort(0, m_size-1);
        }
        //src https://www.geeksforgeeks.org/binary-search/
        int binary_search(T key) {
             while (l <= r) { 
                int m = l + (r - l) / 2; 
        
                // Check if x is present at mid 
                if (arr[m] == x) 
                    return m; 
        
                // If x greater, ignore left half 
                if (arr[m] < x) 
                    l = m + 1; 
        
                // If x is smaller, ignore right half 
                else
                    r = m - 1; 
            }
            return -1; 
        }
};

#endif