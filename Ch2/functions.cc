#include <iostream>


// function declaration (must be before call)
// can be omitted if declaration if before call
void my_print_function();

// function definition (can be after call)
// will be used as declaration+definition in absence of a declaration
void my_print_function()
{
    std::cout << "Hello, World!\n";
}

int main()
{

    my_print_function(); // function call

    return 0;
}
