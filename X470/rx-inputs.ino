//========================= RECEIVER ===============================

#ifdef SBUS
HardwareSerial SBUSS(1);
bfs::SbusRx sbus_rx(&SBUSS, RXpin,TXpin , RXinverted);
bfs::SbusData data;
#define sbusMin 172
#define sbusMax 1811
#endif

//------------------------------------------------------------------
void RXsetup() {

 // IBus.begin(Serial1, IBUSBM_NOTIMER, RXpin, TXpin);
}
//------------------------------------------------------------------
void ReadRX() {

#ifdef SBUS
  if (sbus_rx.Read()) {
    data = sbus_rx.data();  // Read and Organize the received data
    for (uint8_t i = 1; i <= 10; i++) {
      RXchannel[i] = map(data.ch[i - 1], sbusMin, sbusMax, RXmin, RXmax);
      RXchannel[i] = constrain(RXchannel[i], RXmin, RXmax);
    }
  }
#endif

#ifdef RX_DEBUG
    /* Display the received data */
    for (uint8_t i = 1; i <= 10; i++) {
      Serial.print(RXchannel[i]);
      Serial.print("\t");
    }
    Serial.println(data.NUM_CH);
#endif
}
