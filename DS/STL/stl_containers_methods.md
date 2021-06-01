  
 #  ----------------VECTOR--------------

 ##  -------------------ITERATORS METHODS-------------- 

**begin()**  – Returns an iterator pointing to the first element in the vector

**end()**     – Returns an iterator pointing to the theoretical element that follows the last element in the vector

**rbegin()**  – Returns a reverse iterator pointing to the last element in the vector 

**rend()**   – Returns a reverse iterator pointing to the theoretical element preceding the first element 

**cbegin()** – Returns a constant iterator pointing to the first element in the vector.

**cend()**   – Returns a constant iterator pointing to the theoretical element that 
follows the last element     

**crbegin()** – Returns a constant reverse iterator pointing to the last element in the vector (reverse 

**crend()**  – Returns a constant reverse iterator pointing to the theoretical element preceding the first 


#            --------------CAPACITY-----------------------------------


**size()** – Returns the number of elements in the vector.

**max_size()** – Returns the maximum number of elements that the vector can hold.

**capacity()** – Returns the size of the storage space currently allocated to the vector expressed as number of elements.

**resize(n)** – Resizes the container so that it contains ‘n’ elements.

**empty()** – Returns whether the container is empty.

**shrink_to_fit(** – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.

**reserve()** – Requests that the vector capacity be at least enough to contain n elements.


# --------------------ELEMENT ACESS------------------

**reference operator [g]** – Returns a reference to the element at position ‘g’ in the vector

**at(g)** – Returns a reference to the element at position ‘g’ in the vector

**front()** – Returns a reference to the first element in the vector

**back()** – Returns a reference to the last element in the vector

**data()** – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

# ---------------MODIFERS-----------------------

**assign()** – It assigns new value to the vector elements by replacing old ones  

**push_back()** – It push the elements into a vector from the back

**pop_back()** – It is used to pop or remove elements from a vector from the back.

**insert()** – It inserts new elements before the element at the specified position

**erase()** – It is used to remove elements from a container from the specified position or range.

**swap()** – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.

c**lear()** – It is used to remove all the elements of the vector container

**emplace()** – It extends the container by inserting new element at position

**emplace_back()** – It is used to insert a new element into the vector container, the new element is added to the end of the vector 



 # ----------------------STRINGS---------------- 

 #           ---------Input Functions-----------

**getline()**    - This function is used to store a stream of characters as entered by the user in the object memory.

**push_back()**  - This function is used to input a character at the end of the string.

**pop_back()**   - Introduced from C++11(for strings), this function is used to delete the last character from the string.

# ----------------Capacity Functions--------------------

**capacity()** :- This function returns the capacity allocated to the string, which can be equal to or more than the size of the string. Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.

**resize(**) :- This function changes the size of string, the size can be increased or decreased.

**length()**:-This function finds the length of the string

**shrink_to_fit()**** :- This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This operation is useful to save additional memory if we are sure that no further addition of characters have to be made.

# -------------Iterator Functions------------

**begin()** :- This function returns an iterator to beginning of the string.

**end()** :- This function returns an iterator to end of the string.

**rbegin()** :- This function returns a reverse iterator pointing at the end of string.

**rend()** :- This function returns a reverse iterator pointing at beginning of string.

 
# ---------------LIST-----------

**front()**    – Returns the value of the first element in the list.

**back()**     – Returns the value of the last element in the list .

**push_front(g)** – Adds a new element ‘g’ at the beginning of the list .

**push_back(g)** – Adds a new element ‘g’ at the end of the list.

**pop_front(**) – Removes the first element of the list, and reduces size of the list by 1.

**pop_back()** – Removes the last element of the list, and reduces size of the list by 1

**list::begin() and list::end() in C++ STL– begin()** function returns an iterator pointing to the first element of the list

**end()**– end() function returns an iterator pointing to the theoretical last element which follows the last element.

**list rbegin() and rend() function in C++ STL– rbegin()** returns a reverse iterator which points to the last element of the list. rend() returns a reverse iterator which points to the position before the beginning of the list. 

**list cbegin() and cend() function in C++ STL– cbegin()** returns a constant random access iterator which points to the beginning of the list. cend() returns a constant random access iterator which points to the end of the list.

l**ist crbegin() and crend() function in C++ STL**– crbegin() returns a constant reverse iterator which points to the last element of the list i.e reversed beginning of container. crend() returns a constant reverse iterator which points to the theoretical element preceding the first element in the list i.e. the reverse end of the list.

**empty(**) – Returns whether the list is empty(1) or not(0).

**insert()** – Inserts new elements in the list before the element at a specified position.

**erase()** – Removes a single element or a range of elements from the list.

**assign()** – Assigns new elements to list by replacing current elements and resizes the list.

**remove()** – Removes all the elements from the list, which are equal to given element.

**list::remove_if()** in C++ STL– Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.

**reverse()** – Reverses the list.

**size()** – Returns the number of elements in the list.

**list resize()function** in C++ STL– Used to resize a list container.

**sort()** – Sorts the list in increasing order.

**list max_size()**function in C++ STL– Returns the maximum number of elements a list container can hold.

**list unique()**in C++ STL– Removes all duplicate consecutive elements from the list.

**list::emplace_front()** and list::emplace_back() in C++ STL– emplace_front() function is used to insert a new element into the list container, the new element is added to the beginning of the list. emplace_back() function is used to insert a new element into the list container, the new element is added to the end of the list.

**list::clear()** in C++ STL– clear() function is used to remove all the elements of the list container, thus making it size 0.

**list::operator=**in C++ STL– This operator is used to assign new contents to the container by replacing the existing contents.

**list::swap()** in C++ STL– This function is used to swap the contents of one list with another list of same type and size.

**list splice()** function in C++ STL– Used to transfer elements from one list to another.

**list merge()** function in C++ STL– Merges two sorted lists into one

l**ist emplace()** function in C++ STL– Extends list by inserting new element at a given position.


# ---------------STACK ------------------

**empty()** – Returns whether the stack is empty – Time Complexity : O(1) 

**size()** – Returns the size of the stack – Time Complexity : O(1) 

**top()** – Returns a reference to the top most element of the stack – Time Complexity : O(1) 

**push(g)** – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 

**pop()** – Deletes the top most element of the stack – Time Complexity : O(1) 


# --------------DEQUE------------------------


**deque insert()**  function in C++ STL: Inserts an element. And returns an iterator that points to the first of the newly inserted elements.

**deque rbegin(**) function in C++ STL: Returns a reverse iterator which points to the last element of the deque (i.e., its reverse beginning).

**deque rend()** function in C++ STL: Returns a reverse iterator which points to the position before the beginning of the deque (which is considered its reverse end).

**deque cbegin()** in C++ STL: Returns a constant iterator pointing to the first element of the container, that is, the iterator cannot be used to modify, only traverse the deque.

**deque max_size()** function in C++ STL: Returns the maximum number of elements that a deque container can hold.

**deque assign()** function in C++ STL: Assign values to the same or different deque container.

**deque resize()** function in C++ STL: Function which changes the size of the deque.

**deque::push_front()** in C++ STL: This function is used to push elements into a deque from the front.

**deque::push_back()** in C++ STL: This function is used to push elements into a deque from the back.

**deque::pop_front()** and deque::pop_back() in C++ STL: pop_front() function is used to pop or remove elements from a deque from the front. pop_back() function is used to pop or remove elements from a deque from the back.

**deque::front()** and deque::back() in C++ STL: front() function is used to reference the first element of the deque container. back() function is used to reference the last element of the deque container.

**deque::clear()** and deque::erase() in C++ STL: clear() function is used to remove all the elements of the deque container, thus making its size 0. erase() function is used to remove elements from a container from the specified position or range.

**deque::empty()** and deque::size() in C++ STL: empty() function is used to check if the deque container is empty or not. size()** function is used to return the size of the deque container or the number of elements in the deque container.

**deque::operator=** and deque::operator[] in C++ STL:

**operator=** operator is used to assign new contents to the container by replacing the existing contents. operator[] operator is used to reference the element present at position given inside the operator.

**deque::at() and deque::swap()** in C++ STL: at() function is used reference the element present at the position given as the parameter to the function. swap() function is used to swap the contents of one deque with another deque of same type and size.

**deque::begin()**and deque::end in C++ STL: begin() function is used to return an iterator pointing to the first element of the deque container. end() function is used to return an iterator pointing to the last element of the deque container.

**deque::emplace_front()** and deque::emplace_back()** in C++ STL: emplace_front() function is used to insert a new element into the deque container. The new element is added to the beginning of the deque. emplace_back() function is used to insert a new element into the deque container. The new element is added to the end of the deque.**
