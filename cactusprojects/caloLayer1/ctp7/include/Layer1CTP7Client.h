#ifndef Layer1CTP7Client_h
#define Layer1CTP7Client_h

#include "Layer1CTP7.h"

class Layer1CTP7Client : public Layer1CTP7 {

public:

  Layer1CTP7Client(uint32_t phi = 0) : myPhi(phi) {;}

  virtual ~Layer1CTP7Client() {;}

  bool getPhi(uint32_t &phi) {phi = myPhi; return true;}

  bool checkConnection() {return true;}

  bool getConfiguration(Layer1RunMode &m, std::string &output) {return true;}
  bool setConfiguration(Layer1RunMode mode, std::string input) {return true;}

  bool hardReset() {return true;}
  bool softReset() {return true;}
  bool counterReset() {return true;}

  bool getInputLinkStatus(std::vector<LinkStatusSummary> &problemLinks) {return true;}
  bool getOutputLinkStatus(std::vector<LinkStatusSummary> &problemLinks) {return true;}

  bool getInputCaptureStatus(CaptureStatus &c) {return true;}
  bool captureInput() {return true;}
  bool getOutputCaptureStatus(CaptureStatus &c) {return true;}
  bool captureOutput() {return true;}

  bool getInputCaptureBRAM(bool negativeEta, InputLink link, std::vector<uint32_t> &selectedData) {return true;}
  bool setPlaybackBRAM(bool negativeEta, InputLink link,  std::vector<uint32_t> &selectedData) {return true;}

  bool getOutputCaptureBRAM(bool negativeEta, OutputLink link, std::vector<uint32_t> &data) {return true;}
  bool setOutputCaptureBRAM(bool negativeEta, OutputLink link, std::vector<uint32_t> &data) {return true;} // This function is for testing purpose only

  bool getLUTs(bool negativeEta, InputLink link, TowerEtaIndex iEta, std::vector<uint32_t> &lut) {return true;}
  bool setLUTs(bool negativeEta, InputLink link, TowerEtaIndex iEta, std::vector<uint32_t> &lut) {return true;}

  bool alignInputLinks(uint32_t bx) {return true;}
  bool getInputCaptureStatus(std::vector<CaptureStatus> &c) {return true;}
  bool captureInput(CaptureMode mode, uint32_t startBXCounter) {return true;}
  bool getOutputCaptureStatus(std::vector<CaptureStatus> &c) {return true;}
  bool captureOutput(CaptureMode mode, uint32_t startBXCounter) {return true;}
  bool resetRxDecoder(bool negativeEta, InputLink link) {return true;}
  bool checksumCounterReset(bool negativeEta, InputLink link) {return true;}
  bool bx0CounterReset(bool negativeEta, InputLink link) {return true;}
  bool setLinkAlignmentMask(bool negativeEta, InputLink link) {return true;}
  bool getLinkAlignmentMask(bool negativeEta, InputLink link) {return true;}
  bool setTowerMask(bool negativeEta, InputLink link, uint32_t mask) {return true;}
  bool getTowerMask(bool negativeEta, InputLink link, uint32_t &mask) {return true;}
  bool setTxMode(TxMode value = data) {return true;}
  bool getTxMode(TxMode &value) {return true;}
  bool setTxPattern(bool negativeEta, OutputLink link, uint32_t value) {return true;}
  bool getTxPattern(bool negativeEta, OutputLink link, uint32_t &value) {return true;}
  bool setTxLinkID(bool negativeEta, OutputLink link, uint32_t value) {return true;}
  bool getTxLinkID(bool negativeEta, OutputLink link, uint32_t &value) {return true;}
  bool setTMTCycle(OutputLinkPair olPair, uint32_t value) {return true;}
  bool setTMTCycle(OutputLinkPair olPair, uint32_t &value) {return true;}
  bool alignOutputLinks(uint32_t bx = 0) {return true;}
  bool setTMTInterval(uint32_t value = 10) {return true;}
  bool getTMTInterval(uint32_t &value) {return true;}

  bool getFWBuildTimestamp(uint32_t &value) {return true;}
  bool getFWGitHashCode(uint32_t &value) {return true;}
  bool getFWGitDirtyBit(uint32_t &value) {return true;}
  bool getFWVersion(uint32_t &value) {return true;}
  bool getFWProjectCode(uint32_t &value) {return true;}
  bool getFWUptime(uint32_t &value) {return true;}

private:

  uint32_t myPhi;

};

#endif
