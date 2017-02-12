#Program - The Abstract Data Type


The primary purpose is to support operators with your classes: =, +, +=, ==, !=, and the ability to input/output data, as appropriate. Think about how these operators might apply to your classes. For example, the + and += might be used to add a game to the heap, the == and != might be used to determine if a location has already been played. The >> could be used to determine where the player wants to move and the << would display the current board.

2. Should it be a modifiable lvalue or an rvalue? Lvalues are returned by reference, most rvalues are returned by value.
3. What are the data types of the operator’s operands? Remember to pass as a constant reference whenever possible.
4. Is the first operand always an object of class? If so, then it should be a member function.
5. Can the operator be used with constant operands? If the first operand can be a constant, and IF it is a member function, then it should be a constant member function.