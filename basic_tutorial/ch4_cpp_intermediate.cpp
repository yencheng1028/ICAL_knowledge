#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

struct PixelStruct
{
    int r;
    int g;
    int b;

    int get_total()
    {
        return r + g + b;
    }
};

class PixelClass
{
    int r;
    int g;
    int b;

public:
    void set_rgb(int input_r, int input_g, int input_b)
    {
        r = input_r;
        g = input_g;
        b = input_b;
    }
    int get_r()
    {
        return r;
    }
    int get_g()
    {
        return g;
    }
    int get_b()
    {
        return b;
    }
};

int main()
{
    using namespace std;

    // section 1:

    vector<int> vec; // I can now not using std::{asdfasdfasf}!!

    // You can now not specify the size when declare a vector

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i * 2); // you cannot push back in array!
    }

    cout << "pushed back: \n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    cout << "vec_size" << vec.size() << "\n";

    // Ranged-baed loop (if you care about the index don't use it)
    // for (int a : vec)
    // {
    //     cout << a << " ";
    // }

    cout << "\n";

    // section 2:

    PixelStruct pix = {12, 34, 56};

    cout << "======================= struct: ======================="
         << "\n";
    cout << pix.r << " " << pix.g << " " << pix.b << "\n";

    cout << "total of r+g+b: " << pix.get_total() << "\n";

    vector<PixelStruct> pixels;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int rand_r = rand() % 256;
        int rand_b = rand() % 256;
        int rand_g = rand() % 256;
        pixels.push_back({rand_r, rand_g, rand_b});
    }

    for (int i = 0; i < pixels.size(); i++)
    {
        cout << "R: " << pixels[i].r << ", G: " << pixels[i].g << ", B: " << pixels[i].b << "\n";
    }

    // section 3:

    // PixelClass pix_class = {12, 23, 12}; // the class default is private

    PixelClass pix_class;
    pix_class.set_rgb(34, 23, 12);
    cout << "======================= class: ======================="
         << "\n";
    cout << "R: " << pix_class.get_r() << ", G: " << pix_class.get_g() << ", B: " << pix_class.get_b() << "\n";

    // why we need get and set?? (Encapusulation 封裝)
}