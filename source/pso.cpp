#include "../headers/pso.h"
#include <iostream>
#include <random>
#include <assert.h>

template <typename T>
//constructor initialising features based on uniform real distributed randomness
PSO<T>::PSO(size_t N, const std::vector<T> &low_thresholds, const std::vector<T> &high_thresholds): N(N) {
	assert(low_thresholds.size() == high_thresholds.size() && "low_thresholds and high_thresholds have to have the same sizes");
	std::default_random_engine generator;
	std::uniform_real_distribution<T> distribution(0.0, 1.0);
	std::vector<T> init_positions = std::vector<T>(low_thresholds.size());
	for (unsigned int i=0; i<init_positions.size(); ++i) {
		T h = high_thresholds.at(i);
		T l = low_thresholds.at(i);
		T r = distribution(generator);
		std::cout << "r: " << r << '\n';
		init_positions.at(i) = r * (h-l) + l;
	}

	// TODO: use different init_positions vector for each particle
    particles = std::vector< Particle<T> >(N, init_positions);
}

// TODO: add updateFitnessFunction allowing to change FitnessFunction
/*template <typename T>
void PSO<T>::updateFitnessFunction(FitnessFunction fitnessFunction) {
    this->fitnessFunction = fitnessFunction;
}*/

template <typename T>
// TODO: decide what's the target and what gives currently the best solution
void PSO<T>::calcErrors() {
;
}

template <typename T>
// TODO: what should be updated here? features based on the velocity vector?
void PSO<T>::update() {
;
}

template <typename T>
std::vector<T> PSO<T>::getPositionVector(unsigned int at) {
    return particles.at(at).getPositionVector();
}

template <typename T>
float PSO<T>::getError(unsigned int at) {
	// TODO: return real error
    return 0;
}

template <typename T>
void PSO<T>::display() {
	for (unsigned int i=0; i<particles.size(); ++i) {
		std::cout << "particle " << i << ": ";
		particles.at(i).display();
	}
}

template class PSO<float>;
