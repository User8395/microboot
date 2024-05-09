#ifndef SERIALSTREAM
#define SERIALSTREAM

class serialstream
{
public:
  int init()
  {
    delay(1000);
    Serial.println("Serial stream started");
    int line = 1;
    char command[1000];
    while (true)
    {
      if (Serial.available() > 0)
      {
        String function = Serial.readStringUntil('\n');
        if (function == "eeprom")
        {
          line++;
          while (Serial.available() == 0)
            ;
          String action = Serial.readStringUntil('\n');
          if (action == "read")
          {
            line++;
            while (Serial.available() == 0)
              ;
            int address = Serial.readStringUntil('\n').toInt();
            Serial.println(EEPROM.read(address));
          }
          else if (action == "set")
          {
            line++;
            while (Serial.available() == 0)
              ;
            int address = Serial.readStringUntil('\n').toInt();
            line++;
            while (Serial.available() == 0)
              ;
            int value = Serial.readStringUntil('\n').toInt();
            Serial.println(EEPROM.put(address, value));
          }
          else
          {
            line++;
            Serial.print("microboot.serial.BadActionError at line ");
            Serial.print(line);
            Serial.print(": expected read/set, got ");
            Serial.println(action);
          }
        }
        else if (function == "print")
        {
          line++;
          while (Serial.available() == 0)
            ;
          String text = Serial.readStringUntil("\n");
          Serial.print(text);
        }
        else if (function == "println")
        {
          line++;
          while (Serial.available() == 0)
            ;
          String text = Serial.readStringUntil("\n");
          Serial.println(text);
        }
        else if (function == "pinmode")
        {
          line++;
          while (Serial.available() == 0)
            ;
          line++;
          int pin = Serial.readStringUntil("\n").toInt();
          while (Serial.available() == 0)
            ;
          line++;
          String mode = Serial.readStringUntil("\n");
          if (mode == "input")
          {
            pinMode(pin, INPUT);
          }
          else if (mode == "input pullup")
          {
            pinMode(pin, INPUT_PULLUP);
          }
          if (mode == "output")
          {
            pinMode(pin, OUTPUT);
          }
          else
          {
            Serial.print("microboot.serial.BadArgumentError at line ");
            Serial.print(line);
            Serial.print(": expected INPUT/INPUT_PULLUP/OUTPUT, got ");
            Serial.println(mode);
          }
        }
        else if (function == "digitalwrite")
        {
          line++;
          while (Serial.available() == 0)
            ;
          line++;
          int pin = Serial.readStringUntil("\n").toInt();
          while (Serial.available() == 0)
            ;
          line++;
          String mode = Serial.readStringUntil("\n");
          if (mode == "high")
          {
            digitalWrite(pin, HIGH);
          }
          else if (mode == "low")
          {
            digitalWrite(pin, LOW);
          }
          else
          {
            Serial.print("microboot.serial.BadArgumentError at line ");
            Serial.print(line);
            Serial.print(": expected high/low, got ");
            Serial.println(mode);
          }
        }
        else if (function == "")
        {
          line++;
        }
        else
        {
          Serial.print("microboot.serialstream.BadFunctionError at line ");
          Serial.print(line);
          Serial.print(": ");
          Serial.println(function);
        }
      }
    }
  }

private:
};

serialstream serialstream;

#endif
