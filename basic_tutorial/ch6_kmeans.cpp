#include "kmeans/kmeans.hpp"

int main()
{
    srand(0);

    cv::Mat img = cv::imread("../pic/meow.png", cv::IMREAD_COLOR); // try cv::IMREAD_UNCHANGED, cv::IMREAD_GRAYSCALE

    std::vector<std::vector<float>> data_vec = mat_to_vec(img);

    std::cout << "channels: " << img.channels() << "\n";

    Kmeans_algo ret = Kmeans_algorithm(data_vec, 3, img.channels());

    std::vector<std::vector<float>> ret_vec = replace_with_label_and_center(data_vec, ret.labels, ret.centers);

    cv::Mat ret_img = vec_to_mat(ret_vec, img.rows, img.cols, img.channels());

    cv::imshow("ret_img", ret_img);
    cv::waitKey(0);
    return 0;
}