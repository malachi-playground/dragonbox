#include <Arduino.h>

#include <estd/ostream.h>

#include <dragonbox/dragonbox_to_chars.h>

estd::arduino_ostream cout(Serial);

void setup()
{

}


float counter = 0;

void loop()
{
    estd::layer1::string<32> s;

    jkj::dragonbox::to_chars(counter, s.data());
    
    counter += 0.10;

    cout << s << estd::endl;

    delay(1000);
}