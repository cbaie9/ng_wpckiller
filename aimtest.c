int SizeX = 1920;
int SizeY = 720;
color green = color(0,255,0);
color blue = color(0,0,255);
color darkblue = color(51,51,204);
color winblue = color(0,153,153);
color red = color(255,0,0);
color white = color(255);
color gray  = color(125);
color lightgray = color(200);
color black = color(0);
color orange = color(255,153,0);
color MainColor = black;
color SubColor = white;
color HoverColor = orange;
boolean IsMousePressed = false;
boolean IsHovering = false;
int BaseLineTime = SizeX-70;
int BaseLine = SizeY-10;
int ButtonWidth = 100;
int ButtonHeight = 50;
float Random_startX = 50;
float Random_startY = 50;
boolean RegenButton = false;
String TextButton = "Start";
int Score = 0;
int PopUpSizeX = 125;
int PopUpSizeY = 20;
int LeftTimeShow =0;
int SecStart =0;
boolean Show =false;
int MarginButton = 10;
boolean settingOpen = false;
int setting_ButtonSize = 35;

void setup(){
 size(1920,720); // For More responsive put the x and y value into SizeX / SizeY
 noCursor();
  
}

void draw(){
 background(winblue);
 noStroke();
 fill(lightgray);
 rect(0,SizeY-25,SizeX,25);
 fill(black);
 text(mouseX,10,10);
 text(mouseY,35,10);
 text(Score,65,10);
 text(LeftTimeShow,85,10);
 if (settingOpen){
 text("Show On",100,10);
 } else {
  text("Show off",100,10);
 }
 text("BY cbaie9 -- github.com/cbaie9/ng_wpckiller/aimtest1",85,BaseLine);
 text(hour(),BaseLineTime,BaseLine); 
 text(":",BaseLineTime+15,BaseLine);
 text(minute(),BaseLineTime+20,BaseLine);
 text(":",BaseLineTime+35,BaseLine);
 text(second(),BaseLineTime+40,BaseLine);
 
 // -----------------------------------------
 // Options btte
 image(loadImage("settings.png"),SizeX-75,10);
 if (((mouseX > SizeX-75) && (mouseX < SizeX-75+53)) && ((mouseY > 10) && (mouseY< 10 + 53))) {
   // hover button
   image(loadImage("settings_hover.png"),SizeX-75,10);
  if(IsMousePressed){
    if(settingOpen){
    settingOpen = false;
    } else {
      settingOpen = true;
    } 
  }
 }
 if(settingOpen) {
} else {
 // ------------------------------------------
 // Button Test
 fill(blue);
 rect(Random_startX,Random_startY,ButtonWidth,ButtonHeight);
 if (((mouseX > Random_startX) && (mouseX < Random_startX+ButtonWidth)) && ((mouseY > Random_startY) && (mouseY< Random_startY + ButtonHeight))) {
  if(IsMousePressed){
    RegenButton = true;
    Score = Score+1;
    SecStart = second();
    Show = true;
    if(SecStart>=55){
      LeftTimeShow=2;
    } else {
      LeftTimeShow = second()+5;
    } 
  }
  fill(darkblue);
  rect(Random_startX,Random_startY,ButtonWidth,ButtonHeight);
  rect(Random_startX+10,Random_startY+10,ButtonWidth,ButtonHeight);
  fill(white);
  text(TextButton,Random_startX+20,Random_startY+20);
  IsHovering = true;
 } else {
   IsHovering = false;
   fill(white);
   text(TextButton,Random_startX+10,Random_startY+10);
   
 }
 }
 
 // ------------------------------------------
 MainColor = red;
 SubColor = blue;
 if(IsMousePressed){
   MainColor = green;
   SubColor = red;
   
 } else if(IsHovering){
   MainColor = HoverColor;
   SubColor = green;
 }

 fill(MainColor); 
 //Heart -> Mouse
 rect(mouseX-5,mouseY-7,2,12);
 rect(mouseX-6,mouseY-6,5,9);
 rect(mouseX-7,mouseY-5,7,8);
 rect(mouseX-5,mouseY+3,12,2);
 rect(mouseX-3,mouseY+5,8,2);
 rect(mouseX-1,mouseY+7,4,2);
 rect(mouseX,mouseY-3,2,6);
 rect(mouseX+2,mouseY-5,7,8);
 rect(mouseX+3,mouseY-6,5,1);
 rect(mouseX+5,mouseY-7,2,1);
 fill(SubColor);
 // Pop Up score
 if (LeftTimeShow==second()&& Show){
  Show = false;
 } else {
 fill(white);
 rect(10,BaseLine-50,PopUpSizeX,PopUpSizeY);
 fill(black);
 text("Score = ",15,BaseLine-35);
 text(Score,55,BaseLine-35);
 }
 if (RegenButton){
   Random_startX= random(SizeX-MarginButton-10)+10;
   Random_startY= random(SizeY-MarginButton-10)+10;
   RegenButton = false;
   TextButton = "Click me (;";
 }
 
 
}
void mousePressed() {
 IsMousePressed = true; 
}
void mouseReleased() {
 IsMousePressed = false; 
}