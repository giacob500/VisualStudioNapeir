int numberOfimages = 5;
PImage [] images = new PImage[numberOfimages];
int imageIndex = 1;

void setup() {
  size(400, 500);
  //load the image
  images[0] = loadImage("1.jpg");
  images[1] = loadImage("2.jpg");
  images[2] = loadImage("3.jpg");
  images[3] = loadImage("4.png");
  images[4] = loadImage("5.jpg");
}

void draw() {
  background(255);  
  image(images[imageIndex], 0, 0);
}

void mousePressed() {
  if (imageIndex == images.length-1) {
    imageIndex = 0;
  } else { 
    imageIndex++;
  }
  tint((int)random(255), (int)random(255), (int)random(255));
}
