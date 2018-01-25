#include <LinearHashTable.h>
#include "catch.hpp"


SCENARIO("When you delete an item, the size decreases")
{
    GIVEN("LinearHashTable and size")
    {
        LinearHashTable lht;
        lht.insert(43,43);
        lht.insert(24,922);
        lht.insert(50,8);
        lht.insert(432,36);
        auto count = lht.getSize();

        WHEN("remove an element")
        {
            lht.remove(50);

            THEN("number of items reduced by one")
            {
                REQUIRE(lht.getSize() == count - 1);
            }
        }
    }
}

SCENARIO("LinearHashTable is empty => remove method throws an exception")
{
    GIVEN("empty LinearHashTable")
    {
        LinearHashTable lht;

        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(lht.remove(324), std::logic_error);
            }
        }
    }
}


SCENARIO("removing element doesn't exist => remove method throws an exception")
{
    GIVEN("LinearHashTable")
    {
        LinearHashTable lht;
        lht.insert(3,823);
        lht.insert(24,92);
        lht.insert(30,8);
        lht.insert(432,36);
        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(lht.remove(324), std::logic_error);
            }
        }
    }
}
