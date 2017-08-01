#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // We load an image from our "data" folder into the ofImage:
    
    myImage.load("one.jpg");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);

    // Set capture dimensions of 320x240, a common video size.
    camWidth = 320;
    camHeight = 240;
    
    // Open an ofVideoGrabber for the default camera
    myVideoGrabber.setDeviceID(1);
    myVideoGrabber.initGrabber (camWidth,camHeight);
    
    // Create resources to store and display another copy of the data
    invertedVideoData = new unsigned char [camWidth * camHeight * 3];
    myTexture.allocate (camWidth,camHeight, GL_RGB);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Ask the grabber to refresh its data.
    myVideoGrabber.update();
    
    // If the grabber indeed has fresh data,
    if(myVideoGrabber.isFrameNew()){
        
        // Obtain a pointer to the grabber's image data.
        ofPixels pixelData = myVideoGrabber.getPixels();
        
        // Reckon the total number of bytes to examine.
        // This is the image's width times its height,
        // times 3 -- because each pixel requires 3 bytes
        // to store its R, G, and B color components.
        int nTotalBytes = camWidth * camHeight * 3;
        
        // For every byte of the RGB image data,
        for(int i=0; i<nTotalBytes; i++){
            
            // pixelData[i] is the i'th byte of the image;
            // subtract it from 255, to make a "photo negative"
            invertedVideoData[i] = 255 - pixelData[i];
        }
        
        // Now stash the inverted data in an ofTexture
        myTexture.loadData (invertedVideoData, camWidth,camHeight, GL_RGB);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    
    // We fetch the ofImage's dimensions and display it 10x larger.
    int imgWidth = myImage.getWidth();
    int imgHeight = myImage.getHeight();
    myImage.draw(0, 0, imgWidth, imgHeight);

    
    // Draw the grabber, and next to it, the "negative" ofTexture.
    myVideoGrabber.draw(10,10);
    myTexture.draw(340, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
