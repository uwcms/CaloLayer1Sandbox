#include "caloStage1/ts/cell/Cell.h"

XDAQ_INSTANTIATOR_IMPL(caloStage1TSCell::Cell)

caloStage1TSCell::Cell::Cell(xdaq::ApplicationStub * s) :
swatchcellframework::SwatchCellAbstract(s)
{}


caloStage1TSCell::Cell::~Cell()
{}


void caloStage1TSCell::Cell::init()
{
  addGenericSwatchComponents();
}

