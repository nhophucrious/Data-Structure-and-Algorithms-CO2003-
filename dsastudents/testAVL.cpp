#include <iostream>
#include <tree/AVL.h>
#include <tree/BST.h>
int main()
{
    AVL<int, int *> tree;
    cout << "REQUIRE(tree.empty() == true)\nis Tree empty?: " << tree.empty() << endl;

    // cout << "SUBCASE(Removing => no re-balance)" << endl;
    // {
    //     int keys[] = {50, 30, 70, 20, 40, 60, 80};
    //     for(int idx=0; idx < 7; idx++) tree.add(keys[idx]);
    //     cout << "REQUIRE(tree.size() == 7)" << endl;
    //     cout << "Size: " << tree.size() << endl;

    //     tree.remove(20);
    //     cout << "REQUIRE(tree.size() == 6)" << endl;
    //     cout << "Size: " << tree.size() << endl;

    //     tree.remove(40);
    //     cout << "REQUIRE(tree.size() == 5)" << endl;
    //     cout << "Size: " << tree.size() << endl;

    //     int nodes_exp1[] = {50, 30, 70, 60, 80};
    //     string bfactor_exp1[] = {sEH, sEH, sEH, sEH, sEH};

    //     List<string> factor1 = tree.bfactor();
    //     factor1.contains(bfactor_exp1, 5);
    //     List<int> nodes1 = tree.bfsKey();
    //     nodes1.contains(nodes_exp1, 5);
    // }

    cout << "SUBCASE(Simple tree: LHoLH => rotateRight)" << endl;
    int keys[] = {50, 40, 30};
    string bfactor_exp[] = {sEH, sEH, sEH};
    for (int idx = 0; idx < 3; idx++)
        tree.add(keys[idx]);
    cout << "REQUIRE(tree.size() == 3)" << endl;
    cout << "Size: " << tree.size() << endl;

    cout << "REQUIRE(tree.height() == 2);" << endl;
    cout << "Height: " << tree.height() << endl;

    DLinkedList<string> factor = tree.bfactor();
    cout << "REQUIRE(factor.size() == 3);" << endl;
    cout << "Factor: " << factor.size() << endl;

    cout << "REQUIRE(factor.contains(bfactor_exp, 3) == true)" << endl;
    cout << "Fator.contains: " << factor.contains(bfactor_exp, 3) << endl;

    return 0;
}