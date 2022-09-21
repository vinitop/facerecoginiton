#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"  
#include "opencv2/imgproc.hpp"
#include <iostream>
#include<vector>

using namespace std;
using namespace cv;



int main()


{
	


	/*string path = "Resources/Test.jpg";
	Mat img = imread("V:\\Test.jpg");*/

	VideoCapture cam(0); //1 represent  the secondry webcam feed

	Mat img ;

	cout << "Press Q to exit!" << endl;
	while ((char)waitKey(15) != 'q') {
		
			cam.read(img);
			//cascade 
			CascadeClassifier faceCascade;
		faceCascade.load("V:\\VS CODE\\C++\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml"); //pretrained model to detect face.
		
			
			if (faceCascade.empty())
	{
	cout << "XML file not loaded" << endl;
	}

	vector<Rect> faces;
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	faceCascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

		for (int i = 0; i < faces.size(); i++)
			{
					rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
					
			}
		
			imwrite("C:\\Users\\vinit\\Desktop\\Face.jpg", img);   // address where to save the captured picture.

	imshow("FACE DETECTION", img);
	
	

	cout << "number of faces: " << faces.size() << endl;

	}
	
	
	



}