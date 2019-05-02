//#define CATCH_CONFIG_MAIN
//
//#include "ofMain.h"
//#include "bird.h"
//#include "catch.hpp"
//
//TEST_CASE("Bird Default Constructor") {
//	ofSetupOpenGL(1024, 768, OF_WINDOW);
//	Bird bird;
//	REQUIRE(bird.GetDirection() == DOWN);
//}
//
//TEST_CASE("Bird Move") {
//	ofSetupOpenGL(1024, 768, OF_WINDOW);
//	Bird bird;
//	SECTION("Down") {
//		bird.Move();
//		REQUIRE(bird.GetPosition().y == ofGetWindowHeight() / 2 + 90);
//	}
//	SECTION("UP") {
//		bird.SetDirection(UP);
//		bird.Move();
//		REQUIRE(bird.GetPosition().y == ofGetWindowHeight() / 2 - 130);
//	}
//}
//
//TEST_CASE("BirdIsDead") {
//	Bird bird;
//	Pipe pipe;
//	SECTION("Dead") {
//		bird.SetPosition(ofVec2f(pipe.GetPosition().x, pipe.GetPosition().y));
//		REQUIRE(bird.BirdIsDead(pipe) == true);
//	}
//	SECTION("Alive") {
//		REQUIRE(bird.BirdIsDead(pipe) == false);
//	}
//}
//
//TEST_CASE("Pipe Moving") {
//	ofSetupOpenGL(1024, 768, OF_WINDOW);
//	Pipe pipe;
//	pipe.Update();
//	REQUIRE(pipe.GetPosition().x == ofGetWindowWidth() - 60);
//}