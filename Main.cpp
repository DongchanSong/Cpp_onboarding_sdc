#include "FcInputImpl.h"

int main()
{
    FcInputImpl *fcM300 = new FcInputImpl_M300();
    VehicleData *dataM300 = fcM300->FromApiToMc();

    FcInputImpl *fcM600 = new FcInputImpl_M600();
    VehicleData *dataM600 = fcM600->FromApiToMc();

    FcInputImpl *fcMavic = new FcInputImpl_Mavic();
    VehicleData *dataMavic = fcMavic->FromApiToMc();

    delete fcM300;
    delete fcM600;
    delete fcMavic;

    return 0;
}