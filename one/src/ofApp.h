#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        // declare an ofImage:
        ofImage myImage;
    
        // declare an ofVideoGrabber:
        ofVideoGrabber myVideoGrabber;
    
        // frames to display
        ofTexture myTexture;
    
        // invertedVideoData
        unsigned char* invertedVideoData;
        int camWidth;
        int camHeight;
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
		
};
