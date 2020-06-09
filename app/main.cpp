#include <iostream>

#include <PPS/PrimordialParticleSystem.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>

int main()
{
  int width = 1000;
  int height = 1000;
  PPS::PrimordialParticleSystem aSystem(100,
                                        width, height,
                                        6, 0, -6, 55);
  cv::namedWindow("canvas", cv::WINDOW_AUTOSIZE);
  cv::Mat aCanvas(height, width, CV_8UC3, cv::Scalar(255,255,255));

  while(1)
    {
      aCanvas = cv::Scalar(255,255,255);
      aSystem.update();
      aSystem.draw(aCanvas);

      cv::imshow("canvas", aCanvas);
      char c = (char)cv::waitKey(5);
      if(c==27)
        break;
    }
  return 0;
}
