

#ifndef Layer1CTP7_h
#define Layer1CTP7_h

//
// This header file specifies functional interface to the 
// Upgraded Calorimeter Trigger Layer-1 CTP7.
//
// The ZYNQ based softare encapsulates all details of the 
// firmware operation so addresses, internal state transition 
// details, sequencing of commands, etc. are not exposed.
//

#include <stdint.h>

#include <vector>
#include <string>

class Layer1CTP7 {

public:

  // Each CTP7 is processing calorimeter data corresponding to
  // 20 degree Phi region. phi parameter (0 - 17) is set
  // according to the RCT map:
  // https://twiki.cern.ch/twiki/bin/viewauth/CMS/RCTMap

  // Expect constructor to take the form:
  // virtual  Layer1CTP7(uint32_t phi) = 0;
	
  virtual ~Layer1CTP7() {;}

  // Since we don't construct an object of this type there is no 
  // constructor specified.  The actual implementation can specify
  // IP address / port parameters in the public constructor 

  // We want to routinely make sure that connection to CTP7 is good

  virtual bool checkConnection() = 0;

  virtual bool getPhi(uint32_t &phi) = 0;



  // Layer-1 CTP7 boards can be configured to either in normal run
  // mode where data is simply played through, or in playback mode
  // when data from playback buffers is processed and played out
  // There is a special test mode for debugging purpose
  // The idle mode should disable output links

  enum Layer1RunMode {
    normal = 0x0,
    playBack = 0x1,
    testMode = 0x2,
    idleMode = 0xF,
    unknown = 0xFF
  };

  // Configuration string for conveniently storing user information
  // This is just an arbitrary string that can be set and retrieved
  // and is left to the user to maintain -- it has no bearing on the
  // CTP7 or its functionality

  virtual bool getConfiguration(Layer1RunMode &m, std::string &output) = 0;
  virtual bool setConfiguration(Layer1RunMode mode, std::string input) = 0;

  // Resets
  // These functions reset the CTP7 firmware to a known status

  virtual bool hardReset() = 0;
  virtual bool softReset() = 0;

  // Link Alignment and status

  virtual bool alignInputLinks(uint32_t bx) = 0;

  typedef struct LinkStatusSummary {
    uint32_t rawLinkStatus;
    uint32_t linkRunning;
    uint32_t linkAligned;
    uint32_t checkSumErrorCount;
    uint32_t bx0ErrorCount;
    uint32_t bx0Latency;
  } LinkStatusSummary;

  virtual bool getInputLinkStatus(std::vector<LinkStatusSummary> &linkSummary) = 0;
  virtual bool getOutputLinkStatus(std::vector<LinkStatusSummary> &linkSummary) = 0;

  // Special functions for controlling input / output capture

  enum CaptureState {
    Idle = 0,
    Armed = 1, 
    Capturing = 2,
    Done = 3
  };

  typedef struct CaptureStatus {
    uint16_t localBXId;
    uint16_t linkBXId;
    CaptureState s;
  } CaptureStatus;

  enum CaptureMode {
    localBXAligned = 0,
    linkBXAligned = 1
  };

  virtual bool getInputCaptureStatus(std::vector<CaptureStatus> &c) = 0;
  virtual bool captureInput(CaptureMode mode, uint32_t startBXCounter) = 0;

  virtual bool getOutputCaptureStatus(std::vector<CaptureStatus> &c) = 0;
  virtual bool captureOutput(CaptureMode mode, uint32_t startBXCounter) = 0;

  // Functions to write / read BRAM

  // Input Capture and Playback BRAM is the same physical BRAM.
  // Functionally we read input capture BRAM and set playback BRAM.
  // There are 16 ECAL, 14 HCAL and 2 HF BRAMs per eta side, each of 1K 32-bit word blocks
  // So these functions get or set 32 blocks of 1K 32-bit words all together
  // or a selected block to avoid unnecessarily large data transport

  enum InputLink {
    ECAL_Link_0 = 0x00,
    ECAL_Link_1 = 0x01,
    ECAL_Link_2 = 0x02,
    ECAL_Link_3 = 0x03,
    ECAL_Link_4 = 0x04,
    ECAL_Link_5 = 0x05,
    ECAL_Link_6 = 0x06,
    ECAL_Link_7 = 0x07,
    ECAL_Link_8 = 0x08,
    ECAL_Link_9 = 0x09,
    ECAL_Link_10 = 0x0a,
    ECAL_Link_11 = 0x0b,
    ECAL_Link_12 = 0x0c,
    ECAL_Link_13 = 0x0d,
    ECAL_Link_14 = 0x0e,
    ECAL_Link_15 = 0x0f,

    HCAL_Link_0 = 0x10,
    HCAL_Link_1 = 0x11,
    HCAL_Link_2 = 0x12,
    HCAL_Link_3 = 0x13,
    HCAL_Link_4 = 0x14,
    HCAL_Link_5 = 0x15,
    HCAL_Link_6 = 0x16,
    HCAL_Link_7 = 0x17,
    HCAL_Link_8 = 0x18,
    HCAL_Link_9 = 0x19,
    HCAL_Link_10 = 0x1a,
    HCAL_Link_11 = 0x1b,
    HCAL_Link_12 = 0x1c,
    HCAL_Link_13 = 0x1d,

    HF_Link_0 = 0x1e,
    HF_Link_1 = 0x1f
  };

  virtual bool resetRxDecoder(bool negativeEta, InputLink link) = 0;

  virtual bool checksumCounterReset(bool negativeEta, InputLink link) = 0;
  virtual bool bx0CounterReset(bool negativeEta, InputLink link) = 0;

  virtual bool setLinkAlignmentMask(bool negativeEta, InputLink link) = 0;
  virtual bool getLinkAlignmentMask(bool negativeEta, InputLink link) = 0;

  virtual bool setTowerMask(bool negativeEta, InputLink link, uint32_t mask) = 0;
  virtual bool getTowerMask(bool negativeEta, InputLink link, uint32_t &mask) = 0;

  virtual bool getInputCaptureBRAM(bool negativeEta, InputLink link, std::vector<uint32_t> &selectedData) = 0;
  virtual bool setPlaybackBRAM(bool negativeEta, InputLink link,  std::vector<uint32_t> &selectedData) = 0;

  // There are 24 output buffers corresponding to the 24 output links each for positive and negative eta
  // Each buffer corresponds to a memory block of 1K 32-bit words

  enum OutputLink {
    Link_00 = 0x00,
    Link_01 = 0x01,
    Link_02 = 0x02,
    Link_03 = 0x03,
    Link_04 = 0x04,
    Link_05 = 0x05,
    Link_06 = 0x06,
    Link_07 = 0x07,
    Link_08 = 0x08,
    Link_09 = 0x09,
    Link_10 = 0x0a,
    Link_11 = 0x0b,
    Link_12 = 0x0c,
    Link_13 = 0x0d,
    Link_14 = 0x0e,
    Link_15 = 0x0f,
    Link_16 = 0x10,
    Link_17 = 0x11,
    Link_18 = 0x12,
    Link_19 = 0x13,
    Link_20 = 0x14,
    Link_21 = 0x15,
    Link_22 = 0x16,
    Link_23 = 0x17
  };

  virtual bool getOutputCaptureBRAM(bool negativeEta, OutputLink link, std::vector<uint32_t> &data) = 0;
  virtual bool setOutputCaptureBRAM(bool negativeEta, OutputLink link, std::vector<uint32_t> &data) = 0; // This function is for testing purpose only

  // There are 28x 2kB E/HCAL LUT BRAMs (one BRAM per iEta, 1-28) in EB+EE / HB+HE region
  // There are 6x 4kB HF LUT BRAMs (one BRAM per iEta)

  enum TowerEtaIndex {
    iEta_01 = 0x01,
    iEta_02 = 0x02,
    iEta_03 = 0x03,
    iEta_04 = 0x04,
    iEta_05 = 0x05,
    iEta_06 = 0x06,
    iEta_07 = 0x07,
    iEta_08 = 0x08,
    iEta_09 = 0x09,
    iEta_10 = 0x0a,
    iEta_11 = 0x0b,
    iEta_12 = 0x0c,
    iEta_13 = 0x0d,
    iEta_14 = 0x0e,
    iEta_15 = 0x0f,
    iEta_16 = 0x10,
    iEta_17 = 0x11,
    iEta_18 = 0x12,
    iEta_19 = 0x13,
    iEta_20 = 0x14,
    iEta_21 = 0x15,
    iEta_22 = 0x16,
    iEta_23 = 0x17,
    iEta_24 = 0x18,
    iEta_25 = 0x19,
    iEta_26 = 0x1a,
    iEta_27 = 0x1b,
    iEta_28 = 0x1c,
    iEta_30_31 = 0x1f,
    iEta_32_33 = 0x21,
    iEta_34_35 = 0x23,
    iEta_36_37 = 0x25,
    iEta_38_39 = 0x27,
    iEta_40_41 = 0x29
  };

  virtual bool getLUTs(bool negativeEta, InputLink link, TowerEtaIndex iEta, std::vector<uint32_t> &lut) = 0;
  virtual bool setLUTs(bool negativeEta, InputLink link, TowerEtaIndex iEta, std::vector<uint32_t> &lut) = 0;

  // Transmit side configuration

  enum TxMode {
    data = 0,
    pattern = 1
  };

  virtual bool setTxMode(TxMode value = data) = 0;
  virtual bool getTxMode(TxMode &value) = 0;

  virtual bool setTxPattern(bool negativeEta, OutputLink link, uint32_t value) = 0;
  virtual bool getTxPattern(bool negativeEta, OutputLink link, uint32_t &value) = 0;

  virtual bool setTxLinkID(bool negativeEta, OutputLink link, uint32_t value) = 0;
  virtual bool getTxLinkID(bool negativeEta, OutputLink link, uint32_t &value) = 0;

  enum OutputLinkPair {
    LinkPair_00 = 0x00,
    LinkPair_01 = 0x01,
    LinkPair_02 = 0x02,
    LinkPair_03 = 0x03,
    LinkPair_04 = 0x04,
    LinkPair_05 = 0x05,
    LinkPair_06 = 0x06,
    LinkPair_07 = 0x07,
    LinkPair_08 = 0x08,
    LinkPair_09 = 0x09,
    LinkPair_10 = 0x0a,
    LinkPair_11 = 0x0b
  };

  virtual bool setTMTCycle(OutputLinkPair olPair, uint32_t value) = 0;
  virtual bool setTMTCycle(OutputLinkPair olPair, uint32_t &value) = 0;

  virtual bool setTMTInterval(uint32_t value = 10) = 0;
  virtual bool getTMTInterval(uint32_t &value) = 0;

  virtual bool alignOutputLinks(uint32_t bx = 0) = 0;


  virtual bool getFWBuildTimestamp(uint32_t &value) = 0;
  virtual bool getFWGitHashCode(uint32_t &value) = 0;
  virtual bool getFWGitDirtyBit(uint32_t &value) = 0;
  virtual bool getFWVersion(uint32_t &value) = 0;
  virtual bool getFWProjectCode(uint32_t &value) = 0;

  // Get V7 firmware uptime in seconds (since the last configuration) 
  virtual bool getFWUptime(uint32_t &value) = 0;

private:

};

#endif

