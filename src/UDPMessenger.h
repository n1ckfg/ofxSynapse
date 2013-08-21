/*
 *  UDPMessenger.h
 *  emptyExample
 *
 *  Created by Ryan Challinor on 5/17/11.
 *  Copyright 2011 aww bees. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define SEND_PORT 7110
#define SEND_PORT2 12347
#define RECEIVE_PORT 12346
#define USE_TWO_OSC_PORTS   0  //make 1 to enable two ports


class IMessageReceiver
{
public:
    virtual void OnMessage(const ofxOscMessage& msg) = 0;
};

struct Listener
{
    IMessageReceiver* mReceiver;
    string mLabel;
};

class UDPMessenger
{
public:
    UDPMessenger();
    ~UDPMessenger();

    void Poll();

    void SendFloatMessage(string label, float val);
    void SendIntMessage(string label, int val);
    void SendStringMessage(string label, string val);
    void Send3DVectorMessage(string label, string name, ofVec3f val);
    void Send2DVectorMessage(string label, string name, ofVec2f val);

    void AddListener(IMessageReceiver* receiver, string label);
    void RemoveListener(IMessageReceiver* receiver);
    void RemoveListener(IMessageReceiver* receiver, string label);

private:
    ofxOscSender mSender;
    ofxOscSender mSender2;
    ofxOscReceiver mReceiver;

    std::list<Listener> mListeners;
};

extern UDPMessenger* TheMessenger;
