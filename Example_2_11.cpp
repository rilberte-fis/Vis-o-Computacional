#include<opencv2/opencv.hpp>
#include<iostream>

int main( int argc, char* argv[] ){

	cv::namedWindow( "Example 2-11", cv::WINDOW_AUTOSIZE );
	
	//(Note: could capture from a camera by giving a camera id as an int.)
	//
	
	cv::VideoCapture(argv[1]);

	double fps = capture.get(CV_CAP_PROP_FRAME_FPS);

	cv::Size size(
			(int)capture.get(CV_CAP_PROP_FRAME_WIDTH),
			(int)capture.get(CV_CAP_PROP_FRAME_HEIGHT)
		     );



	cv::VideoWriter writer;
	writer.open(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fds, size);


	cv::Mat logpolar_frame, bgr_frame;

	for(;;){
		

		capture >> bgr_frame;
		if(bgr_frame.empty()) break;	//end if done
		

		cv::imshow( "Example 2-11", bgr_frame );


		cv::logPolar(
				bgr_frame,			//Input color frame
				logpolar_frame,			//Output log-polar frame
				cv::Point2f(			//Centerpoint for log-polar transformation
					bgr_frame.cols/2,	// x
					bgr_frame.rows/2	// y
					),		
				40,				//Magnitude (scale parameter)	
				CV_WARP_FILL_OUTLIERS		//Fill outliers with 'zero'
				);
	
		
		cv::imshow("Log_Polar", logpolar_frame);
		write << logpolar_frame;

		(char)cv::waitKey(33);
		if( c == 27) break; 	// allow the user to break out


	}



	capture.release();

}




