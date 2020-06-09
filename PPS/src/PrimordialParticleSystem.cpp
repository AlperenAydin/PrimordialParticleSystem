#include <PPS/PrimordialParticleSystem.hpp>
#include <PPS/PrimordialParticle.hpp>

#include <algorithm>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <random>

// General Utility
inline float randf(float max) {
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  return r*max;
}

inline cv::Scalar convertHLS2BGR(float H, float S, float L) {
  cv::Mat rgb;
  cv::Mat hsl(1, 1, CV_8UC3, cv::Scalar(H,S,L));
  cv::cvtColor(hsl, rgb, cv::COLOR_HLS2BGR);
  return cv::Scalar(rgb.data[0], rgb.data[1], rgb.data[2]);
}

inline cv::Scalar getParticleColor(int N, int N_max) {
  float H = static_cast<float>(N) / static_cast<float>(N_max);
  H = 150.0*H;
  return convertHLS2BGR(H, 0.3*255, 255);
}

namespace PPS {

  PrimordialParticleSystem::PrimordialParticleSystem(int iN,
                                                     int iWidth, int iHeight,
                                                     float iV,
                                                     float iAlpha, float iBeta,
                                                     float iRadius) :
    width(iWidth), height(iHeight)
  {
    particles.reserve(iN);
    for(int i=0; i < iN; i++)
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
    // Resetting the counters of all particles
    std::for_each(particles.begin(), particles.end(),
                  [] (PrimordialParticle &p) {p.resetCounters();});
    // Simulating the interaction between each particle
    int N = particles.size();
    for( int i = 0; i < N; i++)
      {
        for( int j = i+1; j < N; j++)
          {
            PrimordialParticle::ParticleInteraction(particles[i], particles[j]);
          }
      }
    // Updating and clipping
    for(auto& p: particles)
      {
        p.update();
        p.clipParticle(width, height);
      } 
  }

  void PrimordialParticleSystem::draw(cv::Mat &ioCanvas)
  {
    auto comp = [](PrimordialParticle& a, PrimordialParticle b)
                {return a.N < b.N;};
    int N_max = std::max_element(particles.begin(), particles.end(),
                                 comp) -> N;
      
    for(PrimordialParticle& p: particles)
      {
        auto color = getParticleColor(p.N, N_max);
        p.draw(ioCanvas, color);
      }
  }

  } // namespace PPS
