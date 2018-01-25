#include <DoubleHashTable.h>
#include "catch.hpp"


SCENARIO("When you delete an item in DoubleHashTable, the size decreases")
{
    GIVEN("DoubleHashTable and size")
    {
        DoubleHashTable dht;
        dht.insert(43,43);
        dht.insert(24,922);
        dht.insert(50,8);
        dht.insert(432,36);
        auto count = dht.getSize();

        WHEN("remove an element")
        {
            dht.remove(50);

            THEN("number of items reduced by one")
            {
                REQUIRE(dht.getSize() == count - 1);
            }
        }
    }
}

SCENARIO("DoubleHashTable is empty => remove method throws an exception")
{
    GIVEN("empty DoubleHashTable")
    {
        DoubleHashTable dht;

        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(dht.remove(324), std::logic_error);
            }
        }
    }
}


SCENARIO("removing element doesn't exist in DoubleHashTable => remove method throws an exception")
{
    GIVEN("DoubleHashTable")
    {
        DoubleHashTable dht;
        dht.insert(3,823);
        dht.insert(24,92);
        dht.insert(30,8);
        dht.insert(432,36);
        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(dht.remove(324), std::logic_error);
            }
        }
    }
}
