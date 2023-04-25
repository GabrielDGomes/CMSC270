Adam Bruce, Gabe Gomes, and Alibek Mamyrbay

1. We are choosing to use a double linked list. This list allows for us to add and remove from any node in the list, which performs all the functions of 
queues and stacks while also allowing removal from the middle. Additionally we will not have to resize at any point, which would be a drawback to the array implementations. 


3. 

- first make a value stoarage variable for storing values less than the order number when traversing the DLList
 
- traverse the list using pointers looking for the node with the largest value less than the order value. Each time a value is less than the order value, store it in the variable. Then, compare the next smaller value to the stored value and replace it if it is bigger than the current stored value. (use +=)

-finally add the node containing the new order value to the position just after the node with the largest smaller value. Increase the number of elements.

Here is a code outline:

addOrder(A)
    max = 0
    for i < n 
        if getnode(i).x > max & < A
            max = i
    addNode(max + 1, A)
    n++
