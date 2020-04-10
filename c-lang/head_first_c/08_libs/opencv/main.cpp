#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <unistd.h>

static const double MIN_AREA = 500.0;

std::string get_current_date_time();
void draw_text(cv::Mat &frame, const std::string &text);

int main()
{
  sleep(10);

  cv::VideoCapture camera(0);
  if (!camera.isOpened()) {
    std::cout << "error: cannot get access to the camera" << std::endl;
    return 1;
  }

  cv::Mat first_frame;

  while (true) {
    std::string text = "Unoccupied";

    cv::Mat frame;
    if (!camera.read(frame))
      break;

    cv::Mat gray;
    cvtColor(frame, gray, CV_RGB2GRAY);
    GaussianBlur(gray, gray, cv::Size(21, 21), 0);

    if (first_frame.empty()) {
      first_frame = gray;
      continue;
    }

    cv::Mat frame_delta;
    absdiff(first_frame, gray, frame_delta);

    cv::Mat thresh;
    threshold(frame_delta, thresh, 25.0, 255.0, CV_THRESH_BINARY);
    dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);

    std::vector<std::vector<cv::Point>> contours;
    findContours(thresh.clone(),
		 contours,
		 CV_RETR_EXTERNAL,
		 CV_CHAIN_APPROX_SIMPLE);
    for (auto contour : contours) {
      if (contourArea(contour) < MIN_AREA)
	continue;

      cv::Rect rect = boundingRect(contour);
      rectangle(frame, rect, cv::Scalar(0, 255, 0), 2);
      text = "Occupied";
      draw_text(frame, text);
      imwrite("images/" + get_current_date_time() + ".png", frame);
    }

    draw_text(frame, text);
    imshow("Security Feed", frame);

    int key = cv::waitKey(1) & 0xFF;
    if (key == (int)'q')
      break;
  }

  camera.release();
  cv::destroyAllWindows();

  return 0;
}

std::string get_current_date_time()
{
  std::chrono::time_point<std::chrono::system_clock> end;
  end = std::chrono::system_clock::now();
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  return std::ctime(&end_time);
}

void draw_text(cv::Mat &frame, const std::string &text)
{
    putText(frame,
	    "Room Status: " + text,
	    cv::Point(10, 20),
	    CV_FONT_HERSHEY_SIMPLEX,
	    0.5,
	    cv::Scalar(0, 0, 255),
	    2);
    putText(frame,
	    get_current_date_time(),
	    cv::Point(10, frame.size().height - 10),
	    CV_FONT_HERSHEY_SIMPLEX,
	    0.45,
	    cv::Scalar(0, 0, 255),
	    1);
}
