#ifndef NEAT_LINKED_LIST_H
#define NEAT_LINKED_LIST_H

template <typename T>
class LinkedList {
    private:
        struct Node {
            T value;
            Node* m_next;
        };
        Node* m_head, m_tail;
        unsigned int m_size;
    public:
        void push
};

#endif