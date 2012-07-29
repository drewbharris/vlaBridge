#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxMidi.h"

class testApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	stringstream text;
    int val;
    
    ofxUDPManager udpConnection;
    
    string midiInput;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
};
