#include <QDateTime>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "cereal/archives/json.hpp"
#include <cereal/types/vector.hpp>
#include "cereal_qt_types.hpp"



struct Point
{
    Point() = default;

    int x = 0;
    int y = 0;

    template <class Archive> void serialize(Archive & anArchive)
    {
        anArchive(
            CEREAL_NVP(x), CEREAL_NVP(y)
        );
    }
};


struct DataStruct
{
    QDateTime dateTime;
    uint16_t x = 0;
    int32_t y = 0;
    std::string z;

    std::vector<Point> pointCloud;

    template <class Archive> void serialize(Archive & anArchive)
    {
        anArchive(
            CEREAL_NVP(dateTime),
            CEREAL_NVP(x), CEREAL_NVP(y),
            CEREAL_NVP(z),
            CEREAL_NVP(pointCloud)
        );
    }
};



void dumpDataStruct(DataStruct const& data)
{
    std::cout << " dateTime:    " << qPrintable(data.dateTime.toString()) << std::endl;
    std::cout << " x:           " << data.x << std::endl;
    std::cout << " y:           " << data.y << std::endl;
    std::cout << " z:           " << data.z << std::endl;
    std::cout << " pointCloud:  " << data.pointCloud.size() << " points " << std::endl;

    for(auto const& p : data.pointCloud)
    {
        std::cout << "      x:      " << p.x << std::endl;
        std::cout << "      y:      " << p.y << std::endl;
    }
}



void write(const char* aFileName)
{
    DataStruct data;
    data.dateTime = QDateTime::currentDateTime();
    data.x = 12345;
    data.y = -123456789;
    data.z = "sample string";
    data.pointCloud =
    {
        {1, 1}, {2, 2}
    };

    std::ofstream os(aFileName, std::ios::binary);
    cereal::JSONOutputArchive archive(os);
    archive(cereal::make_nvp("DataStruct", data));

    std::cout << "Wrote: " << aFileName << std::endl;
}



void read(const char* aFileName)
{
    std::ifstream os(aFileName, std::ios::binary);
    cereal::JSONInputArchive archive(os);

    DataStruct data;
    archive(cereal::make_nvp("DataStruct", data));

    std::cout << "Read: " << aFileName << std::endl;
    dumpDataStruct(data);
}



int main()
{
    auto const fileName = "E:/x.json";
    write(fileName);
    read(fileName);
}
