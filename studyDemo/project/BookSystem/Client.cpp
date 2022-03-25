/**
 * @author ： HeXinGen
 * @date ： 2021/6/16
 * @description ：
 */

#include "Book.h"
#include <iostream>

using namespace ComBook;
using namespace std;

void test() {
    const int size = 1;
    for (int i = 0; i < size; ++i) {
        string name, description;
        name.append("this is name: ").append(to_string(i + 1));
        description.append(" this is description ").append(to_string(i + 1));
        Book book(name, description);
        Block block;
        transform(book, block);
        writeBlock(fileName, block);
    }
    for (int i = 0; i < size; ++i) {
        int currentBookIndex = (i + 1);
        Block block = queryBlockByPosition(fileName, currentBookIndex);
        Book book = transform(block);
        cout << book.getName() << book.getDescription() << endl;
    }
}

int main() {
    test();

    return 0;
}