#include <iostream>
#include "gdal_priv.h"
#include "cpl_conv.h" // for CPLMalloc()

int main(int argc, char** argv) {
    GDALDataset *poDataset;
    GDALAllRegister();
    poDataset = (GDALDataset *) GDALOpen(argv[1], GA_ReadOnly);
    if (poDataset != NULL) {
        double adfGeoTransform[6];
        std::cout << "Driver: " << poDataset->GetDriver()->GetDescription() << " / " <<
                    poDataset->GetDriver()->GetMetadataItem(GDAL_DMD_LONGNAME) << std::endl;
        std::cout << "Size is " << poDataset->GetRasterXSize() << " x " << poDataset->GetRasterYSize() <<
                    " x " << poDataset->GetRasterCount() << std::endl;
        if(poDataset->GetProjectionRef() != NULL)
            std::cout << "Projection is " << poDataset->GetProjectionRef() << std::endl;
//        if(poDataset->GetGeoTransform(adfGeoTransform) == CE_None)
        if(poDataset->GetGeoTransform(adfGeoTransform)) {
            std::cout << "Origin = (" << adfGeoTransform[0] << ", " << adfGeoTransform[3] << ")" << std::endl;
            std::cout << "Pixel Size = (" << adfGeoTransform[1] << ", " << adfGeoTransform[5] << ")" << std::endl;
        }
        /*****************************/
        /*** Transform Coordinates ***/
        /*****************************/
        OGRSpatialReference source, target;

        source.importFromEPSG(4326);
        target.importFromEPSG(5186);

        OGRPoint p;
        p.setX(127.723625);
        p.setY(34.727303);
        p.assignSpatialReference(&source);
        p.transformTo(&target);

        // transformed coordinates
        std::cout << p.getX() << " | " << p.getY() << std::endl;
        return 0;
    }
    return 0;
}