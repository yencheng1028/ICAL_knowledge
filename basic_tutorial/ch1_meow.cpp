#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{

    cv::Mat image;
    std::string win_name;

    if (argc >= 2) //如果有輸入參數
    {
        std::cout << "Your command: " << argv[0] << "\n"; //印出執行檔名
        std::cout << "Your environment variable is: " << argv[1] << "\n"; //印出環境變數

        image = cv::imread(argv[1], cv::IMREAD_COLOR); //讀取圖片(路徑, 彩色)
        win_name = "PoP_caTTo";
    }
    else //沒有輸入參數
    {
        std::cout << "what?? now Diavolo is here to suffer!\n"
                  << "you should summon the PoP_caTTo to save Diavolo\n";

        image = cv::imread("../pic/default.jpg", cv::IMREAD_GRAYSCALE); //讀取圖片(路徑, 灰階)
        cv::blur(image, image, {15, 15}); //模糊化
        win_name = "what?????";
    }

    if (image.empty()) //如果圖片是空值
    {
        std::cout << "Dude! I cannot find the file, the program dies!"
                  << "\n";
        exit(-1); // 跳出程式
    }

    cv::imshow(win_name, image);

    cv::waitKey(0);

    return 0;
}