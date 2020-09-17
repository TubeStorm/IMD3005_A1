#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundColor(0, 0, 0);


    //to load in an image
    m_backgroundImage.load("background.png");
    m_sunImage.load("sun.png");
    m_earthImage.load("earth.png");
    m_jupiterImage.load("jupiter.png");
    m_marsImage.load("mars.png");
    m_neptuneImage.load("neptune.png");
    m_uranusImage.load("uranus.png");
    m_moonEarthImage.load("moon-earth.png");
    m_moonUranusImage.load("moon-uranus.png");
    m_moonUranus2Image.load("moon-uranus.png");
    m_astronutImage.load("astronut.png");
    m_alarmImage.load("alarm.png");
    m_spaceShipImage.load("spaceShip.png");
    m_cometImage.load("comet.png");
    


    
    //resize images
    m_sunImage.resize(300, 300);
    m_earthImage.resize(100, 100);
    m_jupiterImage.resize(150, 150);
    m_marsImage.resize(80, 78);
    m_neptuneImage.resize(250, 250);
    m_uranusImage.resize(260, 260);
    m_moonEarthImage.resize(150, 150);
    m_moonUranusImage.resize(200, 200);
    m_moonUranus2Image.resize(200, 200);
    m_cometImage.resize(50, 50);
    
    //set background size
    m_backgroundImage.setAnchorPoint(m_backgroundImage.getWidth() / 2, m_backgroundImage.getHeight() / 2);
    m_backgroundPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    
    //set comet size
    m_cometImage.setAnchorPoint(m_cometImage.getWidth() / 2, m_cometImage.getHeight() / 2);
    m_cometPos = ofVec2f(1000, 0);
    
   
    //change anchor point to the middle of the sun image
    m_sunImage.setAnchorPoint(m_sunImage.getWidth() / 2, m_sunImage.getHeight() / 2);
    //m_sunAngle = 0.0f;
    m_sunPos = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    

    //earth anchor point
    m_earthImage.setAnchorPoint(m_earthImage.getWidth() / 2, m_earthImage.getHeight() / 2);
    m_earthPos = ofVec2f(200, 0);

     //mars anchor point
    m_marsImage.setAnchorPoint(m_marsImage.getWidth() / 2, m_marsImage.getHeight() / 2);
    m_marsPos = ofVec2f(300, 0);
    
    //jupiter anchor point
    m_jupiterImage.setAnchorPoint(m_jupiterImage.getWidth() / 2, m_jupiterImage.getHeight() / 2);
    m_jupiterPos = ofVec2f(360, 0);

    //uranus anchor point
    m_uranusImage.setAnchorPoint(m_uranusImage.getWidth() / 2, m_uranusImage.getHeight() / 2);
    m_uranusPos = ofVec2f(350, 0);
    
    //neptune anchor point
    m_neptuneImage.setAnchorPoint(m_neptuneImage.getWidth() / 2, m_neptuneImage.getHeight() / 2);
    m_neptunePos = ofVec2f(440, 0);

    //moonEarth anchor point
    m_moonEarthImage.setAnchorPoint(m_moonEarthImage.getWidth() / 2, m_moonEarthImage.getHeight() / 2);
    m_moonEarthPos = ofVec2f(200, 0);

    //moonUranus 1 & 2 anchor points
    m_moonUranusImage.setAnchorPoint(m_moonUranusImage.getWidth() / 2, m_moonUranusImage.getHeight() / 2);
    m_moonUranusPos = ofVec2f(250, 0);

    m_moonUranus2Image.setAnchorPoint(m_moonUranus2Image.getWidth() / 2, m_moonUranus2Image.getHeight() / 2);
    m_moonUranus2Pos = ofVec2f(400, 0);

    //astronut anchor point
    m_astronutImage.setAnchorPoint(m_astronutImage.getWidth() / 2, m_astronutImage.getHeight() / 2);
    m_astronutPos = ofVec2f(ofGetWindowWidth() / 3, 0);

    //spaceShip anchor point
    m_spaceShipImage.setAnchorPoint(0, 0);
   // m_spaceShipPos = ofVec2f(230, 0);

    //alarm anchor point
    m_alarmImage.setAnchorPoint(0, 0);
    //m_alarmPos = ofVec2f(230, 0);



    m_mousePos = ofVec2f::zero(); //ofVec2f(0,0)
    m_targetPos = ofVec2f(0, 0);

}

//--------------------------------------------------------------
void ofApp::update() {

    //get vector pointing to mouse from astronut
    m_mousePos = ofVec2f((float)ofGetMouseX(), (float)ofGetMouseY());
    ofVec2f astronautToMouse = m_mousePos - m_astronutPos;

    //adjust rotation speed [+ TO MOVE CLOCKWISE/ - TO MOVE ANTI-CLOCKWISE]
    m_sunAngle += -0.1f;
    m_earthAngle += -0.7f;
    m_marsAngle += -0.6f;
    m_jupiterAngle += -0.4f;
    m_uranusAngle += -0.2f;
    m_neptuneAngle += -0.08f;
    m_moonEarthAngle += 6.0f;
    m_moonUranusAngle += -3.0f;
    m_moonUranus2Angle += -0.8f;
    
    //make comet appear with mouse position
    if(m_mousePos == m_mousePos){
    m_cometPos.y += 10;
    m_cometPos.x -= 10;
    if((ofGetWindowHeight() < m_cometPos.y)){
        m_cometPos = m_targetPos;
    }
    }

    //get rotation of vector using atan2
    m_astronutAngle = (ofRadToDeg(atan2(astronautToMouse.x, astronautToMouse.y)) * -0.6f) + 90.0f;

    //lerp astronaut position
    m_astronutPos.x = lerp(m_astronutPos.x, m_targetPos.x, 0.01f);
    m_astronutPos.y = lerp(m_astronutPos.y, m_targetPos.y, 0.01f);

    //lerp alarm position
    m_alarmPos.x = lerp(m_alarmPos.x, (m_astronutPos + 50).x, 0.06f);
    m_alarmPos.y = lerp(m_alarmPos.y, (m_astronutPos - 10).y, 0.06f);

    //lerp spaceship position
    m_spaceShipPos.x = lerp(m_spaceShipPos.x, (m_alarmPos + 50).x, 0.03f);
    m_spaceShipPos.y = lerp(m_spaceShipPos.y, (m_alarmPos - 20).y, 0.03f);
   
    //control the spacing between lerping objects
    if (m_alarmPos == m_astronutPos){
        m_astronutImage.load("alarm.png");
        m_alarmPos.x += 10;
    }
    else{
        m_astronutImage.load("astronut.png");
    }
}
//--------------------------------------------------------------
void ofApp::draw() {
    //Background
    ofPushMatrix();
    ofTranslate(m_backgroundPos);
    ofScale(2, 2);
    m_backgroundImage.draw(0, 0);
    ofPopMatrix();
    
    //transform for comet
    ofPushMatrix();
    ofTranslate(m_cometPos);
    m_cometImage.draw(0, 0);
    ofPopMatrix();

    
    //transform for sun
    ofPushMatrix();
    ofTranslate(m_sunPos);
    ofRotate(m_sunAngle);
    ofScale(0.4, 0.4);
    m_sunImage.draw(0, 0);
    ofPopMatrix();

    //transform for earth
    ofPushMatrix();
    ofTranslate(m_sunPos);
    ofRotate(m_earthAngle);
    ofTranslate(m_earthPos);
    ofRotate(m_earthAngle * 1.0f);
    ofScale(0.3, 0.3);
    m_earthImage.draw(0, 0);

    ofPushMatrix();
    ofRotate(m_moonEarthAngle * 1.0f);
    ofTranslate(m_moonEarthPos);
    ofScale(0.3, 0.3);
    m_moonEarthImage.draw(0, 0);
    ofPopMatrix();
    ofPopMatrix();

    //transform for mars
    ofPushMatrix();
    ofTranslate(m_sunPos);
    ofRotate(m_marsAngle);
    ofTranslate(m_marsPos);
    ofRotate(m_marsAngle * 1.0f);
    ofScale(0.3, 0.3);
    m_marsImage.draw(0, 0);
    ofPopMatrix();

    //transform for jupiter
    ofPushMatrix();
    ofTranslate(m_sunPos);
    ofRotate(m_jupiterAngle);
    ofTranslate(m_jupiterPos);
    ofRotate(m_jupiterAngle * 1.0f);
    ofScale(0.3, 0.3);
    m_jupiterImage.draw(0, 0);
    ofPopMatrix();

    //transform for uranus
    ofPushMatrix();
    ofTranslate(m_sunPos);
    ofRotate(m_uranusAngle);
    ofTranslate(m_uranusPos);
    ofRotate(m_uranusAngle * 1.0f);
    ofScale(0.3, 0.3);
    m_uranusImage.draw(0, 0);

    //moon1
    ofPushMatrix();
    ofRotate(m_moonUranusAngle-100 * 1.0f);
    ofTranslate(m_moonUranusPos);
    ofRotate(m_moonUranus2Angle * 1.0f);
    ofTranslate(m_moonUranus2Pos);
    ofScale(0.3, 0.3);
    m_moonUranusImage.draw(0, 0);
    ofPopMatrix();

    //moon2
    ofPushMatrix();
    ofRotate(m_moonUranus2Angle * 1.0f);
    ofTranslate(m_moonUranus2Pos);
    ofScale(0.3, 0.3);
    m_moonUranus2Image.draw(0, 0);
    ofPopMatrix();

    ofPopMatrix();

    //transform for neptune
    ofPushMatrix();
    ofTranslate(m_sunPos);
    ofRotate(m_neptuneAngle);
    ofTranslate(m_neptunePos);
    ofRotate(m_neptuneAngle * 1.0f);
    ofScale(0.3, 0.3);
    m_neptuneImage.draw(0, 0);
    ofPopMatrix();

    //transform for astronaut
    ofPushMatrix();
    ofTranslate(m_astronutPos);
    ofRotate(m_astronutAngle);
    ofScale(0.3f, 0.3f);
    
    //have astronaut flip when mouse clicks
     if (m_targetPos.x > m_astronutPos.x){
         m_astronutImage.mirror(0,1);
         
     }
     else{
         m_astronutImage.mirror(0,0);
     }
    
    
    m_astronutImage.draw(0, 0);
    ofPopMatrix();

    //transform for spaceship
    ofPushMatrix();
    ofTranslate(m_spaceShipPos);
    ofRotate(m_spaceShipAngle);
    ofScale(0.4f, 0.4f);
    m_spaceShipImage.draw(0, 0);
    ofPopMatrix();

  //transform for alarms
    ofPushMatrix();
    ofTranslate(m_alarmPos);
    ofRotate(m_alarmAngle);
    ofScale(0.06f, 0.06);
    m_alarmImage.draw(0, 0);
    ofPopMatrix();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    m_targetPos.x = (float)x;
    m_targetPos.y = (float)y;

}

float ofApp::lerp(float start, float end, float percent)
{
    //cout << "hello" << endl;
    return (start + percent * (end - start));
}















