#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	score = 0;
	game_state_ = START;
	//background_music_.load("background_music.mp3");
	//background_music_.play();
	background.load("start.jpg");
	ofSetWindowTitle("Flappy Bird");
	fly_sound_.load("fly.mp3");
	coin_sound_.load("coin.mp3");
	bird = Bird();
	pipe = Pipe();
	ofSetFrameRate(70);
	ofSetVerticalSync(true);
	font.load("OpenSans-Regular.ttf", 80);
}
 
//--------------------------------------------------------------
void ofApp::update(){
	if (game_state_ == IN_PROGRESS) {
		background.load("background.png");
		bird.Move();
		pipe.Update();

		if (pipe.GetPosition().x < -130) {
			pipe = Pipe();
		}

		if (bird.BirdIsDead(pipe)) {
			game_state_ = GAME_OVER;
			background.load("end.jpg");
			score = 0;
		}
		
		if (bird.Score(pipe)) {
			score++;
			coin_sound_.play();
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw() {
	background.draw(0, 0, ofGetWidth() + 20, ofGetHeight() + 20);
	if (game_state_ == IN_PROGRESS) {
		ofSetColor(255, 255, 255);
		DrawBird();
		DrawPipe();
		font.drawString(to_string(score), 1500, 300);
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
	top.draw(pipe.GetPosition().x, 0, pipe.GetSize().x, ofGetHeight() - pipe.GetSize().y - ofGetWindowHeight() * 0.25);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		if (game_state_ == GAME_OVER || game_state_ == START) {
			background.load("background.png");
			pipe = Pipe();
			bird.Reset();
			game_state_ = IN_PROGRESS;
		}
		bird.SetDirection(UP);
		fly_sound_.play();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == ' ') {
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
