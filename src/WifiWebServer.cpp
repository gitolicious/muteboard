// self
#include <WifiWebServer.h>

#include <WiFi.h>

// internal
#include <Keyboard.h>
#include <web/index.min.h>

WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void WifiWebServer::setup()
{
  Serial.println("Starting web server");
  server.begin();
}

void WifiWebServer::loop()
{
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client)
  { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    { // loop while the client's connected
      currentTime = millis();
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
        header += c;
        if (c == '\n')
        { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /mute-mic") >= 0)
            {
              Serial.println("mute-mic");
              _keyboard.sendMicMute();
            }
            else if (header.indexOf("GET /mute-cam") >= 0)
            {
              Serial.println("mute-cam");
              _keyboard.sendCameraMute();
            }
            else if (header.indexOf("GET /mute-speaker") >= 0)
            {
              Serial.println("mute-speaker");
              _keyboard.sendSpeakerMute();
            }
            else if (header.indexOf("GET /test") >= 0)
            {
              Serial.println("test");
              _keyboard.sendTest();
            }
            else
            {
              // Display the HTML web page
              client.println(INDEX_HTML);
            }

            client.println();
            // Break out of the while loop
            break;
          }
          else
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
