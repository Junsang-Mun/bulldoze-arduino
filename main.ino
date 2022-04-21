#include <Adafruit_NeoPixel.h>

int sensVal;  //센서값을 읽어올 변수를 선언합니다. int형.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);
/*  네오픽셀을 불러올 모듈을 만듭니다. "pixels".
    Adafruit_NeoPixel(<LED의 갯수>, <LED와 연결된 핀 번호>, NEO_GRB + NEO_KHZ800); */

void setup() {
  Serial.begin(9600);  //Serial init
  pixels.setBrightness(255);  //LED 밝기(0~255) 최대로 설정
  pixels.begin();  //LED init
  pixels.show();  //LED 가동 시작
}

void loop() {
  sensVal = analogRead(A0);                         //sensVal 변수에 A0에서 읽어온 값을 할당합니다. 아마 조도센서로 연결되어있겠지
  if(sensVal <= 700){                               //sensVal(=조도센서 값)이 700 이하라면
    Serial.println("Turn on LEDs");                 //LED가 켜졌다는 메시지를 보내고
    printColor(pixels.Color(255,255,255));          //LED를 켭니다 (색상은 (255, 255, 255)).
  } else if(sensVal > 700){                         //sensVal이 700 초과라면
    Serial.println("Turn off LEDs");                //LED 꺼졌다는 메시지를 쏘고
    printColor(pixels.Color(0,0,0));                //LED를 켭니다 (색상은 (0, 0, 0), 즉 끈다는 의미임)
  }
}

void printColor(uint32_t color){                        //printColor 함수 선언; 인자는 color(unit32_t형, 색상을 의미함)
  for(uint16_t i=0; i < pixels.numPixels(); i++){       //네오픽셀의 픽셀 숫자만큼 반복합니다. (4번줄 참조; pixels.numPixels는 네오픽셀의 픽셀 숫자를 리턴합니다.)
    pixels.setPixelColor(i, color);                     //i번쨰 네오픽셀을 loop에서 받아온 color 인자로 설정하고
    pixels.show();                                      //네오픽셀을 가동합니다.
  }
}
