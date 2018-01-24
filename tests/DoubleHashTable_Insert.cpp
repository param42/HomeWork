#include <DoubleHashTable.h>
#include "catch.hpp"


SCENARIO("When you add an item, the size increases")
{
    GIVEN("DoubleHashTable ")
    {
        DoubleHashTable dht;
        dht.insert(54,34);
        dht.insert(12, 16);
        auto count = dht.getSize();

        WHEN("inserting an element")
        {
            dht.insert(42,42);
            dht.insert(33, 34);
            dht.insert(11,32);
            THEN("the number of elements is increased by the number of inserts")
            {
                REQUIRE( dht.getSize() == count + 3);
            }
        }
    }
}
