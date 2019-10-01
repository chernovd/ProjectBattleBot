#define RxD A0 // Get receiving pin
#define TxD A1 // Get transmitting pin


SoftwareSerial serial = SoftwareSerial(RxD,TxD); // Setting up software serial

void setup() {
    serial.begin(38400); // Starting software serial
}

void loop() {
    String result = ""; // Empty variable
    while (serial.available()) { // Checks whether theres something on the COM channel
        char c = serial.read(); // Reads one character from the COM channel
        result += c; // Adds it to result
    }
    Process(result); // Fake method for parsing commands
}
