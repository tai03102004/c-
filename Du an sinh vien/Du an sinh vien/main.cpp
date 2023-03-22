#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<locale>
#include <vector>
#include <algorithm>
#include <set>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <Windows.h>
#else
#include<unistd.h>
#endif

#include"print_utlis.h"
using namespace std;


const string data_file = "data.txt";

const int Good_Point =8;
const int Normal_Point = 5;

void loopFiger(const vector<string> & figeres){
    unsigned index=0;
    while (true){
        for(int i=0;i<=30;i++) cout <<endl;
        cout << figeres[index++];
        if (index>= figeres.size()) index=0;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void displayWarning(){
    const vector<string> figure = {
         "   O \n"
         "  /|\\ \n"
         "  | | \n",
         "   O \n"
         "  /|\\ \n"
         "  / \\ \n",
         " __O__ \n"
         "   | \n"
         "  / \\ \n",
         "  \\O/ \n"
         "   | \n"
         "  / \\ \n",
         " __O__ \n"
         "   | \n"
         "  / \\ \n",
         "   O \n"
         "  /|\\ \n"
         "  / \\ \n" ,
         "   O/ \n"
         "   |\\ \n"
         "  / \\ \n" ,
         "   O/  hehehe\n"
         "   |\\ \n"
         "  / \\ \n" ,
    };
    loopFiger(figure);
}

void displayLearning(){
    vector<string> figeres={"fix1"};
    loopFiger(figeres);
}

void displayFinalResult(bool won){
    if (won){
        displayWarning();
    }
    else {
        displayLearning();
    }
}

struct Student{
    int _STT;
    string _full_name;
    int _age;
    double _score;
    Student* _next= NULL;
    Student(){}
    Student(int STT,string full_name,int age,double score){
        _STT =STT;
        _full_name=full_name;
        _age = age;
        _score =score;
    }
    // Student (const* Student other){
        
    // }
};
struct StudentList{
    Student* head =NULL;
    ////////////////////////////////////////////////////////////////////////////////
    /****************** Main Function ******************/
    ///////////////////////////////////////////////////////////////////////////////
    void init(){
        ifstream data(data_file);
        string info;
        
        while (getline(data,info)){
            
             stringstream ss(info);
             string word;
             vector<string> v;
             while (getline(ss,word,';')){
                 v.push_back(word);
             }
             Student* student = new Student;
             student->_STT=stoi(v[0]);
             student->_full_name=(v[1]);
             student->_age=stoi(v[2]);
             student->_score=stod(v[3]);
             
            append(student);
        }
        data.close();
    }
    Student* makeNode(int STT,string fullname,int age,double score){
        Student* newNode = new Student;
        newNode->_STT = STT;
        newNode->_full_name = fullname;
        newNode->_age = age;
        newNode->_score=score;
        newNode->_next = NULL;
        return newNode;
    }
    void print(){
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        
        int order =1 ;
        Student* p=head;
        while (p!=NULL){
            print_row(p->_STT,p->_full_name,p->_age,p->_score);
            p=p->_next;
        }
        if (order ==0){
            print_row(" "," "," "," ");
        }
        print_row();
    }
    void append(int STT,string name,int age,float score){
        append (new Student(STT,name,age,score));
    }
     int dem1(){
          int d=0;
          Student* p=head;
          while (p!=NULL){
               d++;
               p=p->_next;
          }
          return d;
     }
    void append(Student* student){
        if (head==NULL){
            head= student;
            return ;
        }
        Student* p =head;
        while (p->_next !=NULL){
            p=p->_next;
        }
        p->_next = student;
    }
    void repair1(int k){
        Student* p =head;
         int m=dem1();
         if (k>m || k<1){
              cout <<"\t(!)Moi ban nhap lai: ";
              return ;
         }
        if (k==1){
            head=head->_next;
            delete(p);
            return;
        }
        for (int i=1;i<k-1;i++){
            p=p->_next;
        }
        Student* tmp=p->_next;
        p->_next = tmp->_next;
        delete(tmp);
    }
    void repair2(int STT,string fullname,int age,double score,int k){
        Student* newNode =makeNode(STT,fullname,age,score);
        if (k==1){
            if (head==NULL) head = newNode;
            newNode->_next=head;
            head = newNode;
            return;
        }
        Student* p =head;
        for (int i=1;i<=k-2;i++){
            p=p->_next;
        }
        newNode->_next = p->_next;
        p->_next = newNode;
    }
    void find1(int k){
        Student* p =head;
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        if (k==1){
            print_row(p->_STT,p->_full_name,p->_age ,p->_score);
            return;
        }
        for (int i=1;i<=k-1;i++){
            p=p->_next;
        }
        print_row(p->_STT,p->_full_name,p->_age ,p->_score);
        print_row();
    }
    void sx (Student* student){
        Student* p =head;
        for (auto i=p;i!=NULL;i=i->_next){
            auto min=i;
            for (auto j=i->_next;j!=NULL;j=j->_next){
                if (j->_score > min->_score){
                    min=j;
                }
                swap(min->_STT,j->_STT);
                swap(min->_score,j->_score);
                swap(min->_full_name,j->_full_name);
                swap(min->_age,j->_age);
            }
        }
    }
    void sx1 (Student* student){
        Student* p =head;
        for (auto i=p;i!=NULL;i=i->_next){
            auto min=i;
            for (auto j=i->_next;j!=NULL;j=j->_next){
                if (j->_score < min->_score){
                    min=j;
                }
                swap(min->_STT,j->_STT);
                swap(min->_score,j->_score);
                swap(min->_full_name,j->_full_name);
                swap(min->_age,j->_age);
            }
        }
    }
    void sx2 (Student* student){
        Student* p =head;
        for (auto i=p;i!=NULL;i=i->_next){
            auto min=i;
            for (auto j=i->_next;j!=NULL;j=j->_next){
                if (j->_age > min->_age){
                    min=j;
                }
                swap(min->_STT,j->_STT);
                swap(min->_score,j->_score);
                swap(min->_full_name,j->_full_name);
                swap(min->_age,j->_age);
            }
        }
    }
    void sx3 (Student* student){
        Student* p =head;
        for (auto i=p;i!=NULL;i=i->_next){
            auto min=i;
            for (auto j=i->_next;j!=NULL;j=j->_next){
                if (j->_age < min->_age){
                    min=j;
                }
                swap(min->_STT,j->_STT);
                swap(min->_score,j->_score);
                swap(min->_full_name,j->_full_name);
                swap(min->_age,j->_age);
            }
        }
    }
    void sx4 (Student* student){
        Student* p =head;
        for (auto i=p;i!=NULL;i=i->_next){
            auto min=i;
            for (auto j=i->_next;j!=NULL;j=j->_next){
                if (j->_full_name > min->_full_name){
                    min=j;
                }
                swap(min->_STT,j->_STT);
                swap(min->_score,j->_score);
                swap(min->_full_name,j->_full_name);
                swap(min->_age,j->_age);
            }
        }
    }
    
    void sx5 (Student* student){
        Student* p =head;
        for (auto i=p;i!=NULL;i=i->_next){
            auto min=i;
            for (auto j=i->_next;j!=NULL;j=j->_next){
                if (j->_full_name < min->_full_name){
                    min=j;
                }
                swap(min->_STT,j->_STT);
                swap(min->_score,j->_score);
                swap(min->_full_name,j->_full_name);
                swap(min->_age,j->_age);
            }
        }
    }
    
    void statictical(){
        double res=0;
        Student* p=head;
        for (auto i=p;i!=NULL;i=i->_next){
            if (res<i->_score){
                res=i->_score;
            }
        }
        cout<<"\t(!) Diem cao nhat la: " <<res <<endl;
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        for (auto i=p;i!=NULL;i=i->_next){
            if (res==i->_score){
                print_row(i->_STT, i->_full_name, i->_age, i->_score);
            }
        }
        print_row();
    }
    void statictical1(){
        double res=100000;
        Student* p=head;
        for (auto i=p;i!=NULL;i=i->_next){
            if (res>=i->_score){
                res=i->_score;
            }
        }
        cout<<"\t(!) Diem thap nhat la: " <<res <<endl;
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        for (auto i=p;i!=NULL;i=i->_next){
            if (res==i->_score){
                print_row(i->_STT, i->_full_name, i->_age, i->_score);
            }
        }
        print_row();
    }
    double dem(){
        int d=0;
        double sum=0;
        Student* p=head;
        while (p!=NULL){
            d++;
            sum+=p->_score*1.0;
            p=p->_next;
        }
        return (sum*1.0)/d;
    }
    void dtkl(){
        double sum=dem();
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        for (auto i=head;i!=NULL;i=i->_next){
            if (i->_score > sum){
                print_row(i->_STT, i->_full_name, i->_age, i->_score);
            }
        }
        print_row();
    }
    void dtkn(){
        double sum=dem();
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        for (auto i=head;i!=NULL;i=i->_next){
            if (i->_score < sum){
                print_row(i->_STT, i->_full_name, i->_age, i->_score);
            }
        }
        print_row();
    }
    void save(){
        ofstream out(data_file);
        
        Student* p=head;
        while (p){
            out<<p->_STT<<";" << p->_full_name <<";" <<p->_age <<";" <<p->_score <<"\n";
            p=p->_next;
        }
        out.close();
    }
    void find2(string word){
        Student* p =head;
        print_row();
        print_row("STT","Ho Ten","Tuoi","Diem");
        print_row();
        while (p != nullptr) {
                if (p->_full_name.find(word) != string::npos) {
                    print_row(p->_STT, p->_full_name, p->_age, p->_score);
                }
                p = p->_next;
            }
        print_row();
    }
     void find3(int age){
         Student* p =head;
         print_row();
         print_row("STT","Ho Ten","Tuoi","Diem");
         print_row();
         while (p != nullptr) {
                 if (age==p->_age) {
                     print_row(p->_STT, p->_full_name, p->_age, p->_score);
                 }
                 p = p->_next;
          }
         print_row();
     }
    void tckt(){
        Student*p= head;
        set<char> se;
        while (p!=nullptr){
            string s=p->_full_name;
            for (int i=0;i<s.length();i++){
                se.insert(s[i]);
            }
            p=p->_next;
        }
        for (auto x: se) cout <<x<<" ";
    }
};
/////////////////////////////////////////////////////////////////////////////////
////////////////////*Danh sach sinh vien*///////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(){
    StudentList list;
    list.init();
    
    string input;
    while (true){
        cout <<" Danh sach thao tac:  \n" \
            <<"1 - In danh sach SV \n" \
            <<"2 - Them \n" \
            <<"3 - Sua \n" \
            <<"4 - Xoa \n" \
            <<"5 - Tim kiem \n"\
            <<"6 - Sap xep \n" \
            <<"7 - Thong ke \n" \
            <<"8 - Sao luu \n" \
            <<"9 - Thoat \n" \
            <<"10 - Giai tri \n";
        cout <<"Nhap lenh:  ";
        cin>>input;
        if (input=="1"){
            cout << "[1] In danh sach sinh vien: \n ";
            list.print();
        }
        else if (input=="2"){
            cout <<"[2] Them sinh vien \n";
            Student* p = new Student;
            
            cout <<"\t(?) Nhap STT:  ";
            cin>>p->_STT;
            cin.ignore();
            
            cout <<"\t(?) Nhap ten:  ";
            cin.ignore();
            getline(cin,p->_full_name);
            
            cout <<"\t(?) Nhap tuoi:  ";
            cin >> p->_age;
            
            cout <<"\t(?) Nhap diem:  ";
            cin >> p->_score;
            
            cout <<"\t(!) Da them sinh vien co STT:  "<< p->_STT <<" , ten: " <<p->_full_name<<" , tuoi: " <<p->_age
                << " , diem: " <<p->_score <<"\n";
                
            list.append(p);
        }
        else if (input=="3"){
            Student* p =new Student;
            cout << "\t(!) Ban muon thay the o STT bao nhieu : ";
            int k ; cin >> k; cin.ignore();
            cout <<"\t(?) Nhap ten:  ";
            getline(cin,p->_full_name);
            
            cout <<"\t(?) Nhap tuoi:  ";
            cin >> p->_age;
            
            cout <<"\t(?) Nhap diem:  ";
            cin >> p->_score;
            list.repair1 (k);
            list.repair2 (p->_STT,p->_full_name,p->_age,p->_score,k);
        }
        else if (input=="4"){
             int m=list.dem1();
             cout <<"\t(!)Nhap vi tri ban muon xoa: (1 - " << m  <<")   " ;
             int k;
             cin >> k;
             list.repair1(k);
        }
        else if (input=="5"){
            cout <<"\t (5.1) Tim kiem theo STT : \n ";
            cout <<"\t (5.2) Tim kiem theo ky tu :\n ";
            cout <<"\t (5.3) Tim kiem theo do tuoi: \n";
            string s;
            cout <<"\t(?) Nhap lua chon cua ban: ";
            cin >>s; cin.ignore();
            if (s=="5.1"){
                cout << "\t(!)Nhap STT ban muon tim kiem: ";
                int k;
                cin >> k;
                cout <<"\t  (!)Thong tin nguoi ban muon tim kiem: \n";
                list.find1(k);
            }
            else if (s=="5.2"){
                cout <<"\t(!) Tat ca ky tu cua sinh vien: ";
                list.tckt();
                cout <<endl;
                cout << "\t(!)Nhap KYTU ban muon tim kiem:   ";
                string s;
                getline(cin,s);
                cout <<"\t  (!)Thong tin nguoi ban muon tim kiem: \n";
                list.find2(s);
            }
            else if (s=="5.3"){
                cout << "\t(!)Nhap do tuoi ban muon tim kiem: ";
                int k;
                cin >> k;
                cout <<"\t  (!)Thong tin nguoi ban muon tim kiem: \n";
                list.find3(k);
            }
            else cout <<"\t(!) Moi ban nhap lai ?????";
        }
        else if (input=="6"){
            Student* p =new Student;
            cout << "\t(!)6.1 Diem tang dan : \n";
            cout << "\t(!)6.2 Diem giam dan : \n";
            cout << "\t(!)6.3 Tuoi tang dan : \n";
            cout << "\t(!)6.4 Tuoi giam dan : \n";
            cout << "\t(!)6.5 Ten sap xep theo thu tu tang dan : \n";
            cout << "\t(!)6.6 Ten sap xep theo thu tu giam dan : \n";
            cout << "\t(!) Lua chon cua ban : ";
            cin >> input ;
            if (input=="6.1"){
                cout << " \t  (1!) Diem sau khi da sap xep tang dan\n : ";
                cout <<" \t  (1.1!) Vui long bam phim 1 de kiem tra danh sach ";
                list.sx(p);
            }
            else if(input =="6.2") {
                cout << "\t  (2!) Diem sau khi da sap xep giam dan \n: ";
                cout << "\t  (2.1!) Vui long bam phim 1 de kiem tra danh sach ";
                list.sx1(p);
            }
            else if (input=="6.3"){
                cout << "\t  (3!) Tuoi sau khi da sap xep tang dan\n : ";
                cout << "\t  (3.1!) Vui long bam phim 1 de kiem tra danh sach ";
                list.sx2(p);
            }
            else if(input =="6.4") {
                cout << "\t  (4!) Tuoi sau khi da sap xep giam dan \n: ";
                cout << "\t  (4.1!) Vui long bam phim 1 de kiem tra danh sach ";
                list.sx3(p);
            }
            else if (input=="6.5"){
                cout << "\t  (5!) Ten theo thu tu tu dien tang dan\n : ";
                cout << "\t  (5.1!) Vui long bam phim 1 de kiem tra danh sach ";
                list.sx4(p);
            }
            else if(input =="6.6") {
                cout << "\t  (6!) Ten theo thu tu tu dien giam dan \n: ";
                cout << "\t  (6.1!) Vui long bam phim 1 de kiem tra danh sach ";
                list.sx5(p);
            }
            else {
                cout << "\t  (*!) Ban da nhap sai,moi ban nhap lai : \n";
            }
        }
        else if (input=="7"){
            string s;
            cout << "\t (1): Xem tong diem trung binh: \n ";
            cout << "\t (2): Xem sinh vien co diem cao nhat: \n";
            cout << "\t (3): Xem sinh vien co diem thap nhat: \n";
            cout <<"\t(!) Ban vui long nhap lua chon: " ;
            cin >>s;
            if (s=="1"){
                cout <<"\t (!): Diem trung binh sinh vien:  ";
                cout << list.dem() <<endl;
                string s1;
                cout << "\t   (1.1): Sinh vien co tong diem lon hon diem trung binh:  \n";
                cout << "\t   (1.2): Sinh vien co tong diem nho hon diem trung binh:  \n";
                cout <<"\t (!): Nhap lua chon: ";
                cin>>s1;
                if (s1=="1.1") list.dtkl();
                
                else if (s1=="1.2") list.dtkn();
                
                else cout <<"\t(!) Moi ban nhap lai ?????";
                
            }
            else if (s=="2"){
                list.statictical();
                
            }
            else if (s=="3"){
                list.statictical1();
            }
            else {
                cout <<"\t(!) Ban da nhap sai,vui long nhap lai ???? ";
            }
        }
        else if (input=="8"){
            list.save();
        }
        else if (input=="9"){
            return 0;
        }
        else if (input=="10"){
             bool won= true;
             displayFinalResult(won);
        }
        else {
             cout <<" O/ Moi ban nhap lai :>>> "<<"\n";
             cout<< " |\ " <<"\n" ;
             cout<< "/ | " <<"\n";
        }
        cout <<endl;
        cout <<"Press any key to continue... ";
        cin.ignore();
        getline(cin,input);
        system("clear");
    }
   // list.save();
    return 0;
}
