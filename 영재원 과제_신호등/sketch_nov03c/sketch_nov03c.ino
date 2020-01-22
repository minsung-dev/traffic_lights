/ 피에조 부저를 3번 핀, 버튼을 5번 핀에 연결합니다.ㅋ/*
 제목    : LED 여러개 연결하기
 내용   : 여러 개의 LED를 제어해 봅시다.
 */

// 배열을 사용하여 사용하는 핀을 한번에 선언합니다.
// 특정 핀 번호를 대신해서 배열명[특정 방 번호] 사용합니다.
// ledPins[0] 은 2번 핀을 의미합니다.
int ledPins[] = {2, 3, 4,};

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
void setup() {
  // 배열의 방 번호를 저장할 변수를 선언 합니다. 
  int idex; 
  // for 반복문과 배열을 사용하여 2번부터 9번까지의 핀을 출력 핀으로 설정합니다.
  for(index = 0 ; index <= 7  ; index++){
      pinMode(ledPins[index],OUTPUT);
    } 
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행합니다.
void loop() {
  // 반복문을 사용하지 않고, LED를 하나씩 키는 함수입니다. 
  oneAfterAnotherNoLoop();    
  // 반복문을 사용하여, LED를 하나씩 키는 함수입니다.
  oneAfterAnotherLoop();
}

// oneAfterAnotherNoLoop : 반복문을 사용하지 않고 하나씩 켜기
// 1. 하나씩 커짐
// 2. 0.1초 씩 일시정지
// 3. 거꾸로 하나씩 꺼짐
void oneAfterAnotherNoLoop() {
  // LED를 하나씩 모두 ON시킵니다. (순서 2번 핀 -> 9번 핀)
  // 2번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[0], HIGH);  
  //0.1초동안 대기합니다.
  delay(100);                      
  // 3번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[1], HIGH);  //3번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100);                
  // 4번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[2], HIGH);  //4번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100);                
  // 5번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[3], HIGH);  //5번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100);                
  // 6번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[4], HIGH);  //6번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100);                
  // 7번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[5], HIGH);  //7번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100);                
  // 8번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[6], HIGH);  //8번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100); 
  // 9번 핀과 연결된 LED를 ON 시킵니다.
  digitalWrite(ledPins[7], HIGH);  //9번 핀과 연결된 LED ON
  //0.1초동안 대기합니다.
  delay(100); 
 
  // LED를 하나씩 모두 OFF시킵니다. (순서 9번 핀 -> 2번 핀)
  // 9번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[7], LOW);   
  //0.1초동안 대기합니다.
  delay(100);                
  // 8번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[6], LOW);  
  //0.1초동안 대기합니다.
  delay(100);                
  // 7번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[5], LOW);   
  //0.1초동안 대기합니다.
  delay(100);           
  // 6번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[4], LOW);   
  //0.1초동안 대기합니다.
  delay(100);                
  // 5번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[3], LOW);   
  //0.1초동안 대기합니다.
  delay(100);                
  // 4번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[2], LOW);   
  //0.1초동안 대기합니다.
  delay(100);                
  // 3번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[1], LOW);   
  //0.1초동안 대기합니다.
  delay(100);                
  // 2번 핀과 연결된 LED를 OFF 시킵니다.
  digitalWrite(ledPins[0], LOW);   
  //0.1초동안 대기합니다.
  delay(100);                 
}

// oneAfterAnotherLoop() : 반복문을 사용하여 하나씩 켜기
void oneAfterAnotherLoop() {
  // 배열의 방 번호를 저장할 변수를 선언합니다.
  int index;            

    //배열의 방 번호를 0부터 하나씩 증가하면서 for문 안의 내용을 반복합니다.
  for(index = 0 ; index <= 7 ; index++){
    //index = 0이면 2번 핀과 연결된 LED를 ON 시킵니다.
    digitalWrite(ledPins[index], HIGH); 
    //0.1초동안 대기합니다.
    delay(100);                
    }                                  

    //배열의 방 번호를 7부터 하나씩 감소하면서 for문 안의 내용을 반복합니다.
  for(index = 7; index >= 0; index--){
    //index = 7이면 9번 핀과 연결된 LED를 OFF 시킵니다.
    digitalWrite(ledPins[index], LOW);  
    //0.1초동안 대기합니다.
    delay(1000);
  }               
}
