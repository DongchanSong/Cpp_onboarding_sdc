#include "FcInputImpl.h"
#include <memory>

int main()
{
    // FcInputImpl *fcM300 = new FcInputImpl_M300();
    // VehicleData *dataM300 = fcM300->FromApiToMc();

    // FcInputImpl *fcM600 = new FcInputImpl_M600();
    // VehicleData *dataM600 = fcM600->FromApiToMc();

    // FcInputImpl *fcMavic = new FcInputImpl_Mavic();
    // VehicleData *dataMavic = fcMavic->FromApiToMc();

    // FcInputImpl *fcSkydio = new FcInputImpl_Skydio();
    // VehicleData *dataSkydio = fcSkydio->FromApiToMc();

    // delete fcM300;
    // delete fcM600;
    // delete fcMavic;
    // delete fcSkydio;

    // delete dataM300;
    // delete dataM600;
    // delete dataMavic;
    // delete dataSkydio;

    std::shared_ptr<FcInputImpl> fcM300(new FcInputImpl_M300());
    std::shared_ptr<FcInputImpl> fcM600(new FcInputImpl_M600());
    std::shared_ptr<FcInputImpl> fcMavic(new FcInputImpl_Mavic());
    std::shared_ptr<FcInputImpl> fcSkydio(new FcInputImpl_Skydio());

    std::unique_ptr<VehicleData> dataM300(fcM300->FromApiToMc());
    std::unique_ptr<VehicleData> dataM600(fcM600->FromApiToMc());
    std::unique_ptr<VehicleData> dataMavic(fcMavic->FromApiToMc());
    std::unique_ptr<VehicleData> dataSkydio(fcSkydio->FromApiToMc());

    return 0;
}