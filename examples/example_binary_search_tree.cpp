#include <forest/binary_search_tree.h>
#include <iostream>

int main(int argc, char const *argv[]) {
        forest::binary_search_tree::tree <int, int> binary_search_tree;

        binary_search_tree.insert(4,0);
        binary_search_tree.insert(2,0);
        binary_search_tree.insert(90,0);
        binary_search_tree.insert(3,100);
        binary_search_tree.insert(0,0);
        binary_search_tree.insert(14,0);
        binary_search_tree.insert(45,0);

        std::cout << "Pre Order Traversal" << std::endl;
        std::cout << std::endl;
        binary_search_tree.pre_order_traversal();
        std::cout << std::endl;

        std::cout << "In Order Traversal" << std::endl;
        std::cout << std::endl;
        binary_search_tree.in_order_traversal();
        std::cout << std::endl;

        std::cout << "Post Order Traversal" << std::endl;
        std::cout << std::endl;
        binary_search_tree.post_order_traversal();
        std::cout << std::endl;

        std::cout << "Breadth First Traversal" << std::endl;
        std::cout << std::endl;
        binary_search_tree.breadth_first_traversal();
        std::cout << std::endl;

        auto min = binary_search_tree.minimum();
        if (min != nullptr) {
                std::cout << "Minimum: " << min->key << std::endl;
        }

        auto max = binary_search_tree.maximum();
        if (max != nullptr) {
                std::cout << "Maximum: " << max->key << std::endl;
        }

        std::cout << "Height: " << binary_search_tree.height() << std::endl;

        std::cout << "Size: " << binary_search_tree.size() << std::endl;

	std::cout << "Empty: " << (binary_search_tree.empty() ? "yes" : "no") << std::endl;

        auto n = binary_search_tree.search(3);
        if (n != nullptr) {
                std::cout << std::endl;
                std::cout << "Found node with key 3" << std::endl;
                std::cout << std::endl;
                n->info();
        }

        return 0;
}
