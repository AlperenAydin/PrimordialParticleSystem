#pragma once


#include <opencv2/opencv.hpp>

#include <PPS/PrimordialParticle.hpp>
#include <vector>


namespace PPS {
  class PrimordialParticleSystem
  {
  public:
    PrimordialParticleSystem(int N,
                             int width, int height,
                             float iV, float iAlpha, float iBeta, float iRadius);

    // simulates the interactions and updates the particles
    void update();
    // Draw the parrticles
    void draw(cv::Mat &ioCanvas);
    
  private:
    std::vector<PrimordialParticle> particles;
    int width, height;    
  };
  
} // namespace PPS    
