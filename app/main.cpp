#include <iostream>

#include <PPS/PrimordialParticleSystem.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>

#include "config.hpp"

int main(int argc, char *argv[])
{
  // Configuration
  Config c(argc, argv);
  if( c.help)
    return 0;
  c.showConfig();
  // Creating the system
  PPS::PrimordialParticleSystem aSystem(c.N,
                                        c.width, c.height,
                                        c.v, c.alpha, c.beta, c.radius);
  // Preparing the window, canvas and video writer
  cv::namedWindow("canvas", cv::WINDOW_AUTOSIZE);
  cv::Mat aCanvas(c.height, c.width, CV_8UC3, cv::Scalar(255,255,255));
  cv::VideoWriter video("output.avi", 
                        cv::VideoWriter::fourcc('M','J','P','G'),
                        30,
                        cv::Size(aCanvas.cols,aCanvas.rows));
  while(1)
    {
      aCanvas = aCanvas + cv::Scalar(50,50,50);
      aSystem.update();
      aSystem.draw(aCanvas);

      cv::imshow("canvas", aCanvas);
      video.write(aCanvas);
      char c = (char)cv::waitKey(1);
      if(c==27)
        break;
    }
  // Destroy the writer
  video.release();
  return 0;
}
