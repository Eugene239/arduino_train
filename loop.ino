void loop()
{
  if (time<millis()) TCP();
  if (client.available()) {
    packetSize = client.read(packetBuffer, MAX_SIZE);
    Serial.print(packetSize + String("---   "));
    for (int i = 0; i < packetSize; i++) {
      Serial.print((char)packetBuffer[i]);
    }
    if (packetSize % 5 == 0) read_command(); //размер пакета кратен 5
    Serial.println("----END MESSAGE----");
  }



  
  if (client.connected()) {
    for (int i = 0; i < sizeof(ds) / sizeof(OneWire); i++) {
      if (ds[i].reset()) {
        ds[i].write(0x33);
        delay(50);
        for (int j = 0; j < 8; j++) {
          addr1[i][j] = ds[i].read(); // считываем
        }
        sendJSON(i + 1);
      }
    }
  }
  
}
