#include <iostream>
#include "CharLinkedList.h"


int main() {
    char comp[6] = {'C', 'O', 'M', 'P', '1', '5'};
    char fifteen[7] = {'f', 'i', 'f', 't', 'e', 'e', 'n'};

    CharLinkedList linkedListComp(comp, 6);
    CharLinkedList linkedListFifteen(fifteen, 7);
    CharLinkedList linkedListEmpty;

    //before
    //Should print - [CharLinkedList of size 6 <<COMP15>>]
    linkedListComp.print();
    //Should print - [CharLinkedList of size 7 <<fifteen>>]
    linkedListFifteen.print();
    //Should print - [CharLinkedList of size 0 <<>>]
    linkedListEmpty.print();

    //test concatenate()
    std::cout << "Testing concatenate\n";

    //test nonempty with empty
    linkedListComp.concatenate(&linkedListEmpty);
    //Should print - [CharLinkedList of size 6 <<COMP15>>]
    linkedListComp.print();

    //test empty with nonempty
    linkedListEmpty.concatenate(&linkedListComp);
    //Should print - [CharLinkedList of size 6 <<COMP15>>]
    linkedListEmpty.print();

    //test empty with empty
    linkedListComp.concatenate(&linkedListFifteen);
    //Should print - [CharLinkedList of size 13 <<COMP15fifteen>>]
    linkedListComp.print();

    //test on self
    linkedListEmpty.concatenate(&linkedListEmpty);
    //Should print - [CharLinkedList of size 13 <<COMP15COMP15>>]
    linkedListEmpty.print();

    return 0;
}
