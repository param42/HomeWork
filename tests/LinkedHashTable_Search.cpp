#include <LinkedHashTable.h>
#include "catch.hpp"


SCENARIO("search an element in LinkedHashTable")
{
    GIVEN("LinkedHashTable")
    {
        LinkedHashTable linkht;
        linkht.insert(3,823);
        linkht.insert(24,92);
        linkht.insert(30,8);
        linkht.insert(432,36);

        WHEN("search for the element")
        {
            int key = linkht.search(30).first;
            int data = linkht.search(30).second;

            THEN("return found element")
            {
                REQUIRE(key == 30);
                REQUIRE(data == 8);
            }
        }
    }
}

SCENARIO("search an element in empty LinkedHashTable")
{
    GIVEN("empty LinkedHashTable")
    {
        LinkedHashTable linkht;

        WHEN("trying to find an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(linkht.search(324), std::logic_error);
            }
        }
    }
}
