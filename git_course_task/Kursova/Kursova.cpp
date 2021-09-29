#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <locale>
#include <vector>
#include <ctime>
#include <iterator>
#include <iomanip>
using namespace std;

SYSTEMTIME setTime() {
    bool choose;
    SYSTEMTIME time;
    cout<< endl << setw(9)<< " День: ";
    cin >> time.wDay;
    cout << setw(9) << " Місяць: ";
    cin >> time.wMonth;
    cout << setw(9) << " Рік: ";
    cin >> time.wYear;
    choose = false;
    while (!choose) {
        cout << setw(9) << " Година: ";
        cin >> time.wHour;
        if (time.wHour > 24 || time.wHour < 0) {
            cout << " Помилка " << endl << " ";
            system("pause");
        }
        else { choose = true; }
    }
    choose = false;
    while (!choose) {
        cout << setw(9) << " Хвилина: ";
        cin >> time.wMinute;
        if (time.wMinute > 60 || time.wMinute < 0) {
            cout << " Помилка " << endl << " ";
            system("pause");
        }
        else { choose = true; }
    }
    return time;
}
SYSTEMTIME setDate() {
    SYSTEMTIME time;
    cout << endl << setw(9) << " День: ";
    cin >> time.wDay;
    cout << setw(9) << " Місяць: ";
    cin >> time.wMonth;
    cout << setw(9) << " Рік: ";
    cin >> time.wYear;    
    return time;
}
string setSex() {
    bool choose = false;
    string sex;
    int check;
    while (!choose) {
        system("cls");
        cout << endl << " Стать "
            << endl << " [1] - чоловіча "
            << endl << " [2] - жіноча " << endl;
        cin >> check;
        if (check == 1) {
            sex = "чоловіча";
            cout << " - чоловіча ";
            choose = true;
        }
        else if (check == 2) {
            sex = "жіноча";
            cout << " - жіноча ";
            choose = true;
        }
        else {
            cout << endl << " Помилка вибору статі! " << endl << " ";
            choose = false;
            system("pause");
            continue;
        }
    }
    return sex;
}
int setAge(int bd, int  bm, int by) {
    int age;
    SYSTEMTIME lt;    
    GetLocalTime(&lt);
    if (lt.wMonth > bm) { age = (int)lt.wYear - by;     }
    else if ((int)lt.wMonth == bm) {
        if ((int)lt.wDay >= bd) { age = (int)lt.wYear - by; }
        else { age = (int)lt.wYear - by - 1; }
    }
    else { age = (int)lt.wYear - by - 1; }
    return age;
}
void frame(unsigned int i) {
    if (i == 1) {
        cout << " --------------------------------------------------------------------------------------------------------------- " << endl
            << " | id  | ПІП" << setw(40) << " | " << setw(18) << "Дата народження | " << "Вік  | " << "Стать    | " << "Секція         | " << setw(7) << "Група | " << endl
            << " --------------------------------------------------------------------------------------------------------------- " << endl;
    }
    else if (i == 2) {
        cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl
            << " | id  | ПІП" << setw(40) << " | " << setw(18) << "Дата народження | " << "Вік  | " << "Стать    | " << "Секція         | " << "Спеціалізація  | " << setw(7) << "Група | " << "Зарплата | " << "К-сть змагань | " << endl
            << " ----------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    }
    else if (i == 3) {
        cout << " ------------------------------------------------------------------------------------------------------------------------------- " << endl
            << " | id  | ПІП" << setw(40) << " | " << setw(18) << "Дата народження | " << "Вік  | " << "Стать    | " << "Секція         | " << setw(7) << "Група | " << "К-сть змагань | " << endl
            << " ------------------------------------------------------------------------------------------------------------------------------- " << endl;
    }
    else if (i == 4) {
        cout << " ----------------------------------------------- " << endl
             << " | id   | Секція          | Дата       | Час   | " << endl
             << " ----------------------------------------------- " << endl;
    }
    else if (i == 5) {
        cout << " ------------------------------------------------------------------------------------------------------- " << endl
             << " | id  | Секція        | Група | Дата       | Початок | Кінець | Тренер                                | " << endl
             << " ------------------------------------------------------------------------------------------------------- " <<endl;
    }
    else if (i == 6) {
        cout << " ------------------------------------------------------------------------ " << endl
             << " | id  | Назва                | Початок    | Кінець     | Тип походу    | " << endl
             << " ------------------------------------------------------------------------ " << endl;
    }
    else if (i == 7) {
        cout << " --------------------------------------------------------------------------------------------------- " << endl
             << " | id  | Довжина (км) | Місця (початок-кінець)                                    | К-сть привалів | " << endl
             << " --------------------------------------------------------------------------------------------------- " << endl;
    }
    else if (i == 8) {
        cout << " ------------------------------------------------------------------------------------------------------------------------------------------- " << endl
            << " | id  | ПІП" << setw(40) << " | " << setw(18) << "Дата народження | " << "Вік  | " << "Стать    | " << "Секція         | " << setw(7) << "Розмір ЗП | " << "Дата працевлаштування | " << endl
            << " ------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    }
    else if (i == 9) {
        cout << " --------------------------------------------------------------- " << endl
             << " | id  | Секція        | Група | Дата       | Початок | Кінець | " << endl
             << " --------------------------------------------------------------- " << endl;
    }
}
template<typename T>
int setInstr(vector<T>& v, int i, string category) {
    unsigned int id, instrId;
    bool choose = false;
    while (!choose) {
        if (v.size() != 0) {
            printVect(v, i);
            cout << endl << " Оберіть інструктора " << endl;
            cin >> id;
        }
        else {
            cout << " Список порожній" << endl << " ";
            system("pause");
            continue;
        }
        if (v[id].categoryCheck(category) == true) {
            instrId = id;
            choose = true;
        }
        else {
            cout << " Цей тренер не може бути інструктором у поході заданої категорії складності!" << endl << " ";
            system("pause");
            continue;
        }
    }
    return instrId;
}

class section {
    friend fstream& operator<<(fstream& stream, section& v);
private:
    string name;
    unsigned int id;
    unsigned int headId;
    vector<unsigned int> members;
    vector<unsigned int> trainers;
    vector<unsigned int> sportsmanMembers;    
    vector<unsigned int> comps;
public:
    section() {}
    section(unsigned int id,string name, unsigned int headId, vector<unsigned int> members, vector<unsigned int> trainers, vector<unsigned int> sportsmanMembers, vector<unsigned int> comps){
        this->id=id;
        this->name = name;
        this->headId= headId;
        this->members= members;
        this->trainers= trainers;
        this->sportsmanMembers= sportsmanMembers;
        this->comps= comps;
    }

    void addCompt(unsigned int compId) { comps.push_back(compId); }
    void addTrainer(unsigned int trId) { trainers.push_back(trId); }
    void addSportsman(unsigned int idVal){ sportsmanMembers.push_back(idVal); }
    void setHeadId(unsigned int idVal) { headId = idVal; }
    void addMember(unsigned int idVal) { members.push_back(idVal); }
    void setValues(string nameValue, unsigned int idVal, unsigned int headIdVal, unsigned int membIdVal) {
        name = nameValue;
        id = idVal;
        headId = headIdVal;
        members.push_back(membIdVal);
    }
    string getName() { return name; }
    unsigned int getId() { return id; }
    void print() { cout << " [" << id << "] - " << name<<endl; }
    vector<unsigned int> getMembers() { return members; }
};
vector<section> sections;

class group {
    friend fstream& operator<<(fstream& stream, group& v);
private:
    unsigned int id;
    string name;    
    unsigned int sectId; 
    vector<unsigned int> trainers;
    vector<unsigned int> members;
    vector<unsigned int> sportsmanMembers;    
public:
    group(unsigned int id, string name, unsigned int sectId, vector<unsigned int> trainerIds, vector<unsigned int> members, vector<unsigned int> sportsmanMembers){
        this->members.clear();
        this->sportsmanMembers.clear();
        this->id=id;
        this->name= name;
        this->sectId= sectId;
        this->trainers = trainerIds;
        this->members= members;
        this->sportsmanMembers= sportsmanMembers;
    }
    group() {}
    void addTrainer(unsigned int idVal) { trainers.push_back(idVal); }
    void addMember(unsigned int idVal) { members.push_back(idVal); }
    void addSportsman(unsigned int idVal) { sportsmanMembers.push_back(idVal); }
    void setValues(string nameValue, unsigned int idVal, unsigned int sectIdVal) {
        name = nameValue;
        id = idVal;
        sectId = sectIdVal;
    }
    string getName() { return name; }
    unsigned int getId() { return id; }
    unsigned int getSectId() { return sectId; }
    vector<unsigned int> getTrainerIds() { return trainers; }
    int getTrainerId(int n) { return trainers[n]; }
    vector<unsigned int> getMembers(){ return members; }
    vector<unsigned int> getsporsmanMembers() { return sportsmanMembers; }
    void print() {
        cout << " | " << id << " | " << name << " | " << sectId << " | " << endl;
        for (int n : members) { cout << n << endl; }
        for (int n : sportsmanMembers) { cout << n << endl; }
        for (int n : trainers) { cout << n << endl; }
    }


};
vector<group> groups;

int setSect(int i) {
    bool choose = false;
    int check, sectId;
    while (!choose) {
        system("cls");        
        if (i == 1) { cout << " Оберіть спеціалізацію " << endl; }
        else if (i == 3) { cout << " Оберіть категорію " << endl; }
        else { cout << " Оберіть секцію " << endl; }
        for (section n : sections) {
            cout << " [" << n.getId() << "] - " << n.getName() << endl;
        }
        if (i == 2 || i == 3) { cout << " [" << sections.size() << "] - піший " << endl; }
        cin >> check;
        if (check > sections.size() || check < 0) {
            cout << endl << " Помилка! " << endl << " ";
            system("pause");
            choose = false;
            continue;
        }
        else {
            sectId = check;
            choose = true;
        }
    }
    return sectId;
}
int setGroup(int sectId) {
    int groupId;
    bool choose;
    int check;
    choose = false;
    while (!choose) {
        system("cls");
        cout << " Оберіть групу " << endl;
        for (int n = 0; n < groups.size(); n++) {
            if (groups[n].getSectId() == sectId) {
                cout << " [" << n << "] - " << groups[n].getName() << endl;
            }
        }
        cin >> check;
        if (sectId == 123) {
            if (sectId < sections.size()) {
                if (groups[check].getSectId() != sectId) {
                    cout << endl << " Помилка вибору групи! " << endl << " ";
                    system("pause");
                    choose = false;
                    continue;
                }
            }
        }
        else {
            groupId = check;
            choose = true;
        }
    }
    return groupId;
}

class visitor {
protected:
    unsigned int id, age, sectId, groupId, toursQuant;
    string surname, name, fathersName, sex, section, mostHardTourCategory;
    SYSTEMTIME bd;
    visitor() {}
    visitor(unsigned int idVal) {
        bool choose;
        int check;
        mostHardTourCategory = "0";
        toursQuant = 0;
        id = idVal;
        cout << endl << " Прізвище: " << setw(2) << " ";
        cin >> surname;
        system("cls");
        cout << endl << " Ім'я: " << setw(6) << " ";
        cin >> name;
        system("cls");
        cout << endl << " По-батькові:  ";
        cin >> fathersName;
        system("cls");
        cout << endl << " Дата народження\n";
        bd = setDate();
        age = setAge(bd.wDay, bd.wMonth, bd.wYear);
        sex = setSex();
        sectId = setSect(0);
        section = sections[sectId].getName();
        
    }
    virtual void print() = 0;
    virtual void bdPrint(int bdVal) = 0;
    virtual void agePrint(int ageVal) = 0;
    virtual void sexPrint(string sexVal) = 0;
    virtual void sectPrint(string sectVal) = 0;
    virtual void categoryPrint(string catVal) = 0;
    virtual void tourQuantPrint(unsigned int quant) = 0;
    virtual bool categoryCheck(string categryVal) = 0;
    virtual void tourQuantNsectPrint(unsigned int quant, string section) = 0;
    virtual void tourQuantNgroupPrint(unsigned int quant, string group) = 0;
    virtual void categoryNsectionPrint(string catVal, string sectVal) = 0;
    virtual void categoryNgroupPrint(string catVal, string groupVal) = 0;
    virtual void set_other_values() = 0;
    virtual string getPIP() = 0;
};

class tourist : public visitor {
    friend fstream& operator<<(fstream& stream, tourist& v);
protected:
    string group;
public:
    tourist() {};
    tourist(int idVal, string surnameVal, string nameVal, string fathersNameVal, int d, int m, int y, string sexVal, string sectVal, string groupVal, unsigned int tourQ) {
        id = idVal;
        surname = surnameVal;
        name = nameVal;
        fathersName = fathersNameVal;
        bd.wDay = d;
        bd.wMonth = m;
        bd.wYear = y;
        age = setAge(d, m, y);
        sex = sexVal;
        section = sectVal;
        group = groupVal;
        mostHardTourCategory = "0";
        toursQuant = tourQ;
    }  
    tourist(unsigned int idVal) : visitor(idVal) {        
    }
    void set_other_values() override {
        groupId = setGroup(sectId);
        group = groups[groupId].getName();
        groups[groupId].addMember(id);
        sections[sectId].addMember(id);
    }
    void print() {
        int ag = to_string(age).length();
        cout << " | " << id << setw(6 - to_string(id).length()) << " | " << getPIP() << setw(43 - getPIP().length()) << " | " << setw(4) << bd.wDay << " " << setw(4) << bd.wMonth << " " << setw(5) << bd.wYear << " | " << age << setw(7-ag) << " | " << sex << setw(11 - sex.length()) << " | " << section << setw(17 - section.length()) << " | " << group << "  | "
            << endl<< " --------------------------------------------------------------------------------------------------------------- "<<endl;
    }
    void bdPrint(int bdVal) override {
        if (bd.wYear == bdVal) { this->print(); }
    }
    void agePrint(int ageVal) {
        if (age == ageVal) { this->print(); }
    }
    void sexPrint(string sexVal) {
        if (sex == sexVal) { this->print(); }
    }
    void sectPrint(string sectVal) {
        if (section == sectVal) { this->print(); }
    }
    void tourQuantPrint(unsigned int quant) override {
        if (toursQuant == quant) { print(); }
    }
    void tourQuantNsectPrint(unsigned int quant, string section) override {
        if (this->section == section && toursQuant == quant) { print(); }
    }
    void tourQuantNgroupPrint(unsigned int quant, string group) override {
        if (this->group == group && toursQuant == quant) { print(); }
    }
    void categoryPrint(string catVal) override {
        if (this->mostHardTourCategory == catVal) { print(); }
    }
    void categoryNsectionPrint(string catVal, string sectVal) override {
        if (categoryCheck(catVal) && section == sectVal) { print(); }
    }
    void categoryNgroupPrint(string catVal, string groupVal) override {
        if (categoryCheck(catVal) && group == groupVal) { print(); }
    }
    void setMostHard(string mostHardVal) { mostHardTourCategory = mostHardVal; }    
    void addTour() { toursQuant++; }
    bool categoryCheck(string categryVal) override {
        if (categryVal == "піший") { return true; }
        else if (section == categryVal) { return true; }
        else { return false; }
    }
    unsigned int getId() { return id; }
    string getSurname() { return surname; }
    string getName() { return name; }
    string getFathersName() { return fathersName; }
    string getPIP() override { return surname + "  " + name + "  " + fathersName; }
    string getSect() { return section; }
    string getCategory() { return mostHardTourCategory; }
    string getGroup() { return group; }
    string getMostHard() { return mostHardTourCategory; }
    unsigned int getToursQ() { return toursQuant; }
};  
vector<tourist> tourists;

class competition {    
    friend fstream& operator<<(fstream& stream, competition& t);
private:
    unsigned int id;
    vector<unsigned int> trainersMembs;
    vector<unsigned int> sprmenMemb;
    SYSTEMTIME beg;
    unsigned int sectId;
public:
    competition(unsigned int idVal, unsigned int sectId, SYSTEMTIME beg, vector<unsigned int> trVals, vector<unsigned int> spVals) {
        id = idVal;
        this->sectId = sectId;
        trainersMembs = trVals;
        sprmenMemb = spVals;
        this->beg = beg;
    }
    void print() {
        int s = sections[sectId].getName().length();
        cout << " | " << setw(4) << id << " | " << sections[sectId].getName() <<setw(18-s)<< " | " << setw(2) << beg.wDay << " " << setw(2) << beg.wMonth << " " << setw(4) << beg.wYear << " | " << setw(2) << beg.wHour << ":" << setw(2) << beg.wMinute <<" | " 
            << endl << " ----------------------------------------------- " << endl;
    }
    int getTrMembsSize() { return trainersMembs.size(); }
    int getSmMembsSize() { return sprmenMemb.size(); }
    unsigned int getTrId(int n) { return trainersMembs[n]; }
    unsigned int getSmId(int n) { return sprmenMemb[n]; }
};
vector<competition> comps;

class sportsman : public tourist {
    friend fstream& operator<<(fstream& stream, sportsman& t);
private:
    vector<unsigned int> compIds;
public:
    void addComp(unsigned int idVal) { compIds.push_back(idVal); }
    sportsman(int idVal, string surnameVal, string nameVal, string fathersNameVal, int d, int m, int y, string sexVal, string sectVal, string groupVal, string mostHardTourCategory, vector<unsigned int> compsVal, unsigned int tourQ) {
        id = idVal;
        surname = surnameVal;
        name = nameVal;
        fathersName = fathersNameVal;
        bd.wDay = d;
        bd.wMonth = m;
        bd.wYear = y;
        age = setAge(d, m, y);
        sex = sexVal;
        section = sectVal;
        group = groupVal;
        this->mostHardTourCategory = mostHardTourCategory;
        compIds = compsVal;
        toursQuant = tourQ;
    }
    sportsman(unsigned int idVal) : tourist(idVal) {        
    }
    void set_other_values() override {
        groupId = setGroup(sectId);
        group = groups[groupId].getName();
        groups[groupId].addSportsman(id);
        sections[sectId].addSportsman(id);
    }
    void print() override {
        int compsLen;
        if (compIds.size() < 10) { compsLen = 1; }
        else if (compIds.size() < 100) { compsLen = 2; }
        else if (compIds.size() < 1000) { compsLen = 3; }
        cout << " | " << id << setw(6 - to_string(id).length()) << " | " << getPIP() << setw(43 - getPIP().length()) << " | " << setw(4) << bd.wDay << " " << setw(4) << bd.wMonth << " " << setw(5) << bd.wYear << " | " << setw(4) << age << " | " << sex << setw(11-sex.length())<< " | "  << section << setw(17-section.length()) << " | " << group << "  | "  << compIds.size() <<setw(16-compsLen) << " | "
            << endl << " ------------------------------------------------------------------------------------------------------------------------------- " <<endl;
    }

    int compsize() { return compIds.size(); }

    unsigned int getCompIdbyNum(unsigned int num){ return compIds[num]; }
};
vector<sportsman> sportsmen;

class trainer : public tourist {
    friend fstream& operator<<(fstream& stream, trainer& t);
private:
    string trGroup;
    string spec;
    int salary;
    vector<unsigned int> compIds,trainingIds;
public: 
    trainer(int idVal, string surnameVal, string nameVal, string fathersNameVal, int d, int m, int y, string sexVal, string sectVal, string specVal, string groupVal, int salaryVal, string mostHardTourCategory ,vector<unsigned int> comps, vector<unsigned int> trainings, unsigned int tourQ) {
        id = idVal;
        surname = surnameVal;
        name = nameVal;
        fathersName = fathersNameVal;
        bd.wDay = d;
        bd.wMonth = m;
        bd.wYear = y;
        age = setAge(d, m, y);
        sex = sexVal;
        section = sectVal;
        spec = specVal;
        trGroup = groupVal;
        salary = salaryVal;
        this->mostHardTourCategory = mostHardTourCategory;
        compIds = comps;
        trainingIds = trainings;
        toursQuant = tourQ;
    }

    trainer(unsigned int idVal) : tourist(idVal) { }
    void set_other_values() override {
        int specId;
        specId = setSect(1);
        spec = sections[specId].getName();
        groupId = setGroup(123);
        trGroup = groups[groupId].getName();
        groups[groupId].addTrainer(id);
        sections[sectId].addTrainer(id);
        cout << " Вкажіть розмір заробітньої плати у гривнях: ";
        cin >> salary;
        toursQuant = 0;        
    }
    int compsize() { return compIds.size(); }
    unsigned int getCompIdbyNum(unsigned int num) { return compIds[num]; }
    void addComp(unsigned int idVal) { compIds.push_back(idVal); }
    void addTraining(unsigned int idVal) { trainingIds.push_back(idVal); }
    void print() override {
        long s = to_string(compIds.size()).length(), sl=section.length(), sp = spec.length(), sal = to_string(salary).length(),ag=to_string(age).length();
        cout << " | " << id << setw(6 - to_string(id).length()) << " | " << getPIP() << setw(43 - getPIP().length()) << " | " << setw(4) << bd.wDay << " " << setw(4) << bd.wMonth << " " << setw(5) << bd.wYear << " | " << age <<setw(7-ag)<< " | " << sex << setw(11 - sex.length()) << " | " << section << setw(17 - sl) << " | " << spec << setw(17 - sp) << " | " << trGroup << "  | " << salary << setw(11 - sal) << " | " << compIds.size() << setw(16 - s) << " | "
            << endl << " ----------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    }
    void specPrint(string specVal) {
        if (spec == specVal) { print(); }
    }
    void salLessThenPrint(float salVal){
        if (salary < salVal) { print(); }
    }
    void salMoreThenPrint(float salVal) {
        if (salary > salVal) { print(); }
    }
    void salEqualPrint(float salVal) {
        if (salary == salVal) { print(); }
    }       
    vector<unsigned int> getTrainingIds() { return trainingIds; }
    string getGroup() { return trGroup; }
};
vector<trainer> trainers;

class training {
    friend class section;
    friend fstream& operator<<(fstream& stream, training& t);
private:
    SYSTEMTIME beg, end;
    unsigned int id, trainerId, sectId, groupId;
    vector<unsigned int> members;
    vector<unsigned int> sportsmanMembers;
public:
    training(unsigned int id, unsigned int trainerId, unsigned int sectId, unsigned int groupId, SYSTEMTIME beg, SYSTEMTIME end, vector<unsigned int> members, vector<unsigned int> smembersV) {
        this->id = id;
        this->trainerId = trainerId;
        this->sectId = sectId;
        this->groupId = groupId;
        this->beg = beg;
        this->end = this->beg;
        this->end = end;
        this->members = members;
        sportsmanMembers = smembersV;
    }
    int getMembersSize() { return members.size(); }
    int getSmenMembsSize() { return sportsmanMembers.size(); }
    void addMember(unsigned int idVal) { members.push_back(idVal); }
    int getDuration() {
        int dur;
        if ((end.wHour - beg.wHour) == 0) { dur = (end.wMinute - beg.wMinute) / 60; }
        else { dur = ((end.wMinute - beg.wMinute) / 60) + (end.wHour - beg.wHour); }
        return dur;
    }    
    unsigned int getId() { return id; }
    unsigned int getTrainerId() { return trainerId; }
    unsigned int getsectId() { return sectId; }
    unsigned int getGroupId() { return groupId; }
    SYSTEMTIME getBegTime() { return beg; };
    SYSTEMTIME getEndTime() { return end; };
    void print() {
        int s = sections[sectId].getName().length();
        cout << " | " << setw(3) << id << " | "
            << sections[sectId].getName() << setw(16 - s) << " | "
            << setw(4) << groups[groupId].getName() << "  | " << setw(2) << beg.wDay << " " << setw(2) << beg.wMonth << " " << setw(4) << beg.wYear << " | " << setw(2) << beg.wHour << ":" << setw(2) << beg.wMinute << "   | " << setw(2) << end.wHour << ":" << setw(2) << end.wMinute << "  | "
            << trainers[trainerId].getPIP() << setw(40 - trainers[trainerId].getPIP().length()) << " | "
            << endl << " ------------------------------------------------------------------------------------------------------- " << endl;
    }
};
vector<training> trainings;

class instructor { 
    friend fstream& operator<<(fstream& stream, instructor& i);
private:
    unsigned int id, type, id_from_list,toursQ;
    string str_type;
public:
    instructor(unsigned int id, unsigned int type, unsigned int id_from_list, unsigned int toursQ) {
        this->id=id;
        this->type = type;
        this->id_from_list = id_from_list;
        this->toursQ = toursQ;
        if (type == 3) { str_type = "турист"; }
        else if (type == 2) { str_type = "спортсмен"; }
        else if (type == 1) { str_type = "тренер"; }
    }
    unsigned int getId() { return id; }
    unsigned int getType() { return type; }
    unsigned int getIdFromList() { return id_from_list; }
    void addTour() { toursQ++; }
    unsigned int getToursQ() { return toursQ; }
};
vector<instructor> instructors;
template<typename T>
void printVect(vector<T>& v, unsigned int i) {
    if (v.size() == 0) {
        cout << endl << "Тут порожньо)" << endl << " ";
    }
    else {
        frame(i);
        for (T n : v) {
            n.print();
        }
    }
}
template<typename T>
vector<unsigned int> addMembs(vector<T>& v, unsigned int i, vector<unsigned int> alrExisting, string catVal) {
    vector<unsigned int> ids;
    ids.clear();
    unsigned int idVal;
    ids = alrExisting;
    int check;
    bool choose = false;
    while (!choose) {
        if (v.size() != 0) {
            printVect(v, i);
            cout << endl << " Вкажіть ID учасника ";
            cin >> idVal;
        }
        else {
            cout << " Список порожній" << endl << " ";
            system("pause");
            return ids;
        }
        int m = 0, n = 0;
        for (n = 0; n < ids.size(); n++) {
            if (idVal == ids[n]) { m++; }
        }
        if (m > 0) {
            cout << " Цей користувач уже є учасником! " << endl;
            m = 0;
        }
        else {
            if (idVal > v.size() || idVal < 0) {
                cout << endl << " Помилка" << endl << " ";
                system("pause");
            }
            else {
                if (catVal != " ") {
                    if (v[idVal].categoryCheck(catVal) == false) {
                        cout << " Даний користувач не може піти у похід заданої складності! " << endl << " ";
                        system("pause");
                    }
                    else { ids.push_back(idVal); }
                }
                else { ids.push_back(idVal); }
            }
        }
        cout << " [1] - Додати нового \n [2] - Вихід\n ";
        cin >> check;
        if (check == 2) {
            choose = true;
            return ids;
        }
        else { system("cls"); }
    }
}
class halt {
private:
    unsigned int id;
    unsigned int duration;
    string place;
public:
    halt(unsigned int id, string place, unsigned int duration) {
        this->id = id;
        this->duration= duration;
        this->place= place;
    }
    halt(unsigned int id){
        this->id = id;
        cout << endl << " Тривалість перевалу (хв): ";
        cin >> this->duration;
        cout << " Місце: ";
        cin >> this->place;
    }
    unsigned int getId() { return id; }
    unsigned int getDuration() { return duration; }    
    string getPlace() { return place; }
};

class route {
    friend fstream& operator<<(fstream& stream, route& r);
private:
    unsigned int id,tourId;
    int length;
    vector<string> places;
    string firstPlace, lastPlace;
    vector<halt> halts;
    string category;
public:
    route() {}
    route(unsigned int id, unsigned int tourId, int length, vector<string> places, vector<halt> halts, string category){
        this->id = id;
        this->tourId = tourId;
        this->length = length;
        this->places = places;
        firstPlace = places[0];
        lastPlace = places[places.size()-1];
        this->halts = halts;
        this->category = category;
    }
    route(unsigned int id,unsigned int tourId, string category) {
        this->id = id;
        this->tourId = tourId;
        string place;
        bool cycle=true;
        int check = 0, haltId=0;
        cout << " Початкова точка: ";
        cin >> firstPlace;
        places.push_back(firstPlace);
        cout << endl << " Кінцева точка: ";
        cin >> lastPlace;
        cycle = true;
        while (cycle) {
            system("cls");
            cout << "[1] - додати точку маршруту\n [0] - вихід ";
            cin >> check;
            if (check == 1) {
                cout << " Назва місця: ";
                cin >> place;
                this->places.push_back(place);
            }
            else { cycle = false; }
        }
        haltId = 0;
        cycle = true;
        while (cycle) {
            system("cls");
            cout << "[1] - додати точку привалу\n [0] - вихід ";
            cin >> check;
            if (check == 1) {
                halt newHalt(haltId);
                this->halts.push_back(newHalt);
                haltId++;
            }
            else { cycle = false; }
        }
        this->category = category;
        this->places.push_back(lastPlace);
        cout << " Довжина маршруту(км): ";
        cin >> this->length;
    }    
    unsigned int getId() { return id; }
    int getLength() { return length; }
    vector<string> getPlaces() { return places; }
    vector<halt> getHalts() { return halts; }
    string getCategory() { return category; }
    void print() {
       string begend = firstPlace + " - " + lastPlace;
        cout <<" | "<< id <<setw(6-to_string(id).length())<<" | " << length << setw(15-to_string(length).length())<<" | "<< begend << setw(60-begend.length())<<" | " << halts.size() << setw(17-to_string(halts.size()).length())<<" | "
             << endl <<" --------------------------------------------------------------------------------------------------- "<<endl;
    }
    void printPlaces() {
        cout << " | Місця маршруту: " << firstPlace;
        for (int n = 1; n < places.size(); n++) {
            cout << " - " << places[n] ;
        }
        cout << " | " << endl;
    }
};
vector<route> routes;

class tour {
    friend fstream& operator<<(fstream& stream, tour& t);
private:
    string name, diary_path;
    unsigned int id, routeId, duration, instrId;
    string category;
    vector<unsigned int> members, sportsmanMembers, trainerMembers;
    SYSTEMTIME beg, end;
    route troute;
public:
    tour(unsigned int id, string name, unsigned int routeId, SYSTEMTIME beg, SYSTEMTIME end, string category, unsigned int instrId, unsigned int durVal,vector<unsigned int> members, vector<unsigned int> sportsmanMembers, vector<unsigned int> trainerMembers)    {
        this->id = id;
        this->name = name;
        this->routeId = routeId;
        route newRoute(routeId,this->id, this->category);
        this->troute = newRoute;
        this->beg = beg;
        this->end = end;
        this->category = category;
        this->instrId = instrId; 
        this->members = members;
        this->sportsmanMembers = sportsmanMembers;
        this->trainerMembers = trainerMembers;
    };
    tour(unsigned int id, string name, route newRoute, SYSTEMTIME beg, SYSTEMTIME end, string category, unsigned int instrId, unsigned int durVal, vector<unsigned int> members, vector<unsigned int> sportsmanMembers, vector<unsigned int> trainerMembers) {
        this->id = id;
        this->name = name;
        this->troute = newRoute;
        this->routeId = troute.getId();
        this->beg = beg;
        this->end = end;
        this->category = category;
        this->instrId = instrId;
        this->members = members;
        this->sportsmanMembers = sportsmanMembers;
        this->trainerMembers = trainerMembers;
    };
    tour(unsigned int id, int& instrNum, int& routeNum) {
        bool choose;
        int check, typeVal, instrIdVal, idVal,tourQ,inum,catId;
        this->id = id;
        cout << " Вкажіть ім'я походу ";
        cin >> name;
        cout << endl << "Вкажіть дату початку ";
            beg = setDate();
            cout << endl << "Вкажіть дату кінця ";
            end = setDate();
        duration = end.wDay - beg.wDay;
        catId = setSect(3);
        if (catId = sections.size()) { category = "піший"; }
        else { category = sections[catId].getName(); }
        choose = false;
        while (!choose) {
            system("cls");
            cout << "Інструктор з групи: "
                << endl << " [1] - тренерів"
                << endl << " [2] - спортсменів "
                << endl << " [3] - туристів ";
            cin >> check;
            typeVal = check;
            switch (check) {
            case 1:
                instrIdVal = setInstr(trainers, 2, category);
                break;
            case 2:
                instrIdVal = setInstr(sportsmen, 3, category);
                break;
            case 3:
                instrIdVal = setInstr(tourists, 1, category);
                break;
            default:
                choose = false;
                break;
            }
        }        
        if (instructors.empty()) {
            tourQ = 1;
            instrId = instrNum++;
            instructor newInstructor(instrId, typeVal, instrIdVal, tourQ);
            instructors.push_back(newInstructor);
        }
        else {
            for (int n = 0; n < instructors.size(); n++) {
                if (instructors[n].getIdFromList() == instrIdVal) {
                    instrId = instructors[n].getId();
                    instructors[instrId].addTour();
                }
                else {
                    tourQ = 1;
                    instrId = instrNum++;
                    instructor newInstructor(instrId, typeVal, instrIdVal, tourQ);
                    instructors.push_back(newInstructor);
                }
            }
        }
        members.clear();
        choose = false;
        while (!choose) {
            system("cls");
            cout << " Додайте учасників зі списку \n [1] - туристів\n [2] - тренерів\n [3] - спортсменів\n";
            cin >> check;
            if (check == 1) {
                members = addMembs(tourists, 1, members, category);
            }
            else if (check == 2) {
                trainerMembers = addMembs(trainers, 2, trainerMembers, category);
            }
            else if (check == 3) {
                sportsmanMembers = addMembs(sportsmen, 3, sportsmanMembers, category);
            }
           
            cout << "Додати ще?\n [1] - так\n [2] - ні \n";
            cin >> check;
            if (check == 2) {
                choose = true;
            }
        }
        for (int n = 0; n < members.size(); n++) {
            tourists[members[n]].setMostHard(category);
            tourists[members[n]].addTour();
        }
        for (int n = 0; n < trainerMembers.size(); n++) {
            trainers[trainerMembers[n]].setMostHard(category);
            trainers[trainerMembers[n]].addTour();
        }
        for (int n = 0; n < sportsmanMembers.size(); n++) {
            sportsmen[sportsmanMembers[n]].setMostHard(category);
            sportsmen[sportsmanMembers[n]].addTour();
        }
        choose = false;
        while (!choose) {
            cout << " [1] - Створити новий маршрут" << endl << " [2] - Обрати раніше створений" << endl;
            cin >> check;
            if (check == 1) {
                routeId = routeNum++;
                route r(routeId, this->id, category);
                troute = r;
                choose = true;
                routes.push_back(r);
            }
            else if (check == 2) {
                printVect(routes, 7);
                cout << endl << " Вкажіть ID ";
                cin >> routeId;
                troute = routes[routeId];
                choose = true;
            }
            else { choose = false; }
        }
    }
    void print() {
        cout << " | " << id << setw(6-to_string(id).length())<<" | " << name << setw(23-name.length())<< " | " <<setw(2)<< beg.wDay << " " << setw(2)<<beg.wMonth << " " <<setw(4)<< beg.wYear<<" | " << setw(2) << end.wDay << " " << setw(2) << end.wMonth << " " << setw(4) << end.wYear << " | " << category << setw(16-category.length()) << " | "
            << endl << " ------------------------------------------------------------------------ " << endl;        
    }
    void setYear(int year) {
        beg.wYear = year;
        end.wYear = year;
    }
    void addDiary(string path) { diary_path = path; }
    string getDiary() { return diary_path; }    
    vector<unsigned int> getMembers() { return members; } 
    vector<unsigned int> getSportsmanMembers() { return sportsmanMembers; }
    vector<unsigned int> getTrainerMembers() { return trainerMembers; }
    SYSTEMTIME getBegTime() { return beg; }
    SYSTEMTIME getEndTime() { return end; }
    unsigned int getId() { return id; }
    unsigned int getRouteId() { return routeId; }
    unsigned int getInstrId() { return instrId; }
};
vector<tour> tours;

class sectHead : public tourist{
    friend fstream& operator<<(fstream& stream, sectHead& v);
private:
    unsigned int salary;
    SYSTEMTIME getJobDate;
public:
    sectHead(unsigned int idVal) : tourist(idVal) { } 
    void set_other_values() {
        sections[sectId].setHeadId(this->id);
        GetLocalTime(&getJobDate);
        cout << endl << " Дата надходження на роботу: " << getJobDate.wDay << " " << getJobDate.wMonth << " " << getJobDate.wYear << endl << " Вкажіть розмір заробітньої плати у гривнях: ";
        cin >> salary;
    }
    sectHead(int idVal, string surnameVal, string nameVal, string fathersNameVal, int d, int m, int y, string sexVal, string sectVal, unsigned int salVal, int jd, int jm, int jy) {
        id = idVal;
        surname = surnameVal;
        name = nameVal;
        fathersName = fathersNameVal;
        bd.wDay = d;
        bd.wMonth = m;
        bd.wYear = y;
        age = setAge(d, m, y);
        sex = sexVal;
        section = sectVal;
        salary = salVal;
        getJobDate.wDay = jd;
        getJobDate.wMonth = jm;
        getJobDate.wYear = jy;


    }
    void print() override {
        int sl = section.length(), sal = to_string(salary).length(), ag = to_string(age).length();
        cout << " | " << id << setw(6 - to_string(id).length()) << " | " << getPIP() << setw(43 - getPIP().length()) << " | " << setw(4) << bd.wDay << " " << setw(4) << bd.wMonth << " " << setw(5) << bd.wYear << " | " << age << setw(7 - ag) << " | " << sex << setw(11 - sex.length()) << " | " << section << setw(17 - sl) << " | " << salary << setw(12 - sal) << " | " << setw(2) << getJobDate.wDay << " " << setw(2) << getJobDate.wMonth << " " << setw(4) << getJobDate.wYear <<setw(14)<< " | "
            << endl << " ------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    }
    void salLessThenPrint(float salVal) {
        if (salary < salVal) {
            print();
        }
    }
    void salMoreThenPrint(float salVal) {
        if (salary > salVal) {
            print();
        }
    }
    void salEqualPrint(float salVal) {
        if (salary == salVal) {
            print();
        }
    }
};
vector<sectHead> sectHeads;

void initGroupsSects() {
    groups.clear();
    sections.clear();
    group g1, g2, g3, g4, g5, g6, g7, g8;
    section s1, s2, s3, s4;
    g1.setValues("пл-1", 0, 0);
    g2.setValues("пл-2", 1, 0);
    g3.setValues("ал-1", 2, 1);
    g4.setValues("ал-2", 3, 1);
    g5.setValues("сп-1", 4, 2);
    g6.setValues("сп-2", 5, 2);
    g7.setValues("їк-1", 6, 3);
    g8.setValues("їк-2", 7, 3); 
    groups.push_back(g1);
    groups.push_back(g2);
    groups.push_back(g3);
    groups.push_back(g4);
    groups.push_back(g5);
    groups.push_back(g6);
    groups.push_back(g7);
    groups.push_back(g8);
    s1.setValues("плавання", 0, 0, 0);
    s2.setValues("альпінізм", 1, 0, 0);
    s3.setValues("спелеологія", 2, 0, 0);
    s4.setValues("їзда_на_конях", 3, 0, 0);
    sections.push_back(s1);
    sections.push_back(s2);
    sections.push_back(s3);
    sections.push_back(s4);
}

fstream& operator<<(fstream& stream, tourist& v)
{
    stream << endl << v.id << endl << v.surname << endl << v.name << endl << v.fathersName << endl << v.bd.wDay << endl << v.bd.wMonth << endl << v.bd.wYear << endl << v.age << endl << v.sex << endl << v.section << endl << v.group << endl << v.mostHardTourCategory << endl << v.toursQuant << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, trainer& t) {
    stream << endl << t.id << endl << t.surname << endl << t.name << endl << t.fathersName << endl << t.bd.wDay << endl << t.bd.wMonth << endl << t.bd.wYear << endl << t.age << endl << t.sex << endl << t.section << endl << t.spec << endl << t.trGroup << endl << t.salary << endl << t.mostHardTourCategory << endl<< t.toursQuant<<endl;
    for (int n = 0; n < t.compIds.size(); n++) {
        stream << t.compIds[n] << endl;
    }
    stream << -21 << endl;
    for (int n = 0; n < t.trainingIds.size(); n++) {
        stream << t.trainingIds[n] << endl;
    }
    stream << -22 << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, sportsman& t) {
    stream << endl << t.id << endl << t.surname << endl << t.name << endl << t.fathersName << endl << t.bd.wDay << endl << t.bd.wMonth << endl << t.bd.wYear << endl << t.age << endl << t.sex << endl << t.section  << endl << t.group << endl << t.mostHardTourCategory << endl << t.toursQuant << endl;
    for (int n = 0; n < t.compIds.size(); n++) {
        stream << t.compIds[n] << endl;
    }
    stream << -31 << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, training& t) {
    stream << endl << t.id << endl << t.trainerId <<endl<< t.sectId <<endl<< t.groupId << endl << t.beg.wDay << " " << t.beg.wMonth << " " << t.beg.wYear<<endl<< t.beg.wHour<<" "<< t.beg.wMinute<<endl << t.end.wHour << " " << t.end.wMinute<<endl;
    for (int n = 0; n < t.members.size(); n++) {
        stream << t.members[n] << endl;
    }
    stream << -41<<endl;
    for (int n = 0; n < t.sportsmanMembers.size(); n++) {
        stream << t.sportsmanMembers[n] << endl;
    }
    stream << -42<<endl << endl;

    return stream;
}
fstream& operator<<(fstream& stream, competition& t) {
    stream << endl << t.id << endl << t.sectId << endl << t.beg.wDay << endl << t.beg.wMonth << endl << t.beg.wYear << endl << t.beg.wHour << endl << t.beg.wMinute << endl;
    for (int n = 0; n < t.trainersMembs.size(); n++) {
        stream << t.trainersMembs[n] << endl;
    }
    stream << -51 << endl;
    for (int n = 0; n < t.sprmenMemb.size(); n++) {
        stream << t.sprmenMemb[n] << endl;
    }
    stream << -52 << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, section& v)
{
    stream << endl << v.id << endl << v.name << endl << v.headId << endl;
    for (int n = 0; n < v.members.size(); n++) {
        stream << v.members[n] << endl;
    }
    stream << -61 << endl;
    for (int n = 0; n < v.trainers.size(); n++) {
        stream << v.trainers[n] << endl;
    }
    stream << -62 << endl;
    for (int n = 0; n < v.sportsmanMembers.size(); n++) {
        stream << v.sportsmanMembers[n] << endl;
    }
    stream << -63 << endl;
    for (int n = 0; n < v.comps.size(); n++) {
        stream << v.comps[n] << endl;
    }
    stream << -64 << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, group& v) {
    stream << v.id << endl << v.name << endl << v.sectId << endl;
    for (int n = 0; n < v.members.size(); n++) {
        stream << v.members[n] << endl;
    }
    stream << -71 << endl;
    for (int n = 0; n < v.sportsmanMembers.size(); n++) {
        stream << v.sportsmanMembers[n] << endl;
    }
    stream << -72 << endl;
    for (int n = 0; n < v.trainers.size(); n++) {
        stream << v.trainers[n] << endl;
    }
    stream << -73 << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, tour& t) {
    stream << t.id << endl << t.name << endl << t.routeId 
        << endl << t.beg.wDay << " " << t.beg.wMonth << " " << t.beg.wYear
        << endl << t.end.wDay << " " << t.end.wMonth << " " << t.end.wYear
        << endl << t.category << endl << t.instrId << endl << t.duration <<endl;
    for (int n = 0; n < t.members.size();n++) {
        stream << t.members[n] << endl;
    }
    stream << -81 << endl;
    for (int n = 0; n < t.sportsmanMembers.size(); n++) {
        stream << t.sportsmanMembers[n] << endl;
    }    
    stream << -82 << endl;
    for (int n = 0; n < t.trainerMembers.size(); n++) {
        stream << t.trainerMembers[n] << endl;
    }
    stream << -83 << endl << endl;      
    return stream;

}
fstream& operator<<(fstream& stream, route& t) {
    stream << t.getId() << endl << t.tourId << endl << t.getLength() << endl << t.category <<endl;
    for (int n = 0; n < t.getPlaces().size(); n++) {
        stream << t.getPlaces()[n] << endl;
    }
    stream << "-91" << endl;
    for (int n = 0; n < t.getHalts().size(); n++) {
        stream << t.getHalts()[n].getId() << endl << t.getHalts()[n].getPlace() << endl << t.getHalts()[n].getDuration() << endl;
    }
    stream << -92 << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, sectHead& v)
{
    stream << endl << v.id << " " << v.surname << " " << v.name << " " << v.fathersName << endl << v.bd.wDay << " " << v.bd.wMonth << " " << v.bd.wYear << endl << v.age << endl << v.sex << endl << v.section<< endl << v.salary << endl << v.getJobDate.wDay << " " << v.getJobDate.wMonth << " " << v.getJobDate.wYear << endl << endl;
    return stream;
}
fstream& operator<<(fstream& stream, instructor& i) {
    stream << endl << i.id << endl << i.type << endl << i.id_from_list << endl<<i.toursQ<<endl << endl;
    return stream;
}

class database {
   friend void menu();
private:
    int touristNum, trainerNum, soprtsmanNum, compNum, trainingNum, tourNum, sectHeadNum, sectNumber, groupNumber, routeNum,instrNum;
    long fsize;
    bool choose = false;
    int readQuant=0, quant=0, check=0, max=0, indVal=0, idVal=0,tmp;
    unsigned int bdVal, bmVal, byVal, edVal, emVal=0, eyVal=0, ageVal, tmpAge,  yearVal, typeVal, instrIdVal, durVal,haltsNum,haltDurVal, lenVal, hourVal, minVal,sectId, groupId, trainerId, headId, routeIdVal,tourId,tourQ,hourQ,idfromlist;
    vector<unsigned int> tmpMembers;
    vector<string>tmpPlaces;
    float salVal;
    string surnameVal, nameVal, fathersNameVal, sectVal, groupVal, sexVal, specVal,begPlaceV, endPlaceV,categoryVal, placeVal,mostVal;  
public:
    template<typename T>
    void addVisitor(vector<T>& v, int& num,int q){
        readQuant = num;
        if (q == 1) {  quant=1; }
        else {
            cout << endl << " Кількість нових користувачів: ";
            cin >> quant;
        }
        for (int n = 0; n < quant; n++) {
            idVal = n + readQuant;
            system("cls");
            cout << " ID користувача: " << idVal << endl;
            T newVisitor(idVal);
            newVisitor.set_other_values();
            v.push_back(newVisitor);
        }
        quant += readQuant;
        num = quant;
    }

    void readData() {
        int m;
        bool cycle = true, cycle2 = true;
        ifstream read;      
        string path;
        cout << " Введіть шлях до файлу";
        cin >> path;
        read.open(path);
        tourists.clear();
        trainers.clear();
        sportsmen.clear();
        trainings.clear();
        comps.clear();
        tours.clear();
        groups.clear();
        sections.clear();
        sectHeads.clear();
        routes.clear();
        instructors.clear();
            read >> touristNum >> trainerNum >> soprtsmanNum >> trainingNum >> compNum >> tourNum >> sectHeadNum >> sectNumber >> groupNumber >> routeNum >> instrNum;
            for (int n = 0; n < touristNum; n++) {
                read >> idVal >> surnameVal >> nameVal >> fathersNameVal >> bdVal >> bmVal >> byVal >> ageVal >> sexVal >> sectVal >> groupVal >> categoryVal >> tourQ;
                tourist newTourist(idVal, surnameVal, nameVal, fathersNameVal, bdVal, bmVal, byVal, sexVal, sectVal, groupVal, tourQ);
                newTourist.setMostHard(categoryVal);
                tourists.push_back(newTourist);
            }
            for (int n = 0; n < trainerNum; n++) {
                vector<unsigned int> compsIdVal,trngIdVal;
                read >> idVal >> surnameVal >> nameVal >> fathersNameVal >> bdVal >> bmVal >> byVal >> ageVal >> sexVal >> sectVal >> specVal >> groupVal >> salVal >> categoryVal >> tourQ;
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -21) cycle = false;
                    else compsIdVal.push_back(tmp);
                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -22) cycle = false;
                    else trngIdVal.push_back(tmp);
                }
                trainer newTrainer(idVal, surnameVal, nameVal, fathersNameVal, bdVal, bmVal, byVal, sexVal, sectVal, specVal, groupVal, salVal, categoryVal, compsIdVal, trngIdVal, tourQ);
                trainers.push_back(newTrainer);
                compsIdVal.clear();
                trngIdVal.clear();
            }
            for (int n = 0; n < soprtsmanNum; n++) {
                vector<unsigned int> compsIdVal;
                read >> idVal>> surnameVal >> nameVal >> fathersNameVal >> bdVal >> bmVal >> byVal >> ageVal >> sexVal >> sectVal >> groupVal >> categoryVal >> tourQ;
                cycle2 = true;
                while (cycle2) {                    
                    read >> tmp;
                    if (tmp == -31) cycle2 = false;
                    else compsIdVal.push_back(tmp);                }                
                sportsman newSportsman(idVal, surnameVal, nameVal, fathersNameVal, bdVal, bmVal, byVal, sexVal, sectVal, groupVal, categoryVal, compsIdVal, tourQ);
                sportsmen.push_back(newSportsman);
                compsIdVal.clear();
            }
            for (int n = 0; n < trainingNum; n++) {
                SYSTEMTIME beg, end;
                vector<unsigned int> membersV, smMembsV;
                read >> idVal >> trainerId >> sectId >> groupId >> beg.wDay >> beg.wMonth >> beg.wYear >> beg.wHour >> beg.wMinute >> end.wHour >> end.wMinute;
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -41)  cycle = false; 
                    else  membersV.push_back(tmp); 
                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -42)  cycle = false; 
                    else  smMembsV.push_back(tmp); 
                }
                training newTraining(idVal, trainerId, sectId, groupId, beg,end, membersV, smMembsV);
                trainings.push_back(newTraining);
                membersV.clear();
                smMembsV.clear();
            }
            for (int n = 0; n < compNum; n++) {
                SYSTEMTIME time;
                vector<unsigned int> trIds, smIds;               
                read >> idVal >> sectId >> time.wDay >> time.wMonth >> time.wYear >> time.wHour >> time.wMinute;
                cycle = true;
                while (cycle) {    
                    read >> tmp;
                    if (tmp == -51) cycle = false;
                    else trIds.push_back(tmp);
                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -52) cycle = false;
                    else smIds.push_back(tmp);

                }
                competition comp(idVal, sectId, time, trIds, smIds);
                comps.push_back(comp);
                trIds.clear();
                smIds.clear();
            }
            for (int n = 0; n < sectNumber; n++) {                
                vector<unsigned int> membsIdVal, trIds, smIds, compIds;
                read >> idVal >> nameVal >> headId;
                cycle = true;
                while(cycle) {
                    read >>tmp;
                    if (tmp == -61)  cycle = false; 
                    else  membsIdVal.push_back(tmp); 
                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -62)  cycle = false; 
                    else  trIds.push_back(tmp); 

                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -63) cycle = false;
                    else  smIds.push_back(tmp); 

                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -64)  cycle = false; 
                    else compIds.push_back(tmp);

                }
                section newSect(idVal, nameVal, headId, membsIdVal, trIds, smIds, compIds);
                sections.push_back(newSect);
                membsIdVal.clear();
                trIds.clear();
                smIds.clear();
                compIds.clear();
            }
            for (int n = 0; n < groupNumber; n++) {
                vector<unsigned int> membsIdVal, smIds, trIds;
                read >> idVal >> nameVal >> sectId;
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -71)  cycle = false; 
                    else  membsIdVal.push_back(tmp); 

                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -72) cycle = false;
                    else smIds.push_back(tmp);
                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -73) cycle = false;
                    else trIds.push_back(tmp);
                }
                group newGroup(idVal, nameVal, sectId, trIds, membsIdVal, smIds);
                groups.push_back(newGroup);
                membsIdVal.clear();
                smIds.clear();
            }
            for (int n = 0; n < routeNum; n++) {
                vector<halt>tmpHalts;
                vector<string> tmpPlaces;
                read >> routeIdVal >> tourId >> lenVal >> categoryVal;                
                cycle = true;
                while (cycle) {
                    read >> placeVal;
                    if (placeVal == "-91") cycle = false;
                    else { tmpPlaces.push_back(placeVal); }
                }
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -92) { cycle = false; }
                    else {                        
                        read >> placeVal;
                        read >> durVal;
                        halt newHalt(tmp, placeVal, durVal);
                        tmpHalts.push_back(newHalt);
                    }                    
                }
                route newRoute(routeIdVal, tourId, lenVal, tmpPlaces, tmpHalts, categoryVal);
                routes.push_back(newRoute);
                tmpPlaces.clear();
                tmpHalts.clear();
            }
            for (int n = 0; n < tourNum; n++) {
                vector<unsigned int> members, trMembers, smMembers;
                SYSTEMTIME beg, end;
                read >> idVal >> nameVal >> routeIdVal >> beg.wDay >> beg.wMonth >> beg.wYear >> end.wDay >> end.wMonth >> end.wYear >> categoryVal >> instrIdVal >> durVal;
                cycle = true;
                while(cycle) {
                    read >> tmp;
                    if (tmp == -81) cycle = false;
                    else members.push_back(tmp);
                }                
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -82) cycle = false;
                    else smMembers.push_back(tmp);
                } 
                cycle = true;
                while (cycle) {
                    read >> tmp;
                    if (tmp == -83) cycle = false;
                    else trMembers.push_back(tmp);
                }                
                tour newTour(idVal, nameVal,routes[routeIdVal], beg,end, categoryVal, instrIdVal, durVal, members, smMembers, trMembers);
                tours.push_back(newTour);
                members.clear();
                smMembers.clear();
                trMembers.clear();
                tmpPlaces.clear();
            }
            for (int n = 0; n < sectHeadNum; n++) {
                read >> idVal >> surnameVal >> nameVal >> fathersNameVal >> bdVal >> bmVal >> byVal >> ageVal >> sexVal >> sectVal >> salVal >> edVal >> emVal >> eyVal;
                sectHead newSectHead(idVal, surnameVal, nameVal, fathersNameVal, bdVal, bmVal, byVal, sexVal, sectVal, salVal, edVal, emVal, eyVal);
                sectHeads.push_back(newSectHead);
            }
            for (int n = 0; n < instrNum; n++) {
                read >> idVal >> typeVal >> idfromlist >> tourQ;
                instructor newInstructor(idVal, typeVal, idfromlist, tourQ);
                instructors.push_back(newInstructor);
            }        
        read.close();
        cout << endl << " Дані успішно зчитано " << endl<<" ";
        system("pause");
        
    }
    void writeData() {
        fstream fs;
        fs.open("data.txt", ios::in | ios::out);
        fs << touristNum<<endl << trainerNum << endl << soprtsmanNum << endl << trainingNum << endl << compNum << endl << tourNum << endl << sectHeadNum << endl << sections.size() << endl << groups.size() << endl << routeNum << endl << instrNum << endl;
        for (tourist n : tourists) { fs << n; }
        for (trainer n : trainers) { fs << n; }
        for (sportsman n : sportsmen) { fs << n; }
        for (training n : trainings) { fs << n; }
        for (competition n : comps) { fs << n; }        
        for (section n : sections) { fs << n; }
        for (group n : groups) { fs << n; }
        for (route n : routes) { fs << n; }
        for (tour n : tours) { fs << n; }
        for (sectHead n : sectHeads) { fs << n; }
        for (instructor n : instructors) { fs << n; }
        fs.close();
    }
    void createTour() {
        unsigned int tmpId;
        tmpId = tours.size();
        int& i = instrNum;
        int& r = routeNum;
        tour newTour(tmpId, i, r);
        tours.push_back(newTour);
        tourNum = tours.size();
        routeNum = routes.size();
        instrNum = instructors.size();
    }
    void createSchedule() {
        unsigned int tmpId;
        system("cls");
        cout << "Вкажіть рік ";
        cin >> yearVal;
        cout << "Вкажіть к-сть походів ";
        cin >> quant;        
        for (int n = 0; n < quant; n++) {
            tmpId = tours.size();
            int& i = instrNum;
            int& r = routeNum;
            tour newTour(tmpId, i, r);
            newTour.setYear(yearVal);
            tours.push_back(newTour);            
        }
        tourNum = tours.size();
        routeNum = routes.size();
        instrNum = instructors.size();
    }
    void addComp() {
        vector<unsigned int> trIds, spormIds;        
        SYSTEMTIME beg;
        idVal =compNum++;
        cout<<" " << idVal << " - id змагання " << endl<<" Дата початку: ";
        beg = setTime();
        sectId = setSect(0);
        trIds.clear();
        spormIds.clear();
        choose = false;
        while (!choose) {
            system("cls");            
            cout << " Додайте учасників зі списку \n [1] - тренерів\n [2] - спортсменів\n";
            cin >> check;
            if (check == 1) { trIds = addMembs(trainers, 2,trIds," "); }
            else if (check == 2) { spormIds = addMembs(sportsmen, 3, spormIds," "); }
            cout << "Додати ще?\n [1] - так\n [2] - ні \n";
            cin >> check;
            if (check == 2) { choose = true; }           
        }
        for (int n : trIds) { trainers[n].addComp(idVal); }
        for (int n : spormIds) { sportsmen[n].addComp(idVal); }
        competition newComp(idVal, sectId , beg, trIds, spormIds);
        comps.push_back(newComp);
        sections[sectId].addCompt(idVal);        
    }
    void addTraining() {
        SYSTEMTIME beg,end;
        idVal = trainingNum++;
        cout << " " << idVal << " - id змагання " << endl << " Дата початку: ";
        beg = setTime();
        end = beg;
        cout << " Кінець: год - ";
        cin >> end.wHour;
        cout << " хв - ";
        cin >> end.wMinute;   
        groupId = setGroup(123);
        choose = false;
        while (!choose) {
                choose = true;
                cout << "Оберіть тренера зі списку тренерів цієї групи" << endl;
                for (int n = 0; n < groups[groupId].getTrainerIds().size(); n++) {
                    cout << " [" << n << "] - " << groups[groupId].getTrainerId(n) << " " 
                        << trainers[groups[groupId].getTrainerId(n)].getPIP() << endl;
                }
                if (groups[groupId].getTrainerIds().size() != 0) {
                    cin >> check;
                    trainerId = groups[groupId].getTrainerId(check);
                    trainers[trainerId].addTraining(idVal);
                    sectId = groups[groupId].getSectId();
                }
                else {
                    cout << " В цій групі немає тренерів!";
                    trainerId = NULL;
                }
        }
        training newTraining(idVal,trainerId, sectId, groupId, beg ,end, groups[groupId].getMembers(), groups[groupId].getsporsmanMembers());
        trainings.push_back(newTraining);
    }
    void addDiary() {
        system("cls");
        int id;
        string path;
        printVect(tours, 6);
        cout << " Оберіть похід ";
        cin >> id;
        cout << " Вкажіть шлях до документу .txt ";
        cin >> path;
        tours[id].addDiary(path);
    }    
 };
 void printDiary() {
     system("cls");
     int id;
     string word;
     printVect(tours, 6);
     cout << " Оберіть похід ";
     cin >> id;
     ifstream openfile(tours[id].getDiary());
     if (openfile.is_open())
     {
         while (!openfile.eof())
         {
             openfile >> word;
             cout << word << endl;
         }
     }    
 }
 void fullTourPrint() {
     int idVal;
     system("cls");
     printVect(tours, 6);
     cout << endl << " Вкажіть ID ";
     cin >> idVal;
     system("cls");
     cout << "\n\t\t\t\t\tПОХІД" << endl;
     frame(6);
     tours[idVal].print();
     cout << "\n\t\t\t\t\tІНСТРУКТОР" << endl;
     if (instructors[tours[idVal].getInstrId()].getType() == 3) {
         frame(1);
         tourists[instructors[tours[idVal].getInstrId()].getIdFromList()].print();
     }
     else if (instructors[tours[idVal].getInstrId()].getType() == 2) {
         frame(3);
         sportsmen[instructors[tours[idVal].getInstrId()].getIdFromList()].print();
     }
     else if (instructors[tours[idVal].getInstrId()].getType() == 1) {
         frame(2);
         trainers[instructors[tours[idVal].getInstrId()].getIdFromList()].print();
     }
     cout << "\n\t\t\t\t\tМАРШРУТ" << endl;
     frame(7);
     routes[tours[idVal].getRouteId()].print();
     routes[tours[idVal].getRouteId()].printPlaces();
     cout << "\n\t\t\t\t\tУЧАСНИКИ:\n Зі списку туристів:\n";
     if (tours[idVal].getMembers().size() == 0) {
         cout << " Тут нікого! " << endl;
     }
     else {
         frame(1);
         for (int n = 0; n < tours[idVal].getMembers().size(); n++) {
             tourists[tours[idVal].getMembers()[n]].print();
         }
     }
     cout << endl << " Зі спистку тренерів:\n";
     if (tours[idVal].getTrainerMembers().size() == 0) {
         cout << " Тут нікого! " << endl;
     }
     else {
         frame(2);
         for (int n = 0; n < tours[idVal].getTrainerMembers().size(); n++) {
             trainers[tours[idVal].getTrainerMembers()[n]].print();
         }
     }
     cout << endl << " Зі спистку спортсменів:\n";
     if (tours[idVal].getSportsmanMembers().size() == 0) {
         cout << " Тут нікого! " << endl;
     }
     else {
         frame(3);
         for (int n = 0; n < tours[idVal].getSportsmanMembers().size(); n++) {
             sportsmen[tours[idVal].getSportsmanMembers()[n]].print();
         }
     }
     cout << endl;
 }
 void fullCompPrint() {
     int idVal;
     system("cls");
     printVect(comps, 4);
     if (comps.size() != 0) {
         cout << endl << " Вкажіть ID ";
         cin >> idVal;
         if (idVal >= comps.size()) {
             cout << endl << " Помилка! " << endl << " ";
             return;
         }
     }
     else { return; }
     system("cls");
     frame(4);
     comps[idVal].print();
     cout << "\n\t\t\t\t\t\t\t\t\tУЧАСНИКИ:\n Зі списку тренерів:\n";
     if (comps[idVal].getTrMembsSize() == 0) { cout << " Тут нікого! " << endl; }
     else {
         frame(2);
         for (int n = 0; n < comps[idVal].getTrMembsSize(); n++) {
             trainers[comps[idVal].getTrId(n)].print();
         }
     }
     cout << endl << " Зі спистку спортсменів:\n";
     if (comps[idVal].getSmMembsSize() == 0) { cout << " Тут нікого! " << endl; }
     else {
         frame(3);
         for (int n = 0; n < comps[idVal].getSmMembsSize(); n++) {
             sportsmen[comps[idVal].getSmId(n)].print();
         }
     }
     cout << endl;
 }
 void printInstr() {
     system("cls");
     for (int n = 0; n < instructors.size(); n++) {
         if (instructors[n].getType() == 3) {
             cout << " | " << n << " | " << tourists[instructors[n].getIdFromList()].getPIP() << endl;
         }
         else if (instructors[tours[n].getInstrId()].getType() == 2) {
             cout << " | " << n << " | " << trainers[instructors[n].getIdFromList()].getPIP() << endl;
         }
         else if (instructors[tours[n].getInstrId()].getType() == 1) {
             cout << " | " << n << " | " << sportsmen[instructors[n].getIdFromList()].getPIP() << endl;
         }
     }
 }
 void showByTrainings() {
     int check, groupId;
     bool choose;
     system("cls");
     SYSTEMTIME first, second, time;
     bool res = false;
     cout << endl << " Початкова межа:";
     first = setTime();
     cout << endl << " Кінцева межа:";
     second = setTime();
     groupId = setGroup(123);
     system("cls");
     frame(2);
     for (int n = 0; n < trainings.size(); n++) {
         time = trainings[n].getBegTime();
         res = false;
         if (trainings[n].getGroupId() == groupId) {
             if (first.wYear < time.wYear && time.wYear < second.wYear) { res = true; }
             else if (first.wYear == time.wYear) {
                 if (first.wMonth < time.wMonth) { res = true; }
                 else if (time.wMonth == second.wMonth && time.wMonth == first.wMonth) {
                     if (time.wDay > first.wDay && time.wDay < second.wDay) { res = true; }
                 }
                 else if (first.wMonth == time.wMonth) {
                     if (first.wDay <= time.wDay) { res = true; }
                 }
             }
             else if (time.wYear == second.wYear) {
                 if (time.wMonth < second.wMonth) { res = true; }
                 else if (time.wMonth == second.wMonth) {
                     if (time.wDay <= second.wDay) { res = true; }
                 }
             }
             if (res == true) {
                 trainers[trainings[n].getTrainerId()].print();
             }
         }
     }
     cout << endl;
 }
 void showBySect() {
     bool choose;
     int similiar = 0,sectId;
     system("cls");
     vector<int> compIds;
     compIds.clear();
     string sectVal;
     sectId = setSect(0);
     sectVal = sections[sectId].getName();
     system("cls");
     frame(4);
     for (int n = 0; n < sportsmen.size(); n++) {
         if (sportsmen[n].getSect() == sectVal) {
             for (int m = 0; m < sportsmen[n].compsize(); m++) {
                 similiar = 0;
                 for (int i = 0; i < compIds.size(); i++) {
                     if (m == compIds[i]) { similiar++; }
                 }
                 if (similiar == 0) {
                     comps[m].print();
                     compIds.push_back(m);
                 }
             }
         }
     }
 }
 void printWorkload() {
     int check, trainerId,hourQ;
     printVect(trainers, 2);
     cout << endl << " id тренера: ";
     cin >> trainerId;
     if (trainerId >= trainers.size()) { cout << " Помилка! " << endl << " "; }
     system("cls");
     cout << " [1] - За вказаний час \n [2] - За весь час " << endl;
     cin >> check;
     if (check == 2) {
         system("cls");
         frame(2);
         trainers[trainerId].print();
         cout << "\t\t\t\t\t\tСПИСОК ТРЕНУВАНЬ" << endl;
         frame(9);
         hourQ = 0;
         for (int n = 0; n < trainers[trainerId].getTrainingIds().size(); n++) {
             hourQ += trainings[trainers[trainerId].getTrainingIds()[n]].getDuration();
             trainings[trainers[trainerId].getTrainingIds()[n]].print();
         }
         cout << " К-сть годин: " << hourQ << endl << " ";
     }
     else if (check == 1) {
         SYSTEMTIME first, second, time;
         bool res;
         system("cls");
         cout << endl << " Початкова межа:";
         first = setTime();
         cout << endl << " Кінцева межа:";
         second = setTime();
         system("cls");
         frame(2);
         trainers[trainerId].print();
         cout << "\t\t\t\t\t\tСПИСОК ТРЕНУВАНЬ" << endl;
         frame(9);
         hourQ = 0;
         for (int n = 0; n < trainers[trainerId].getTrainingIds().size(); n++) {
             res = false;
             time = trainings[trainers[trainerId].getTrainingIds()[n]].getBegTime();
             if (first.wYear < time.wYear && time.wYear < second.wYear) {
                 res = true;
             }
             else if (first.wYear == time.wYear) {
                 if (first.wMonth < time.wMonth) { res = true; }
                 else if (time.wMonth == second.wMonth && time.wMonth == first.wMonth) {
                     if (time.wDay > first.wDay && time.wDay < second.wDay) { res = true; }
                 }
                 else if (first.wMonth == time.wMonth) {
                     if (first.wDay <= time.wDay) { res = true; }
                 }
             }
             else if (time.wYear == second.wYear) {
                 if (time.wMonth < second.wMonth) { res = true; }
                 else if (time.wMonth == second.wMonth) {
                     if (time.wDay <= second.wDay) { res = true; }
                 }
             }
             if (res == true) {
                 hourQ += trainings[trainers[trainerId].getTrainingIds()[n]].getDuration();
                 trainings[trainers[trainerId].getTrainingIds()[n]].print();
             }
         }
         cout << " К-сть годин: " << hourQ << endl << " ";
     }
 }
 void sortInstrbyCat() {
     system("cls");
     string catVal;
     int catId;
     catId = setSect(3);
     if (catId == sections.size()) { catVal = "піший"; }
     else { catVal = sections[catId].getName(); }
     system("cls");
     for (instructor ins : instructors) {
         switch (ins.getType()) {
         case 1:
             if (trainers[ins.getIdFromList()].categoryCheck(catVal)) {
                 trainers[ins.getIdFromList()].print();
             }
             break;
         case 2:
             if(sportsmen[ins.getIdFromList()].categoryCheck(catVal)) {
                 sportsmen[ins.getIdFromList()].print();
             }
             break;
         case 3:
             if (tourists[ins.getIdFromList()].categoryCheck(catVal)) {
                 tourists[ins.getIdFromList()].print();
             }
             break;
         }
    }     
 }
 void sortInstrbyTourQuant() {
     int quant;
     system("cls");
     cout << " Вкажіть кількість походів ";
     cin >> quant;
     system("cls");
     for (instructor inst : instructors) {
         if (inst.getToursQ() == quant) {
             if (inst.getType() == 1) {
                 trainers[inst.getIdFromList()].print();
             }
             if (inst.getType() == 2) {
                 sportsmen[inst.getIdFromList()].print();
             }
             if (inst.getType() == 3) {
                 tourists[inst.getIdFromList()].print();
             }
         }
     }
 }
 void sortInstrbyTour() {
     system("cls");
     printVect(tours, 6);
     int tourId;
     cout << endl << " Вкажіть id походу ";
     cin >> tourId;
     system("cls");
     if (instructors[tours[tourId].getInstrId()].getType() == 1) {
         trainers[instructors[tours[tourId].getInstrId()].getIdFromList()].print();
     }
     else if (instructors[tours[tourId].getInstrId()].getType() == 2) {
         sportsmen[instructors[tours[tourId].getInstrId()].getIdFromList()].print();
     }
     else if (instructors[tours[tourId].getInstrId()].getType() == 3) {
         tourists[instructors[tours[tourId].getInstrId()].getIdFromList()].print();
     }
 }
 void sortInstrbyRoute() {
     unsigned int idVal;
     printVect(routes, 7);
     cout << endl << " id маршруту: ";
     cin >> idVal;
     system("cls");
     for (int n = 0; n < tours.size(); n++) {
         if (tours[n].getRouteId() == idVal) {
             if (instructors[tours[n].getInstrId()].getType() == 1) {
                 trainers[instructors[tours[n].getInstrId()].getIdFromList()].print();
             }
             else if (instructors[tours[n].getInstrId()].getType() == 2) {
                 sportsmen[instructors[tours[n].getInstrId()].getIdFromList()].print();
             }
             else if (instructors[tours[n].getInstrId()].getType() == 3) {
                 tourists[instructors[tours[n].getInstrId()].getIdFromList()].print();
             }
         }
     }
 }
 void sortInstrbyRoutePlace() {
     system("cls");
     int similiar, placeId;
     vector<string>tmpPlaces;
     vector<int> tmpInstructors;
     for (int n = 0; n < routes.size(); n++) {
         for (int m = 0; m < routes[n].getPlaces().size(); m++) {
             if (tmpPlaces.size() == 1) {
                 tmpPlaces.push_back(routes[n].getPlaces()[m]);
             }
             else {
                 similiar = 0;
                 for (int i = 0; i < tmpPlaces.size(); i++) {
                     if (routes[n].getPlaces()[m] == tmpPlaces[i]) {
                         similiar++;
                     }
                 }
                 if (similiar == 0) {
                     tmpPlaces.push_back(routes[n].getPlaces()[m]);
                 }
                 similiar = 0;
             }
         }
     }
     for (int n = 0; n < tmpPlaces.size(); n++) {
         cout << " [" << n << "] - " << tmpPlaces[n] << endl;
     }
     cout << endl << " Вкажіть id ";
     cin >> placeId;
     system("cls");
     for (int n = 0; n < tours.size(); n++) {
         for (int m = 0; m < routes[tours[n].getRouteId()].getPlaces().size(); m++) {
             if (routes[tours[n].getRouteId()].getPlaces()[m] == tmpPlaces[placeId]) {
                 if (tmpInstructors.empty()) {
                     tmpInstructors.push_back(tours[n].getInstrId());
                 }
                 else {
                     similiar = 0;
                     for (int i = 0; i < tmpInstructors.size(); i++) {
                         if (tmpInstructors[i] == tours[n].getInstrId()) {
                             similiar++;
                         }
                     }
                     if (similiar == 0) {
                         tmpInstructors.push_back(tours[n].getInstrId());
                     }                     
                 }
             }
         }
         
     }
     for (int n = 0; n < tmpInstructors.size(); n++) {
         if (instructors[tmpInstructors[n]].getType() == 1) {
             trainers[instructors[tmpInstructors[n]].getIdFromList()].print();
         }
         else if (instructors[tmpInstructors[n]].getType() == 2) {
             sportsmen[instructors[tmpInstructors[n]].getIdFromList()].print();
         }
         else if (instructors[tmpInstructors[n]].getType() == 3) {
             tourists[instructors[tmpInstructors[n]].getIdFromList()].print();
         }
     }
 }

 void sortRoutebySect() {
     int sectId,similiar;
     string catVal;
     vector<route>tmpRoutes;
     printVect(sections,11);
     cout << " [" << sections.size() << "] - піший";
     cout <<endl<< " Вкажіть id ";
     cin >> sectId;
     if (sectId == sections.size()) { catVal = "піший"; }
     else { catVal = sections[sectId].getName(); }
     system("cls");     
     frame(7);
     for (int n = 0; n < tours.size(); n++) {
         for (int m = 0; m < tours[n].getMembers().size(); m++) {
             if (tourists[tours[n].getMembers()[m]].categoryCheck(catVal)) {
                 if (tmpRoutes.size() == 1) {
                     routes[tours[n].getRouteId()].print();
                     tmpRoutes.push_back(routes[tours[n].getRouteId()]);
                 }
                 else {
                     similiar = 0;
                     for (int i = 0; i < tmpRoutes.size(); i++) {
                         if (tmpRoutes[i].getId() == routes[tours[n].getRouteId()].getId()) {
                             similiar++;
                         }
                     }
                     if (similiar == 0) {
                         routes[tours[n].getRouteId()].print();
                         tmpRoutes.push_back(routes[tours[n].getRouteId()]);
                     }
                 }
             }
         }
     }
     tmpRoutes.clear();
 }
 void sortRoutebyTime() {
     system("cls");
     SYSTEMTIME first, second, time, time2;
     bool res = false, res2 = false;
     cout << endl << " Початкова межа:";
     first = setTime();
     cout << endl << " Кінцева межа:";
     second = setTime();
     system("cls");
     frame(7);
     for (int n = 0; n < tours.size(); n++) {
         time = tours[n].getBegTime();
         time2 = tours[n].getEndTime();
         res = false;
         if (first.wYear < time.wYear && time.wYear < second.wYear) { res = true; }
         else if (first.wYear == time.wYear) {
             if (first.wMonth < time.wMonth) { res = true; }
             else if (time.wMonth == second.wMonth && time.wMonth == first.wMonth) {
             if (time.wDay > first.wDay && time.wDay < second.wDay) { res = true; }
             }
             else if (first.wMonth == time.wMonth) {
             if (first.wDay <= time.wDay) { res = true; }
             }
         }
         else if (time.wYear == second.wYear) {
            if (time.wMonth < second.wMonth) { res = true; }
            else if (time.wMonth == second.wMonth) {
                 if (time.wDay <= second.wDay) { res = true; }
            }
         }
         if (first.wYear < time2.wYear && time2.wYear < second.wYear) { res2 = true; }
         else if (first.wYear == time2.wYear) {
             if (first.wMonth < time2.wMonth) { res2 = true; }
             else if (time2.wMonth == second.wMonth && time2.wMonth == first.wMonth) {
                 if (time2.wDay > first.wDay && time2.wDay < second.wDay) { res2 = true; }
             }
             else if (first.wMonth == time2.wMonth) {
                 if (first.wDay <= time2.wDay) { res2 = true; }
             }
         }
         else if (time2.wYear == second.wYear) {
             if (time2.wMonth < second.wMonth) { res2 = true; }
             else if (time2.wMonth == second.wMonth) {
                 if (time2.wDay <= second.wDay) { res2 = true; }
             }
         }
         if (res == true && res2 == true) { routes[tours[n].getRouteId()].print(); }
     }
     cout << endl;
 }
 void sortRoutebyInstructor() {
     int idVal;
     printInstr();
     cout << endl << " Вкажіть id ";
     cin >> idVal;
     system("cls");
     frame(7);
     for (int n = 0; n < tours.size(); n++) {
         if (tours[n].getInstrId() == idVal) {
             routes[tours[n].getRouteId()].print();
         }
     }
 }
 void sortRoutebyGroupNum() {
     system("cls");
     int groupNumber, similiar;
     vector<string> local_groups;
     vector<int> local_routes, gr;
     cout << " Вкажіть кількість груп ";
     cin >> groupNumber;
     system("cls");
     frame(7);
     for (int i = 0; i < tours.size(); i++) {
         gr.push_back(0);
     }
     for (int n = 0; n < tours.size(); n++) {
         local_routes.push_back(tours[n].getRouteId());
         for (int m = 0; m < local_routes.size(); m++) {
             if (tours[n].getRouteId() == local_routes[m]) { ++gr[n]; }
         }
     }
     for (int n = 0; n < gr.size(); n++) {
         if (gr[n] == groupNumber) { routes[tours[n].getRouteId()].print(); }
     }
 }
 void sortRoutebyPlace() {
     system("cls");
     int similiar,placeId;
     vector<string>tmpPlaces;
     for (int n = 0; n < routes.size(); n++) {
         for (int m = 0; m < routes[n].getPlaces().size(); m++) {
             if (tmpPlaces.size() == 1) {
                 tmpPlaces.push_back(routes[n].getPlaces()[m]);
             }
             else {
                 similiar = 0;
                 for (int i = 0; i < tmpPlaces.size(); i++) {
                     if (routes[n].getPlaces()[m] == tmpPlaces[i]) { similiar++; }
                 }
                 if (similiar == 0) { tmpPlaces.push_back(routes[n].getPlaces()[m]); }
                 similiar = 0;
             }
         }
     }
     for (int n = 0; n < tmpPlaces.size(); n++) {
         cout << " [" << n << "] - " << tmpPlaces[n] << endl;
     }
     cout <<endl<< " Вкажіть id ";
     cin >> placeId;     
     system("cls");
     cout << " --------------------------------------" << endl <<
         " | Місце: " << tmpPlaces[placeId] << setw(30 - tmpPlaces[placeId].length()) << " | " << endl;
     frame(7);
     for (int n = 0; n < routes.size(); n++) {
         for (int m = 0; m < routes[n].getPlaces().size(); m++) {
             if (routes[n].getPlaces()[m] == tmpPlaces[placeId]) { routes[n].print(); }
         }
     }
 }
 void sortRoutebyLength() {
     int lenVal;
     system("cls");
     cout << " Вкажіть довжину маршруту (км) ";
     cin >> lenVal;
     system("cls");
     cout << " ---------------------"<<endl<<
         " | Довжина: " << lenVal << " км" << setw(8 - to_string(lenVal).length()) << " | "<<endl;
     frame(7);
     for (route r : routes) {
         if (r.getLength() > lenVal) { r.print(); }
     }
 }
 void sortRoutebyCategory() {
     system("cls");
     string catVal;
     int catId;
     catId = setSect(3);
     system("cls");
     cout << " --------------------------- " << endl << " | Категорія: " << setw(12) << catVal << " | " << endl;
     frame(7);
     for (int n = 0; n < routes.size(); n++) {
         if (routes[n].getCategory() == catVal) routes[n].print();
     }
 }
  template<typename T>
 void sortbyAllRoutes(vector<T>& v, unsigned int i) {
     int check,idVal;
     cout << endl << " [1] - загалом \n [2] - і за секцією \n [3] - і за групою\n ";
     cin >> check;
     if (check == 1) {
         system("cls");
         frame(i);;
         for (int n = 0; n < v.size(); n++) {
             if (v[n].getToursQ() >= routes.size()) {
                 v[n].print();
             }
         }
     }
     else if (check == 2) {
         idVal = setSect(0);
         system("cls");
         frame(i);
         for (int n = 0; n < tours.size(); n++) {
             if (v[n].getToursQ() >= routes.size() && v[n].getSect() == sections[idVal].getName()) { v[n].print(); }
         }
     }
     else if (check == 3) {
         idVal = setGroup(123);
         system("cls");
         frame(i);
         for (int n = 0; n < tours.size(); n++) {
             if (v[n].getToursQ() >= routes.size() && v[n].getGroup() == groups[idVal].getName()) { v[n].print(); }
         }
     }
 }
 template<typename T>
 void sortbyRouteCat(vector<T>& v, unsigned int i) {
     system("cls");
     int check,catId,groupId,sectId;
     cout << " [1] - загалом\n [2] - і за секцією\n [3] - і за групою\n";
     cin >> check;
     string catVal,sectVal;     
     catId = setSect(3);
     if (catId == sections.size()) catVal = "піший";
     else catVal = sections[catId].getName();
     system("cls");
     if (check == 1) {
         cout << " --------------------------- " << endl << " | Категорія: " << setw(12) << catVal << " | " << endl;
         frame(i);
         for (int n = 0; n < v.size(); n++) {
             v[n].categoryPrint(catVal);
         }
     }
     else if (check == 2) {         
         sectId = setSect(0);
         sectVal = sections[sectId].getName();
         cout << " -------------------------------------------------------- " << endl << " | Категорія: " << setw(12) << catVal << " | Секція: "<<sectVal << setw(21-sectVal.length()) <<" | "<< endl;
         frame(i);
         for (int n = 0; n < v.size(); n++) {
             v[n].categoryNsectionPrint(catVal,sectVal);
         }
     }
     else if (check == 3) {
         groupId = setGroup(123);
         sectVal = groups[groupId].getName();
         cout << " ------------------------------------------- " << endl << " | Категорія: " << setw(12) << catVal << " | Група: " << sectVal << setw(8 - sectVal.length()) << " | " << endl;
         frame(i);
         for (int n = 0; n < v.size(); n++) {
             v[n].categoryNgroupPrint(catVal, sectVal);
         }
     }
 }
 template<typename T>
 void sortbyTourQ(vector<T>& v, unsigned int i) {
     system("cls");
     unsigned int quant;
     cout << " Кількість походів: ";
     cin >> quant;
     system("cls");
     cout << " ------------------ " << endl << " | Кількість: "  << quant << setw(6-to_string(quant).length()) << " | " << endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].tourQuantPrint(quant);
     }
 }
 template<typename T>
 void sortbyTourQandSect(vector<T>& v, unsigned int i) {
     system("cls");
     unsigned int quant, check, sectId;
     string sect;
     cout << " Кількість походів: ";
     cin >> quant;   
     sectId = setSect(0);
     sect = sections[sectId].getName();     
     system("cls");
     cout << " ------------------------------------------ " << endl << " | Кількість: " << quant << setw(6 - to_string(quant).length()) << " | " << "Секція: " << sect << setw(16 - sect.length()) << " | " << endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].tourQuantNgroupPrint(quant,sect);
     }
 }
 template<typename T>
 void sortbyTourQandGroup(vector<T>& v, unsigned int i) {
     system("cls");
     unsigned int quant, check,groupId;
     string groupV;
     cout << " Кількість походів: ";
     cin >> quant;
     groupId = setGroup(123);
     groupV = groups[groupId].getName();
     system("cls");
     cout << " -------------------------------- " << endl << " | Кількість: " << quant << setw(6 - to_string(quant).length()) << " | " << "Група: " << groupV << " | " << endl;

     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].tourQuantNgroupPrint(quant, groupV);
     }
 } 
 template<typename T>
 void sortbyAge( vector<T>& v,unsigned int i) {
     system("cls");
     unsigned int ageVal;
     cout << " Вкажіть вік ";
     cin >> ageVal;
     system("cls");     
     cout << " ------------ " << endl << " | Вік: " << setw(3) << ageVal << " | " << endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].agePrint(ageVal);
     }
 }
 template<typename T>
 void sortbyBy( vector<T>& v, unsigned int i) {
     system("cls");
     unsigned int byVal;
     cout << " Вкажіть рік народження: ";
     cin >> byVal;
     system("cls");
     cout << " ------------------------ " << endl << " | Рік народження: " << setw(3) << byVal << " | "<< endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].bdPrint(byVal);
     }
 }
 template<typename T>
 void sortbySex( vector<T>& v, unsigned int i) {
     system("cls");
     string sexVal;
     int check;
     sexVal = setSex();
     system("cls");
     cout << " ---------------------- " << endl << " | Стать: " << setw(11) << sexVal << " | "<<endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].sexPrint(sexVal);
     }
 }
 template<typename T>
 void sortbySect( vector<T>& v, unsigned int i) {
     system("cls");
     string sectVal;
     int sectId;
     bool choose = false;
     sectId = setSect(0);
     sectVal = sections[sectId].getName();
     system("cls");
     cout << " ------------------------ " << endl << " | Секція: " << setw(12) << sectVal << " | "<<endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].sectPrint(sectVal);
     }
 }
 template<typename T>
 void sortbySpec(vector<T>& v, unsigned int i) {
    string specVal;
    int specId;
    specId = setSect(1);
    specVal = sections[specId].getName();
     system("cls");
     cout << " ------------------------ " << endl << " | Секція: " << setw(12) << specVal << " | " << endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].specPrint(specVal);
     }
 }
 template<typename T>
 void sortbySal( vector<T>& v, unsigned int i) {
     float salVal;
     bool choose=false;
     int check;
     cout << " Вкажіть розмір зарплати ";
     cin >> salVal;
     system("cls");
     cout << " ------------ " << endl << " | зарплата: " << setw(5) << salVal << " | " << endl;
     choose = false;
     while (!choose) {
         cout << "\n [1] - Більше вказаної\n [2] - Менше вказаної\n [3] - Рівно вказаній ";
         cin >> check;
         if (check == 1) {
             frame(i);
             for (int n = 0; n < v.size(); n++) {
                 v[n].salMoreThenPrint(salVal);
                 choose = true;
             }
         }
         else if (check == 2) {
             frame(i);
             for (int n = 0; n < v.size(); n++) {
                 v[n].salLessThenPrint(salVal);
                 choose = true;
             }
         }
         else if (check == 3) {
             frame(i);
             for (int n = 0; n < v.size(); n++) {
                 v[n].salEqualPrint(salVal);
                 choose = true;
             }
         }
         else {
             choose = false;
             cout << endl << " Помилка, спробуйте знову" << endl;
             system("pause");
             system("cls");
         }
     }
 }

 template<typename T>
 void sortbyCat(vector<T>& v, unsigned int i) {
     system("cls");
     string category;
     int catVal;
     catVal = setSect(2);
     if (catVal == sections.size()) { category = "піший"; }
     else { category = sections[catVal].getName(); }
     system("cls");
     cout << " --------------------------- " << endl << " | Категорія: " << setw(12) << catVal << " | " << endl;
     frame(i);
     for (int n = 0; n < v.size(); n++) {
         v[n].categoryPrint(category);
     }
 }
 template<typename T>
 void sortbyChoosenTour(vector<T>& v, unsigned int i) {
     system("cls");
     unsigned int idVal;
     printVect(tours, 6);
     cout << endl << " id походу: ";
     cin >> idVal;
     system("cls");
     frame(i);
     if (i == 1) {
         for (int n = 0; n < tours[idVal].getMembers().size(); n++) {
             v[tours[idVal].getMembers()[n]].print();
         }
     }
     if (i == 2) {
         for (int n = 0; n < tours[idVal].getTrainerMembers().size(); n++) {
             v[tours[idVal].getTrainerMembers()[n]].print();
         }
     }
     if (i == 3) {
         for (int n = 0; n < tours[idVal].getSportsmanMembers().size(); n++) {
             v[tours[idVal].getSportsmanMembers()[n]].print();
         }
     }
 }
 template<typename T>
 void sortbyTourTime(vector<T>& v, unsigned int i) {
     system("cls");
     SYSTEMTIME first, second, time, time2;
     bool res = false, res2 = false;
     cout << endl << " Початкова межа:";
     first = setTime();
     cout << endl << " Кінцева межа:";
     second = setTime();
     system("cls");
     frame(i);
     for (int n = 0; n < tours.size(); n++) {
         time = tours[n].getBegTime();
         time2 = tours[n].getEndTime();
         res = false;
         if (first.wYear < time.wYear && time.wYear < second.wYear) {
             res = true;
         }
         else if (first.wYear == time.wYear) {
             if (first.wMonth < time.wMonth) { res = true; }
             else if (time.wMonth == second.wMonth && time.wMonth == first.wMonth) {
                 if (time.wDay > first.wDay && time.wDay < second.wDay) { res = true; }
             }
             else if (first.wMonth == time.wMonth) {
                 if (first.wDay <= time.wDay) { res = true; }
             }
         }
         else if (time.wYear == second.wYear) {
             if (time.wMonth < second.wMonth) { res = true; }
             else if (time.wMonth == second.wMonth) {
                 if (time.wDay <= second.wDay) { res = true; }
             }
         }
         if (first.wYear < time2.wYear && time2.wYear < second.wYear) { res2 = true; }
         else if (first.wYear == time2.wYear) {
             if (first.wMonth < time2.wMonth) { res2 = true; }
             else if (time2.wMonth == second.wMonth && time2.wMonth == first.wMonth) {
                 if (time2.wDay > first.wDay && time2.wDay < second.wDay) { res2 = true; }
             }
             else if (first.wMonth == time2.wMonth) {
                 if (first.wDay <= time2.wDay) { res2 = true; }
             }
         }
         else if (time2.wYear == second.wYear) {
             if (time2.wMonth < second.wMonth) { res2 = true; }
             else if (time2.wMonth == second.wMonth) {
                 if (time2.wDay <= second.wDay) { res2 = true; }
             }
         }

         if (res == true && res2 == true) {
             if (i == 1) {
                 for (int m = 0; m < tours[n].getMembers().size(); m++) {
                     v[tours[n].getMembers()[m]].print();
                 }
             }
             else if (i == 2) {
                 for (int m = 0; m < tours[n].getTrainerMembers().size(); m++) {
                     v[tours[n].getTrainerMembers()[m]].print();
                 }
             }
             else if (i == 3) {
                 for (int m = 0; m < tours[n].getSportsmanMembers().size(); m++) {
                     v[tours[n].getSportsmanMembers()[m]].print();
                 }
             }
         }
     }
     cout << endl;
 }
 template<typename T>
 void sortbyRoute(vector<T>& v, unsigned int i) {
     unsigned int idVal;
     printVect(routes, 7);
     cout << endl << " id маршруту: ";
     cin >> idVal;
     system("cls");
     frame(i);
     for (int n = 0; n < tours.size(); n++) {         
         if (tours[n].getRouteId() == idVal) {
             if (i == 1) {
                 for (int m = 0; m < tours[n].getMembers().size(); m++) {
                     v[tours[n].getMembers()[m]].print();
                 }
             }
             else if (i == 2) {
                 for (int m = 0; m < tours[n].getTrainerMembers().size(); m++) {
                     v[tours[n].getTrainerMembers()[m]].print();
                 }
             }
             else if (i == 3) {
                 for (int m = 0; m < tours[n].getSportsmanMembers().size(); m++) {
                     v[tours[n].getSportsmanMembers()[m]].print();
                 }
             }
         }
     }
 }
 template<typename T>
 void sortbyRoutePlace(vector<T>& v, unsigned int i) {
     system("cls");
     int similiar, placeId;
     vector<string>tmpPlaces;
     for (int n = 0; n < routes.size(); n++) {
         for (int m = 0; m < routes[n].getPlaces().size(); m++) {
             if (tmpPlaces.size() == 1) {
                 tmpPlaces.push_back(routes[n].getPlaces()[m]);
             }
             else {
                 similiar = 0;
                 for (int i = 0; i < tmpPlaces.size(); i++) {
                     if (routes[n].getPlaces()[m] == tmpPlaces[i]) {
                         similiar++;
                     }
                 }
                 if (similiar == 0) {
                     tmpPlaces.push_back(routes[n].getPlaces()[m]);
                 }
                 similiar = 0;
             }
         }
     }
     for (int n = 0; n < tmpPlaces.size(); n++) {
         cout << " [" << n << "] - " << tmpPlaces[n] << endl;
     }
     cout << endl << " точка маршруту: ";
     cin >> placeId;
     system("cls");
     frame(i);
     for (int n = 0; n < routes.size(); n++) {
         for (int m = 0; m < routes[n].getPlaces().size(); m++) {
             if (routes[n].getPlaces()[m] == tmpPlaces[placeId]) {
                 if (i == 1) {
                     for (int m = 0; m < tours[n].getMembers().size(); m++) {
                         v[tours[n].getMembers()[m]].print();
                     }
                 }
                 else if (i == 2) {
                     for (int m = 0; m < tours[n].getTrainerMembers().size(); m++) {
                         v[tours[n].getTrainerMembers()[m]].print();
                     }
                 }
                 else if (i == 3) {
                     for (int m = 0; m < tours[n].getSportsmanMembers().size(); m++) {
                         v[tours[n].getSportsmanMembers()[m]].print();
                     }
                 }
             }
         }
     }
 }
 template<typename T>
 void sortbyBeingInstructor(vector<T>& v, unsigned int i) {
     int type,check,idVal;
     if (i == 1) {
         type = 3;
     }
     else if (i == 3) {
         type = 2;
     }  
     cout << endl<< " [1] - загалом \n [2] - і за секцією \n [3] - і за групою\n ";
     cin >> check;
     if (check == 1) {
         system("cls");
         frame(i);
         for (int n = 0; n < tours.size(); n++) {
             if (instructors[tours[n].getInstrId()].getType() == type) {
                 v[tours[n].getInstrId()].print();
             }
         }
     }
     else if (check == 2) {
         printVect(sections, 123);
         cout << endl << " Вкажіть id секції";
         cin >> idVal;
         system("cls");
         frame(i);
         for (int n = 0; n < tours.size(); n++) {
             if (instructors[tours[n].getInstrId()].getType() == type && v[tours[n].getInstrId()].getSect()==sections[idVal].getName()) {
                 
                 v[tours[n].getInstrId()].print();
             }
         }
     }
     else if (check == 3) {
         for (group gr : groups) {
             cout << " [" << gr.getId() << "] - " << gr.getName() << endl;
         }
         cout << endl << " Вкажіть id групи ";
         cin >> idVal;
         system("cls");
         frame(i);
         for (int n = 0; n < tours.size(); n++) {
             if (instructors[tours[n].getInstrId()].getType() == type && v[tours[n].getInstrId()].getGroup() == groups[idVal].getName()) {

                 v[tours[n].getInstrId()].print();
             }
         }
     }
 }
 void menu() {
    bool is_admin=false, is_trainer= false, is_sect_head= false;
    string login, password;
    cout << setw(55) << " " << " Login: ";
    cin >> login;
    cout << setw(55) << " " << " Password: ";
    cin >> password;
    if (login == "admin" && password == "ytrewq") {
        is_admin = true;
        system("cls");
        cout << setw(55) << " " << " Logged in as admin"<<endl;
        system("pause");
    }
    else if (login == "trainer" && password == "qwerty") {
        is_trainer = true;
        system("cls");
        cout << setw(55) << " " << " Logged in as trainer" << endl;
        system("pause");
    }
    else if (login=="shead" && password=="54321") {
        is_sect_head = true;
        system("cls");
        cout << setw(55) << " " << " Logged in as section head" << endl;
        system("pause");
    }
    else {
        system("cls");
        cout << setw(55) << " " << " Logged in as visitor"<<endl;
        system("pause");
    }
    int check;
    database db;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("mode con cols=161 lines=50");
    int stateMenu = -1, stateTMenu = -1, stateTrMenu = -1, stateTourMenu = -1, stateEventMenu=-1,stateSportmenMenu=-1,stateSortByToursMenu=-1,stateSortBytourQuantMenu=-1,stateSectHeadMenu=-1,stateRouteMenu=-1,stateInstrMenu=-1,stateAddMenu=-1, num;
    while (stateMenu != 0) {
        stateTMenu = -1;
        stateTrMenu = -1;
        stateTourMenu = -1;
        stateSportmenMenu = -1;
        stateEventMenu = -1;
        stateSortByToursMenu = -1;
        stateSortBytourQuantMenu = -1;
        stateSectHeadMenu = -1;
        stateRouteMenu = -1;
        stateInstrMenu = -1;
        stateAddMenu = -1;
        system("cls");
        cout << endl << setw(55) << " " << " Оберіть дію " << endl
            << setw(55) << " " << " [1] \t- Меню туристів" << endl
            << setw(55) << " " << " [2] \t- Меню спортсменів " << endl
            << setw(55) << " " << " [3] \t- Меню тренерів " << endl
            << setw(55) << " " << " [4] \t- Меню подій " << endl
            << setw(55) << " " << " [5] \t- Меню походів" << endl
            << setw(55) << " " << " [6] \t- Меню керівників секцій" << endl
            << setw(55) << " " << " [7] \t- Відсортувати список відвідувачів за походами " << endl << endl

            << setw(55) << " " << " [8] \t- Зчитати дані з файлу" << endl;            
       if (is_admin) {
           cout << setw(55) << " " << " [9] \t- Записати дані у файл" << endl
                << setw(55) << " " << " [10] \t- Меню додавання даних" << endl << endl
                << setw(55) << " " << " [12] \t- Ініціалізація секцій та груп" << endl << endl;
       }
       else if (is_trainer) {
           cout << setw(55) << " " << " [10] \t- Створити тренування" << endl<<endl;
       }
       else if (is_sect_head) {
           cout << setw(55) << " " << " [10] \t- Створити змагання" << endl << endl;
       }
       cout << setw(55) << " " << " [0] \t- Вихід " << endl
            << setw(55) << " " << " Вибір \t- ";
        cin >> stateMenu;
        switch (stateMenu)
        {
        case 10:
            while (stateAddMenu != 0) {
                if (is_admin) {
                    system("cls");
                    cout << endl << setw(55) << " " << " Оберіть дію " << endl
                        << setw(55) << " " << " [1] \t- Додати туристів" << endl
                        << setw(55) << " " << " [2] \t- Додати спортсменів" << endl
                        << setw(55) << " " << " [3] \t- Додати тренера" << endl
                        << setw(55) << " " << " [4] \t- Створити тренування" << endl
                        << setw(55) << " " << " [5] \t- Створити змагання" << endl
                        << setw(55) << " " << " [6] \t- Створити плановий похід" << endl
                        << setw(55) << " " << " [7] \t- Додати керівника секції" << endl
                        << setw(55) << " " << " [8] \t- Додати щоденник до походу " << endl
                        << setw(55) << " " << " [9] \t- Створити план походів на рік " << endl << endl

                        << setw(55) << " " << " [0] \t- Назад " << endl
                        << setw(55) << " " << " Вибір \t- ";
                    cin >> stateAddMenu;
                    switch (stateAddMenu) {
                    case 1:
                        db.addVisitor(tourists, db.touristNum, 0);
                        break;
                    case 2:
                        db.addVisitor(sportsmen, db.soprtsmanNum, 0);
                        break;
                    case 3:
                        db.addVisitor(trainers, db.trainerNum, 0);
                        break;
                    case 4:
                        db.addTraining();
                        break;
                    case 5:
                        db.addComp();
                        break;
                    case 6:
                        db.createTour();
                        break;
                    case 7:
                        db.addVisitor(sectHeads, db.sectHeadNum, 0);
                        break;
                    case 8:
                        db.addDiary();
                        break;
                    case 9:
                        db.createSchedule();
                        break;
                    case 0:
                        stateAddMenu = 0;
                        stateMenu = -1;
                        continue;
                        break;
                    default:
                        stateAddMenu = 0;
                        stateMenu = -1;
                        continue;
                        break;
                    }                    
                    break;
                }
                else if (is_trainer) {
                    db.addTraining();
                    break;
                }
                else if (is_sect_head) {
                    db.addComp();
                    break;
                }                
            }
            system("cls");
            continue;
            break;
        case 1:
            while (stateTMenu != 0) {
                system("cls");
                cout << endl << setw(55) << " " << " Оберіть дію " << endl
                    << setw(55) << " " << " [1] \t- Вивести список туристів" << endl

                    << setw(55) << " " << " Відсортувати список туристів за" << endl
                    << setw(55) << " " << " [2] \tстатевою ознакою" << endl
                    << setw(55) << " " << " [3] \tроком народження" << endl
                    << setw(55) << " " << " [4] \tвіком" << endl
                    << setw(55) << " " << " [5] \tсекцією " << endl
                    << setw(55) << " " << " [6] \tкатегорією походу, в який може іти " << endl
                    << setw(55) << " " << " [7] \tпоходами, в яких вони були інструкторами " << endl << endl
                    << setw(55) << " " << " [8] \t- Вивести тих туристів, що ходили по всіх маршрутах " << endl << endl

                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateTMenu;
                switch (stateTMenu) {
                case 1:
                    system("cls");
                    printVect(tourists, 1);
                    break;
                case 2:
                    sortbySex(tourists,1);
                    break;
                case 3:
                    sortbyBy(tourists,1);
                    break;
                case 4:
                    sortbyAge(tourists,1);
                    break;
                case 5:
                    sortbySect(tourists,1);
                    break;
                case 6:
                    sortbyRouteCat(tourists, 1);
                    break;
                case 7:
                    sortbyBeingInstructor(tourists, 1);
                    break;
                case 8:
                    sortbyAllRoutes(tourists, 1);
                    break;
                case 0:
                    stateTMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                default:
                    stateTMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                }
                system("pause");
                continue;
            }
            break;
        case 2:
            while (stateSportmenMenu != 0) {
                system("cls");
                cout << endl << setw(55) << " " << " Оберіть дію " << endl
                    << setw(55) << " " << " [1] \t- Вивести список спортсменів" << endl

                    << setw(55) << " " << " Відсортувати список спортсменів за" << endl
                    << setw(55) << " " << " [2] \tстатевою ознакою" << endl
                    << setw(55) << " " << " [3] \tроком народження" << endl
                    << setw(55) << " " << " [4] \tвіком" << endl
                    << setw(55) << " " << " [5] \tсекцією " << endl
                    << setw(55) << " " << " [6] \tкатегорією походу, в який може іти " << endl 
                    << setw(55) << " " << " [7] \t походами, в яких вони були інструкторами " << endl << endl

                    << setw(55) << " " << " [8] \t- Отримати перелік змагань, в яких брали участь спортсмени вказаної секцієї " << endl << endl

                    << setw(55) << " " << " [9] \t- Вивести тих спортсменів, що ходили по всіх маршрутах " << endl << endl
                    
                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateSportmenMenu;
                switch (stateSportmenMenu) {
                case 1:
                    system("cls");
                    printVect(sportsmen, 3);
                    break;
                case 2:
                    sortbySex(sportsmen, 3);
                    break;
                case 3:
                    sortbyBy(sportsmen, 3);
                    break;
                case 4:
                    sortbyAge(sportsmen, 3);
                    break;
                case 5:
                    sortbySect(sportsmen, 3);
                    break;
                case 6:
                    sortbyCat(sportsmen, 3);
                    break;
                case 7:
                    sortbyBeingInstructor(sportsmen, 3);
                    break;
                case 8:
                    showBySect();
                    break;                    
                case 9:
                    sortbyAllRoutes(sportsmen, 3);
                    break;
                case 0:
                    stateSportmenMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                default:
                    stateSportmenMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                }
                system("pause");
                continue;
            }
            break;
        case 3:
            while (stateTrMenu != 0) {
                system("cls");
                cout << endl << setw(55) << " " << " Оберіть дію " << endl
                    << setw(55) << " " << " [1] \t- Вивести список тренерів" << endl

                    << setw(55) << " " << " Відсортувати список тренерів за" << endl
                    << setw(55) << " " << " [2] \tстатевою ознакою" << endl
                    << setw(55) << " " << " [3] \tроком народження" << endl
                    << setw(55) << " " << " [4] \tвіком" << endl
                    << setw(55) << " " << " [5] \tсекцією " << endl
                    << setw(55) << " " << " [6] \tспеціалізацією " << endl
                    << setw(55) << " " << " [7] \tзарплатою " << endl
                    << setw(55) << " " << " [8] \tкатегорією походу, в який може іти " << endl << endl

                    << setw(55) << " " << " [9] \t- Отримати список тpенеpів, які проводили тренування у зазначеній групі, за вказаний період часу " << endl
                    << setw(55) << " " << " [10] \t- Навантаження тренерів " << endl << endl

                    << setw(55) << " " << " [11] \t- Вивести тих тренерів, що ходили по всіх маршрутах " << endl << endl

                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateTrMenu;
                switch (stateTrMenu) {
                case 1:
                    system("cls");
                    printVect(trainers, 2);
                    break;
                case 2:
                    sortbySex(trainers,2);
                    break;
                case 3:
                    sortbyBy(trainers,2);
                    break;
                case 4:
                    sortbyAge(trainers,2);
                    break;
                case 5:
                    sortbySect(trainers,2);
                    break;
                case 6:
                    sortbySpec(trainers,2);
                    break;
                case 7:
                    sortbySal(trainers,2);
                    break;
                case 8:
                    sortbyRouteCat(trainers, 2);
                    break;
                case 9:
                    showByTrainings();
                    break;
                case 10:
                    printWorkload();
                    break;
                case 11:
                    sortbyAllRoutes(trainers, 2);
                    break;
                case 0:
                    stateTrMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                default:
                    stateTrMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                }
                system("pause");
                continue;
            }
            break;
        case 4:
            while (stateEventMenu != 0) {
                system("cls");
                cout << endl << setw(55) << " " << " Оберіть дію " << endl
                    << setw(55) << " " << " [1] \t- Вивести список тренувань" << endl << endl

                    << setw(55) << " " << " [2] \t- Вивести список змагань" << endl
                    << setw(55) << " " << " [3] \t- Повна інформація про змагання" << endl << endl

                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateEventMenu;
                switch (stateEventMenu) {
                case 1:
                    system("cls");
                    printVect(trainings, 5);
                    break;
                case 2:
                    system("cls");
                    printVect(comps, 4);
                    break;
                case 3:
                    fullCompPrint();
                    break;
                case 0:
                    stateEventMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                default:
                    stateEventMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                }
                system("pause");
                continue;
            }
            break;
        case 5:
            while (stateTourMenu != 0) {
                system("cls");
                cout << endl << setw(55) << " " << " Оберіть дію " << endl
                    << setw(55) << " " << " [1] \t- Вивести список походів " << endl
                    << setw(55) << " " << " [2] \t- Повна інформація про похід за id" << endl
                    << setw(55) << " " << " [3] \t- Переглянути щоденник походу" << endl << endl


                    << setw(55) << " " << " [4] \t- Меню маршрутів" << endl << endl

                    << setw(55) << " " << " [5] \t- Меню інструкторів " << endl << endl

                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateTrMenu;
                switch (stateTrMenu) {
                case 1:
                    system("cls");
                    printVect(tours, 6);
                    break;
                case 2:
                    fullTourPrint();
                    break;
                case 3:
                    printDiary();
                    break;
                case 4:
                    stateRouteMenu = -1;
                    while (stateRouteMenu != 0) {
                        system("cls");
                        cout << endl << setw(55) << " " << " Отримати перелік маршрутів по яких ходили туристи " << endl
                            << setw(55) << " " << " [1] \t- Із вказаної секції" << endl
                            << setw(55) << " " << " [2] \t- В означений період часу " << endl
                            << setw(55) << " " << " [3] \t- За якими водили свої групи даний інструктор" << endl
                            << setw(55) << " " << " [4] \t- За якими пройшли вказану кількість груп" << endl << endl

                            << setw(55) << " " << " [5] \t- Вивести список маршрутів" << endl<<endl

                            << setw(55) << " " << " Відсортувати список маршрутів за " << endl
                            << setw(55) << " " << " [6] \t- зазначеною точкою, через яку проходить маршрут " << endl
                            << setw(55) << " " << " [7] \t- довжиною маршруту, більшою за вказану" << endl
                            << setw(55) << " " << " [8] \t- категорією складності " << endl<<endl

                            << setw(55) << " " << " [0] \t- Назад " << endl
                            << setw(55) << " " << " Вибір \t- ";
                        cin >> stateRouteMenu;
                        switch (stateRouteMenu) {
                        case 1:
                            sortRoutebySect();
                            break;
                        case 2:
                            sortRoutebyTime();
                            break;
                        case 3:
                            sortRoutebyInstructor();
                            break;
                        case 4:
                            sortRoutebyGroupNum();
                            break;
                        case 5:
                            system("cls");
                            printVect(routes, 7);
                            break;
                        case 6:
                            sortRoutebyPlace();
                            break;
                        case 7:
                            sortRoutebyLength();
                            break;
                        case 8:
                            sortRoutebyCategory();
                            break;                        
                        case 0:
                            stateRouteMenu = 0;
                            stateTourMenu = -1;
                            stateMenu = -1;
                            continue;
                            break;
                        default:
                            stateRouteMenu = 0;
                            stateTourMenu = -1;
                            stateMenu = -1;
                            continue;
                            break;
                        }
                        system("pause");
                        continue;
                    }
                    break;
                case 5:
                    stateInstrMenu = -1;
                    while (stateInstrMenu != 0) {
                        system("cls");
                        cout << endl << setw(55) << " " << " Меню інструкторів " << endl
                            << setw(55) << " " << " [1] \t- Вивести список інструкторів " << endl
                            << setw(55) << " " << " Отримати перелік інстрокторів які  " << endl
                            << setw(55) << " " << " [2] \t- мають певну катеорію " << endl
                            << setw(55) << " " << " [3] \t- ходили в задану кількість походів " << endl
                            << setw(55) << " " << " [4] \t- були в конкретному поході " << endl
                            << setw(55) << " " << " [5] \t- ходили конкретним маршрутом " << endl
                            << setw(55) << " " << " [6] \t- були в заданій точці маршруту " << endl
                            << setw(55) << " " << " [0] \t- Назад " << endl
                            << setw(55) << " " << " Вибір \t- ";
                        cin >> stateInstrMenu;
                        switch (stateInstrMenu) {
                        case 1:
                            printInstr();
                            break;
                        case 2:
                            sortInstrbyCat();
                            break;
                        case 3:
                            sortInstrbyTourQuant();
                            break;
                        case 4:
                            sortInstrbyTour();
                            break;
                        case 5:
                            sortInstrbyRoute();
                            break;
                        case 6:
                            sortInstrbyRoutePlace();
                            break;
                        case 0:
                            stateInstrMenu = 0;
                            stateTourMenu = -1;
                            stateMenu = -1;
                            continue;
                            break;
                        default:
                            stateInstrMenu = 0;
                            stateTourMenu = -1;
                            stateMenu = -1;
                            continue;
                            break;
                        }
                        system("pause");
                        continue;
                    }
                    break;
                case 0:
                    stateTourMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                default:
                    stateTourMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                }
                system("pause");
                continue;                
            }
            break;
        case 6:
            while (stateSectHeadMenu != 0) {
                system("cls");
                   cout << setw(55) << " " << " [1] \t- Вивести список керівників секцій" << endl

                    << setw(55) << " " << " Відсортувати список керівників секцій за" << endl
                    << setw(55) << " " << " [2] \tстатевою ознакою" << endl
                    << setw(55) << " " << " [3] \tроком народження" << endl
                    << setw(55) << " " << " [4] \tвіком" << endl
                    << setw(55) << " " << " [5] \tдатою надходження на роботу " << endl
                    << setw(55) << " " << " [6] \tзарплатою " << endl << endl

                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateSectHeadMenu;
                switch (stateSectHeadMenu) {
                case 1:
                    system("cls");
                    printVect(sectHeads, 8);
                    break;
                case 2:
                    sortbySex(sectHeads, 8);
                    break;
                case 3:
                    sortbyBy(sectHeads, 8);
                    break;
                case 4:
                    sortbyAge(sectHeads, 8);
                    break;
                case 5:
                    sortbySect(sectHeads, 8);
                    break;
                case 6:
                    sortbySal(sectHeads, 8);
                    break;
                case 0:
                    stateSectHeadMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                default:
                    stateSectHeadMenu = 0;
                    stateMenu = -1;
                    continue;
                    break;
                }
                system("pause");
                continue;
            }
            break;
        case 7:
            while (stateSortByToursMenu != 0) {
                system("cls");
                cout << endl << setw(55) << " " << " Оберіть дію " << endl
                    << setw(55) << " " << " Відсортувати список туристів: " << endl
                    << setw(55) << " " << " [1] \tза кількістю походів " << endl
                    << setw(55) << " " << " [2] \tходили в конкретний похід " << endl
                    << setw(55) << " " << " [3] \tходили в похід в зазначений час" << endl
                    << setw(55) << " " << " [4] \tходили по певному маршруту " << endl
                    << setw(55) << " " << " [5] \tбули в деякій точці маршруту " << endl
                    << setw(55) << " " << " [6] \tмають деяку категорію " << endl << endl

                    << setw(55) << " " << " [0] \t- Назад " << endl
                    << setw(55) << " " << " Вибір \t- ";
                cin >> stateSortByToursMenu;
                switch (stateSortByToursMenu) {
                case 1:
                    stateSortBytourQuantMenu = -1;                                        
                    while (stateSortBytourQuantMenu != 0) {
                        system("cls");
                        cout << endl << setw(55) << " " << " Оберіть дію " << endl
                            << setw(55) << " " << " Відсортувати список відвідувачів клубу за кількістю походів: " << endl
                            << setw(55) << " " << " [1] \tзагалом" << endl
                            << setw(55) << " " << " [2] \tі за вказаною секцією " << endl
                            << setw(55) << " " << " [3] \tі за вказаною групою " << endl
                            << setw(55) << " " << " [0] \t- Назад " << endl
                            << setw(55) << " " << " Вибір \t- ";
                        cin >> stateSortBytourQuantMenu;
                        switch (stateSortBytourQuantMenu) {
                        case 1:
                            system("cls");
                            cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t- ";
                            cin >> check;
                            switch (check) {
                            case 1:
                                sortbyTourQ(tourists, 1);
                                break;
                            case 2:
                                sortbyTourQ(sportsmen, 3);
                                break;
                            case 3:
                                sortbyTourQ(trainers, 2);
                                break;
                            case 0:
                                continue;
                                check = -1;
                                break;
                            default:
                                cout << "Помилка!" << " ";
                                break;
                            
                        }
                            system("pause");
                            continue;
                            break;
                        case 2:
                            system("cls");
                            cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t - ";
                            cin >> check;
                            switch (check) {
                            case 1:
                                sortbyTourQandSect(tourists, 1);
                                break;
                            case 2:
                                sortbyTourQandSect(sportsmen, 3);
                                break;
                            case 3:
                                sortbyTourQandSect(trainers, 2);
                                break;
                            case 0:
                                continue;
                                check = -1;
                                break;
                            default:
                                cout << "Помилка!" << " ";
                                break;
                            }
                            system("pause");
                            continue;
                            break;
                        case 3:
                            system("cls");
                            cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t - ";
                            cin >> check;
                            switch (check) {
                            case 1:
                                sortbyTourQandGroup(tourists, 1);
                                break;
                            case 2:
                                sortbyTourQandGroup(sportsmen, 3);
                                break;
                            case 3:
                                sortbyTourQandGroup(trainers, 2);
                                break;
                            case 0:
                                continue;
                                check = -1;
                                break;
                            default:
                                cout << "Помилка!" << " ";
                                break;
                            }
                            system("pause");
                            continue;
                            break;
                        case 0:
                            stateSortBytourQuantMenu = 0;
                            stateMenu = -1;
                            stateSortByToursMenu = -1;
                            break;
                        default:
                            stateSortBytourQuantMenu = 0;
                            stateMenu = -1;
                            stateSortByToursMenu = -1;
                            cout << "Помилка!" << " ";
                            system("pause");
                            break;
                        }
                        continue;
                    }
                    continue;
                    break; 
                case 0:
                    stateMenu = -1;
                    stateSortByToursMenu = 0;
                    continue;
                    break;
                case 6:
                    stateSortBytourQuantMenu = -1;
                    system("cls");
                    cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t- ";
                    cin >> check;
                    switch (check) {
                    case 1:
                        sortbyCat(tourists, 1);
                        break;
                    case 2:
                        sortbyCat(sportsmen, 3);
                        break;
                    case 3:
                        sortbyCat(trainers, 2);
                        break;
                    case 0:
                        continue;
                        check = -1;
                        break;
                    default:
                        cout << "Помилка!" << " ";
                        break;
                    }                    
                    break;
                case 5:
                    stateSortBytourQuantMenu = -1;
                    system("cls");
                    cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t- ";
                    cin >> check;
                    switch (check) {
                    case 1:
                        sortbyRoutePlace(tourists, 1);
                        break;
                    case 2:
                        sortbyRoutePlace(sportsmen, 3);
                        break;
                    case 3:
                        sortbyRoutePlace(trainers, 2);
                        break;
                    case 0:
                        continue;
                        check = -1;
                        break;
                    default:
                        cout << "Помилка!" << " ";
                        break;
                    }
                    break;
                case 4:
                    stateSortBytourQuantMenu = -1;
                    system("cls");
                    cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t- ";
                    cin >> check;
                    switch (check) {
                    case 1:
                        sortbyRoute(tourists, 1);
                        break;
                    case 2:
                        sortbyRoute(sportsmen, 3);
                        break;
                    case 3:
                        sortbyRoute(trainers, 2);
                        break;
                    case 0:
                        continue;
                        check = -1;
                        break;
                    default:
                        cout << "Помилка!" << " ";
                        break;
                    }
                    break;
                case 3:
                    stateSortBytourQuantMenu = -1;
                    system("cls");
                    cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t- ";
                    cin >> check;
                    switch (check) {
                    case 1:
                        sortbyTourTime(tourists, 1);                        
                        break;
                    case 2:
                        sortbyTourTime(sportsmen, 3);
                        break;
                    case 3:
                        sortbyTourTime(trainers, 2);
                        break;
                    case 0:
                        continue;
                        check = -1;
                        break;
                    default:
                        cout << "Помилка!" << " ";
                        break;
                    }
                    break;
                case 2:
                    stateSortBytourQuantMenu = -1;
                    system("cls");
                    cout << endl << " [1] - Туристи\n [2] - Спортсмени \n [3] - Тренери\n [0] - Назад\n Вибір \t- ";
                    cin >> check;
                    switch (check) {
                    case 1:
                        sortbyChoosenTour(tourists, 1);                        
                        break;
                    case 2:
                        sortbyChoosenTour(sportsmen, 3);
                        break;
                    case 3:
                        sortbyChoosenTour(trainers, 2);
                        break;
                    case 0:
                        continue;
                        check = -1;
                        break;
                    default:
                        cout << "Помилка!" << " ";
                        break;
                    }
                    break;
                default:
                    stateMenu = -1;
                    stateSortByToursMenu = 0;
                    continue;
                    break;
                }
                system("pause");
                continue;
            }
            break;
        case 8:
            db.readData();
            break;
        case 9:
            if (is_admin) {
                db.writeData();
            }
            break;        
        case 12:
            if (is_admin) {
                initGroupsSects();
            }
            break;
        case 0:
            return;
            break;
        default:
            continue;
            break;
        }
    }
}

int main()
{    
    menu();
	return 0;
}
