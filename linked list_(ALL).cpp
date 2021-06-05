#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node*next;

  node(int data){
    this->data=data;
    next=NULL;
  }
};

void insertAtTail(node* &head,int data){
  if(head==NULL){
    head = new node(data);
    return;
  }
  node* temp = head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next = new node(data);
  return;
}

node* kReverse(node *head,int k){
	//base case
	if(head==NULL){
		return NULL;
	}

	//reverse the first k nodes
	node* prev = NULL;
	node* current = head;
	node * temp;
	int cnt = 0;

	while(current!=NULL and cnt<=k){
		//store next
		temp = current->next;
		//update the current
		current->next = prev;

		//prev and current
		prev = current;
		current = temp;
		cnt++;
	}

	if(temp!=NULL){
		 head->next = kReverse(temp,k);
	}
	return prev;
}

void printLL(node *head){
  while(head!=NULL){
    cout<<head->data<<"->";
      head=head->next;
}
}

node* kAppend(node* &head,int k){
  node* fast = head;
  node* slow = head;
  node* oldhead = head;

  while(k--){
    fast = fast->next;
  }
  while(fast->next!=NULL and fast!=NULL){
    fast=fast->next;
    slow=slow->next;
  }
  node* newhead = slow->next;
  slow = NULL;
  fast->next = oldhead;
  return newhead;
  
}

void evenOdd(node* &head){
  node* evenstart = NULL;
  node* evenend = NULL;
  node* oddstart = NULL;
  node* oddend = NULL;
  node* curr = head;

  while(curr!=NULL){
    int val = curr->data;
    if(val%2==0){
      if(evenstart==NULL){
        evenstart = curr;
        evenend = evenstart;
      }
      else{
        evenend->next = curr;
        evenend = evenend->next;
      }
    }
    else{
      if(oddstart == NULL){
        oddstart = curr;
        oddend = oddstart;
      }
      else{
        oddend->next = curr;
        oddend = oddend->next;
      }
    }
    curr = curr->next;
  }
  if(evenstart == NULL or oddstart == NULL){
    return;
  }
  oddend->next = evenstart;
  evenend->next = NULL;
  head = oddstart;
}

node* kthFromLast(node* &head,int k){
  node* fast = head;
  node* slow = head;
  node* oldhead = head;

  while(k--){
    fast = fast->next;
  }
  while(fast->next!=NULL and fast!=NULL){
    fast=fast->next;
    slow=slow->next;
  }
  return newhead;
  
}


// node* evenAfterOdd(node* &head){
//   node* temp = head;
//   while(temp->next==NULL and temp!=NULL){
//     if((temp->data)%2!=2){
//       temp = temp->next;

//     }
//     insertAtTail(head, temp->data);
//     temp = temp->next;
//   }
//   return head;
// }

bool cycleDetect&Remove(node* head){
  node* fast = head;
  node* slow = head;
  while(slow!=fast){
    fast = fast->next->next;
    slow = slow->next;
  }
  if(fast==NULL or slow==NULL){
    //no cycle present 
    return false;
  }
  //corner case
  if(fast->next == head){
    fast->next = NULL;
    return true;
  }
  slow = head;
  while(slow->next!=fast->next){
    fast = fast->next;
    slow = slow->next;
  }
  fast->next = NULL;
  return true;
}

node *intersectionOfTwoLinkedLists(node *l1, node *l2)
{
    //point of intersection 2 LL
    node* a=l1;
    node* b=l2;
    while(a!=b){
      a = a==NULL ? l1:a->next;
      b = b==Null ? l2:b->next;

    }
    return a;

}

node* merge(node *a, node* b){
	//Complete this method
	//base case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	//rec case
	node * c;

	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}
int main(){
  node*a=NULL;
  node*b=NULL;
  node*head = NULL;
  int t;
  cin>>t;
  
  while(t--){
    
    int data1;//,data2;
    cin>>data1;
    insertAtTail(head,data1);
    //cin>>data2;
    //insertAtTail(b,data2);
  }
  int k;
  cin>>k;
  //kReverse(head, k);
  //printLL(head);
  //merge(a,b);
  //kAppend(head,k);
  evenAfterOdd(head);
  printLL(head);

  return 0;
}