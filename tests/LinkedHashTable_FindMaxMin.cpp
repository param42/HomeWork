#include <LinkedHashTable.h>
#include "catch.hpp"


SCENARIO("find min in LinkedHashTable")
{
    GIVEN("LinkedHashTable")
    {
        LinkedHashTable linkht;
        linkht.insert(393,823);
        linkht.insert(1,92);
        linkht.insert(3,8);
        linkht.insert(49,36);

        WHEN("search min")
        {
            int key = linkht.getMin().first;
            int data = linkht.getMin().second;

            THEN("return min")
            {
                REQUIRE(key == 3);
                REQUIRE(data == 8);
            }
        }
    }
}

SCENARIO("find max in LinkedHashTable")
{
    GIVEN("LinkedHashTable")
    {
        LinkedHashTable linkht;
        linkht.insert(38,823);
        linkht.insert(27,92);
        linkht.insert(21,8);
        linkht.insert(930,36);

        WHEN("search max")
        {
            int key = linkht.getMax().first;
            int data = linkht.getMax().second;

            THEN("return max")
            {
                REQUIRE(key == 38);
                REQUIRE(data == 823);
            }
        }
    }
}
