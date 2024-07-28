#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);


	int width = 200;
	int height = 200;
	int len = 15;
	for (int z = -200; z <= 200; z += 20) {

		ofPushMatrix();
		ofTranslate(0, 0, z);
		ofRotate(ofMap(ofNoise((z + 300) * 0.001 + ofGetFrameNum() * 0.02), 0, 1, -360, 360));

		ofFill();
		ofSetColor(39);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
		ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.25 + len, height * -0.25 + len));
		ofVertex(glm::vec2(width * 0.25 - len, height * -0.25 + len));
		ofVertex(glm::vec2(width * 0.25 - len, height * 0.25 - len));
		ofVertex(glm::vec2(width * -0.25 + len, height * 0.25 - len));

		ofEndShape(true);

		ofNoFill();
		ofSetColor(239);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
		ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
		ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.25 + len, height * -0.25 + len));
		ofVertex(glm::vec2(width * 0.25 - len, height * -0.25 + len));
		ofVertex(glm::vec2(width * 0.25 - len, height * 0.25 - len));
		ofVertex(glm::vec2(width * -0.25 + len, height * 0.25 - len));

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 125;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}