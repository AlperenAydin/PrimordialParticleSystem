#include <PPS/PrimordialParticleSystem.hpp>
#include <PPS/PrimordialParticle.hpp>

#include <algorithm>
#include <opencv2/opencv.hpp>

#include <random>

// General Utility
float randf(float max) {
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  return r*max; 
}

namespace PPS {

  PrimordialParticleSystem::PrimordialParticleSystem(int iN,
                                                     int iWidth, int iHeight,
                                                     float iV,
                                                     float iAlpha, float iBeta,
                                                     float iRadius) :
    width(iWidth), height(iHeight)
  {
    particles.reserve(N);
    for(int i=0; i <N; i++)
    {
      PrimordialParticle p(randf(width),
                           randf(height),
                           randf(360),
                           iV, iAlpha, iBeta, iRadius);
      particles.push_back(p);
    }
  }

  void PrimordialParticleSystem::update()
  {
    std::for_each(particles.begin(), particles.end(),
                  [] (PrimordialParticle &p) {p.resetCounters();});
    
    int N = particles.size();
    for( int i = 0; i < N; i++)
      {
        for( int j = i+1; j < N; j++)
          {
            PrimordialParticle::ParticleInteraction(particles[i], particles[j]);
          }
      }

    
  }

  } // namespace PPS
