#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    cv::Mat image = cv::imread("../pic/rainbow.jpg", cv::IMREAD_COLOR); //路徑是和執行檔的位置綁定！！
    cv::Mat image_grey = cv::imread("../pic/rainbow.jpg", cv::IMREAD_GRAYSCALE);

    if (image.empty())
    {
        std::cout << "Dude! I cannot find the file, the program dies!"
                  << "\n";
        exit(-1);
    }

    cv::imshow("image", image);
    cv::waitKey(0); // 程式執行到這裡暫停直到按鍵
    cv::imshow("image_grey", image_grey);
    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::Mat blur, canny, smaller, bigger, specific_size;

    cv::blur(image, blur, {31, 31});
    cv::Canny(image, canny, 3, 50);
    cv::resize(image, smaller, {image.cols / 2, image.rows / 3});
    cv::resize(image, bigger, {image.cols * 2, image.rows * 2});
    cv::resize(image, specific_size, {100, 100});

    cv::imshow("blur", blur);
    cv::imshow("canny", canny);
    cv::imshow("smaller", smaller);
    cv::imshow("bigger", bigger);
    cv::imshow("specific_size", specific_size);

    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::Mat blue_mask, green_mask, red_mask, hsv;

    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
    cv::inRange(hsv, cv::Scalar{100, 100, 100}, cv::Scalar{140, 255, 255}, blue_mask);
    cv::inRange(hsv, cv::Scalar{35, 43, 46}, cv::Scalar{77, 255, 255}, green_mask);
    cv::inRange(hsv, cv::Scalar{0, 43, 46}, cv::Scalar{10, 255, 255}, red_mask);

    cv::imshow("blue_mask", blue_mask);
    cv::imshow("green_mask", green_mask);
    cv::imshow("red_mask", red_mask);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}