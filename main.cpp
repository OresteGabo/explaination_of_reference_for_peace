#include <iostream>

using namespace std;
class Person{
private:
    string _name;
    int _age;   //in cm
    int _weight; //in kg
    Person * _bestfriend;
public:
    Person(string name,int age,int weight, Person* bestfriend){
        _name=name;
        _age=age;
        _weight=weight;
        _bestfriend=bestfriend;
    }

    const string &getName() const {
        return _name;
    }

    void setName(const string &name) {
        _name = name;
    }

    int getAge() const {
        return _age;
    }

    void setAge(int age) {
        _age = age;
    }

    int getWeight() const {
        return _weight;
    }

    void setWeight(int weight) {
        _weight = weight;
    }

    /*
     * Paying attention here, u have to test first if the bestfriend exist before asking him his name
     * Because, requesting to get a name of your bestfriend who doenst exist, will crush your program
     * */
    string getBestfriendsName() const {
        string bestfriendName="";
        if(_bestfriend== nullptr){
            bestfriendName="NO BESTFRIEND";
        }else{
            bestfriendName=_bestfriend->getName();
        }
        return bestfriendName;
    }

    void setBestfriend(Person *bestfriend) {
        _bestfriend = bestfriend;
    }

    void display()const{
        std::cout<<"name:"+getName();
        std::cout<<"age:"+getAge();
        std::cout<<"weight:"+getWeight();
        std::cout<<"bestfriend's name:"+getBestfriendsName();
    }
};

int main(){
    Person *oreste= new Person("oreste",27,75,nullptr);
    std::cout<<"The bestfriend of oreste is :"+ oreste->getBestfriendsName()<<std::endl;

    Person *darlene= new Person("darlaine",20,55,oreste);
    std::cout<<"The bestfriend of darlène is :"+ darlene->getBestfriendsName()<<std::endl;

    Person *peace= new Person("peace",19,45,darlene);
    std::cout<<"The bestfriend of peace is :"+ peace->getBestfriendsName()<<std::endl;

    /// if u change the name of darlene, from darlaine to darlène and display again peace, u will see that data in peace has changes as well,
    darlene->setName("darlène");
    std::cout<<"The bestfriend of peace is :"+ peace->getBestfriendsName() <<std::endl;
}
