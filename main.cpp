#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include <unistd.h>

namespace fs = std::filesystem;
using namespace cv;
using namespace std;

const string ASCII_CHARS = "@$B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

char pixelToASCII(int pixelVal) {
    int index = pixelVal * ASCII_CHARS.size() / 256;
    return ASCII_CHARS[index];
}

void playVideoInAscii(const string& folder) {
    vector<fs::path> frames;

    for (auto& p : fs::directory_iterator(folder)) {
        if (p.path().extension() == ".png")
            frames.push_back(p.path());
    }

    sort(frames.begin(), frames.end());

    for (const auto& framePath : frames) {
        Mat img = imread(framePath.string(), IMREAD_GRAYSCALE);
        if (img.empty()) continue;

        system("clear");

        for (int i = 0; i < img.rows; i += 4) {
            for (int j = 0; j < img.cols; j += 2) {
                cout << pixelToASCII(img.at<uchar>(i, j));
            }
            cout << endl;
        }

        usleep(33000);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: ./yt2ascii <frames_folder>" << endl;
        return 1;
    }

    playVideoInAscii(argv[1]);
    return 0;
}
