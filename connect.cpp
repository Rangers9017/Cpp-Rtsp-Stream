#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap("rtsp://user:password@ip:port/cam/realmonitor?channel=1&subtype=0");  // (default kamera, index 0)

    if (!cap.isOpened()) {
        std::cerr << "Camera not open" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {  
        if (!cap.read(frame) || frame.empty()) {c
            std::cerr << "Frame not working" << std::endl;
            break;
        }

        cv::imshow("Display with camera", frame);  

        if (cv::waitKey(30) == 27) {  // ESC exit
            break;
        }
    }

    cap.release();  
    cv::destroyAllWindows();  
    return 0;
}
