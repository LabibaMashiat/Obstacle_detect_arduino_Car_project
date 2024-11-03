void obstacle() {
  m2 = millis();
  if (m2 - m1 > 50) { //check the sonar value only after certain period of time (50ms)
    int sf = sonar.ping_cm();
    if (sf > 0 && sf < 15 && mode && digitalRead(sw)) {
      if (x == 'F' || x == 'G' || x == 'I') motor(0, 0); //if  going forward, it will stop the robot
     
      while (sf > 0 && sf < 15 && mode && digitalRead(sw)) { //it will keep the robot in this loop as long as  detect obstacle infront of it
        sf = sonar.ping_cm(); delay(50); 
        if (bt.available()) {
          x = bt.read();
          if (x != 'F' && x != 'G' && x != 'I') {
            command(); break;
          }
          else if (x == 'S') command();
        }
      
    }
    m1 = m2 = millis(); //refreshing the timer to check sonar value
  }
}
