#include<iostream>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Read the input image
    Mat img = imread("Image.png", IMREAD_COLOR);

    // Declare Mat objects to store filtered images
    Mat bilateralImg, gaussianImg, medianImg;

    // Apply bilateral filter (Noise reduction while preserving edges)
    bilateralFilter(img, bilateralImg, 15, 95, 45);

    // Apply Gaussian blur (Smoothing)
    GaussianBlur(img, gaussianImg, Size(15, 15), 0);

    // Apply median filter (Noise reduction while preserving edges)
    medianBlur(img, medianImg, 15);

    // Display the images with their respective filters
    imshow("Gaussian", gaussianImg);
    imshow("Median", medianImg);
    imshow("Bilateral", bilateralImg);

    // Display the original input image
    imshow("Input", img);

    // Wait for a key press
    waitKey(0);

    // Conclusion: The speed of filters can depend on the specific image and the desired result.
    // In general, bilateral and Gaussian filters are faster than the median filter for most scenarios.
    // However, the choice of the fastest filter can vary based on the specific requirements of the task.
    // It's recommended to benchmark on your specific images and application to determine the most efficient filter.

    return 0;
}
