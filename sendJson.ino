void sendJSON(int rf) {
  String rfid = "";
  for (int i = 0; i < 8; i++) {
    rfid += String(addr1[rf-1][i], HEX);
  }
  if (rfid!="00000000" and rfid!="ffffffff" and rfid!="ffffffffffffffff"){
  String Json = "{ \"Reader\" :\"" + String(rf) + "\", \"HEX\":\"";
  Json += rfid+ "\"}";
  if (client.connected()) {
    client.print(Json);
    Serial.println(Json);
    //delay(50);
    // }
    }
  }
}
void sendAnswer(int x, int y){
  String value ="";
  if (x<10) value+="0"+String(x*10+y);
  else value +=String(x*10+y);
  String Json = "{ \"command\" :\"" +value+ "\"}";
  client.print(Json);
}
void sendState(){
  String semaphoreJS ="{\"semaphore\":[";
  for(int i=0; i<sizeof(semaphore)/sizeof(int);i++){
    if (i+1<sizeof(semaphore)/sizeof(int)) 
      semaphoreJS+="{\""+String(i)+"\":\""+ String(!digitalRead(semaphore[i])) +"\"},";
    else
      semaphoreJS+="{\""+String(i)+"\":\""+String(!digitalRead(semaphore[i]))+"\"}],";
  }

  String strelkaJS = "\"strelka\":[";
  for(int i=0; i<sizeof(strelka)/sizeof(int);i++){
    if (i+1<sizeof(strelka)/sizeof(int)) 
      strelkaJS+="{\""+String(i+5)+"\":\""+String(!digitalRead(strelka[i]))+"\"},";
    else 
      strelkaJS+="{\""+String(i+5)+"\":\""+String(!digitalRead(strelka[i]))+"\"}],";
  }
   String svetoforJS = "\"svetofor\":[";
    for(int i=0; i<sizeof(svet)/sizeof(int);i++){
    if (i+1<sizeof(svet)/sizeof(int)) 
      svetoforJS+="{\""+String(i+12)+"\":\""+String(!digitalRead(svet[i]))+"\"},";
    else 
      svetoforJS+="{\""+String(i+12)+"\":\""+String(!digitalRead(svet[i]))+"\"}]}";
  }
  client.print(semaphoreJS+strelkaJS+svetoforJS);
}

