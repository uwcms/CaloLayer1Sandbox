#ifndef _caloStage1_ts_cell_Cell_h_
#define _caloStage1_ts_cell_Cell_h_

#include "swatchcell/framework/SwatchCellAbstract.h"


namespace CaloStage1TSCell
{
  class Cell : public swatchcellframework::SwatchCellAbstract
  {
  public:

    XDAQ_INSTANTIATOR();

    Cell(xdaq::ApplicationStub * s);

    ~Cell();

    void init();

  private:
    Cell(const Cell&);
  };

}

#endif
