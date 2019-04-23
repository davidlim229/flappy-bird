#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	background.load("background.png");
	fly_sound_.load("fly.mp3");
	bird = Bird();
	pipe = Pipe();
	ofSetFrameRate(100);
	ofSetVerticalSync(true);
	game_state_ = IN_PROGRESS;
}


//--------------------------------------------------------------
void ofApp::update(){
	if (game_state_ == IN_PROGRESS) {
		bird.Move();
		pipe.Update();

		if (pipe.GetPosition().x < -130) {
			pipe = Pipe();
		}
		if (bird.BirdIsDead(pipe)) {
			game_state_ = GAME_OVER;
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw() {
	background.draw(0, 0, ofGetWidth() + 20, ofGetHeight() + 20);
	if (game_state_ == IN_PROGRESS) {
		DrawBird();
		DrawPipe();
	}
}

// Draws Bird
void ofApp::DrawBird() {
	ofVec2f bird_pos = bird.GetPosition();
	bird.GetSprite().draw(bird_pos.x, bird_pos.y, 200, 200);
}

// Draws Pipe
void ofApp::DrawPipe() {
	ofImage bottom = pipe.GetSprite();
	ofImage top = pipe.GetSprite();
	top.rotate90(2);
	bottom.draw(pipe.GetPosition().x, pipe.GetPosition().y, pipe.GetSize().x, pipe.GetSize().y);
	top.draw(pipe.GetPosition().x, 0, pipe.GetSize().x, ofGetHeight() - pipe.GetSize().y - ofGetWindowHeight() * 0.35);
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
