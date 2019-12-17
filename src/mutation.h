#ifndef NEAT_MUTATION_H
#define NEAT_MUTATION_H

class Mutation {
    enum Type {
        None,
        Node,
        Connection
    };
    public:
    Mutation() : 
    m_type(None), m_from(0), m_to(0)
    {}
    Mutation(Type type, unsigned int from, unsigned int to) : 
    m_type(type), m_from(from), m_to(to)
    {}
    const Type m_type;
    //if this is a connection, from and to are the nodes it connects
    //if this is a node, from and to is the connection it was added on
    const unsigned int m_from;
    const unsigned int m_to;
};

#endif