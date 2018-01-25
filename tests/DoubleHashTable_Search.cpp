#include <DoubleHashTable.h>
#include "catch.hpp"


SCENARIO("search an element in DoubleHashTable")
{
    GIVEN("DoubleHashTable")
    {
        DoubleHashTable dht;
        dht.insert(3,823);
        dht.insert(24,92);
        dht.insert(30,8);
        dht.insert(432,36);

        WHEN("search for the element")
        {
            int key = dht.search(30).first;
            int data = dht.search(30).second;

            THEN("return found element")
            {
                REQUIRE(key == 30);
                REQUIRE(data == 8);
            }
        }
    }
}

SCENARIO("search an element in empty DoubleHashTable")
{
    GIVEN("empty DoubleHashTable")
    {
        DoubleHashTable dht;

        WHEN("trying to find an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(dht.search(324), std::logic_error);
            }
        }
    }
}
