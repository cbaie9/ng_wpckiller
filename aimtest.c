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
boolean IsHovering_random = false;
int FontSize_Size = 20;
int BaseLineTime = SizeX-8*FontSize_Size;
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
int setting_Margin = 50;
boolean IsHovering_settings = false;
boolean NoLimit = false;
boolean Buffer_already_click = false;
void setup(){
  
  
 size(1920,720); // For More responsive put the x and y value into SizeX / SizeY
 noCursor();
 textFont(loadFont("Consolas-14.vlw"));
  
}

void draw(){
 background(winblue);
 noStroke();
 fill(lightgray);
 rect(0,SizeY-25,SizeX,25);
 fill(black);
 text(mouseX,10,10);
 text(mouseY,45,10);
 text(Score,70,10);
 text(LeftTimeShow,85,10);
 if (NoLimit){
 text("Show On",100,10);
 } else {
  text("Show off",100,10);
 }
 text("BY cbaie9 -- github.com/cbaie9/ng_wpckiller/aimtest1",85,BaseLine);
 text(hour(),BaseLineTime,BaseLine); 
 text(":",BaseLineTime+FontSize_Size,BaseLine);
 text(minute(),BaseLineTime+((2*FontSize_Size)-(0.5*FontSize_Size)),BaseLine);
 text(":",BaseLineTime+((3*FontSize_Size)-(0.5*FontSize_Size)),BaseLine);
 text(second(),BaseLineTime+((4*FontSize_Size)-(0.5*FontSize_Size)),BaseLine);
 
 
 if(Score > 30) {
   fill(125);
   textFont(loadFont("Consolas-65.vlw"));
   text("YOU WIN",100,100);
   textFont(loadFont("Consolas-22.vlw"));
   
 } else {
 // -----------------------------------------
 // Options btte
 image(loadImage("settings.png"),SizeX-75,10);
 if ((((mouseX > SizeX-75) && (mouseX < SizeX-75+53)) && ((mouseY > 10) && (mouseY< 10 + 53)))&& (settingOpen == false)) {
   // hover button
   image(loadImage("settings_hover.png"),SizeX-75,10);
  if(IsMousePressed){
     settingOpen = true; 
  }
 }
 if(settingOpen) {
   fill(100,100,100,125);
   rect(0,0,SizeX,SizeY);
   fill(black);
   textFont(loadFont("Consolas-22.vlw"));
   strokeJoin(ROUND);
   rect(SizeX*0.35,30,550,SizeY-75);
   fill(white);
   text("Settings",SizeX*0.45,45);
   fill(red);
   rect(((SizeX*0.35)+520),30,30,30);
   fill(white);
   rect(SizeX*0.40,75,35,35);
   text("No Score Limit",SizeX*0.43,105);
   if (((mouseX > (((SizeX*0.35)+520))) && (mouseX < (SizeX*0.35)+550)) && ((mouseY > 30) && (mouseY< 60))) {
     stroke(white);
     IsHovering_settings = true;
     if(IsMousePressed){
      settingOpen = false;
     }
    } else {
   stroke(black);
   IsHovering_settings = false;
    }
   line((((SizeX*0.35)+520)+3),33,(SizeX*0.35)+520+27,57); // croix fermeture settings
   line((((SizeX*0.35)+520)+3),57,(SizeX*0.35)+520+27,33);
   // ---
   // croix noLimit
   if ((((mouseX > SizeX*0.40) && (mouseX < SizeX*0.40+30)) && ((mouseY > 75) && (mouseY< 110))) || NoLimit) {
     stroke(black);
     IsHovering_settings = true;
     if(IsMousePressed && (Buffer_already_click == false)){
      if (NoLimit) {
          NoLimit = false;
          Buffer_already_click = true;
              
        } else {
          NoLimit = true;
          Buffer_already_click = true;
        }
     }
    } else {
   stroke(white);
   IsHovering_settings = false;
    }
   line(SizeX*0.40,108,SizeX*0.40+30,77);
   line(SizeX*0.40,77,SizeX*0.40+30,108);
   // exit font - reset to default
   textFont(loadFont("Consolas-14.vlw"));
   noStroke();
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
  IsHovering_random = true;
 } else {
   IsHovering_random = false;
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
   
 } else if(IsHovering_random || IsHovering_settings){
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
 text(Score,FontSize_Size*4.5,BaseLine-35);
 }
 if (RegenButton){
   Random_startX= random(SizeX-MarginButton-10)+10;
   Random_startY= random(SizeY-MarginButton-10)+10;
   RegenButton = false;
   TextButton = "Click me (;";
 }
 }
 
 
}
void mousePressed() {
 IsMousePressed = true; 
}
void mouseReleased() {
 IsMousePressed = false; 
 Buffer_already_click = false;
}
