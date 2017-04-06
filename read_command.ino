void read_command() {
  /*while (client.available()){
    Serial.println((char)client.read());
    }*/
  int cnt_command = packetSize / 5;
  Serial.println("CNT_COMMAND: " + String(cnt_command));
  for (int i = 0; i < cnt_command; i++) {
    int x = (packetBuffer[i * 5] - '0') * 10 + (packetBuffer[i * 5 + 1] - '0');
    int y = packetBuffer[i * 5 + 2] - '0';
    Serial.println(x + String(" - x"));
    Serial.println(y + String(" - y"));
    if(x>0 and x<5){ // семафоры
      semaphoreCommand(x,y);
    }
    if (x>=5 and x<12){
      strelkaCommand(x,y);
    }
    if (x>=12){
      svetCommand(x,y);
    }
    if(x==99 and y==9){
      sendState();
    }
   // if (x <= sizeof(out) / sizeof(int)) {
   //   if (y == 1) {
   //     digitalWrite(out[x - 1], HIGH);
   //   }
   //   else if (y == 0) {
   //     digitalWrite(out[x - 1], LOW);
   //   }
    //}
  }
  for (int i = 0; i < MAX_SIZE; i++){
    packetBuffer[i]=0;
  }
}
