#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	fly_sound_.load("fly.mp3");
	bird = Bird();
}

// Draws Bird
void ofApp::DrawBird() {
	ofVec2f bird_pos = bird.GetPosition();
	bird.GetSprite().draw(bird_pos.x, bird_pos.y, 70, 70);
}

//--------------------------------------------------------------
void ofApp::update(){
	bird.Move();
}

//--------------------------------------------------------------
void ofApp::draw(){
	DrawBird();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'u') {
		bird.SetDirection(UP);
		fly_sound_.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'u') {
		bird.SetDirection(DOWN);
	}
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
