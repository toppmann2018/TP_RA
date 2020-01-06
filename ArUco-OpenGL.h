//
//  ArUco-OpenGL.h
//
//  Created by Jean-Marie Normand on 28/02/13.
//  Copyright (c) 2013 Centrale Nantes. All rights reserved.
//

#ifndef UserPerspectiveAR_ArUco_OpenGL_h
#define UserPerspectiveAR_ArUco_OpenGL_h

#include <iostream>

#include <fstream>
#include <sstream>
#ifdef __APPLE__
    #include <OPENGL/gl.h>
    #include <GLUT/glut.h>
#else
	#include <Windows.h>
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif
#include <aruco/aruco.h>
#include <chrono>

using namespace cv;
using namespace aruco;

class ArUco {
// Attributes
protected:
   // Intrinsics file for the camera
   string            m_IntrinsicFile;
   // Size of the marker (in meters)
   float             m_MarkerSize;
   // The Marker Detector
   MarkerDetector    m_PPDetector;
   
   // Vector of detected markers in the image
   vector<Marker>    m_Markers;
   
   // OpenCV matrices storing the images
   // Input Image
   Mat               m_InputImage;
   // Undistorted image
   Mat               m_UndInputImage;
   // Resized image
   Mat               m_ResizedImage;
   // Camera parameters
   CameraParameters  m_CameraParams;
   // Size of the OpenGL window size
   Size              m_GlWindowSize;
   
   // Test to read OpenGL framebuffer
   Mat               m_pixels;


   
// Methods
public:
   // Constructor
   ArUco(string intrinFileName, float markerSize);
   // Destructor
   ~ArUco();
   
   // Detect marker and draw things
   void  doWork(Mat inputImg);
   
   // Draw axis function
   void  drawAxis(float axisSize);
   
   // GLUT functionnalities
   
   // Drawing function
   void  drawScene(chrono::time_point<chrono::system_clock> start);
   
   // Idle function
   void  idle(Mat newImage);
   
   // Resize function
   void  resize(GLsizei iWidth, GLsizei iHeight);
   
   // Jim
   Mat   getPixels();
   
   void  setDesiredImageSize(Size desiredSize);
   void  setDesiredImageSize(int desiredWidth, int desiredHeight);
   
   // Test using ArUco to display a 3D cube in OpenCV
   void  draw3DCube(cv::Mat img, int markerInd=0);
   void  draw3DAxis(cv::Mat img, int markerInd=0);


};

typedef struct {
   float x;
   float y;
   float z;
} vertex;

// Cr�ation des sommets d'un perso
static vertex personnage[5]={
   {0.0f,0.0f,0.0f},
   {0.025,0.1f,0.025},
   {0.025,0.1f,-0.025},
   {-0.025,0.1f,-0.025},
   {-0.025,0.1f,0.025}
};

// Cr�ation des faces d'un perso
static int facePersonnage[4][3] ={
   {0,1,2},
   {0,2,3},
   {0,3,4},
   {0,4,1},
};

#endif
