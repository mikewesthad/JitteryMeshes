##Programming Graphics

Personal goals chapter:
* Explain the basics in a way so as to not lose anyone who is just picking up programming
* Explain one way for thinking about generating visuals algorithmically 
* Demonstrate some ways to get your work off of your computer and into the interwebs
* And [hopefully] include interesting things for those who are more advanced

####Section 1: Simple Graphics Loop
* __Intent:__ Get comfortable the update/draw, background and 'foregrounds'
* __Project:__ Drawing a simple shapes at the mouse position  
  * Explain XY pixel coordinate system
  * Clearing the screen using background
  * Circle/Rect/Ellipse/Line (and ofSetRectMode)
  * Fill and stroke concepts in openFrameworks
  * Drawing multiple shapes, drawing order
  * Turning off auto background and using transparency for trail effect 
    * If not covered in a previous chapter, effects of framerate


####Section 2: Procedural Colors
* __Intent:__ Explain ofColor and ways to explore colors procedurally
* __Project:__ Explore the HSB way of thinking by making color compositions 
  * Explain the ways color can be specified (grayscale, RGB, RGBA, HSB)
  * Using HSB dimensions to generate color palettes
    * Concept of recursion
    * Subdivide screen into smaller rectangles that change slowly along one of the HSB color dimensions
      * Examples in EvolvingColor_.png images
      * Code makes use of: ofRect, ofRectangle, ofRandom and std::vector
      * Using variables to define parameters 
        * Parameter searching interactively using mouseX, mouseY and key presses
* __Extension:__ Documenting your work (part 1)
  * Static work, saving an image (PNG or PDF)
    * Workarounds to make ofSaveScreen() work with ofSetBackgroundAuto(false) using ofImage
    * Saving images at a higher resolution than screen?
  * Moving work, saving a gif
    * Best for short animations, like here where we can show the process of the colors evolving in the recursion
    * Saving a series of images and compositing them 
    * Possibly a section on ofxGifEncoder
    * Tips for compression
  
####Section 3: Coordinate Systems Transformations
* __Intent:__ Explain power of moving coordinate system
* __Project:__ Trippy animated spiralling rectangles
  * Explain the 'moving the paper' analogy
  * Concept of repetition
  * Drawing expanding and sprialling rectangles using
    * Same rectangle code, ofRect(0, 0, w, h) 
    * Visual changes comes from ofRotate, ofScale, ofTranslate
    * Makes use of ofNoise for creating coherent rotation
  * Examples in CoordSystem_*.png images

####Section 4: Complex Shapes
  - Curve, beziers, and custom shape
  - Teach in the context of a project with generative visuals, like:
    - Cellular automata like Conway's Game of Life
    - Dynamic brushes
    - Using a movie or image to drive the creation of shapes
    - Haven't quite pinned down the project for this section
  - Documenting your work (part 2)
    - Sometimes a gif doesn't cut it
    - Saving a movie
      - ofxVideoRecorder (doesn't work on windows, so I can only really link to it)
      - For interactive works, 3rd party recording software
      - For noninteractive works, creating a 'rendering' mode, saving frames and stiching them together using ffmpeg or openFrameworks

####Section 5: Meshes
  - This is pushing the limits of what can fit in a basics of graphics chapter, but I'd love to see some coverage of 3D basics and meshes in the book
  - I could attempt to shorten up the generative mesh tutorial (http://openframeworks.cc/tutorials/graphics/generativemesh.html) and include it
  - That would add:
    - Basics of meshes
      - Modes, indicies, vertices
    - One way to think about creating a generative mesh
      - Loading image, getting pixels, using them as source data
      - Applying rules to the data to generate vertices and connections
    - ofEasyCam to navigate
    - How to handle the mesh to create simple animation and interactivity

####Section 6: Links to Addons and Where to Learn More
* Addons
  * Adding Physics
    * ofxBullet
    * ofxBox2d
  * Computer Vision
    * ofxCv or ofxOpenCv
  * Vector Graphics
    * ofxSVG or ofxVectorGraphics
* Additional Resources
  * I'll sort this out in more detail once I have an idea of what the other chapters in the book will look like 
  * ofBook will already have computer vision and shaders, so I'd like to point to resources on particle systems, opengl, vector math, and whatever else fits. 
  * Links to cool openFrameworks projects
