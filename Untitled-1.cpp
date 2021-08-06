
//declaring the pins
const uint8_t led_pin = 5;
const uint8_t interrupt_pin = 2;
const uint8_t sound_pin = 3;
//declaring the volatile varible so that the changes are immediately available in the loop.
volatile byte state = LOW;
void setup()
{
    Serial.begin(9600);
    pinMode(led_pin, OUTPUT);
    pinMode(sound_pin, INPUT);
    pinMode(interrupt_pin, INPUT);
    //declaring the two interupt one is when there is motion the led will be on  and if the sound sensor will detect the sound and the led will go off which will automatically trigger the another interupt.
    attachInterrupt(digitalPinToInterrupt(interrupt_pin), Interrupt, RISING);
    attachInterrupt(digitalPinToInterrupt(sound_pin), Sound, FALLING);
}

void loop()
{
    // if the state is high initially led will blink and the motion sensor interrupt will be triggered
    if (state == HIGH)
    {
        digitalWrite(led_pin, HIGH);
        Serial.println("Motion active");
        delay(500);
    }
    //on the same time as the sound sensor detetct and the led is on sound sensor interrupt will be triggered and take the led to low state
    if (state == HIGH)
    {
        Serial.println("Motion Inactive");
        state = LOW;
        digitalWrite(led_pin, LOW);
    }
}
// Interrupt triggered from the motion snsor
void Interrupt()
{
    state = HIGH;
    Serial.println("interrupt");
}
// Interrupt triggered from the sound snsor
void Sound()
{
    state = LOW;
    Serial.println("interrupt");
}