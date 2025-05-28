#include <jni.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_edgedetectorapp_NativeLib_processFrame(JNIEnv *env, jobject /* this */,
jlong inputImageAddr, jlong outputImageAddr) {
cv::Mat &inputImage = *(cv::Mat *) inputImageAddr;
cv::Mat &outputImage = *(cv::Mat *) outputImageAddr;

// Convert to grayscale
cv::cvtColor(inputImage, outputImage, cv::COLOR_RGBA2GRAY);

// Apply Canny edge detection
cv::Canny(outputImage, outputImage, 80, 100);
}
