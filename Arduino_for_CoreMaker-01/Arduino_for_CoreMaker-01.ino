#include <Servo.h>   
Servo myservo;
int rain, notRain, windowIsOpen, recep;
char cmd;

void setup() {
  Serial.begin(115200); //設定鮑率115200
  Serial.println("Arduino Ready!");
  pinMode(13, OUTPUT); //設定LED輸出腳位
  myservo.attach(9); //設定馬達腳位
  rain = 0; //雨聲次數
  notRain = 0; //非下雨聲次數
  recep = 0; //總接收次數
  //窗戶是否開啟 1是0否 預設為開啟狀態
  windowIsOpen = 1;
  //LED燈亮代表窗戶開啟 熄滅關閉 預設為開啟狀態
  digitalWrite(13, HIGH);  
}

void loop() {
  while(Serial.available()>0){
    //接收來自CoreMaker-01的訊號
    cmd = Serial.read();
    Serial.println(cmd);
    //接收1代表雨聲
    if(cmd == '1'){
      rain++;
      recep++;                
    }
    //接收2代表不是雨聲
    if(cmd == '2'){
      notRain++;
      recep++;                 
    }  
    //若總接收次數大於7次    
    if(recep == 7){
      //雨聲大於非雨聲的情況
      if(rain > notRain){
        //窗戶是開啟狀態，下雨要關閉窗戶
        if(windowIsOpen == 1){
          digitalWrite(13, LOW);//燈暗
          myservo.attach(9);
          myservo.write(150); // 馬達逆時針旋轉
          delay(1000);
          myservo.write(90); 
          delay(1000);
          myservo.detach();
          Serial.println("下雨 窗戶關閉，馬達逆時針旋轉");
          windowIsOpen = 0;
          rain = 0;
          notRain = 0;
          recep = 0;             
        }
        //窗戶是關閉狀態，維持原樣
        else{
          rain = 0;
          notRain = 0;
          recep = 0;
        }  
      }
      //非雨聲大於雨聲的情況 
      else{
        //窗戶是關閉狀態，沒下雨要打開窗戶
        if(windowIsOpen == 0){
          digitalWrite(13, HIGH);//燈亮
          myservo.attach(9);
          myservo.write(30); //馬達順時針旋轉
          delay(1000);
          myservo.write(90); 
          delay(1000);
          myservo.detach();
          Serial.println(" 沒下雨 窗戶開啟，馬達順時針旋轉"); 
          windowIsOpen = 1;
          rain = 0;
          notRain = 0;
          recep = 0;             
        }
        //窗戶是開啟狀態，維持原樣
        else{
          rain = 0;
          notRain = 0;
          recep = 0;
        }  
      }
    }
  }
}
