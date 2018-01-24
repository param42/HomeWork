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
            s.insert(42,42);
            s.insert(33, 34);
            s.insert(11,32);
            THEN("the number of elements is increased by the number of inserts")
            {
                REQUIRE(s.count() == count + 3);
            }
        }
    }
}
