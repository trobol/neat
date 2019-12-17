#ifndef NEAT_GENOME_H
#define NEAT_GENOME_H

#include "gene.h"
#include "priority_stack.hpp"

#define MUTATION_CHANCE
#define PRETURB_CHANCE

class Genome {
    private:
        PriorityStack<Gene> m_genes;
        int m_fitness;
    public:
        Genome(unsigned int size) : m_genes(size) {
            m_fitness = 0;
        }
        static Genome Crossover(Genome* g0, Genome *g1) {
            //TODO take disjoint and execss genes from both when fitness is equal
            //g0 is the most fit
            if(g0->m_fitness < g1->m_fitness) {
                Genome* temp = g0;
                g0 = g1;
                g1 = temp;
            }
            unsigned int size = g0->size();
            int matching = 0;
            int maxInov = 0;
            Genome result(size);
            for(int i = 0; i < size; ++i) {
                Gene *gene0 = &g0->m_genes[i];
                Gene* gene1 = g1->find(*gene0);
                if(gene1 != nullptr) {
                    if(rand()%2 == 0) {
                        result.m_genes.push(*gene0);
                    } else {
                        result.m_genes.push(*gene1); 
                    }
                } else {
                    result.m_genes.push(*gene0);
                }
            }
        };
        Gene* find(Gene &gene) {
            return m_genes.find(gene);
        }
        unsigned int size() { return m_genes.size(); }
        unsigned int nodeCount() {
            unsigned int count = 0;
            for(int i = 0; i < m_genes.size(); ++i) {
                if(m_genes[i].m_from > count)
                    count = m_genes[i].m_from;
            }
            return count;
        }
        Gene& operator[] (int i) {
            return m_genes[i];
        }
};

#endif