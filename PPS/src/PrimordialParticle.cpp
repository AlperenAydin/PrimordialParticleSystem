#include <PPS/PrimordialParticle.hpp>

#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <cmath>


// Utility functions 
inline int signum(int x) {
  if( x < 0 ) return -1;
  if( 0 < x ) return 1;
  return 0;
}

float modulo(float number, float denom) {
  float res = std::fmod(number, denom);
  if (res < 0)
    return res + denom;
  return res; 
}

inline float euclidianDistance(float xa, float ya, float xb, float yb) {
  float res = std::pow(xa-xb, 2) + std::pow(ya-yb, 2);
  return std::sqrt(res);   
}

namespace PPS {


  
  PrimordialParticle::PrimordialParticle(float iX, float iY, float iPhi,
                                         float iV, float iAlpha, float iBeta, float iRadius):
    x(iX), y(iY),
    phi(iPhi),
    v(iV),
    alpha(iAlpha), beta(iBeta),
    radius(iRadius)
  {}

  
  void PrimordialParticle::update()
  {
    // Update the angle
    phi += alpha + beta*N*signum(RL);
    // Then update the position
    x += std::cos(phi*M_PI/180.0);
    y += std::sin(phi*M_PI/180.0);             
  }

  void PrimordialParticle::resetCounters()
  {
    N = 0;
    RL = 0;
  }

  void PrimordialParticle::clipParticle(int width, int height)
  {
    x = modulo(x, width);
    y = modulo(y, height);
  }

  void PrimordialParticle::draw(cv::Mat &ioCanvas, cv::Scalar iColor)
  {
    cv::circle(ioCanvas, cv::Point(x,y), 5, iColor);
  }

  int PrimordialParticle::RelativeDirection(const PrimordialParticle& a,
                                             const PrimordialParticle& b)
  {
    // We will use cross-product to determine the relative direction
    // Using the right hand rule, we know that if b is to the right a
    // the result has to be 
    float xProduct = std::cos(a.phi*M_PI/180.0)*(b.y - a.y)
      - std::sin(a.phi*M_PI/180.0)*(b.x - a.x);

    if( xProduct < 0)
      return 1;
    return -1;     
  }

  void PrimordialParticle::ParticleInteraction(PrimordialParticle &a, PrimordialParticle &b)
  {
    float distance = euclidianDistance(a.x, a.y, b.x, b.y);
    if( distance < a.radius)
      {
        a.N += 1;
        a.RL += PrimordialParticle::RelativeDirection(a, b); 
      }
    if( distance < b.radius)
      {
        b.N += 1;
        b.RL += PrimordialParticle::RelativeDirection(b, a); 
      }
  }

  
} // namespace PPS

