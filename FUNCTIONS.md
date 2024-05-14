# Supported functions

## eeprom
Manipulate the EEPROM

### Syntax
```
eeprom
read
<address> <--- can be an integer from 0 to 255
```
Read EEPROM value at &lt;address&gt;

```
eeprom
set
<address> <--- can be an integer from 0 to 255
<value> <--- can be any value
```
Set EEPROM value at &lt;address&gt; to &lt;value&gt;

## println
Print text to serial with a new line

### Syntax
```
println
<text>
```
Print &lt;text&gt; to serial with a newline at the end

## print
Print text to serial

### Syntax
```
print
<text>
```
Print &lt;text&gt; to serial

## digitalwrite
Write a digital value to a pin

### Syntax
```
digitalwrite
<pin>  <--- any digital or analog pin number (depends on board model)
<value> <--- high/low
```
Write &lt;mode&gt; to &lt;pin&gt;

## sleep
Do nothing for a specified amount of time

### Syntax
```
sleep
<time> <--- any positive integer
```

Do nothing for &lt;time&gt; milliseconds

### Notes
If the used serial monitor does not send strings ending with a line feed (LF), then any function sent via serial after this function is run will be interpreted as one line

For example, if you do
```
sleep
10000
```
and right after run
```
digitalwrite
13
high
```
then microboot will throw the error
```
microboot.serialstream.BadFunctionError at line 3: digitalwrite13high
```
To fix this, set the line endings to LF in your serial monitor (automatically done in the Arduino IDE).