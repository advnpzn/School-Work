# Implementation of Single Linked List in Python

class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None


def length_of_linked_list(linked_list):
    temp = linked_list.head
    length = 0
    while temp is not None:
        length += 1
        temp = temp.next
    return length


def add_element(linked_list):
    val = int(input("Enter the Value to Insert : "))
    new_node = Node(val)
    if is_empty(linked_list):
        linked_list.head = new_node
    else:
        temp = linked_list.head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node
    print("\nAdded element.")
    print_list(linked_list)
    options(linked_list)


def insert_node(linked_list):
    i = 1
    temp = linked_list.head
    print_list(linked_list)
    pos = int(input("\nEnter the position where you want to insert the Value : "))
    if pos > length_of_linked_list(linked_list):
        print("Incorrect Position !")
        insert_node(linked_list)
    val = int(input("Enter the Value to Insert : "))
    new_node = Node(val)
    if pos != 1:
        while i < pos - 1:
            temp = temp.next
            i += 1
        new_node.next = temp.next
        temp.next = new_node
    else:
        new_node.next = temp
        linked_list.head = new_node
    print(f"\nInserted {val} at position {pos}.")
    print_list(linked_list)
    options(linked_list)


def delete_node(linked_list):
    temp = linked_list.head
    if temp is not None:
        i = 1
        print_list(linked_list)
        pos = int(input("\nEnter the position where you want to Delete the Value : "))
        if pos > length_of_linked_list(linked_list):
            print("Incorrect Position !")
            delete_node(linked_list)
        if pos != 1:
            while i < pos - 1:
                temp = temp.next
                i += 1
            temp.next = temp.next.next
        else:
            linked_list.head = temp.next
        print(f"\nInserted value at position {pos}.")
        print_list(linked_list)
    else:
        print("Linked List is Already Empty!")
    options(linked_list)


def find_middle(linked_list):
    if linked_list.head is not None:
        slow = linked_list.head
        fast = linked_list.head
        while (fast and fast.next) is not None:
            slow = slow.next
            fast = fast.next.next
        print(f"\nThe Middle element is {slow.data}")
    else:
        print("Linked List is Empty!")
    options(linked_list)


def is_empty(linked_list):
    temp = linked_list.head
    if temp is None:
        return True
    else:
        return False


def print_list(linked_list):
    l_elems = []
    temp = linked_list.head
    while temp is not None:
        l_elems.append(temp.data)
        temp = temp.next
    print(*l_elems, sep='-->')


def options(linked_list):
    print("\n1. Add an Element\n"
          "2. Insert an Element\n"
          "3. Delete an Element\n"
          "4. Find Middle element\n"
          "5. Check if Empty\n"
          "6. Print Linked List\n"
          "7. Exit\n")
    chosen = int(input("Enter the Choice : "))
    try:
        if chosen == 1:
            add_element(linked_list)
        elif chosen == 2:
            insert_node(linked_list)
        elif chosen == 3:
            delete_node(linked_list)
        elif chosen == 4:
            find_middle(linked_list)
        elif chosen == 5:
            print("EMPTY" if is_empty(linked_list) else "NOT EMPTY")
            options(linked_list)
        elif chosen == 6:
            print_list(linked_list)
            options(linked_list)
        elif chosen == 7:
            exit(0)
        else:
            print("Choose from 1-7")
            options(linked_list)
    except ValueError:
        print("Choose a number.")
        options(linked_list)


def main():
    print("LINKED LIST IMPLEMENTATION :\n")
    linked_list = LinkedList()
    temp = None
    no_of_nodes = int(input("Enter the no.of nodes to be inserted : "))
    for i in range(no_of_nodes):
        val = int(input("Enter the Value : "))
        if linked_list.head is None:
            linked_list.head = Node(val)
            temp = linked_list.head
        else:
            next_node = Node(val)
            temp.next = next_node
            temp = next_node
    options(linked_list)


if __name__ == '__main__':
    main()
