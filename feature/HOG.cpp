//// https://blog.csdn.net/u011960822/article/details/46987145
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <string>
//
//// 计算每个cell的9维bin数组
//// input_param: 每个cell左上角的x,y坐标，cell的宽，处理的图片，输出的每个cell的9维的bin数组
//void cellBin(int i_x, int i_y, int i_w, cv::Mat Img_in, float* fbin)
//{
//    memset(fbin, 0, 9*sizeof(float));
//    float f_x = 0.0f, f_y = 0.0f, f_Nvm = 0.0f, f_theta = 0.0f;
//    for (int ii = i_y; ii < i_y + i_w; ii++)
//    {
//        for (int jj = i_x; jj < i_x + i_w; jj++)
//        {
//            uchar* pData = (uchar*)(Img_in->imageData + ii * Img_in->widthStep + jj);
//            f_x = pData[1] - pData[-1];
//            f_y = pData[Img_in->widthStep]- pData[-Img_in->widthStep];
//            f_Nvm = pow( f_x*f_x + f_y*f_y,  0.5f);
//
//            float fAngle = 90.0f;
//            if (f_x == 0.0f)
//            {
//                if (f_y > 0)
//                {
//                    fAngle = 90.0f;
//                }
//            }
//            else if (f_y == 0.0f)
//            {
//                if (f_x > 0)
//                {
//                    fAngle == 0.0f;
//                }
//                else if (f_x < 0)
//                {
//                    fAngle == 180.0f;
//                }
//            }
//            else
//            {
//                f_theta = atan(f_y/f_x); //// atan() 范围为 -Pi/2 到 pi/2 所有9个bin范围是 0~180°
//                fAngle = (BIN_SIZE*BIN_NVM * f_theta)/PI;
//            }
//
//            if (fAngle < 0)
//            {
//                fAngle += 180;
//            }
//
//            int iWhichBin = fAngle/BIN_SIZE;
//            fbin[iWhichBin] += f_Nvm;
//        }
//    }
//}
//int main(int argc, char ** argv)
//{
////    std::string imgPath = argv[1];
//    std::string imgPath = "/home/yl/data/timg.jpeg";
//    cv::Mat srcImg = cv::imread(imgPath, -1);
//
//    // 1 灰度化
//    cv::Mat grayImg;
//    if(srcImg.channels() != 1)
//        cv::cvtColor(srcImg, grayImg, CV_BGR2GRAY);
//    else
//        grayImg = srcImg.clone();
//
//    // 2 伽马校正
//    cv::Mat img, temp;
//    grayImg.convertTo(temp, CV_32FC1);  // convert to CV_32FC1
//    float gamma = 1.0/2.2;  //gamma值
//    std::cout << "gamma:" << gamma << std::endl;
//    cv::pow(temp, gamma, img);
//
//    // 3
//
//    cv::imshow("gamma", img);
//    cv::waitKey(0);
//    return 0;
//
//
//
//}

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#define PI 3.14
#define BIN_SIZE 20
#define BIN_NVM 9
#define NORM_WIDTH 130
#define NORM_HEIGHT 82
#define CELL_SIZE 8
#define BLOCK_SIZE 2
#define PIC_CELL_WH 50
#define CELL_W_NVM  ((NORM_WIDTH-2) / CELL_SIZE)
#define CELL_H_NVM  ((NORM_HEIGHT-2) / CELL_SIZE)
#define BLOCK_W_NVM  (CELL_W_NVM - BLOCK_SIZE + 1)
#define BLOCK_H_NVM  (CELL_H_NVM - BLOCK_SIZE + 1)
#define CELL_NVM (CELL_W_NVM * CELL_H_NVM)
#define BLOCK_NVM (BLOCK_W_NVM * BLOCK_H_NVM)
#define ARRAY_ALL (BLOCK_W_NVM * BLOCK_H_NVM * BLOCK_SIZE * BLOCK_SIZE * BIN_NVM)

using namespace std;
using namespace cv;

void  func(int i_x, int i_y, int i_w, IplImage* Img_in, float* fbin)
{
    memset(fbin, 0, 9*sizeof(float));
    float f_x = 0.0f, f_y = 0.0f, f_Nvm = 0.0f, f_theta = 0.0f;
    for (int ii = i_y; ii < i_y + i_w; ii++)
    {
        for (int jj = i_x; jj < i_x + i_w; jj++)
        {
            uchar* pData = (uchar*)(Img_in->imageData + ii * Img_in->widthStep + jj);
            f_x = pData[1] - pData[-1];
            f_y = pData[Img_in->widthStep]- pData[-Img_in->widthStep];
            f_Nvm = pow( f_x*f_x + f_y*f_y,  0.5f);

            float fAngle = 90.0f;
            if (f_x == 0.0f)
            {
                if (f_y > 0)
                {
                    fAngle = 90.0f;
                }
            }
            else if (f_y == 0.0f)
            {
                if (f_x > 0)
                {
                    fAngle == 0.0f;
                }
                else if (f_x < 0)
                {
                    fAngle == 180.0f;
                }
            }
            else
            {
                f_theta = atan(f_y/f_x); //// atan() 范围为 -Pi/2 到 pi/2 所有9个bin范围是 0~180°
                fAngle = (BIN_SIZE*BIN_NVM * f_theta)/PI;
            }

            if (fAngle < 0)
            {
                fAngle += 180;
            }

            int iWhichBin = fAngle/BIN_SIZE;
            fbin[iWhichBin] += f_Nvm;
        }
    }
}

int main(void)
{
    IplImage* img = cvLoadImage("/home/yl/data/timg.jpeg");
    IplImage *img1 = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    IplImage *img2 = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    CvMat* mat = cvCreateMat(img->width, img->height,CV_32FC1);

    //// 灰度图
    cvCvtColor(img,img1,CV_BGR2GRAY);
    cvNamedWindow("GrayImage",CV_WINDOW_AUTOSIZE);
    cvShowImage("GrayImage",img1);

    //// gamma校正
    uchar* uData  = (uchar*)(img1->imageData);
    float* fMat = mat->data.fl;

    for (int ii = 0; ii < img1->imageSize; ii++)
    {
        fMat[ii] = pow( uData[ii],  0.5f);
        ((uchar*)img2->imageData)[ii] = (uchar)(fMat[ii]);
    }
}
