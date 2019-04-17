#pragma once

#include "ofMain.h";
enum BirdDirection {
	UP = 0,
	DOWN
};

// Class that will represent the bird
class Bird {
private:
	// The position of the bird in (x, y) coordinates
	ofVec2f position;

	// The image that represents the bird
	ofImage sprite;

	// The direction that the bird is going at the moment
	BirdDirection direction;

public:
	// Default constructor that initializes the bird's position
	Bird();

	// Getter for bird sprite
	ofImage GetSprite() const;

	// Getter for position
	ofVec2f GetPosition() const;

	// Getter for current direction
	BirdDirection GetDirection() const;

	// Updates the bird to move depending on what direction it is going
	void Move();

	// Sets the new direction of the bird
	void SetDirection(BirdDirection new_direction);
};
