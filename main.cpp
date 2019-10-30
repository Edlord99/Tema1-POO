#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class stiva;
class nod
{
    char info;
    nod* next;
    public:
    nod(char, nod*);
    ~nod();
    friend class stiva;
    friend ostream& operator<<(ostream&, stiva&);
    friend istream& operator>>(istream&, stiva&);
};

class stiva
{
    nod* v;
    public:
    stiva();
    ~stiva();
    void push(char);
    void pop();
    void top();
    void isempty();
    friend ostream& operator<<(ostream&, stiva&);
    friend istream& operator>>(istream&, stiva&);
    stiva& operator-(stiva);
    void invers(char*);
    void citire(int,stiva*&);
};

nod::nod(char a='0',nod*urm=NULL)
{
    this->info=a;
    this->next=urm;
}

nod::~nod()
{
}

stiva::stiva()
{
    this->v=new nod;
    this->v=NULL;
}

stiva::~stiva()
{
    while(this->v!=NULL)//cat timp nu am terminat elementel din stiva
    {nod *temp=this->v;//salvez adresa varfului curent
    this->v=this->v->next;//mut varful pe un nivel mai jos
    delete temp;}//sterg fostul varf
}

void stiva::push(char a)
{
    nod*temp=new nod;//creez un nou loc in stiva
    temp->info=a;//introduc informatia
    temp->next=this->v;//o leg la stiva existenta
    this->v=temp;//actualizez varful stivei
}

void stiva::pop()
{
    nod* temp=this->v;//salvez adresa varfului curent
    this->v=this->v->next;//mut varful pe un nivel mai jos
    delete temp;//sterg fostul varf

}

void stiva::top()
{
    if(this->v==NULL)cout<<"Stiva vida";//verfic daca exista elemente in stiva
    else cout<<this->v->info<<endl;//afisez informatia
}

void stiva::isempty()
{
    if(v==NULL)//verfic daca exista elemte in stiva
        cout<<"Stiva este vida"<<endl;
    else
        cout<<"Stiva mai are caractere"<<endl;
}

ostream& operator<<(ostream& out, stiva& ob)
{
    while(ob.v!=NULL)//cat timp mai am elemente in stiva
    {nod *temp=ob.v;//salvez adresa varfului cursnt
    out<<temp->info<<" ";//afisez informatia
    ob.v=ob.v->next;//mut varful pe un nivel mai jos
    delete temp;}//sterg fostul varf
    return out;//returnez fluxul
}

istream& operator>>(istream& in, stiva& ob)
{
    char a;
    in>>a;//citesc informatia
    while(a>=97&&a<=122)//verfic sa fie o litera lowercase.pentru a incheia citirea pun la sfarsitul sirului un caracter de terminare de exemplu '.'
    {
        ob.push(a);//o introduc in stiva
        in>>a;//continui citirea
    }
    return in;//returnez fluxul
}

void stiva::invers(char* a)
{
    for(int i=0;i<strlen(a);i++)
        this->push(a[i]);//introduc caracter cu caracter sirul in stiva
    cout<<*this;//afisez stiva,golind-o in acelasi timp
}

stiva& stiva::operator-(stiva ob)
{
    stiva* temp=new stiva;
    while(this->v!=NULL&&ob.v!=NULL)//cat timp am elemente in ambele stive
    {if(this->v->info>ob.v->info)//compar codurile ascii
        temp->push(this->v->info);//introduc pe cel mai mare
    else
        temp->push(ob.v->info);
    this->pop();ob.pop();//trec la urmatorul nivel de elemente
    }
    return *temp;//returnez stiva nou creata
}

void stiva::citire(int n,stiva*& s)
{
    stiva*temp=new stiva[n+1];//aloc memorie
    for(int i=0;i<n;i++)
        cin>>temp[i];//citesc pe rand stivele.
        s=temp;//salvez citirile
}

int main()
{
    char c='a';int a=0;int b;int n=0;
    srand(time(NULL));
    while(c)
    {
        cout<<"Meniu de operare:"<<endl<<"0 - Oprire"<<endl<<"1 - Initializare"<<endl<<"2 - Push"<<endl;
        cout<<"3 - Pop"<<endl<<"4 - Top"<<endl<<"5 - IsEmpty"<<endl<<"6 - Invers"<<endl;
        cout<<"7 - Diferenta"<<endl<<"8 - Citire"<<endl<<"9 - Afisare"<<endl<<"d - Delete"<<endl<<endl;
        cout<<"Optiune: ";cin>>c;cout<<endl;
        switch(c)
        {int x;char p;char*sir;int i,j,k;
        case '0': cout<<"Programul se inchide..."<<a<<"%"<<endl;_sleep(1000);while(a!=100){x=rand()*rand();x=a+x%(100-a+1);a=x;if(a!=b)cout<<"Programul se inchide..."<<a<<"%"<<endl;b=a;_sleep(1000);};c=0;break;
        case '1': stiva *s;cout<<"Numar de stive: ";cin>>n;s= new stiva[n+1];break;
        case '2': if(n==0)cout<<"Nu ai initializat.";else {cout<<"In ce stiva introduc?: ";cin>>i;cout<<"Caracter de introdus: ";cin>>p;s[i].push(p);};break;
        case '3': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Din ce stiva scot?: ";cin>>i;s[i].pop();};break;
        case '4': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva te intereseaza?: ";cin>>i;s[i].top();};break;
        case '5': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva te intereseaza?: ";cin>>i;s[i].isempty();};break;
        case '6': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva sa folosesc?: ";cin>>i;cout<<"Sirul este: ";sir=new char[20];cin>>sir;s[i].invers(sir);};break;
        case '7': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Intre ce stive sa fac diferenta?: ";cin>>i>>j;cout<<"In ce stiva pun rezultatul?: ";cin>>k;s[k]=s[i]-s[j];cout<<s[k];};break;
        case '8': if(n==0)cout<<"Nu ai initializat.";else {cout<<"In ce stiva citesc?(toate=n+1): ";cin>>i;if(i!=n+1)cin>>s[i];else s->citire(n,s);};break;
        case '9': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva sa afisez?: ";cin>>i;cout<<s[i];};break;
        case 'd': if(n==0)cout<<"Nu ai initializat.";else {cout<<"Ce stiva sa sterg?: ";cin>>i;s[i].~stiva();};break;
        default: cout<<"Nu ai introdus o comanda corecta!"<<endl;
        }
        cout<<endl;
    }

    return 0;
}
