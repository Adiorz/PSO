#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <vector>

template <class T> class Particle {
  private:
    std::vector<T> position;
    std::vector<T> velocity;
    std::vector<T> pbest;	// the best known position vector of the population
    float error;
    std::vector<T> best;	// the best position vector of the particle
  public:
    Particle(const std::vector<T> &position = std::vector<T>(), const std::vector<T> &velocity = std::vector<T>());
    const std::vector<T> &getPositionVector() const;
    const std::vector<T> &getVelocityVector() const;
    const std::vector<T> &getBestVector() const;
    float getError();
    const std::vector<T> &getPBestVector() const;

    void setVelocityVector(const std::vector<T> &velocity);
    void setPositionVector(const std::vector<T> &position);
    void setBestVector(const std::vector<T> &best);
    void setPBestVector(const std::vector<T> &pbest_position);
    void display();
};
#endif // PARTICLE_H_
