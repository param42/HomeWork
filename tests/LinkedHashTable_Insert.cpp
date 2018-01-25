#include <LinkedHashTable.h>
#include "catch.hpp"


SCENARIO("When you add an item, the size increases")
{
    GIVEN("LinkedHashTable ")
    {
        LinkedHashTable linkht;
        linkht.insert(54,34);
        linkht.insert(12, 16);
        auto count = linkht.getSize();

        WHEN("inserting an element")
        {
            linkht.insert(42,42);
            linkht.insert(33, 34);
            linkht.insert(11,32);
            THEN("the number of elements is increased by the number of inserts")
            {
                REQUIRE( linkht.getSize() == count + 3);
            }
        }
    }
}
