#pragma once

#include "ofMain.h"
#include "bird.h"
#include "pipe.h"

class ofApp : public ofBaseApp{
	
	enum GameState {
		START,
		IN_PROGRESS,
		GAME_OVER
	};
	
	GameState game_state_;
	Bird bird;
	Pipe pipe;
	ofImage background;
	ofSoundPlayer background_music_;
	ofSoundPlayer fly_sound_;
	ofSoundPlayer coin_sound_;
	ofTrueTypeFont font;
	int score;

	void DrawBird();
	void DrawPipe();

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
