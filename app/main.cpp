#include <iostream>

#include <PPS/PrimordialParticleSystem.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>

int main()
{
  int width = 1000;
  int height = 1000;
  PPS::PrimordialParticleSystem aSystem(500,
                                        width, height,
                                        15, 120, -60, 55);
  cv::namedWindow("canvas", cv::WINDOW_AUTOSIZE);
  cv::Mat aCanvas(height, width, CV_8UC4, cv::Scalar(255,255,255));

  while(1)
    {
      aCanvas = aCanvas + cv::Scalar(50,50,50);
      aSystem.update();
      aSystem.draw(aCanvas);

      cv::imshow("canvas", aCanvas);
      char c = (char)cv::waitKey(20);
      if(c==27)
        break;
    }
  return 0;
}
