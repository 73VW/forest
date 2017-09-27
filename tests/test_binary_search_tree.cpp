#include "catch.hpp"
#include <forest/binary_search_tree.h>

SCENARIO("Test Binary Search Tree") {
        GIVEN("A Binary Search Tree") {
                forest::binary_search_tree <int, int> binary_search_tree;
                WHEN("The Binary Search Tree is empty") {
                        THEN("Test empty") {
                                REQUIRE(binary_search_tree.empty() == true);
                        }
                        THEN("Test size") {
                                REQUIRE(binary_search_tree.size() == 0);
                        }
                        THEN("Test height") {
                                REQUIRE(binary_search_tree.height() == 0);
                        }
                        THEN("Test maximum") {
                                auto max = binary_search_tree.maximum();
                                REQUIRE(max == nullptr);
                        }
                        THEN("Test minimum") {
                                auto min = binary_search_tree.minimum();
                                REQUIRE(min == nullptr);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = binary_search_tree.search(555);
                                REQUIRE(result == nullptr);
                        }
                }
                WHEN("Nodes are inserted in random order") {
                        REQUIRE(binary_search_tree.insert(4 , -10) != nullptr);
                        REQUIRE(binary_search_tree.insert(2 ,  30) != nullptr);
                        REQUIRE(binary_search_tree.insert(90, -74) != nullptr);
                        REQUIRE(binary_search_tree.insert(3 ,   1) != nullptr);
                        REQUIRE(binary_search_tree.insert(0 ,-110) != nullptr);
                        REQUIRE(binary_search_tree.insert(14,   0) != nullptr);
                        REQUIRE(binary_search_tree.insert(45,   0) != nullptr);
                        THEN("Test empty") {
                                REQUIRE(binary_search_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(binary_search_tree.size() == 7);
                        }
                        THEN("Test height") {
                                REQUIRE(binary_search_tree.height() == 4);
                        }
                        THEN("Test maximum") {
                                auto max = binary_search_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 90);
                                REQUIRE(max->value == -74);
                        }
                        THEN("Test minimum") {
                                auto min = binary_search_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == -110);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = binary_search_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = binary_search_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 1);
                        }
                }
                WHEN("Nodes are inserted in ascending order") {
                        for (int i = 0; i < 10; i++) {
                                REQUIRE(binary_search_tree.insert(i, i*i) != nullptr);
                        }
                        THEN("Test empty") {
                                REQUIRE(binary_search_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(binary_search_tree.size() == 10);
                        }
                        THEN("Test height") {
                                REQUIRE(binary_search_tree.height() == 10);
                        }
                        THEN("Test maximum") {
                                auto max = binary_search_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 9);
                                REQUIRE(max->value == 81);
                        }
                        THEN("Test minimum") {
                                auto min = binary_search_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == 0);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = binary_search_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = binary_search_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 9);
                        }
                }
                WHEN("Nodes are inserted in descending order") {
                        for (int i = 9; i >= 0; i--) {
                                REQUIRE(binary_search_tree.insert(i, i*i) != nullptr);
                        }
                        THEN("Test empty") {
                                REQUIRE(binary_search_tree.empty() == false);
                        }
                        THEN("Test size") {
                                REQUIRE(binary_search_tree.size() == 10);
                        }
                        THEN("Test height") {
                                REQUIRE(binary_search_tree.height() == 10);
                        }
                        THEN("Test maximum") {
                                auto max = binary_search_tree.maximum();
                                REQUIRE(max != nullptr);
                                REQUIRE(max->key == 9);
                                REQUIRE(max->value == 81);
                        }
                        THEN("Test minimum") {
                                auto min = binary_search_tree.minimum();
                                REQUIRE(min != nullptr);
                                REQUIRE(min->key == 0);
                                REQUIRE(min->value == 0);
                        }
                        THEN("Test search for a node that does not exist") {
                                auto result = binary_search_tree.search(1337);
                                REQUIRE(result == nullptr);
                        }
                        THEN("Test search for a node that does exist") {
                                auto result = binary_search_tree.search(3);
                                REQUIRE(result != nullptr);
                                REQUIRE(result->key == 3);
                                REQUIRE(result->value == 9);
                        }
                }
        }
}
