#include "../headers/particle.h"
#include <assert.h>
#include <iostream>

template <typename T>
Particle<T>::Particle(const std::vector<T> &position, const std::vector<T> &velocity) {
    this->position = std::vector<T>(position);
    this->pbest = std::vector<T>(position);
    this->best = std::vector<T>(position);
    this->velocity = std::vector<T>(velocity);
    this->error = 0.f;
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

template <typename T>
void Particle<T>::setVelocityVector(const std::vector<T> &velocity) {
    assert(velocity.size() == this->velocity.size() && "Velocity vectors have to have the same size");
    std::copy(velocity.begin(), velocity.end(), this->velocity.begin());
}

template <typename T>
void Particle<T>::setPositionVector(const std::vector<T> &position) {
    assert(position.size() == this->position.size() && "Position vectors have to have the same size");
    std::copy(position.begin(), position.end(), this->position.begin());
}

template <typename T>
void Particle<T>::setBestVector(const std::vector<T> &best) {
    assert(best.size() == this->best.size() && "Best vectors have to have the same size");
    std::copy(best.begin(), best.end(), this->best.begin());
}

template <typename T>
void Particle<T>::setPBestVector(const std::vector<T> &pbest_position) {
    assert(pbest_position.size() == this->pbest.size()&& "PBest vectors have to have the same size");
    std::copy(pbest_position.begin(), pbest_position.end(), this->pbest.begin());
}

template <typename T>
void Particle<T>::display() {
    for (unsigned int i=0; i<position.size(); ++i) {
    	std::cout << position.at(i) << ' ';
    }
    std::cout << '\n';
}

template class Particle<float>;
