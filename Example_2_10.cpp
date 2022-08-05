#include<iostream>
#include<opencv2/opencv.hpp>


int main(int argc, char** argv){

	cv::VideoCapture cap;

	if(argc == 1){
		cap.open(0);		//open the first camera
	}else{
		cap.open(argv[1]);
	}

	if(!cap.isOpened){ 		// check if we succeded
		std::cerr << "Could't open capture." << std::endl;
		return -1;
	}



	cv::Mat frame;

	for(;;){
		cap >> frame;
		if(frame.empty()) break; 	//Ran out of film
		cv::imshow("Example 2-3", frame);
		if((char)cv::waitKey >= 0) break;
	}


	return 0;
}
