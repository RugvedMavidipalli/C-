/*    @file image.cpp    
      @author <-- Fill in your name here -->
      @date <-- Fill this in -->
*/
// Example of generating and saving a PNG image.
#include <iostream>
#include <stdlib.h>
#include <sstream>

// Import the CImg Library
// http://cimg.eu/reference/index.html
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

int main(int argc, char* argv[]){
  // We accept 3 command-line paramters, filename, x and y
  // If no paramters are given, it will save a 800x600 image 
  // to image.png
  
  string filename = "image.png";
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
  
  // The image will be from -100 to +100 in both axes and scaled to
  // fit the requested image size.
  double urr = 100.0; // UpperRightReal (x)
  double uri = 100.0; // UpperRightImaginary (y)
  
  double llr = -100.0;
  double lli = -100.0;
 
  double dx = (urr-llr) / (double)width;
  double dy = (uri-lli) / (double)height;
  
  // Setup the image in CImg
  cil::CImg<unsigned char> image(width,height,1, 3, 255); 
  for(int x = 0; x < width; x++){
    for(int y = 0; y < height; y++){
      // Calculate where in the complex plane this point is
      double real = (double)x * dx + llr;
      double complex = (double)y * dy * -1 + uri;
      // Now real and complex will be x and y from -100 to +100
      
      // For this example, just do a fade.
      // There are 3 channels, R,G,B  which you can assign to.
      // Each channel takes a single byte 0-255
      
      setRGB(x,y,
             (int)real % 256, 
             (int)(real * complex / 4) % 256,
             (int)complex % 256,
             image);
    }
  } 
  
  // save the image
  cout << "Saving: " << filename << " Width: " << width;
  cout << " Height: " << height << endl;
  // Saves the image
  image.save(filename.c_str());
  
  return 0;
}
