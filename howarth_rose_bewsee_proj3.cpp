//////////////////////////////////////////////
// Neil Howarth && Paul Rose && Alec Bewsee	//
//				  Project 3					//
//////////////////////////////////////////////

#include <iostream>
#include <algorithm>

using namespace std;

struct node // paul
{
	int data;
	node* next;
};

class linkedlist // paul
{
	public:

        //required functions
		void InsertBeginning(node*, int); //1 insert node at beginning
		void AddNode(node*, int); //2 insert node at the end
		void InsertNode(node*,int,int); //3 insert node at any position
		void SortList(node*); //4 sort link list
		void DeleteNode(node*,int); //5 delete a particular node
		void UpdateNodeValue(node*,int,int); //6 update node value
		void SearchElement(node*,int); //7 search element
		void DisplayList(node*); //8 Display Linked List
		void Reverse(node*); //9 reverse linked list
		void ExitList(bool); //10 exit

		//other functions used
		void InitList(node*, int);//initializes the at a choosen value
		int linked2array(node*,int[]);// converts linked list to an array
		void array2linked(node*,int[],int);//converts array to a linked list

};

int linkedlist::linked2array(node *head, int b[]) // neil
{
	node *list = head;
	int k=0;

	while(list)
	{
		b[k] = list->data;
		list = list->next;
		k++;
	}

	return k;
}

void linkedlist::array2linked(node *head, int b[],int length) // neil
{
	InitList(head,b[0]);

	for(int j=1; j<length; j++)
		AddNode(head,b[j]);
}

void linkedlist::InitList(node *head, int n) // paul
{
	head->data = n;
	head->next = NULL;
}

void linkedlist::InsertBeginning(node *head, int n) //1 // neil
{
	int b[1000];
	int c[1000];

	int j=1;
	int length = linked2array(head,b);

	c[0] = n;

	for(int i=0; i<length+1; i++)
		{
			c[j] = b[i];
			j++;
		}

	array2linked(head,c,length+1);
}

void linkedlist::AddNode(node *head, int n)// 2 // alec
{
	node *newNode = new node;
	newNode->data = n;
	newNode->next = NULL;

	node *cur = head;

	while(cur)
	{
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void linkedlist::InsertNode(node *head, int n, int value)//3 // neil
{
	node *cur = new node;
	cur = head;

	node *newnode = new node;
	newnode->data = value;

	int i = 0;

	while(cur)
	{
		if(i == n-2)
		{
			newnode->next = cur->next;
			cur->next = newnode;
		}
		cur = cur -> next;
		i++;
	}
}

void linkedlist::SortList(node *head) // 4 // alec
{
	int b[1000];
	int length = linked2array(head,b);

	sort(b,b+length);

	array2linked(head,b,length);
}

void linkedlist::DeleteNode(node *head, int n) //5 // neil
{
	node *cur = new node;
	cur = head;
	int i = 1;
	
	if(n==1)
	{
		cur->data=cur->next->data;
		cur->next=cur->next->next;
	}
	
	while(cur)
	{
		if(i == n-1)
			cur->next = cur->next->next;

		cur = cur -> next;
		
		i++;
	}
}

void linkedlist::UpdateNodeValue(node *head, int n, int nodevalue)//6 // paul
{
	int b[1000];
	int length = linked2array(head,b);

	b[n-1] = nodevalue;

	array2linked(head,b,length);
}

void linkedlist::SearchElement(node *head, int n) //7 // neil
{
	node *cur = new node;
	cur = head;

	int i = 0, location=-5;

	cout<< "\tThe number "<<n<<" can be found at location(s): ";

	while(cur)
	{
		i++;

		if(cur->data == n)
			cout<<i<<" ";
			//location = i;

		cur = cur -> next;
	}

}

void linkedlist::DisplayList(node *head) // 8 // alec
{
    cout << endl;
	node *list = head;
	while(list)
	{
		cout << "| " << list->data << " ";
		list = list->next;
	}
	cout << "|" << endl;
	cout << endl;
}

void linkedlist::Reverse(node *head) // neil
{
	int b[1000];
	int c[1000];
	int j=0;
	int length = linked2array(head,b);

	for(int i=length-1; i>=0; i--)
		{
			c[j] = b[i];
			j++;
		}

	array2linked(head,c,length);
}

void linkedlist::ExitList(bool x) // paul
{
	x = true;
}

void HeaderMenu() // alec
{
	cout << endl;
	cout << "Enter the operation (1-10) you would like to perform\n" << '\n';
	cout << "1) Insert node at the beginning\n";
	cout << "2) Insert node at the end\n";
	cout << "3) Insert Node at any position\n";
	cout << "4) Sort the linked list\n";
	cout << "5) Delete a particular node\n";
	cout << "6) Update node value\n";
	cout << "7) Search element\n";
	cout << "8) Display Linked List\n";
	cout << "9) Reverse Linked List\n";
	cout << "10) Exit Program";
	cout << endl << endl;
}

int main()
{
	// Beginning of output - paul
	cout<<"Neil Howarth & Paul Rose & Alec Bewsee - Project 3\n";
	cout << "____________________________________________________" << endl;

	// Declare variables 
	node *a = new node;
	linkedlist list;
	bool exitgame = false;
	int choice;
	int start;

    // initialize the list at a user specified value - neil
	cout<<"What value should the list start at? ";
	cin >> start;
	list.InitList(a,start);
	list.DisplayList(a);

    // main loop
	do
	{
        int value=0,location=0;
		HeaderMenu();
		cout << "Input: ";
		cin >> choice;

		switch (choice) // alec
		{
			case 1:
				cout << "\tYou chose to insert node at the beginning\n";
				cout << "\tEnter the value for the node: ";
				cin >> value;
                list.InsertBeginning(a,value);
                list.DisplayList(a);
				break;
			case 2:
				cout << "\tYou chose to insert node at the end\n";
                cout << "\tEnter the value for the node: ";
				cin >> value;
                list.AddNode(a,value);
                list.DisplayList(a);
				break;
			case 3:
				cout << "\tYou chose to insert node at any position\n";
                cout << "\tEnter the value for the node: ";
				cin >> value;
				cout << "\tEnter the location for the node: ";
				cin >> location;
                list.InsertNode(a,location,value);
                list.DisplayList(a);
				break;
			case 4:
				cout << "\tYou chose to sort the Linked List\n";
                list.SortList(a);
                list.DisplayList(a);
				break;
			case 5:
				cout << "\tYou chose to delete a particular node\n";
				cout << "\tChoose the location of the node you wish to delete: ";
				cin >> location;
				list.DeleteNode(a,location);
                list.DisplayList(a);
				break;
			case 6:
				cout << "\tYou chose to update node value\n";
				cout << "\tEnter the location of the node you would like to update: ";
				cin >> location;
				cout << "\tEnter the new node value: ";
				cin >> value;
				list.UpdateNodeValue(a,location,value);
                list.DisplayList(a);
				break;
			case 7:
				cout << "\tYou chose to search element\n";
				cout << "\tEnter the value you wish to search for: ";
				cin >> location;
				list.SearchElement(a,location);
                list.DisplayList(a);
				break;
			case 8:
				cout << "\tYou chose to display linked list\n";
				list.DisplayList(a);
				break;
			case 9:
				cout << "\tYou chose to reverse linked list\n";
				list.Reverse(a);
                list.DisplayList(a);
				break;
			case 10:
				cout << "\tGoodbye!!!\n";
				exitgame = true;
				break;
			default:
				cout << "\tInvalid entry\n";
		}

	}while(!exitgame);

}

