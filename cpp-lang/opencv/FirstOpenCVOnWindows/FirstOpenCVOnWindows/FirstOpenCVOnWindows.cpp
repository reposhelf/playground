#include <opencv2\core.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	Mat image;
	image = imread(argv[1], IMREAD_COLOR);

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	namedWindow("Display Window", WINDOW_AUTOSIZE);
	imshow("Display Window", image);

	waitKey(0);
	return 0;
}