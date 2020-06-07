#pragma once

#include <opencv2/opencv.hpp>

#include <utility>


namespace PPS
{
  // Forward declarations
  class PrimordialParticleSystem; 
  
  class PrimordialParticle
  {
  public:
    // Standard issue constructor
    PrimordialParticle(float iX, float iY, float iPhi,
                       float v, float alpha, float beta, float radius);

    // Update state
    void update();

    // Reset the counters
    void resetCounters(); 

    // Draw on the canvas
    void draw(cv::Mat& ioCanvas, cv::Scalar iColor);

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
