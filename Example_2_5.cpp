#include<iostream>
#include<opencv/opencv.hpp>

int main(int argc, char* argv[]){

	//Load an image specified on the commando line
	//
	//Create some windows to show the input
	//and output images in.
	
	cv::nameWindow("Example 2-5-in", cv::WINDOW_AUTOSIZE );
	cv::nameWindow( "Example 2-5-out", cv::WINDOW_AUTOSIZE );

	//Create a window so show our input image
	//
	cv::imshow( "Example 2-5-in", image );

	//Create a image to hold the smoothed output
	//
	cv::Mat out;

	//Do the smoothing
	//(Note:: Could use GaussianBlur(), blur, medianBlur(), or bilateralFilter(). )
	//
	

	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GuassianBlur( out, out, cv::Size(5, 5,), 3, 3);

	//Show the smoothed image in the output window
	//
	cv::imshow("Example 2-5-out", out);

	//Wait for the user to hit a key, windows will self destruct
	//
	
	//comentario para o aprendizado git

	cv::waitKey(0);


}
