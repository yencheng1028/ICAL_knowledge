#include "kmeans.hpp"

void print2d_float_vec(std::vector<std::vector<float>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

float vec_distance(std::vector<float> a, std::vector<float> b)
{
    if (a.size() != b.size())
    {
        std::cout << "Error!! the dimension does not match"
                  << "\n";

        exit(-1);
        return -1.0f;
    }

    float square_sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        square_sum += std::pow(std::abs(a[i] - b[i]), 2);
    }

    return std::sqrt(square_sum);
}

float vec_mean(std::vector<float> vec)
{
    if (vec.size() == 0)
    {
        std::cout << "generate new one randomly!\n";
        return rand() % 256;
    }

    float sum = 0;

    for (int i = 0; i < vec.size(); i++)
        sum += vec[i];

    return sum / vec.size();
}

bool vec_2d_equal_epsilon(std::vector<std::vector<float>> a, std::vector<std::vector<float>> b, float epsilon)
{
    // epsilon: 容許誤差
    // check if the size is the same
    if (a.size() != b.size())
    {
        std::cout << "Error!! the dimension does not match"
                  << "\n";

        exit(-1);
        return false;
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (std::abs(a[i][j] - b[i][j]) > epsilon)
                return false;
        }
    }

    return true;
}

std::vector<std::vector<float>> generate_random_k_centers(int k_num, int dim, int min, int max)
{
    std::vector<std::vector<float>> centers_vec;

    for (int i = 0; i < k_num; ++i)
    {
        std::vector<float> row_vec; // When loop back, the vector is re-initialized!

        for (int j = 0; j < dim; ++j)
            row_vec.push_back(rand() % (max - min + 1) + min);

        centers_vec.push_back(row_vec);
    }
    return centers_vec;
}

Kmeans_algo Kmeans_algorithm(std::vector<std::vector<float>> data_vec, int k_num, int dim)
{
    std::vector<std::vector<float>> old_centers_vec(k_num, std::vector<float>(dim, 0));          // float[k_num][dim]=0 K個中心點 每個中心點有dim個維度，初始值為0
    std::vector<std::vector<float>> centers_vec = generate_random_k_centers(k_num, dim, 0, 255); // K個中心點 每個中心點有dim個維度，初始值為0～255的隨機值
    std::vector<int> labels_vec(data_vec.size(), -1);                                            // n筆資料 每筆資料有label，初始值為-1 基本上就是標記

    // i: 第i筆資料 j: 第j個維度 k: 第k群
    // 類比 i個像素 j=3（b值 g值 r值） k種顏色

    while (!vec_2d_equal_epsilon(old_centers_vec, centers_vec, 0.1f)) // while(old_center_vec==center_vec) 直到舊的和新的中心一樣
    {
        old_centers_vec = centers_vec; // centers_vec將會被更新

        // 1. 將每一筆資料和距離最近的中心做標記
        for (int i = 0; i < data_vec.size(); i++)
        {
            float min_distance = 999999999.0f; //設超大的數字，第一次一定會被更新
            int min_index = -1;

            for (int k = 0; k < k_num; k++)
            {
                float distance = vec_distance(data_vec[i], centers_vec[k]);

                if (distance < min_distance)
                {
                    min_distance = distance; // 更新最小值
                    min_index = k;           // 知道最小值的資料是屬於哪一群（第k群）
                }
            }

            labels_vec[i] = min_index; // 第i筆資料的label屬於第min_index(k)個中心點
        }                              // 目標: 得到標記labels_vec[第i筆資料]->k群

        // 2. 利用先前的標記，將同個標記的資料取重心，以更新k個中心
        for (int j = 0; j < dim; j++)
        {
            std::vector<std::vector<float>> sum_2d(k_num);

            for (int i = 0; i < data_vec.size(); i++)
            {
                int k = labels_vec[i];               // 第i筆資料屬於k群
                sum_2d[k].push_back(data_vec[i][j]); // 收集第k群在第j維的所有值
            }

            for (int k = 0; k < k_num; ++k)
                centers_vec[k][j] = vec_mean(sum_2d[k]); // 計算每個群的平均

        } // 目標: 得到centers_vec[第k群]的重心值
    }

    // 要怎麼回傳多個參數？
    Kmeans_algo ret;
    ret.centers = centers_vec;
    ret.labels = labels_vec;

    return ret;
}

std::vector<std::vector<float>> replace_with_label_and_center(std::vector<std::vector<float>> data_vec, std::vector<int> labels_vec, std::vector<std::vector<float>> centers_vec)
{
    std::vector<std::vector<float>> ret_vec(data_vec.size(), std::vector<float>(data_vec[0].size(), 0)); // 挖float[m][n]的空間 其中m代表m筆資料 n代表n個維度

    for (int i = 0; i < data_vec.size(); i++)
    {
        for (int j = 0; j < data_vec[i].size(); j++)
        {
            ret_vec[i][j] = centers_vec[labels_vec[i]][j];
        }
    }

    return ret_vec;
}

std::vector<std::vector<float>> mat_to_vec(cv::Mat img)
{
    std::vector<std::vector<float>> data_vec;

    switch (img.channels())
    {
    case 1:
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                std::vector<float> row_vec;

                for (int k = 0; k < img.channels(); k++)
                {
                    row_vec.push_back(img.at<cv::Vec<uchar, 1>>(i, j)[k]); // <>裡面的東西需要在編譯時期決定 "1"這個位置不能是變數 （template是什麼？）
                }

                data_vec.push_back(row_vec);
            }
        }
        break;

    case 3:
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                std::vector<float> row_vec;

                for (int k = 0; k < img.channels(); k++)
                {
                    row_vec.push_back(img.at<cv::Vec<uchar, 3>>(i, j)[k]);
                }

                data_vec.push_back(row_vec);
            }
        }
        break;

    case 4:
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                std::vector<float> row_vec;

                for (int k = 0; k < img.channels(); k++)
                {
                    row_vec.push_back(img.at<cv::Vec<uchar, 4>>(i, j)[k]);
                }

                data_vec.push_back(row_vec);
            }
        }
        break;

    default:
        std::cout << "error"
                  << "\n";

        exit(-1);
        break;
    }

    return data_vec;
}

cv::Mat vec_to_mat(std::vector<std::vector<float>> data_vec, int rows, int cols, int channels)
{
    cv::Mat ret(rows, cols, CV_MAKETYPE(CV_8U, channels));

    switch (channels)
    {
    case 1:
        for (int i = 0; i < data_vec.size(); i++)
        {
            for (int j = 0; j < data_vec[i].size(); j++)
            {
                ret.at<cv::Vec<uchar, 1>>(i / cols, i % cols)[j] = (float)data_vec[i][j];
            }
        }
        break;

    case 3:
        for (int i = 0; i < data_vec.size(); i++)
        {
            for (int j = 0; j < data_vec[i].size(); j++)
            {
                ret.at<cv::Vec<uchar, 3>>(i / cols, i % cols)[j] = (float)data_vec[i][j];
            }
        }
        break;

    case 4:
        for (int i = 0; i < data_vec.size(); i++)
        {
            for (int j = 0; j < data_vec[i].size(); j++)
            {
                ret.at<cv::Vec<uchar, 4>>(i / cols, i % cols)[j] = (float)data_vec[i][j];
            }
        }
        break;

    default:
        std::cout << "error"
                  << "\n";

        exit(-1);
        break;
    }

    return ret;
}