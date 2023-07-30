#include<iostream>
#include<string>

using namespace std;

class lms{
    private:
    int ep_id;
    string ep_name;
    float salary;
    int pl=14;
    int unpaid_leave;
    float deduction=0;

    public:

    void set_data(int i){
        cout<<"\t\t Enter employee ID of employee "<<i<<" : ";
        cin>>ep_id;
        cout<<"\t\t Enter employee name of employee "<<i<<" : ";
        cin.ignore();
        getline(cin,ep_name);
        cout<<"\t\t Enter salary of employee "<<i<<" "<<ep_name<<" : ";
        cin>>salary;
    }

    void get_data(){
        cout<<"\t\t Employee ID: "<<ep_id<<endl;
        cout<<"\t\t Employee name: "<<ep_name<<endl;
        cout<<"\t\t Salary of employee "<<ep_name<<" : "<<salary<<endl;
        cout<<"\t\t Deductions: "<<deduction<<endl;
    }

    void apply_leave(){
        int option,days;
        cout<<"\t\t Select \n 1.Paid Leave \n 2.Unpaid Leave";
        cin>>option;
        if(option==1){
            cout<<"\t\t Enter the number of paid leaves you want: ";
            cin>>days;
            if(days>pl){
                cout<<"\t\t You only have "<<pl<<" paid leaves and you are asking for "<<days<<" leaves "<<endl;
            }
            else{
                pl=pl-days;
                cout<<"\t\t Leave granted and you have "<<pl<<" paid leaves left"<<endl;
            }
        }
        else if(option==2){
            cout<<"\t\t Enter the number of unpaid leaves you want: ";
            cin>>unpaid_leave;
            cout<<"\t\t "<<unpaid_leave<<" Leave granted "<<endl;
            deduction= unpaid_leave*(salary/365);
        }
    }

    void get_leave_data(){
        cout<<"\t\t Paid leave: "<<pl<<endl;
        cout<<"\t\t Unpaid leave: "<<unpaid_leave<<endl;
    }
    int found(lms ep[],int e_id){
        int f;
        for(int i=0;i<3;i++){
            if(ep[i].ep_id=e_id){
                f=i;
            }
        }
        return f;
    }

};

int main(){
    lms ep[3];
    int operation,e_id,status;
    char decision;
    label:
    cout<<"-----------------LEAVE MANAGEMENT SYSTEM----------------- \n \n";
    cout<<"\t\t 1.Enter Employee Data \n";
    cout<<"\t\t 2.Check Employee Data \n";
    cout<<"\t\t 3.Apply for leave\n";
    cout<<"\t\t 4.Check leave data \n \n";
    cout<<"\t\t What what operation do you want to perform (select: 1, 2, 3, 4): ";
    cin>>operation;;

    switch (operation)
    {
    case 1:
        for(int i=0;i<3;i++){
            ep[i].set_data(i+1);

        }
        status=1;
        break;
    case 2:
        if(status==1){
            cout<<"\n \t\t Details are: \n";
            for(int i=0;i<3;i++){
                ep[i].get_data();
            }
        }
        else{
            cout<<"\t\t First enter employee details"<<endl;
        }
        
        break;
    
    case 3:
        cout<<"\t\t Enter your employee ID: ";
        cin>>e_id;
        for(int i=0;i<3;i++){
            ep[ep[i].found(ep,e_id)].apply_leave();
        }
        
        break;

    case 4:
        cout<<"\t\t Enter your employee ID: ";
        cin>>e_id;
        for(int i=0;i<3;i++){
            ep[ep[i].found(ep,e_id)].get_leave_data();
        }
        
        break;

    default:
        cout<<"\t\t Enter valid operation"<<endl;
        break;
    }   

    cout<<"\t\t Do you want to continue using the Leave Management System(y/n): ";
    cin>>decision;
    cout<<endl;

    if(decision=='y')
    {
        goto label;
    }

    else if(decision=='n'){
        cout<<"\t\t Thank you for using our Leave Management System";
    }

    else{
        cout<<"\t\t Enter Valid character";
    }
    return 0;
}