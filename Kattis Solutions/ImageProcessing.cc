#include <iostream>
using namespace std;

int main() {
    int imageHeight, imageWidth, kernelHeight, kernelWidth;
    cin >> imageHeight >> imageWidth >> kernelHeight >> kernelWidth;
    int image[imageHeight][imageWidth];
    for (int i = 0; i < imageHeight; ++i) {
        for (int j = 0; j < imageWidth; ++j) {
            int element;
            cin >> element;
            image[i][j] = element;
        }
    }
    int kernel[kernelHeight][kernelWidth];
    for (int i = kernelHeight - 1; i >= 0; --i) {
        for (int j = kernelWidth - 1; j >= 0; --j) {
            int kernelElement;
            cin >> kernelElement;
            kernel[i][j] = kernelElement;
        }
    }
    int answer[imageHeight - kernelHeight + 1][imageWidth - kernelWidth + 1];
    for (int i = 0; i < (imageHeight - kernelHeight + 1); ++i) {
        for (int j = 0; j < (imageWidth - kernelWidth + 1); ++j) {
            answer[i][j] = 0;
            for (int l = 0; l < kernelHeight; ++l) {
                for (int k = 0; k < kernelWidth; ++k) {
                    answer[i][j] += (kernel[l][k] * image[i + l][j + k]);
                }
            }
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}