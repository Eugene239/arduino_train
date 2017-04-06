void strelkaCommand(int x, int y){
  digitalWrite(strelka[x - 5], !y);
  delay(50);
  //Serial.println("powerON");
  digitalWrite(strelkaPower[x - 5], LOW);
  delay(400);
  //Serial.println("powerOFF");
  digitalWrite(strelkaPower[x - 5], HIGH);
  delay(50);
  sendAnswer(x,y);
  //response
}

