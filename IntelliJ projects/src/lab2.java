
public class lab2 {
    public static void main(String[] args) {
        teacher Ivanov = new teacher(0, "Ivanov","Radislaw","Olzhevich",67,33);
        teacher Mostavchuk = new teacher(1, "Mostavchuk","Petro","Petrovich",33,7);
        teacher Bandera = new teacher();
        Bandera.setId(2);
        Bandera.setSurname("Bandera");
        Bandera.setName("Stepan");
        Bandera.setFathersName("Andriyovych");
        Bandera.setAge(112);
        Bandera.setExperience(80);

        teacher[] teachers = new teacher[3];
        teachers[0]=Ivanov;
        teachers[1]=Mostavchuk;
        teachers[2]=Bandera;

        for (teacher t : teachers) {
           System.out.println(t.getSurname() + t.getName() + "'s id is " + t.getId());
        }
          }
}