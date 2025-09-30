#include <iostream>
#include <string>
using namespace std;

struct Passenger{
    string name;
    Passenger* next;
    Passenger(string n):name(n),next(nullptr){}
};

struct Flight{
    string flightNo;
    Passenger* head;
    Flight* next;
    Flight(string f):flightNo(f),head(nullptr),next(nullptr){}
};

class Airline{
    Flight* flights;
public:
    Airline(){ flights=nullptr; }

    Flight* findFlight(string fno){
        Flight* f=flights;
        while(f){
            if(f->flightNo==fno) return f;
            f=f->next;
        }
        return nullptr;
    }

    void addFlight(string fno){
        if(findFlight(fno)){ cout<<"Flight already exists\n"; return; }
        Flight* f=new Flight(fno);
        f->next=flights;
        flights=f;
        cout<<"Flight "<<fno<<" added\n";
    }

    void reserve(string fno,string name){
        Flight* f=findFlight(fno);
        if(!f){ cout<<"No such flight\n"; return; }
        Passenger* p=new Passenger(name);
        if(!f->head || name<f->head->name){
            p->next=f->head;
            f->head=p;
            cout<<"Reserved "<<name<<" on "<<fno<<endl;
            return;
        }
        Passenger* cur=f->head;
        while(cur->next && cur->next->name<name) cur=cur->next;
        if(cur->name==name || (cur->next && cur->next->name==name)){
            cout<<"Already reserved\n"; delete p; return;
        }
        p->next=cur->next;
        cur->next=p;
        cout<<"Reserved "<<name<<" on "<<fno<<endl;
    }

    void cancel(string fno,string name){
        Flight* f=findFlight(fno);
        if(!f){ cout<<"No such flight\n"; return; }
        if(!f->head){ cout<<"No passengers\n"; return; }
        if(f->head->name==name){
            Passenger* t=f->head;
            f->head=f->head->next;
            delete t;
            cout<<"Canceled "<<name<<" from "<<fno<<endl;
            return;
        }
        Passenger* cur=f->head;
        while(cur->next && cur->next->name!=name) cur=cur->next;
        if(!cur->next){ cout<<"Not found\n"; return; }
        Passenger* t=cur->next;
        cur->next=cur->next->next;
        delete t;
        cout<<"Canceled "<<name<<" from "<<fno<<endl;
    }

    void check(string fno,string name){
        Flight* f=findFlight(fno);
        if(!f){ cout<<"No such flight\n"; return; }
        Passenger* cur=f->head;
        while(cur){
            if(cur->name==name){ cout<<name<<" has reservation on "<<fno<<endl; return; }
            cur=cur->next;
        }
        cout<<name<<" not reserved on "<<fno<<endl;
    }

    void showPassengers(string fno){
        Flight* f=findFlight(fno);
        if(!f){ cout<<"No such flight\n"; return; }
        if(!f->head){ cout<<"No passengers on "<<fno<<endl; return; }
        cout<<"Passengers of "<<fno<<":\n";
        Passenger* cur=f->head;
        while(cur){ cout<<cur->name<<endl; cur=cur->next; }
    }

    void showFlights(){
        if(!flights){ cout<<"No flights\n"; return; }
        Flight* f=flights;
        while(f){
            cout<<"Flight "<<f->flightNo<<endl;
            Passenger* cur=f->head;
            while(cur){ cout<<"  "<<cur->name<<endl; cur=cur->next; }
            f=f->next;
        }
    }
};

int main(){
    Airline a;
    int ch; string fno,name;
    do{
        cout<<"\n1.Add flight 2.Reserve 3.Cancel 4.Check 5.Show passengers 6.Show all flights 7.Exit\n";
        cin>>ch;
        if(ch==1){ cout<<"Flight no: "; cin>>fno; a.addFlight(fno); }
        else if(ch==2){ cout<<"Flight no: "; cin>>fno; cout<<"Name: "; cin>>name; a.reserve(fno,name); }
        else if(ch==3){ cout<<"Flight no: "; cin>>fno; cout<<"Name: "; cin>>name; a.cancel(fno,name); }
        else if(ch==4){ cout<<"Flight no: "; cin>>fno; cout<<"Name: "; cin>>name; a.check(fno,name); }
        else if(ch==5){ cout<<"Flight no: "; cin>>fno; a.showPassengers(fno); }
        else if(ch==6){ a.showFlights(); }
    }while(ch!=7);
}
