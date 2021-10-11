
public class Lab2 {
    public static void main(String[] args) {
        Teacher Ivanov = new Teacher(0, "Ivanov","Radislaw","Olzhevich",67,33);
        Teacher Mostavchuk = new Teacher(1, "Mostavchuk","Petro","Petrovich",33,7);
        Teacher Bandera = new Teacher();
        Bandera.setId(2);
        Bandera.setSurname("Bandera");
        Bandera.setName("Stepan");
        Bandera.setFathersName("Andriyovych");
        Bandera.setAge(112);
        Bandera.setExperience(80);

        Teacher[] Teachers = new Teacher[3];
        Teachers[0]=Ivanov;
        Teachers[1]=Mostavchuk;
        Teachers[2]=Bandera;

        for (Teacher t : Teachers) {
           System.out.println(t.getSurname() + t.getName() + "'s id is " + t.getId());
        }
          }
}