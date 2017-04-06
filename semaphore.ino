void semaphoreCommand(int x, int y) {
  Serial.println("pin"+!y);
  digitalWrite(semaphore[x - 1], !y);
  delay(50);
  Serial.println("powerON");
  digitalWrite(semaphorePower[x - 1], LOW);
  delay(200);
  Serial.println("powerOFF");
  digitalWrite(semaphorePower[x - 1], HIGH);
  delay(50);
  sendAnswer(x,y);
}

