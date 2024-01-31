#include "./Serializer.hpp"

static void initData(Data& data, int num, const std::string& str);

int main(void)
{
    Data        dataA;
    Data        dataB;
    Data*       dataRaw;
    uintptr_t   dataPtr;

    initData(dataA, 100, "cpp06");
    initData(dataB, 125, "hahaha");

    dataPtr = Serializer::serialize(&dataA);
    dataRaw = Serializer::deserialize(dataPtr);
    std::cout << "dataA:   address(" << &dataA << ")num(" << dataA.num << "), str(" << dataA.str << ")" << std::endl;
    std::cout << "dataRaw: num(" << dataRaw->num << "), str(" << dataRaw->str << ")" << std::endl;

    dataPtr = Serializer::serialize(&dataB);
    dataRaw = Serializer::deserialize(dataPtr);
    std::cout << "dataB:   num(" << dataB.num << "), str(" << dataB.str << ")" << std::endl;
    std::cout << "dataRaw: num(" << dataRaw->num << "), str(" << dataRaw->str << ")" << std::endl;

    return 0;
}

static void initData(Data& data, int num, const std::string& str)
{
    data.num = num;
    data.str = str;
}
