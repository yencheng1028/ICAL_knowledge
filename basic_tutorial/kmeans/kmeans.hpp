#include <opencv4/opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <cmath>

struct Kmeans_algo
{
    std::vector<std::vector<float>> centers;
    std::vector<int> labels;
};

void print2d_float_vec(std::vector<std::vector<float>> vec);

float vec_distance(std::vector<float> a, std::vector<float> b);

float vec_mean(std::vector<float> vec);

bool vec_2d_equal_epsilon(std::vector<std::vector<float>> a, std::vector<std::vector<float>> b, float epsilon);

std::vector<std::vector<float>> generate_random_k_centers(int k_num, int dim, int min, int max);

Kmeans_algo Kmeans_algorithm(std::vector<std::vector<float>> data_vec, int k_num, int dim);

std::vector<std::vector<float>> replace_with_label_and_center(std::vector<std::vector<float>> data_vec, std::vector<int> labels_vec, std::vector<std::vector<float>> centers_vec);

std::vector<std::vector<float>> mat_to_vec(cv::Mat img);

cv::Mat vec_to_mat(std::vector<std::vector<float>> data_vec, int rows, int cols, int channels);