#include "pipe.h"

Pipe::Pipe() {
	sprite.load("pipe.png");
	srand(time(nullptr));
	double height = ofGetWindowHeight() * (0.15 + ((double)(rand() % 50)) / 100);
	size.set(200, height);
	position.set(ofGetWindowWidth(), ofGetWindowHeight() - height);
}

ofImage Pipe::GetSprite() const {
	return sprite;
}

ofVec2f Pipe::GetSize() const {
	return size;

}

ofVec2f Pipe::GetPosition() const {
	return position;
}

void Pipe::Update() {
	position.set(position.x - 60, position.y);
 }