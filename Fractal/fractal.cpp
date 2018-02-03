/*    @file fractal.cpp    
      @author <-- Fill in your name here -->
      @date <-- Fill this in -->

			@description 
*/
#include <iostream>
#include <stdlib.h>
#include <sstream>
// Use your myComplex class!
#include "myComplex.h"

// Import and setup the CImg library
#define cimg_display 0
#include "CImg.h"

using namespace std;


// Convenience function to set the red, green, and blue channels
// at a given pixel location in the image.
void setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue, cil::CImg<unsigned char>& image){
  *(image.data(x,y,0,0)) = red;
  *(image.data(x,y,0,1)) = green;
  *(image.data(x,y,0,2)) = blue;
}

// Fill me in!

myComplex p(myComplex x)
{
	myComplex temp1(x.getReal(), x.getImaginary());
	temp1 = (temp1*temp1)*temp1;
	myComplex temp2(1);
	return temp1-temp2;
}

myComplex pp(myComplex x)
{
	myComplex temp1(x.getReal(), x.getImaginary());
	temp1 = temp1*temp1;
	myComplex temp2(3);
	return temp2*temp1;
}

double newtonsIteration(myComplex z)
{
	double i;
	for (i = 0; i <= 200; ++i)
	{
		myComplex temp = p(z)/pp(z);
		double val = temp.getMagnitude();
		if(abs(val) < 0.0001)
			break;
		z = z - temp;
	}
	return i;
}

int main(int argc, char* argv[]){
  // Fill me in!
	string filename = "fractal.png";
	if(argc >= 2){
		filename = argv[1];
	}

	// Default Image size
	int width  = 800;
	int height = 600;

	if(argc >= 3){  // Width was given
		width = atoi(argv[2]);
	}
	if(argc >= 4){  // Height was given
		height = atoi(argv[3]);
	}
	int scale = 7;
	int arr[3];
  	cil::CImg<unsigned char> image(width,height,1, 3, 255); 
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			double real = (double)x- width/2;
			double complex = (double)y- height/2;
			myComplex z0(real, complex);
			int brightness = newtonsIteration(z0); 
			for(int k=0;k<3;k++)
				arr[k] = 0;
			arr[brightness%3] = brightness;
			for(int k=0;k<3;k++)
				arr[k] *= scale;
			setRGB(x,y,arr[0],arr[1],arr[2],image);
		}
	} 

	cout << "Saving: " << filename << " Width: " << width;
	cout << " Height: " << height << endl;
	// Saves the image
	image.save(filename.c_str());
  return 0;
}
