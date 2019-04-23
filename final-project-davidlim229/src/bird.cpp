#include "bird.h"

Bird::Bird() {
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
		position.set(position.x, position.y - 120);
	}
	else {
		position.set(position.x, position.y + 70);
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