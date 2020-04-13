#include <exiv2/exiv2.hpp>

#include <string>
#include <iostream>
#include <iomanip>
#include <cassert>

int main(int argc, char** argv)
{
    Exiv2::XmpParser::initialize();
    ::atexit(Exiv2::XmpParser::terminate);

    try
    {
        if (argc != 2)
        {
            std::cout << "Usage: " << argv[0] << " file\n";
            return 1;
        }

        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(argv[1]);
        assert (image.get() != 0);
        image->readMetadata();

        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
            std::string error("No Exif data found in file");
            throw Exiv2::Error(Exiv2::kerErrorMessage, error);
        }

        Exiv2::XmpData &xmpData = image->xmpData();
        if (xmpData.empty()) {
            std::string error(argv[1]);
            error += ": No XMP data found in the file";
            throw Exiv2::Error(Exiv2::kerErrorMessage, error);
        }

        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Exif.Image.Make" << exifData["Exif.Image.Make"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Exif.Image.Orientation" << exifData["Exif.Image.Orientation"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Exif.Photo.FocalLength" << exifData["Exif.Photo.FocalLength"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Exif.GPSInfo.GPSLatitude" << exifData["Exif.GPSInfo.GPSLatitude"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Exif.GPSInfo.GPSLongitude" << exifData["Exif.GPSInfo.GPSLongitude"] << std::endl;

        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Xmp.drone-dji.RelativeAltitude" << xmpData["Xmp.drone-dji.RelativeAltitude"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Xmp.drone-dji.GimbalRollDegree" << xmpData["Xmp.drone-dji.GimbalRollDegree"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Xmp.drone-dji.GimbalPitchDegree" << xmpData["Xmp.drone-dji.GimbalPitchDegree"] << std::endl;
        std::cout << std::setfill(' ') << std::left << std::setw(44)
                  << "Xmp.drone-dji.GimbalYawDegree" << xmpData["Xmp.drone-dji.GimbalYawDegree"] << std::endl;

        Exiv2::XmpParser::terminate();

        return 0;
    }
    catch (Exiv2::AnyError& e)
    {
        std::cout << "Caught Exiv2 exception '" << e << "'\n";
        return -1;
    }
}