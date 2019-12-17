#ifndef NEAT_NETWORK_H
#define NEAT_NETWORK_H

#include "genome.h"


class Network {
    public:
        struct Node {

        };
        struct Connection {
            
        };
        std::vector m_nodes;
        std::vector m_connections
        Network(Genome genome) {
            unsigned int nodeCount = genome.nodeCount()+1;

            int nodeInputs[nodeCount];
            int nodeOutputs[nodeCount];
            
            for(int i = 0; i < genome.size(); ++i) {
                ++nodeInputs[genome[i].m_to];
                ++nodeOutputs[genome[i].m_from];
            }

            m_nodes.resize(nodeCount);

            for(int i = 0; i < nodeCount; ++i) {
                m_nodes.push();
            }

        }
    private:
        
};

#endif