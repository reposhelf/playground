#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    if (argc != 2) {
        cerr << "usage: display_image <image_path>" << endl;
        return -1;
    }

    Mat image = imread(argv[1], 1);

    if (!image.data) {
        cerr << "No image data" << endl;
        return -1;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}
