#pragma once

#include <opencv2/opencv.hpp>

namespace PPS
{
  // Forward declarations
  class PrimordialParticleSystem; 
  
  class PrimordialParticle
  {
  public:
    friend class PrimordialParticleSystem;
    // Standard issue constructor
    PrimordialParticle(float iX, float iY, float iPhi,
                       float iV, float iAlpha, float iBeta, float iRadius);

    // Update state
    void update();

    // Reset the counters
    void resetCounters();

    // Fill the particle so that is within dimensions
    void clipParticle(int width, int height); 

    // Draw on the canvas
    void draw(cv::Mat& ioCanvas, cv::Scalar iColor);

    // Find the relative direction of a particle
    // 1 if b is on the rightside of a,
    // -1 if it is on the left
    static int RelativeDirection(const PrimordialParticle& a, const PrimordialParticle& b);
    
    // Simulate the interaction between points
    static void ParticleInteraction(PrimordialParticle& a, PrimordialParticle& b);

  private:
    // State
    float x, y;
    float phi; // In degrees

    // Parameters
    float v;
    float alpha, beta;
    float radius;

    // Counters
    int N;
    int RL; // R-L 
    
  };
} // namespace PPS
