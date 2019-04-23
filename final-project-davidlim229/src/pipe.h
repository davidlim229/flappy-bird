#include "ofMain.h"
#pragma once

class Pipe {
private:
	ofImage sprite;
	ofVec2f size;
	ofVec2f position;

public:
	Pipe();
	ofImage GetSprite() const;
	ofVec2f GetSize() const;
	ofVec2f GetPosition() const;
	void Update();
};