// main.cpp
// #include <sqlite3.h>
// #include <stdio.h>

// int main()
// {
//     printf("%s\n", sqlite3_libversion());
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#include <filesystem>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }

    cout << "Current working directory: " << filesystem::current_path() << endl;

    cv::Mat img = cv::imread("./res/lena.jpg");
    cv::imshow("lena image", img);
    cv::waitKey(0);
    cv::destroyWindow("lena image");

    return 0;
}