#include <LinearHashTable.h>
#include "catch.hpp"


SCENARIO("search an element in LinearHashTable")
{
    GIVEN("LinearHashTable")
    {
        LinearHashTable lht;
        lht.insert(3,823);
        lht.insert(24,92);
        lht.insert(30,8);
        lht.insert(432,36);

        WHEN("search for the element")
        {
            int key = lht.search(30).first;
            int data = lht.search(30).second;

            THEN("return found element")
            {
                REQUIRE(key == 30);
                REQUIRE(data == 8);
            }
        }
    }
}

SCENARIO("search an element in empty LinearHashTable")
{
    GIVEN("empty LinearHashTable")
    {
        LinearHashTable lht;

        WHEN("trying to find an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(lht.search(324), std::logic_error);
            }
        }
    }
}
