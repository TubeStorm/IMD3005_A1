#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    //to create an image variable
    ofImage m_backgroundImage;
    ofImage m_sunImage;
    ofImage m_earthImage;
    ofImage m_jupiterImage;
    ofImage m_marsImage;
    ofImage m_neptuneImage;
    ofImage m_uranusImage;
    ofImage m_moonEarthImage;
    ofImage m_moonUranusImage;
    ofImage m_moonUranus2Image;
    ofImage m_astronutImage;
    ofImage m_spaceShipImage;
    ofImage m_alarmImage;
    ofImage m_cometImage;

    //to create angle and pos variables
    ofVec2f m_backgroundPos;

    float m_sunAngle;
    ofVec2f m_sunPos;

    float m_earthAngle;
    ofVec2f m_earthPos;

    float m_jupiterAngle;
    ofVec2f m_jupiterPos;

    float m_marsAngle;
    ofVec2f m_marsPos;

    float m_neptuneAngle;
    ofVec2f m_neptunePos;

    float m_uranusAngle;
    ofVec2f m_uranusPos;

    float m_moonEarthAngle;
    ofVec2f m_moonEarthPos;

    float m_moonUranusAngle;
    ofVec2f m_moonUranusPos;

    float m_moonUranus2Angle;
    ofVec2f m_moonUranus2Pos;

    float m_astronutAngle;
    ofVec2f m_astronutPos;

    float m_spaceShipAngle;
    ofVec2f m_spaceShipPos;

    float m_alarmAngle;
    ofVec2f m_alarmPos;
    
    ofVec2f m_cometPos;

    //to create an mouse variable
    ofVec2f m_mousePos;

    //to create an target variable
    ofVec2f m_targetPos; //saving where mouse was clicked

    //to create an lerping with mouse pos
    void mousePressed(int x, int y, int button);
    float lerp(float start, float end, float percent);

    bool vertical;
    bool horizontal;




    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
