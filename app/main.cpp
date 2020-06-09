#include <iostream>

#include <PPS/PrimordialParticleSystem.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>

int main()
{
  // Parameters of the canvas
  int width = 1000;
  int height = 1000;
  // Creating the system
  PPS::PrimordialParticleSystem aSystem(800,
                                        width, height,
                                        6, 120, -6, 70);
  // Preparing the window, canvas and video writer
  cv::namedWindow("canvas", cv::WINDOW_AUTOSIZE);
  cv::Mat aCanvas(height, width, CV_8UC3, cv::Scalar(255,255,255));
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
