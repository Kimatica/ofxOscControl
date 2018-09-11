//
//  ofxOscControl.hpp
//  lightFixtures-osc
//
//  Created by Nestor Rubio Garcia on 26/04/2018.
//

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxGui.h"

class ofxOscControl {
    
public:
    ofxOscControl();
    
    void setup(int localPort);
    
    void update();
    
    void addParameterGroup(ofParameterGroup *parameters);
    
    // usefull to expose all available addresses to external apps (eg: osculator)
    void sendAllParameters();
    
    int getLocalPort();
    
    void onSendHostInfo();
    void setRemoteHostName(string hostName);
    void setRemotePort(string port);
    
private:
    ofxOscReceiver receiver;
    
    vector<ofAbstractParameter*> groups;
    ofAbstractParameter* getGroupByName(const string &name);
    
    void processMessagesIn();
    
    int localPort;
    int remotePort;
    string remoteHostName;
};
