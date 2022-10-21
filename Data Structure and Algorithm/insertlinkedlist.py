
class Node:
 
   t
    def __init__(self, x):
        self.x = x 
        self.next = None 
 
 
class LinkedList:
 
    def __init__(self):
        self.head = Nxone
 
    def push(self, new_x):
 
      
        new_node = Node(new_x)
 
       
        new_node.next = self.head
 
        self.head = new_node
 
 
 
    def insertAfter(self, prev_node, new_x):

        if prev_node is None:
            print("The given previous node must inLinkedList.")
            return
 
        
        new_node = Node(new_data)
 
        new_node.next = prev_node.next
 
       
        prev_node.next = new_node
 
 
    def append(self, new_data):
 
 
        new_node = Node(new_data)
 
   
        if self.head is None:
            self.head = new_node
            return
 
       
        last = self.head
        while (last.next):
            last = last.next
 
    
        last.next =  new_node
 
 
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data,end=" ")
            temp = temp.next
 
 

if __name__=='__main__':
 

    llist = LinkedList()
 

    llist.append(6)
 

    llist.push(7);
 
    llist.push(1);
 
  
    llist.append(4)
 
   
    llist.insertAfter(llist.head.next, 8)
 
    print('Created linked list is: ')
    llist.printList()
