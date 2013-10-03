#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void printVector(vector <int> v);

		ofIcoSpherePrimitive icoSphere;
		ofMesh mesh;

		float xrotation = 0;
		float yrotation = 0;
		float zrotation = 0;

        int numVertices;
		int numUniqueVertices;
		std::vector< vector<int> > uniqueVerticesIndices;

		std::vector< float > phase;
		std::vector< float > speed;
		std::vector< float > amplitude;

		std::vector< ofVec3f > originalUniqueVertexLocations;

};
