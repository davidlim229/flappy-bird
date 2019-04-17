#define CATCH_CONFIG_MAIN

#include "ofMain.h"
#include "bird.h"
#include "catch.hpp"

TEST_CASE("Bird Default Constructor") {
	ofSetupOpenGL(1024, 768, OF_WINDOW);
	Bird bird;
	REQUIRE(bird.GetDirection() == DOWN);
}

TEST_CASE("Move") {
	ofSetupOpenGL(1024, 768, OF_WINDOW);
	Bird bird;
	SECTION("Down") {
		bird.Move();
		REQUIRE(bird.GetPosition().y == ofGetWindowHeight() / 3 + 20);
	}
	SECTION("UP") {
		bird.SetDirection(UP);
		bird.Move();
		REQUIRE(bird.GetPosition().y == ofGetWindowHeight() / 3 - 30);
	}
}

