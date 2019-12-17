#ifndef NEAT_FAMILY_H
#define NEAT_FAMILY_H

class Family {
    private:
    const char *m_name;
    const unsigned int m_inputs;
    const unsigned int m_outputs;

    public:
    Family(const char* name, unsigned int inputs, unsigned int outputs) :
    m_name(name), m_inputs(inputs), m_outputs(outputs) {}
    static Family Load(const char* path){

    }
    void Save(const char* path) {

    }
};

#endif