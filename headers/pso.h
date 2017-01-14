#ifndef PSO_H_
#define PSO_H_

#include "fitness.h"
#include "particle.h"
#include <stddef.h>

template <typename T> class PSO {
    private:
        size_t N;
        std::vector< Particle<T> > particles;
        // TODO: add usage of FitnessFunction for error computation
        // FitnessFunction fitnessFunction;
    public:
        PSO(size_t N, const std::vector<T> &low_thresholds, const std::vector<T> &high_thresholds);
        void calcErrors();
        void update();
        std::vector<T> getPositionVector(unsigned int at);
        float getError(unsigned int at);
        void display();
};

#endif // PSO_H_
