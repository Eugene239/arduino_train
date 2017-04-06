void svetCommand(int x, int y){
  digitalWrite(svet[x - 12], !y);
  sendAnswer(x,y);
//  delay(50);
//  //Serial.println("powerON");
//  digitalWrite(strelkaPower[x - 5], LOW);
//  delay(400);
//  //Serial.println("powerOFF");
//  digitalWrite(strelkaPower[x - 5], HIGH);
//  delay(50);
}
