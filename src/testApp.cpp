#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
    ofSetFrameRate(60);
	ofSetLogLevel(OF_LOG_VERBOSE);
	midiInput = "virtualLightArray";
	midiIn.openVirtualPort(midiInput);
    midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
    
    //create the socket and set to send to 127.0.0.1:11999
    //string ipAddress = "127.0.0.1";
    string bCastIPAddress = "142.104.211.255";
	udpConnection.Create();
    //udpConnection.ConnectMcast(const_cast<char*>(mCastIPAddress.c_str()), 11999);
	//udpConnection.Connect(ipAddress.c_str(),11999);
    udpConnection.Connect(bCastIPAddress.c_str(),11999);
	udpConnection.SetNonBlocking(true);
    udpConnection.SetEnableBroadcast(true);
    val = 0;
}

//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(0);
    
//    if (val == 127) {
//        val = 0;
//    }
//    else {
//        val++;
//    }
    //string message="";
    if (ofToString(midiMessage.control) == "41") {
       val = midiMessage.value; 
    }
    string message=ofToString(val);
	int sent = udpConnection.Send(message.c_str(),message.length());

	
    ofDrawBitmapString(ofToString("MIDI input: ")+ofToString(midiInput), 20, 20);
	ofDrawBitmapString(ofToString("Current value: ")+ofToString(val), 20, 40);
	text.str(""); // clear
}

//--------------------------------------------------------------
void testApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg) {

	// make a copy of the latest message
	midiMessage = msg;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

	switch(key) {
		case 'l':
			midiIn.listPorts();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mouseReleased() {
}
