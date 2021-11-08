#include <iostream>

int main()
{
    int example[5];
    int* ptr = example;

    example[2] = 5;
    
    std::cout << "Prior to modifcations, idx 2 is " << example[2] << std::endl;

    // Change value by using the ptr
    *(ptr + 2) = 2;
    std::cout << "First mod using integer pointer: " << example[2] << std::endl;

    // Cast pointer into char ptr, then change values
    *(int*)((char*)ptr + 8) = 6;
    std::cout << "Second mod using char pointer: " << example[2] << std::endl;



    /*for (int i = 0; i < 5; i++)
    {
        std::cout << example[i] << std::endl;
    }*/
    
    
    
}
