void TCP(){
  if (!client.connected()) { //подсоединение к серверу
    if (client.connect(server, port)) {
      Serial.println("---connected---");
      client.print(name+" connected");
    }
    else {
      client.stop();
      time = millis()+5000;
    }
  }
}

