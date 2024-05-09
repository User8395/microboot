# microboot
Firmware platform for Arduinos

## Setup
```
git clone https://github.com/User8395/microboot
```
Compile and install the ino file via the Arduino IDE or command line

## Usage
Wait until the Arduino outputs "Serial stream started"

Now you can execute microboot functions

## Syntax
```
digitalwrite <--- function name
13           <--- argument
high         <--- argument
```
Functions and arguments are kept in seperate lines of the serial stream

For example,

```
println
Hello there

(will return "Hello there")
```

# Supported functions
See [FUNCTIONS.md](FUNCTIONS.md)