#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;  // start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide(){

	g_cap.set( cv::CAP_PROP_POP_FRAMES, pop );

	if( !g_dontset )
		g_run = 1;
	g_dontset = 0;

}

int main( int argc, char** argv ){

	cv::namedWindow( "Example 2-4", cv::WINDOW_AUTOSIZE );
	g_cap( string(argv[1]) );
	int frames = (int) g_cap.get(CV_CAP_PROP_FRAME_COUNT);
	int tmpw   = (int) g_cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int tmph   = (int) g_cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	std::cout << "Video has "<< frames <<" frames of dimensions(" << tmpw << " ," << tmph << ")" << std::endl;  



	cv::createTrackbar("Positon", "Example 2-4", &g_slider_position, frames, onTrackbarSlide);
	cv::Mat frame;

	for(;;){
		
		if(g_run != 0){
			g_cap >> frame; if(frame.empty()) break;
			int current_pos = (int)g_cap.get(CV_PROP_POS_FRAMES);

			g_dontset = 1;

			cv::setTrackbarPos("Position", "Example 2-4", current_pos);
			cv::imshow("Examplo 2-4", frame );

			g_run = 1;
		}
	
	
	char c = (char)cv::waitKey(10);
	if(c == 's')   //single step
		{g_run = 1; std::cout << "Step, run = " << g_run << endl;}
	if(c == 'r')  //run mode
		{g_run = -1; std::cout << "Run mode, run = " << g_run << endl;}
	if(c == 27)
		break;

	
	}

	return(0);

}

