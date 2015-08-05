#include "CaloLayer1/ts/cell/Cell.h"

XDAQ_INSTANTIATOR_IMPL(CaloStage1TSCell::Cell)

CaloStage1TSCell::Cell::Cell(xdaq::ApplicationStub * s) :
swatchcellframework::SwatchCellAbstract(s)
{}


CaloStage1TSCell::Cell::~Cell()
{}


void CaloStage1TSCell::Cell::init()
{
  addGenericSwatchComponents();
}

