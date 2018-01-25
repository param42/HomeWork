#include <LinearHashTable.h>
#include "catch.hpp"


SCENARIO("find min in LinearHashTable")
{
    GIVEN("LinearHashTable")
    {
        LinearHashTable lht;
        lht.insert(393,823);
        lht.insert(1,92);
        lht.insert(3,8);
        lht.insert(49,36);

        WHEN("search min")
        {
            int key = lht.getMin().first;
            int data = lht.getMin().second;

            THEN("return min")
            {
                REQUIRE(key == 3);
                REQUIRE(data == 8);
            }
        }
    }
}

SCENARIO("find max in LinearHashTable")
{
    GIVEN("LinearHashTable")
    {
        LinearHashTable lht;
        lht.insert(38,823);
        lht.insert(27,92);
        lht.insert(21,8);
        lht.insert(930,36);

        WHEN("search max")
        {
            int key = lht.getMax().first;
            int data = lht.getMax().second;

            THEN("return max")
            {
                REQUIRE(key == 38);
                REQUIRE(data == 823);
            }
        }
    }
}
