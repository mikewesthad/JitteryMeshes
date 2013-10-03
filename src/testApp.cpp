#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    icoSphere.setRadius(300);
    icoSphere.setResolution(3);
    icoSphere.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    icoSphere.enableColors();
    mesh = icoSphere.getMesh();

    // Add colors so that they can then be modified (otherwise, error)
    //  NOTE: This has to happen before doing all the vertex stuff...
    mesh.addColor((255,255,255));

    numVertices = mesh.getNumVertices();
    vector<int> vertexIndicesToCheck;
    for (int i=0; i<numVertices; i++) vertexIndicesToCheck.push_back(i);

    while (vertexIndicesToCheck.size() > 0) {
        // Clear the vector that is going to hold all copies of a vertex
        vector<int> vertexIndices;
        vector<int> indicesToRemove;

        // Pick a vertex and add it to the vector
        int vertexIndex = vertexIndicesToCheck[0];
        ofVec3f vertex = mesh.getVertex(vertexIndex);
        vertexIndices.push_back(vertexIndex);
        indicesToRemove.push_back(0);

        // Loop through the remaining vertices to find all copies of the vertex
        //  NOTE: start at the second element because the first element is the
        //        original vertex
        for (int i=1; i<vertexIndicesToCheck.size(); i++) {
            int vertexCopyIndex = vertexIndicesToCheck[i];
            ofVec3f vertexCopy = mesh.getVertex(vertexCopyIndex);
            if (vertex == vertexCopy) {
                vertexIndices.push_back(vertexCopyIndex);
                indicesToRemove.push_back(i);
            }
        }

        // Remove the copies from further checks
        //  NOTE: Remove elements in descending order so that deleteing one
        //  will not change the index of other elements to be deleted
        for (int i=indicesToRemove.size()-1; i>-1; i--) {
            vertexIndicesToCheck.erase(vertexIndicesToCheck.begin()+indicesToRemove[i]);
        }

        uniqueVerticesIndices.push_back(vertexIndices);
    }

    numUniqueVertices = uniqueVerticesIndices.size();
    cout << "Number Original Vertices " << numVertices << endl;
    cout << "Number Vertices Without Copies " << numUniqueVertices << endl;


    // Color all 'copies' of vertices with a random red
    for (int a=0; a<uniqueVerticesIndices.size(); a++) {
        ofColor c = ofColor(ofRandom(255), 0, 0);
        vector<int> vertexCopyIndices = uniqueVerticesIndices[a];
        for (int b=0; b<vertexCopyIndices.size(); b++) {
            mesh.setColor(vertexCopyIndices[b], c);
        }
    }



    for (int i=0; i<uniqueVerticesIndices.size(); i++) {
        phase.push_back(ofRandom(360));
        speed.push_back(ofRandom(10, 360));
        amplitude.push_back(ofRandom(10, 100));
        originalUniqueVertexLocations.push_back(mesh.getVertex(uniqueVerticesIndices[i][0]));
    }


}


void testApp::printVector(vector <int> v) {
    for (int i=0; i<v.size(); i++) cout << v[i] << endl;
    cout << endl;
}

//--------------------------------------------------------------
void testApp::update(){
    float t = ofGetElapsedTimef();
//    int uniqueIndex = 0;
//
//    vector<int> vertexCopyIndices = uniqueVerticesIndices[uniqueIndex];
//    for (int i=0; i<vertexCopyIndices.size(); i++) {
//        int index = vertexCopyIndices[i];
//        ofVec3f v = mesh.getVertex(index);
//        ofVec3f n = mesh.getNormal(index);
//        mesh.setVertex(index, v+sin(t*ofDegToRad(180))*n);
//    }

    for (int a=0; a<uniqueVerticesIndices.size(); a++) {
//    for (int a=0; a<5; a++) {

        vector<int> vertexCopyIndices = uniqueVerticesIndices[a];
        int originalIndex = vertexCopyIndices[0];
        float s = speed[a];
        float p = phase[a];
        float amp = amplitude[a];
        ofVec3f originalVertexLocation = originalUniqueVertexLocations[a];
        ofVec3f vertexNormal = mesh.getNormal(originalIndex).getNormalized();

        int scaleFactor = amp*sin(ofDegToRad(t*s+p));
        ofVec3f newPos = originalVertexLocation + scaleFactor*vertexNormal;

        for (int b=0; b<vertexCopyIndices.size(); b++) {
            mesh.setVertex(vertexCopyIndices[b], newPos);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateX(xrotation);
        ofRotateY(yrotation);
        mesh.drawWireframe();
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    // Swap the x and y mouse movements for a more intuitive feel
    xrotation = ofMap(y, 0, ofGetHeight(), 0, 360, true);
    yrotation = ofMap(x, 0, ofGetWidth(), 0, 360, true);


}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
