#include "bird.h"

Bird::Bird() {
	position.set(ofGetWindowWidth() / 4, ofGetWindowHeight() / 2);
	direction = DOWN;
	sprite.load("bird.png");
}

void Bird::Reset() {
	position.set(ofGetWindowWidth() / 4, ofGetWindowHeight() / 2);
	direction = DOWN;
	sprite.load("bird.png");
}

ofVec2f Bird::GetPosition() const {
	return position;
}

BirdDirection Bird::GetDirection() const {
	return direction;
}

ofImage Bird::GetSprite() const {
	return sprite;
}

void Bird::Move() {
	if (direction == UP) {
		position.set(position.x, position.y - 130);
	}
	else {
		position.set(position.x, position.y + 90);
	}
}

void Bird::SetDirection(BirdDirection new_direction) {
	if (new_direction == UP) {
		sprite.load("bird_up.png");
	}
	else {
		sprite.load("bird.png");
	}
	direction = new_direction;
}

bool Bird::BirdIsDead(Pipe pipe) {
	if (position.y < 0 || position.y > ofGetWindowHeight() - 50) {
		return true;
	}
	ofRectangle bird_rectangle(position.x + 5, position.y + 5, 200, 200);
	ofRectangle bottom(pipe.GetPosition().x, pipe.GetPosition().y, pipe.GetSize().x, pipe.GetSize().y);
	ofRectangle top(pipe.GetPosition().x, 0, pipe.GetSize().x, ofGetHeight() - pipe.GetSize().y - ofGetWindowHeight() * 0.35);

	if (bottom.intersects(bird_rectangle) || top.intersects(bird_rectangle)) {
		return true;
	}
	return false;
}

bool Bird::Score(Pipe pipe) {
	return position.x == pipe.GetPosition().x;
}