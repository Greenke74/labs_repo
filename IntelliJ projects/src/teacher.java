import java.util.Locale;

public class teacher { // викладач
    private int _id; // унікальний кодовий номер
    private String _surname, _name, _fathersName; // ПІБ
    private int _age; // вік
    private int _experience; // стаж роботи

        //setters
    public void setId(int id) {
        _id = id;
    }
    public void setSurname(String surname) {
        _surname=surname;
    }
    public void setName(String name) {
        _name=name;
    }
    public void setFathersName(String fathersName) {
        _fathersName=fathersName;
    }
    public void setAge(int age) {
        if(age>21){
            _age=age;
        }
        else {
            System.out.println(" Incorrect age for teacher! ");
        }
    }
    public void setExperience(int experience) {
        if(experience>0) {
            if(experience<_age) {
                _experience=experience;
            }
            else {
                System.out.println(" The experience can't be more that age! ");
            }
        }
    }

        //getters
    public int getId() {
        return _id;
    }
    public String getSurname() {
        return _surname;
    }
    public String getName() {
        return _name;
    }
    public String getFathersName() {
        return _fathersName;
    }
    public int getAge() {
        return _age;
    }
    public int getExperience() {
        return _experience;
    }
        //constructors
    teacher() {} // порожній конструктор
    teacher(int id, String surname, String name, String fathersName, int age, int experience){ // конструктор з параметрами
        _id=id;
        _surname=surname;
        _name=name;
        _fathersName=fathersName;
        _age=age;
        _experience=experience;
    }
        //information printers
    public void print() {
        System.out.println("teacher: " +  _surname + " " + _name + " " + _fathersName + " age: " + _age + " experience: " + _experience);
    }
    public void upperPrint() {
        System.out.println("TEACHER: " +  _surname.toUpperCase() + " " + _name.toUpperCase() + " " + _fathersName.toUpperCase() + " AGE: " + _age + " EXPERIENCE: " + _experience);
    }
}
