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
<pin>  <--- any integer (depends on board model)
<mode> <--- high/low
```
Write &lt;mode&gt; to &lt;pin&gt;