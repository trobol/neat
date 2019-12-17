#ifndef NEAT_STACK_H
#define NEAT_STACK_H
#include <stdlib.h>  

namespace neat {
	template <typename T>
	class Stack {
		public:
			Stack(size_t size) {
				m_capacity = size;
				m_index = 0;
				m_data = malloc(size* sizeof(T));
			}
			void push(T value) {
				if(m_index >= m_capacity) 
					resize(m_capacity*2)
					
				m_data[m_index] = value;
				m_index++;
			}
			T pop() {
				m_index--;
				return m_data[m_index+1];
			}
			int size() {
				return m_index;
			}
			bool resize(int size) {
				T* newData = malloc(size* sizeof(T));
				if(newData == nullptr)
					throw "Unable to resize stack";
				memcpy(newData, m_data, m_index);
				free(m_data);
				m_data = newData;
				m_capacity = size;
			}
			bool trim() {
				resize(m_index);
			}
		private:
			size_t m_capacity = 0;
			size_t m_index = 0;
			T* m_data = 0;
	};
} // namespace neat

#endif