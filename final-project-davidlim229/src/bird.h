#pragma once

#include "ofMain.h"
#include "pipe.h"

enum BirdDirection {
	UP,
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

	// Setter for position, used for testing purposes
	void SetPosition(ofVec2f coordinates);

	// Getter for position
	ofVec2f GetPosition() const;

	// Getter for current direction
	BirdDirection GetDirection() const;

	// Updates the bird to move depending on what direction it is going
	void Move();

	// Resets bird position to starting
	void Reset();

	// Sets the new direction of the bird
	void SetDirection(BirdDirection new_direction);

	// Returns true if the bird died (hit an obstacle or went out of the screen)
	bool BirdIsDead(Pipe pipe);

	// Returns true if the bird went over the pipe and scored a point
	bool Score(Pipe pipe);
};
