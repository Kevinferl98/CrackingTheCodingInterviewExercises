import java.util.HashSet;

class Node{
    int data;
    Node next;

    Node(int d){
        data = d;
        next = null;
    }
}

class LinkedList{
    Node head;

    public void insert(LinkedList list, int data){
        Node new_node = new Node(data);

        if(list.head == null)
            list.head = new_node;
        else{
            Node last = list.head;
            while(last.next != null)
                last = last.next;
            last.next = new_node;
        }
    }

    public static void printList(LinkedList list){
        Node curr = list.head;

        while(curr!=null){
            System.out.println(curr.data + " ");
            curr = curr.next;
        }
    }
}

class prova{
    
    static void removeDuplicate(Node head){
        Node temp = head;
        Node prev = null;
        Node temp2 = null;

        while(temp!=null){
            int val = temp.data;
            prev = temp;
            temp2 = temp.next;
            while(temp2!=null){
                if(temp2.data == val){
                    prev.next = temp2.next;
                }
                prev = prev.next;
                temp2 = temp2.next;
            }
            temp = temp.next;
        }
    }

    static void removeDuplicateBook(Node head){
        HashSet<Integer> set = new HashSet<Integer>();
        Node prev = null;
        while(head!=null){
            if(set.contains(head.data))
                prev.next = head.next;
            else{
                set.add(head.data);
                prev = head;
            }
            head = head.next;
        }
    }
    
    public static void main(String[] args){
        LinkedList list = new LinkedList();

        list.insert(list, 1);
        list.insert(list, 3);
        list.insert(list, 1);
        list.insert(list, 4);
        list.insert(list, 5);
        list.insert(list, 3);

        list.printList(list);

        removeDuplicate(list.head);

        System.out.println("----");
        list.printList(list);
    }


}