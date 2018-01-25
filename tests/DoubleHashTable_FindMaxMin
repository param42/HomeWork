#include <DoubleHashTable.h>
#include "catch.hpp"


SCENARIO("find min in DoubleHashTable")
{
    GIVEN("DoubleHashTable")
    {
        DoubleHashTable dht;
        dht.insert(393,823);
        dht.insert(1,92);
        dht.insert(3,8);
        dht.insert(49,36);

        WHEN("search min")
        {
            int key = dht.getMin().first;
            int data = dht.getMin().second;

            THEN("return min")
            {
                REQUIRE(key == 3);
                REQUIRE(data == 8);
            }
        }
    }
}

SCENARIO("find max in DoubleHashTable")
{
    GIVEN("DoubleHashTable")
    {
        DoubleHashTable dht;
        dht.insert(38,823);
        dht.insert(27,92);
        dht.insert(21,8);
        dht.insert(930,36);

        WHEN("search max")
        {
            int key = dht.getMax().first;
            int data = dht.getMax().second;

            THEN("return max")
            {
                REQUIRE(key == 38);
                REQUIRE(data == 823);
            }
        }
    }
}
