#include <LinearHashTable.h>
#include "catch.hpp"


SCENARIO("When you add an item, the size increases")
{
    GIVEN("LinearHashTable ")
    {
        LinearHashTable lht;
        lht.insert(54,34);
        lht.insert(12, 16);
        auto count = lht.getSize();

        WHEN("inserting an element")
        {
            lht.insert(42,42);
            lht.insert(33, 34);
            lht.insert(11,32);
            THEN("the number of elements is increased by the number of inserts")
            {
                REQUIRE( lht.getSize() == count + 3);
            }
        }
    }
}
