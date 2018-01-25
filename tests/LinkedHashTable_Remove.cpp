#include <LinkedHashTable.h>
#include "catch.hpp"


SCENARIO("When you delete an item in LinkedHashTable, the size decreases")
{
    GIVEN("LinkedHashTable and size")
    {
        LinkedHashTable linkht;
        linkht.insert(43,43);
        linkht.insert(24,922);
        linkht.insert(50,8);
        linkht.insert(432,36);
        auto count = linkht.getSize();

        WHEN("remove an element")
        {
            linkht.remove(50);

            THEN("number of items reduced by one")
            {
                REQUIRE(linkht.getSize() == count - 1);
            }
        }
    }
}

SCENARIO("LinkedHashTable is empty => remove method throws an exception")
{
    GIVEN("empty LinkedHashTable")
    {
        LinkedHashTable linkht;

        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(linkht.remove(324), std::logic_error);
            }
        }
    }
}


SCENARIO("removing element doesn't exist in LinkedHashTable => remove method throws an exception")
{
    GIVEN("LinkedHashTable")
    {
        LinkedHashTable linkht;
        linkht.insert(3,823);
        linkht.insert(24,92);
        linkht.insert(30,8);
        linkht.insert(432,36);
        WHEN("trying to remove an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(linkht.remove(324), std::logic_error);
            }
        }
    }
}
