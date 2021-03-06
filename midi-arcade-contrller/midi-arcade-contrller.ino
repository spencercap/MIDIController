#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1; //midi channel
int val = 24; // for buttons
//int val2 = 0; //for LEDS

// analogRead(0) / 8

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 5);
Bounce button1 = Bounce(1, 5);  // 5 = 5 ms debounce time
Bounce button2 = Bounce(2, 5);  // which is appropriate for good
Bounce button3 = Bounce(3, 5);  // quality mechanical pushbuttons
Bounce button4 = Bounce(4, 5);
Bounce button5 = Bounce(5, 5);  // if a button is too "sensitive"
Bounce button6 = Bounce(7, 5);  // to rapid touch, you can
Bounce button7 = Bounce(12, 5);  // increase this time.
Bounce button8 = Bounce(8, 5);
Bounce button9 = Bounce(9, 5);
Bounce button10 = Bounce(10, 5);
Bounce button11 = Bounce(11, 5);

// analog values
int THRESHOLD = 3; // Sensitivity Knob
int current_analog0,previous_analog0; //variable fuer Potentiometer 0
int current_analog1,previous_analog1; //variable fuer Potentiometer 1
int current_analog2,previous_analog2; //variable fuer Potentiometer 2
int current_analog3,previous_analog3; //variable fuer Potentiometer 3
int THRESHOLD2 = 2; // Sensitivity Fader
int current_analog4,previous_analog4; //variable fuer Potentiometer 4
int current_analog5,previous_analog5; //variable fuer Potentiometer 5

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  
  // buttons
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup if digital 6
  pinMode(12, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP); // Teensy LED, may need 1k resistor pullup
  
  // set up analog knobs
  pinMode(A0, INPUT); //analog input 0
  pinMode(A1, INPUT); //analog input 1  
  pinMode(A2, INPUT); //analog input 2  
  pinMode(A3, INPUT); //analog input 3
  pinMode(A4, INPUT); //analog input 4
  pinMode(A5, INPUT); //analog input 5
  
  //leds
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();

  // Check each button for "falling" edge.
  // Send a MIDI Note On message when each button presses
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    usbMIDI.sendNoteOn(val, 99, channel);  // increment steps
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(val+1, 99, channel);  // increment steps
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(val+2, 99, channel);  // increment steps
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(val+3, 99, channel);  // increment steps
  }
  if (button4.fallingEdge()) {
    usbMIDI.sendNoteOn(val+4, 99, channel);  // increment steps
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOn(val+5, 99, channel);  // increment steps
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOn(val+6, 99, channel);  // increment steps
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendNoteOn(val+7, 99, channel);  // increment steps
  }
  if (button8.fallingEdge()) {
    usbMIDI.sendNoteOn(val+8, 99, channel);  // increment steps
  }
  if (button9.fallingEdge()) {
    usbMIDI.sendNoteOn(val+9, 99, channel);  // increment steps
  }
  if (button10.fallingEdge()) {
    usbMIDI.sendNoteOn(val+10, 99, channel);  // increment steps
  }
  if (button11.fallingEdge()) {
    usbMIDI.sendNoteOn(val+11, 99, channel);  // increment steps
  }
 
  // Check each button for "rising" edge
  // Send a MIDI Note Off message when each button releases
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    usbMIDI.sendNoteOff(val, 0, channel);  // 60 = C4
  }
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(val+1, 0, channel);  // 61 = C#4
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(val+2, 0, channel);  // 62 = D4
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(val+3, 0, channel);  // 63 = D#4
  }
  if (button4.risingEdge()) {
    usbMIDI.sendNoteOff(val+4, 0, channel);  // 64 = E4
  }
  if (button5.risingEdge()) {
    usbMIDI.sendNoteOff(val+5, 0, channel);  // 65 = F4
  }
  if (button6.risingEdge()) {
    usbMIDI.sendNoteOff(val+6, 0, channel);  // 66 = F#4
  }
  if (button7.risingEdge()) {
    usbMIDI.sendNoteOff(val+7, 0, channel);  // 67 = G4
  }
  if (button8.risingEdge()) {
    usbMIDI.sendNoteOff(val+8, 0, channel);  // 68 = G#4
  }
  if (button9.risingEdge()) {
    usbMIDI.sendNoteOff(val+9, 0, channel);  // 69 = A5
  }
  if (button10.risingEdge()) {
    usbMIDI.sendNoteOff(val+10, 0, channel);  // 70 = A#5
  }
  if (button11.risingEdge()) {
    usbMIDI.sendNoteOff(val+11, 0, channel);  // 71 = B5
  }
  
  
  // ANALOG SECTION!!
  
  // raw values from the analog control are 0-1023 (1024)
  // we divide by 8 here to get MIDI style 0-127 (128)
  // put in beginning -->>  val = analogRead(0) / 8;
  
  // usbMIDI.sendControlChange(control, value, channel);
  
  // EXAMPLE: this will send regular olde CC data, here on channel 50
  // usbMIDI.sendControlChange(50, val, channel);

  current_analog0 = analogRead(0);
  current_analog1 = analogRead(1); 
  current_analog2 = analogRead(2);
  current_analog3 = analogRead(3);
  current_analog4 = analogRead(4);
  current_analog5 = analogRead(5);

// analog 1 controls pitch of all buttons, instead of CC value!

  if ( abs(current_analog0 - previous_analog0) >= THRESHOLD )  {
      //usbMIDI.sendControlChange(0, current_analog0/8, 1 );
      previous_analog0 = current_analog0;
      
      
      usbMIDI.sendNoteOff(val, 0, channel);
      usbMIDI.sendNoteOff(val+1, 0, channel);
      usbMIDI.sendNoteOff(val+2, 0, channel);
      usbMIDI.sendNoteOff(val+3, 0, channel);
      usbMIDI.sendNoteOff(val+4, 0, channel);
      usbMIDI.sendNoteOff(val+5, 0, channel);
      usbMIDI.sendNoteOff(val+6, 0, channel);
      usbMIDI.sendNoteOff(val+7, 0, channel);
      usbMIDI.sendNoteOff(val+8, 0, channel);
      usbMIDI.sendNoteOff(val+9, 0, channel);
      usbMIDI.sendNoteOff(val+10, 0, channel);
      usbMIDI.sendNoteOff(val+11, 0, channel);
     
      val = 24 + (16 * round(current_analog0/256));
      
  }
  
  if ( abs(current_analog1 - previous_analog1) >= THRESHOLD )  {
     usbMIDI.sendControlChange(1, current_analog1/8, 1 ); 
     previous_analog1 = current_analog1;
  }
  
  if ( abs(current_analog2 - previous_analog2) >= THRESHOLD )  {
      usbMIDI.sendControlChange(2, current_analog2/8, 1 ); 
      previous_analog2 = current_analog2;
  }
  
  if ( abs(current_analog3 - previous_analog3) >= THRESHOLD )  {
      usbMIDI.sendControlChange(3, current_analog3/8, 1 );
      previous_analog3 = current_analog3;
  }
  
  if ( abs(current_analog4 - previous_analog4) >= THRESHOLD2 )  {
      usbMIDI.sendControlChange(val+4, current_analog4/8, 1 );
      previous_analog4 = current_analog4;
  }
  
  if ( abs(current_analog5 - previous_analog5) >= THRESHOLD2 )  {
      usbMIDI.sendControlChange(val+5, current_analog5/8, 1 );
      previous_analog5 = current_analog5;
  }

  
  //LEDS
  
  // Always On
  digitalWrite(14, LOW);    // set the LED on/off
   digitalWrite(15, LOW);    // set the LED on/off
  //HIGH=OFF
  //LOW=ON
  
  // FADING 
  // negative 'val' because it fades upsidedown. 
  
  //val = analogRead(A4); // reads fader
  //analogWrite(14, val/4); 
  //val = analogRead(A5); // reads fader
  //analogWrite(15, - val/4); 
 
}

