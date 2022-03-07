#include <bits/stdc++.h>

using namespace std;

string name;
int i,j,k,a,b,c,n;
double P,A,B,C;

vector <int> Info[1000];
vector <string> Name[1000];
stack < pair<string,int> > Customer;
priority_queue < pair<double,int> > Waiting_List,Flight_List;

void Instruction();
void Build_Priority_Queue();
void Show_Queue(priority_queue < pair<double,int> > FirstQueue);
void Build_Stack(priority_queue < pair<double,int> > FirstStack);
void Show_Stack();
int Calculation(int x,int y,int z);

int main()
{
    system("Color 70");
    cout << "\n\n\t\tInput Passenger's Information According to the Instruction.\n";
    cout << "\n\t\t-> To Know the Instruction and Run the Program, Please Press 0.\n";
    cout << "\t\t-> To Run the Program Direct, Please Press 1.\n";
    cout << "Input: ";

    char press;
    while (cin >> press)
    {
        if (press=='0')
        {
            Instruction();
            break;
        }
        else if (press=='1')
            break;
        else
        {
            cout << "\tInvalid Input. Please Input 0 or 1.\n";
            cout << "Input: ";
        }
    }
    Build_Priority_Queue();
    Show_Queue(Waiting_List);
    Build_Stack(Flight_List);
    Show_Stack();
}

void Instruction()
{
    cout << "\n\n\tWelcome\n\n";
    cout << "\tThank You to Choose Our Service.";
    cout << "\n\n\tPlease Input Following Information:\n";
    cout << "\n\t\t1.Your First Name.";
    cout << "\n\t\t2.Your's Total Mileage in the Past Year.";
    cout << "\n\t\t3.The Number of Years You frequent in flier program.";
    cout << "\n\t\t4.Your's Arrival Position When You Booked the Flight.";
    cout << "\n\n\tThank You.\n\n";
}

int Calculation(int x,int y,int z)
{
    A = x;
    B = y;
    C = z;
    return (((A/(1000*1.0))+B)-C);
}

void Build_Priority_Queue()
{
    int t;
    cout << "\n\n\tHow Many Passenger are Waiting for the Ticket: ";
    cin >> k;
    t = k;
    cout << "\n\tHow Many Seats are Available: ";
    cin >> n;
    i =- 1;
    cout << endl;

    while (k--)
    {
        i++;

        cin >> name;
        Name[i].push_back(name);

        cin >> a >> b >> c;

        Info[i].push_back(a);
        Info[i].push_back(b);
        Info[i].push_back(c);

        P = Calculation(a,b,c);

        Waiting_List.push(make_pair((i*-1),P));
        Flight_List.push(make_pair(P,i));
    }
}

void Show_Queue(priority_queue < pair<double,int> > FirstQueue)
{
    priority_queue < pair<double,int> > NewQueue = FirstQueue;

    cout << "\n\n\tThe list of Customer's According to Sequence With Priority Number.";
    cout << "\n\n\t\tName\t     Sequence\tPriority Number\n\n";
    while (!NewQueue.empty())
    {
        i = NewQueue.top().first;
        i *= -1;

        for (j=0; j<Name[j].size(); j++)
            cout << "\t\t" << Name[i][j];

        cout << "\t\t" << ((NewQueue.top().first)*-1)+1 << "\t\t" << NewQueue.top().second << endl;

        NewQueue.pop();
    }
}

void Build_Stack(priority_queue < pair<double,int> > FirstStack)
{
    priority_queue < pair<double,int> > NewStack = FirstStack;

    cout << "\n\n\tThe List of Customer's Name Who Will Get The Ticket According to Priority.\n\n";
    while (n--)
    {
        i = NewStack.top().second;

        cout << "\t\t" << Name[i][0] << endl;

        Customer.push(make_pair(Name[i][0],i));

        NewStack.pop();
    }
}

void Show_Stack()
{
    int h;
    cout << "\n\n\tThe Information of The Customers Who Get the Ticket.";
    cout << "\n\n\t\tName\tMileage\tYears\tSequence\n\n";
    while (!Customer.empty())
    {
        h = Customer.top().second;

        cout << "\t\t" << Customer.top().first << "\t";

        for (j=0; j<Info[j].size(); j++)
            cout << Info[h][j] << "\t";

        cout << endl;

        Customer.pop();
    }
}
