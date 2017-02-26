//www.elegoo.com
//2016.09.23

#include <IRremote.h>

int ABS=150;
unsigned long RED;
#define A 4294967295

#define B 4294967299

#define X 16712445

#define C 16720605

#define D 16761405
extern int receiverpin;
IRrecv irrecv(receiverpin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  _mStop();
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
    { 

      RED=results.value;
       Serial.println(RED);
       irrecv.resume();
    delay(150);
    if(RED==A)
  {  
     _mForward();
  }

  else if(RED==B)
  {
        _mBack();
  }

  else if(RED==C)
  {
        _mleft();
  }

  else if(RED==D)
  {
        _mright();
   }

  else if(RED==X)
  { 
         _mStop();
   }
}
} 

