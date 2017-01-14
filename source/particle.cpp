#include "../headers/particle.h"
#include <assert.h>
#include <iostream>

/*template <typename T>
Particle<T>::Particle(FitnessFunction fitnessFunction, T position, T velocity) {
    this->position = 0;
    this->velocity = 0;
    this->pbest = this->best = this->position;
    this->fitnessFunction = fitnessFunction;
}*/
template <typename T>
Particle<T>::Particle(const std::vector<T> &position, const std::vector<T> &velocity) {
    this->position = std::vector<T>(position);
//.reserve(position.size());
    this->pbest = std::vector<T>(position);
//.reserve(position.size());
    this->best = std::vector<T>(position);
//.reserve(position.size());
    this->velocity = std::vector<T>(velocity);
//.reserve(velocity.reserve.size());
/*    std::copy(position.begin(), position.end(), std::back_inserter(this->position));
    std::copy(position.begin(), position.end(), std::back_inserter(this->pbest));
    std::copy(position.begin(), position.end(), std::back_inserter(this-best));
    std::copy(velocity.begin(), position.end(), std::back_inserter(this->velocity));*/
//    this->position = std::vector<T>(0);
//    this->velocity = std::vector<T>(0);
//    this->pbest = this->best = this->position;
}
template <typename T>
const std::vector<T> &Particle<T>::getPositionVector() const { return this->position; }
template <typename T>
const std::vector<T> &Particle<T>::getVelocityVector() const { return this->velocity; }
template <typename T>
const std::vector<T> &Particle<T>::getBestVector() const { return this->best; }
template <typename T>
float Particle<T>::getError() { return this->error; }
template <typename T>
const std::vector<T> &Particle<T>::getPBestVector() const { return this->best; }
/*template <typename T>
float Particle<T>::calcError() {
    return this->fitnessFunction(5);
}*/
/*template <typename T>
void Particle<T>::updateFitnessFunction(FitnessFunction fitnessFunction) {
    this->fitnessFunction = fitnessFunction;
}*/
template <typename T>
void Particle<T>::setVelocityVector(const std::vector<T> &velocity) {
//    this->velocity.reserve(velocity.size());
    assert(velocity.size() == this->velocity.size() && "Velocity vectors have to have the same size");
    std::copy(velocity.begin(), velocity.end(), this->velocity.begin());
}
template <typename T>
void Particle<T>::setPositionVector(const std::vector<T> &position) {
//    this->position.reserve(position.size());
//    std::copy(position.begin(), position.end(), std::back_inserter(this->position));
    assert(position.size() == this->position.size() && "Position vectors have to have the same size");
    std::copy(position.begin(), position.end(), this->position.begin());
}
template <typename T>
void Particle<T>::setBestVector(const std::vector<T> &best) {
//    this->best.reserve(best.size());
    assert(best.size() == this->best.size() && "Best vectors have to have the same size");
    std::copy(best.begin(), best.end(), this->best.begin());
}
template <typename T>
void Particle<T>::setPBestVector(const std::vector<T> &pbest_position) {
//    this->pbest_position.reserve(pbest_position.size());
    assert(pbest_position.size() == this->pbest.size()&& "PBest vectors have to have the same size");
    std::copy(pbest_position.begin(), pbest_position.end(), this->pbest.begin());
}
template <typename T>
void Particle<T>::display() {
//    this->pbest_position.reserve(pbest_position.size());
    for (unsigned int i=0; i<position.size(); ++i) {
    	std::cout << position.at(i) << ' ';
    }
    std::cout << '\n';
}

template class Particle<float>;
